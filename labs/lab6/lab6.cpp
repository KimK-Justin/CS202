//File: lab6.cpp                                                                                                              

#include <iostream>
#include <string>
#include <vector>
#include "Groceries.h"
using namespace std;

//COMPLETE THIS FUNCTION                                                                                                      
void fillVector(vector<Groceries> &groceryList){
  int amount = 0;
  string name;
  double price;
  int quant;
  cout << "How many grocery items do you want to add to the list? ";
  cin >> amount;
  for(int i = 0; i < amount; i++){
    cout << "Enter name of grocery item #" << i+1 << ": ";
    cin >> name;
    cout << "Enter price of grocery item #" << i+1 << ": ";
    cin >> price;
    cout << "Enter quantity of grocery item #" << i+1 << ": ";
    cin >> quant;
    cout << endl << endl;
    Groceries newitem = Groceries(name, price, quant);
    groceryList.push_back(newitem);
  }
  // ask for amount of grocery items                                                                                          
  // ask for name, price, quantity of each item and                                                                           
  // add completed grocery item to vector                                                                                                       
}

//COMPLETE THIS FUNCTION                                                                                                      
void printVectorWithoutIterator(vector<Groceries> &groceryList){
  cout << endl << "Grocery list (without iterator)" << endl;
  for(unsigned int i = 0; i < groceryList.size(); i++){
    cout.precision(2);
    cout << (i+1) << " " << groceryList[i].getItem() << "(" << groceryList[i].getQuantity() << ") : $" << groceryList[i].getPrice() << endl;
  }
  // print each item's name, price, and quantity with correct                                                                 
  // precision for price                                                                                                      
  // DON'T USE ITERATOR                                                                                                       

}

//COMPLETE THIS FUNCTION                                                                                                      
void printVectorWithIterator(vector<Groceries> &groceryList){
  cout << "Grocery list (with iterator)" << endl;
  int counter = 1;
  for(vector<Groceries>::iterator it = groceryList.begin(); it != groceryList.end(); ++it){
    cout.precision(2);
    cout << counter << " " << (*it).getItem() << "(" << (*it).getQuantity() << ") : $" << (*it).getPrice() << endl;
    counter++;
  }


  // print each item's name, price, and quantity with correct                                                                 
  // precision for price                                                                                                      
  // USE ITERATOR                                                                                                       

}

void checkStatus(vector<Groceries> &groceryList){
  //DEFINE ENUM HERE BASED ON NAMES BELOW                                                                                                          
  int listSize = groceryList.size();
  enum members {nonMem, bronze, silver};
  switch (listSize) {
  case nonMem: cout << "You did not purchase enough items to become a member." << endl;
    break;
  case bronze: cout << "You purchased enough items to become a bronze member." << endl;
    break;
  case silver: cout << "You purchased enough items to become a silver member." << endl;
    break;
  default: cout << "You purchased enough items to become a gold member!" << endl;
  }
}

int main(){

  vector<Groceries> groceryList; //Creates a new vector of Groceries

  fillVector(groceryList); //Populates the vector of Groceries
  printVectorWithoutIterator(groceryList); //Displays the contents of the vector
  cout << endl;
  printVectorWithIterator(groceryList); //Alterate way to display the contents of the vector
  checkStatus(groceryList); //calls function defined above (must define enum)

  return 0;
}
