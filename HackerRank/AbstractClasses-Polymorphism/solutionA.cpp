#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Node {
  Node *next;
  Node *prev;
  int value;
  int key;
  Node(Node *p, Node *n, int k, int val)
      : prev(p), next(n), key(k), value(val){};
  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {

protected:
  map<int, Node *> mp;            // map the key to the node in the linked list
  int cp;                         // capacity
  Node *tail;                     // double linked list tail pointer
  Node *head;                     // double linked list head pointer
  virtual void set(int, int) = 0; // set function
  virtual int get(int) = 0;       // get function
};

class LRUCache : public Cache {
public:
  LRUCache(int capacity) {
    cp = capacity;
    head = nullptr;
    tail = nullptr;
  }

  void set(int key, int value) override {
    if (mp.find(key) != mp.end()) {
      Node *existingNode = mp[key];
      existingNode->value = value;
      moveToHead(existingNode);
    } else {
      Node *newNode = new Node(key, value);
      if (mp.size() == cp) {
        mp.erase(tail->key);
        removeNode(tail);
      }
      addNode(newNode);
      mp[key] = newNode;
    }
  }

  int get(int key) override {
    if (mp.find(key) == mp.end()) {
      return -1;
    } else {
      Node *node = mp[key];
      moveToHead(node);
      return node->value;
    }
  }

private:
  void addNode(Node *node) {
    node->next = head;
    node->prev = nullptr;
    if (head != nullptr) {
      head->prev = node;
    }
    head = node;
    if (tail == nullptr) {
      tail = node;
    }
  }

  void removeNode(Node *node) {
    if (node->prev != nullptr) {
      node->prev->next = node->next;
    } else {
      head = node->next;
    }
    if (node->next != nullptr) {
      node->next->prev = node->prev;
    } else {
      tail = node->prev;
    }
    if (node == tail) {
      tail = node->prev;
    }
  }

  void moveToHead(Node *node) {
    if (node == head)
      return;
    removeNode(node);
    addNode(node);
  }
};

int main() {
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for (i = 0; i < n; i++) {
    string command;
    cin >> command;
    if (command == "get") {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    } else if (command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
  return 0;
}
