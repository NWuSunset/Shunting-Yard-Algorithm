#ifndef STACK_AND_QUEUE_H
#define STACK_AND_QUEUE_H

#include <cstring>

struct Node {
  char data = '\0'; //null character
  Node* next = nullptr;

  Node(const char data) {
    this->data = data;
  }
};


class Stack {
 public:
  Stack();
  
  void push(Node* node); //Push to top of stack (head of linked list)
  void pop(); //pop/remove from top of stack (head of linked list)
  void peek(); //See what the top of the stack is

private:
  Node* top = nullptr; //top of stack (head of linked list)
};


class Queue {
 public:
  Queue();
  
  void enqueue(); //Add to 'top' of queue (head of linked list)
  void dequeue(); //remove from 'bottom' of the queue (last linked list value)

private:
  Node* first = nullptr; //first in queue
  Node* last = nullptr; //last in queue
};

#endif //STACK_AND_QUEUE_H
