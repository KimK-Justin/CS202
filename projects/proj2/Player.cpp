#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

Player::Player(){
    m_name = "Beannie";
    for(int i = 0; i < 3; i++){
        m_stat[i] = 1;
    }
    m_races = 0;
    m_wins = 0;
    m_falls = 0;
}
Player::Player(string name){
    m_name = name;
    for(int i = 0; i < 3; i++){
        m_stat[i] = 1;
    }
    m_races = 0;
    m_wins = 0;
    m_falls = 0;
}

//MOSTLY GETTER AND SETTERS
string Player::GetName(){
    return m_name;
}
void Player::SetName(string name){
    m_name = name;
}
int Player::GetSpeed(){
    return m_stat[0];
}
int Player::GetAgility(){
    return m_stat[1];
}
int Player::GetJump(){
    return m_stat[2];
}
int Player::GetRaces(){
    return m_races;
}
int Player::GetFalls(){
    return m_falls;
}
void Player::SetRaces(int races){
    m_races = races;
}
void Player::SetFalls(int falls){
    m_falls = falls;
}


//Displays all the stats when hitting 2 on the menu
void Player::DisplayStatus(){
    cout << "*****The Mighty Racer " << m_name << " *********"<< endl;
    cout << "Races: " << m_races << "\nWins: " << m_wins << "\nFalls: " << m_falls << endl;
    cout << endl << "stats" << endl << "Speed: " << m_stat[0] << endl << "Agility: " << m_stat[1] << endl << "Jump: " << m_stat[2] << endl; 
}
//increase stat of choice
void Player::IncreaseStat(){
    int choice;
    cout << "which stat would you like to increase? " << endl << "1. Speed\n2. Agility\n3. Jump" << endl;
    cin >> choice;
    m_stat[choice - 1] += 1;
}
int Player::GetStat(int stat){
    return m_stat[stat];
}
void Player::IncreaseWins(){
    m_wins += 1;
}


