#include "NPC.h"
#include "Traveler.h"
#include "Merchant.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

Traveler::Traveler(){

}
Traveler::Traveler(string name, string desc, string dia, string origin, string weapon, int power) : NPC(name, desc, dia){
    m_origin = origin;
    m_weapon = weapon;
    m_power = power;
}
void Traveler::Fight(int userPwr){
    if(userPwr > m_power){
        cout << "You bested " << GetName() << endl;
    }else{
        cout << GetName() << " has bested you" << endl;
    }
}
void Traveler::Inquire(){
    cout << m_origin;
}
string Traveler::GetOrigin(){
    return m_origin;
}
string Traveler::GetWeapon(){
    return m_weapon;
}
int Traveler::GetPower(){
    return m_power;
}