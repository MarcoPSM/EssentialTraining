#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>

struct Message {
  long msgType;
  size_t size;
  void *ptr;
};

int main() {
  key_t key = ftok("memory_manager", 65);
  int msgid = msgget(key, 0666 | IPC_CREAT);

  Message message;
  message.msgType = 1;
  message.size = 50 * 1024 * 1024; // 50MB

  msgsnd(msgid, &message, sizeof(message), 0);

  msgrcv(msgid, &message, sizeof(message), 1, 0);
  std::cout << "Allocated memory at: " << message.ptr << std::endl;

  msgctl(msgid, IPC_RMID, nullptr);
  return 0;
}
