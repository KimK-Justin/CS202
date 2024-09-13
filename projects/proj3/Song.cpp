/*
Author: Justin Kim
Date: 11/3/2022
Desc: Make a Song class that can be used as an object in other classes
*/

#include <iostream>
#include <string>
#include "Song.h"
using namespace std;
  //Name: Song - Default Constructor
  //Precondition: None
  //Postcondition: Creates a default song using "New Title", "New Artist", 0 , 0 and sets m_next = nullptr;
Song::Song(){
    m_title = "New Title";
    m_artist = "New Artist";
    m_year = 0;
    m_rank = 0;
    m_next = nullptr;
}
  //Name: Song - Overloaded Constructor
  //Precondition: Requires title, artist, year, and rank
  //Postcondition: Creates a song based on passed parameters and sets m_next = nullptr;
Song::Song(string title, string artist, int year, int rank ){
    m_title = title;
    m_artist = artist;
    m_year = year;
    m_rank = rank;
    m_next = nullptr;
}
  //Name: Mutators and Accessors
  //May or may not be used specifically but implement all
  //Precondition: None
  //Postcondition: Sets and Gets private member variables
string Song::GetTitle(){
    return m_title;
}
string Song::GetArtist(){
    return m_artist;
}
int Song::GetYear(){
    return m_year;
}
int Song::GetRank(){
    return m_rank;
}
void Song::SetTitle(string title){
    m_title = title;
}
void Song::SetArtist(string artist){
    m_artist = artist;
}
void Song::SetYear(int year){
    m_year = year;
}
void Song::SetRank(int rank){
    m_rank = rank;
}
Song* Song::GetNext(){
    return m_next;
}
void Song::SetNext(Song* next){
    m_next = next;
}
