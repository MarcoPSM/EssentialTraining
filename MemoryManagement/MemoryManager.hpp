#ifndef MEMORYMANAGER_HPP
#define MEMORYMANAGER_HPP

#include <cstddef>

struct MemoryBlock {
  size_t size;
  bool isFree;
  MemoryBlock *next;
};

class MemoryManager {
public:
  MemoryManager(size_t totalSize);
  void *allocate(size_t size);
  void deallocate(void *ptr);
  void printMemoryLayout();

private:
  MemoryBlock *head;
  void mergeFreeBlocks();
};

#endif // MEMORYMANAGER_HPP
