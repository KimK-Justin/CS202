#include "NPC.h"
#include "Merchant.h"
#include <iostream>
#include <string>
using namespace std;

Merchant::Merchant(){

}
Merchant::Merchant(string name, string desc, string dia, string ware, double price, int quantity) : NPC(name, desc, dia){
    m_wares = ware;
    m_price = price;
    m_quantity = quantity;
}
void Merchant::Sell(){
    int userGoods;
    cout << GetName() << ": \"Selling " << m_wares << ". How many will you buy?\"" << endl;
    cin >> userGoods;
    if(m_quantity > userGoods){
        cout << GetName() << ": \"Sorry I do not have enough.\"" << endl;
    }else{
        cout << GetName() << ": \"That'll be " << userGoods*m_price << " gold.\"" << endl;
    }
}
string Merchant::GetWares(){
    return m_wares;
}
double Merchant::GetPrice(){
    return m_price;
}
int Merchant::GetQuantity(){
    return m_quantity;
}