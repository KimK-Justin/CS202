#include "Landmass.h"
#include <iostream>
#include "Continent.h"
using namespace std;

Continent::Continent(){

}
Continent::Continent(string name){
    m_myName = name;
}
Continent::~Continent(){

}

void Continent::CallMyName(){
    cout << "I am the continent of "<< m_myName << endl;
}
void Continent::DescribeMe(){
    cout << "I am one of seven continents! " << endl;
}
