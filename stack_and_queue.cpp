#include "stack_and_queue.h"
#include <iostream>

using namespace std;

//Stack things
Stack::Stack() = default;

//Push to top of stack
void Stack::push(Node* node) {
  if (top == nullptr) { //If head is null then there is nothing in the list
    //For first item in the list top == head
    top = node;
    return;
  }
  
  node->next = top;
  top = node;
  } 

//Pop from top of stack
Node* Stack::pop() {
  if (top == nullptr) {
    cout << "Stack is empty" << endl;
    return nullptr;
  }

  Node* toPop = top;
  
  top = top->next;
 
  return toPop; //return the top of the stack
}

//Peek top of stack
Node* Stack::peek() const {
  if (top == nullptr) {
    cout << "Stack empty, top is null" << endl;
  }
  
  return top;
}

//Extra function to check if the top is null. For readablility
bool Stack::isEmpty() const {
  if (top == nullptr) { //head will be null if there is nothing in the stack
    return true;
  }
  return false;
}

Stack::~Stack() {
  while (top != nullptr) {
    const Node* temp = top;
    top = top->next;
    delete temp;
  }
}


Queue::Queue() = default;

//Add to first in queue (head of linked list)
void Queue::enqueue(Node* node) {
  //if there are no items in the queue
  if (first == nullptr) {
    first = node;
    last = node;
    return;
  }

  last->next = node;
  last = node; //last in queue
  
}


//Remove from first in queue (head in linked list)
Node* Queue::dequeue() {
  if (first == nullptr) {
    cout << "Queue is empty" << endl;
    return nullptr;
  }

  Node* toDequeue = first;

  first = first->next; 

  if (first == nullptr) { //if there is only one item in the queue
    last = nullptr;
  }
 
  return toDequeue;
}

bool Queue::isEmpty() const {
  if (first == nullptr) {
    return true;
  }
  return false;
}

void Queue::printQueue() const {
  //GO through the linked list
  const Node* curr = first;

  while (curr != nullptr) {
    cout << curr->data << " ";
    curr = curr->next;
  }
}

Queue::~Queue() {
  while (first != nullptr) {
    const Node* temp = first;
    first = first->next;
    delete temp;
  }
}


