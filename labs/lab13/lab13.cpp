/*
CMSC 202 - Lab 13 
Lab to practice recursion
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/* Node Struct */
struct Node{
  Node(int v) : m_val(v), m_next(nullptr) {} //Overloaded constructor
  int m_val; //Data in node
  Node* m_next; //Pointer to next node
};

/*************************************************
 * Implement stringify()                         *
 * Input: Node* -> Linked List                   *
 * Return: String of linked list values          *
 * Hint: Use to_string to convert int to string  *
 * Hint 2: Use + to concatenate strings          *
 ************************************************/

//&&&&&&&&&&  IMPLEMENT STRINGIFY HERE &&&&&&&&&&&&
string stringify(Node* head){
  string contain = "";
  if(head -> m_next == nullptr){
    contain = to_string(head ->m_val);
    return contain;
  }else{
    contain = to_string(head ->m_val) + stringify(head->m_next);
  }
  return contain;
}





/*********************************************
 * main()                                    *
 * DO NOT EDIT                               *
 *********************************************/
int main(){
  int len = 0; //Stores length of linked list
  Node *head = nullptr, *cur = nullptr; //Node pointer to head and curr

  srand(time(NULL)); //Seeds random number generator

  // create randomized linked list with possible length between 1 and 5
  head = new Node(rand() % 100); //Creates new node and points head to new node
  cur = head; //Sets cur to point to head
  cout << "Linked list:\n" << head->m_val; //Outputs value of first node

  len = rand() % 5; //Returns number between 0 and 4
  while(len--) { //Counts down from len
    cur->m_next= new Node(rand() % 100); //Makes cur next point to a new node
    cur = cur->m_next; //Moves cur to next node
    cout << "->" << cur->m_val; //outputs an arrow and the next value
  }

  // test stringify()
  cout << "\nstringify result (should be same as above, but without arrows):\n"
       << stringify(head) << endl; //Calls the recursive function

  // deallocate all nodes
  while(head) {
    cur = head;
    head = head->m_next;
    delete cur;
  }

  return 0;
}
