#ifndef STACK_AND_QUEUE_H
#define STACK_AND_QUEUE_H

#include <cstring>

struct Node {
  char data = '\0'; //null character (this may be changed to a string later)
  Node* next = nullptr;

  Node(const char data) {
    this->data = data;
  }
};


class Stack {
 public:
  Stack();
  //Stack will pop when the operator being put in has equal or less presedence than top of stack and added to the end queue.
 
  
  void push(Node* node); //Push to top of stack (head of linked list)
  Node* pop(); //pop/remove from top of stack (head of linked list)
  Node* peek(); //See what the top of the stack is

private:
  Node* top = nullptr; //top of stack (just the end of linked list)
  Node* head = nullptr; //head of list 
};


class Queue {
 public:
  Queue();
  
  void enqueue(Node* node); //Add to queue (end of linked list)
  Node* dequeue(); //remove from 'first' of the queue (head of linked list)

private:
  Node* first = nullptr; //first in queue (linked list head)
  Node* last = nullptr; //last in queue (linked list end)
};

#endif //STACK_AND_QUEUE_H
