#include "Train.h"

// Constructor
// Gets the linked list ready to be used
Train::Train(){
  m_head = nullptr;
  m_size = 0;
}

// Destructor
// Removes all the train cars from the train
Train::~Train(){
  TrainCar* next = m_head->m_next;
  while(next != nullptr){ // iterates through the list until the end is found
    delete m_head; // delete the head 
    m_head = next; // iterate m_head
    next = next->m_next; // iterate the next ptr
  }
  delete m_head; // clean up the last node 
  m_head = nullptr; // always set hanging pointers to nullptr
}

// COMPLETE THIS FUNCTION
// insert a train car into the back of the train
void Train::InsertCar(string name){
  TrainCar* newNode = new TrainCar();
  newNode->m_name = name;
  newNode -> m_next = nullptr;
  TrainCar* end = m_head;
  if(!m_head){
    m_head = newNode;
    m_size++;
  }else{
    while(end -> m_next){
      end = end -> m_next;
    }
    end -> m_next = newNode;
    m_size++;
  }
  m_tail = newNode;
}

// COMPLETE THIS FUNCTION
// remove the last train car
void Train::RemoveLast(){
  TrainCar* end = m_head;
  TrainCar* prev = nullptr;
  while(end -> m_next){
    prev = end;
    end = end-> m_next;
  }
  prev -> m_next = nullptr;
  m_size --;
  free(end);
}

// display()
// iterates through the train and says all their names
void Train::Display(){
  TrainCar* current = m_head;

  while(current != nullptr){ // iterate through the list
    cout << current->m_name << " -> ";
    current = current->m_next;
  }
  cout << "END" << endl << "Size: " << m_size << endl; 
} 
