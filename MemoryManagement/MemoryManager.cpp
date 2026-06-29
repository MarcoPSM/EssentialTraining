#include "MemoryManager.hpp"
#include <cstring>
#include <iostream>

MemoryManager::MemoryManager(size_t totalSize) {
  head = new MemoryBlock{totalSize, true, nullptr};
}

void *MemoryManager::allocate(size_t size) {
  MemoryBlock *current = head;
  while (current) {
    if (current->isFree && current->size >= size) {
      if (current->size > size) {
        MemoryBlock *newBlock =
            new MemoryBlock{current->size - size, true, current->next};
        current->size = size;
        current->next = newBlock;
      }
      current->isFree = false;
      return (void *)(current + 1);
    }
    current = current->next;
  }
  return nullptr; // Sem espaço suficiente
}

void MemoryManager::deallocate(void *ptr) {
  if (!ptr)
    return;
  MemoryBlock *block = (MemoryBlock *)ptr - 1;
  block->isFree = true;
  mergeFreeBlocks();
}

void MemoryManager::mergeFreeBlocks() {
  MemoryBlock *current = head;
  while (current && current->next) {
    if (current->isFree && current->next->isFree) {
      current->size += current->next->size;
      MemoryBlock *temp = current->next;
      current->next = current->next->next;
      delete temp;
    } else {
      current = current->next;
    }
  }
}

void MemoryManager::printMemoryLayout() {
  MemoryBlock *current = head;
  while (current) {
    std::cout << "Block size: " << current->size << " - "
              << (current->isFree ? "Free" : "Allocated") << std::endl;
    current = current->next;
  }
}
