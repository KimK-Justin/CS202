#include "Landmass.h"
#include <iostream>
#include "Island.h"
using namespace std;

Island::Island(){

}
Island::Island(string name){
    m_myName = name;
}
Island::~Island(){

}
void Island::CallMyName(){
    cout << "I am a beautiful island named " << m_myName << endl;
}
void Island::DescribeMe(){
    cout << "I am surrounded by a body of water." << endl;
}
