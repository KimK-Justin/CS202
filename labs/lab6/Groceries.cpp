#include <iostream>
#include <string>
#include "Groceries.h"
using namespace std;

Groceries::Groceries(){
    m_item = " ";
    m_price = 0.0;
    m_quantity = 0;
}
Groceries::Groceries(string item, double price, int quantity){
    m_item = item;
    m_price = price;
    m_quantity = quantity;
}
void Groceries::setItem(string item){
    m_item= item;
}
void Groceries::setPrice(double price){
    m_price = price;
}
void Groceries::setQuantity(int quantity){
    m_quantity = quantity;
}
string Groceries::getItem(){
    return m_item;
}
double Groceries::getPrice(){
    return m_price;
}
int Groceries::getQuantity(){
    return m_quantity;
}