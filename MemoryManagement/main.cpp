#include "MemoryManager.hpp"
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

struct Message {
  long msgType;
  size_t size;
  void *ptr;
};

void memoryManagerProcess() {
  MemoryManager manager(200 * 1024 * 1024); // 200MB
  key_t key = ftok("memory_manager", 65);
  int msgid = msgget(key, 0666 | IPC_CREAT);
  Message message;

  while (true) {
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    if (message.size > 0) {
      message.ptr = manager.allocate(message.size);
      if (message.ptr) {
        std::cout << "Allocated " << message.size << " bytes." << std::endl;
      } else {
        std::cout << "Allocation failed." << std::endl;
      }
    } else {
      manager.deallocate(message.ptr);
      std::cout << "Deallocated memory." << std::endl;
    }
    manager.printMemoryLayout();
    break;
  }
}

void memoryRequesterProcess() {
  key_t key = ftok("memory_manager", 65);
  int msgid = msgget(key, 0666 | IPC_CREAT);
  Message message;

  // Exemplo de pedidos de alocação e desalocação
  message.msgType = 1;
  message.size = 50 * 1024 * 1024; // 50MB
  msgsnd(msgid, &message, sizeof(message), 0);

  sleep(1); // Espera para simular tempo de uso

  message.size = 0;          // Desalocar
  message.ptr = message.ptr; // Usar o ponteiro retornado anteriormente
  msgsnd(msgid, &message, sizeof(message), 0);

  sleep(1); // Espera para simular tempo de uso

  message.size = 100 * 1024 * 1024; // 100MB
  msgsnd(msgid, &message, sizeof(message), 0);

  msgctl(msgid, IPC_RMID, nullptr);
}

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    memoryManagerProcess();
  } else {
    memoryRequesterProcess();
  }
  return 0;
}