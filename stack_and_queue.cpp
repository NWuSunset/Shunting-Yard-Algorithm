#include "stack_and_queue.h"
#include <iostream>

using namespace std;

//Stack things
Stack::Stack() = default;

//Push to top of stack
void Stack::push(Node* node) {
  Node* curr = head;

  if (head == nullptr) { //If head is null then there is nothing in the list
    //For first item in the list top == head
    head = node;
    top = head;
    return;
  }
  
  while (curr->next != nullptr) {
    curr = curr->next;
  }

  //Once we hit end of linked list (should be top of stack)
  curr->next = node;
  top = curr->next;
}

//Pop from top of stack
Node* Stack::pop() {
  if (top == nullptr) {
    cout << "Stack is empty" << endl;
    return nullptr;
  }

  Node* toPop = top;

  Node* curr = head;
  
  //Go through list until curr->next is the top of the stack
  while (curr->next != top) {
    curr = curr->next;
  }

  //once list end is hit (curr->next should now be the top of the stack)
  curr->next = nullptr; 
  top = curr; //curr is now the new top, and it's next is null

  return toPop; //return the top of the stack
}

//Peek top of stack
Node* Stack::peek() {
  return top;
}

Queue::Queue() = default;

//Add to first in queue (head of linked list)
void Queue::enqueue(Node* node) {
  Node* curr = first; //head of linked list (or first in queue)
  
  while (curr->next != nullptr) {
    curr = curr->next;
  }

  curr->next = node;
  last = curr->next; //last in queue
  
}


//Remove from first in queue (head in linked list)
Node* Queue::dequeue() {
  if (first == nullptr) {
    cout << "Queue is empty" << endl;
    return nullptr;
  }

  Node* toDequeue = first;

  first = first->next; 
 
  return toDequeue;
}
