#include "stack_and_queue.h"

//Stack things
Stack::Stack() = default;

//Push to top of stack
void Stack::push(Node* node) {
  const Node* curr = head;

  if (head == nullptr) {
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

  const Node* toPop = top;

  const Node* curr = head;
  
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
  //set head of linked list to passed in node, walk through and move linked list over one space.

  Node* curr = head;

  while (curr != nullptr) {
    curr = curr->next;
  }
  
}


//Remove from last in queue (last in linked list)
Node* Queue::dequeue() {

}
