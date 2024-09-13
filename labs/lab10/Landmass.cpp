#include <iostream>
#include "Landmass.h"
using namespace std;

Landmass::Landmass(){

}
Landmass::~Landmass(){

}
void Landmass::CallMyType(){
    cout <<  "My type is " << m_myType;
}
string Landmass::GetType(){
    return m_myType;
}
void Landmass::SetType(string type){
    m_myType = type;
}