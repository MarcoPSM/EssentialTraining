#include "MemoryManager.hpp"
#include <sys/types.h>
#include <unistd.h>

void memoryManagerProcess() {
  MemoryManager manager(200 * 1024 * 1024); // 200MB
  // Código para gerenciar pedidos de alocação/desalocação
}

void memoryRequesterProcess() {
  // Código para enviar pedidos de alocação/desalocação
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
