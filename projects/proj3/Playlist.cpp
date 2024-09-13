#include <string>
#include <fstream>
#include <iostream>
#include "Song.h"
#include "Playlist.h"
using namespace std;
  // Name: Playlist() - Default Constructor
  // Desc - Creates a new empty playlist
  // Preconditions - None
  // Postconditions - Sets everything to either nullptr or 0
Playlist::Playlist(){
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}
  // Desc - Removes all of the songs from the playlist
  // Preconditions - Playlist must have songs
  // Postconditions - Playlist will be empty and m_head and m_tail will be nullptr. Size will be 0
Playlist::~Playlist(){
    if(m_size != 0){//iterates through the entire linked list deleting the next link
        Song* temp = m_head;
        while(temp != nullptr){
            Song* next = temp -> GetNext();
            delete temp;
            temp = next;
        }
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}
  // Name: AddSong(string, string, int, int)
  // Desc - Dynamically allocates new song using title, artist, year, and rank
  // Preconditions - Playlist allocated
  // Postconditions - New song inserted in end of list
void Playlist::AddSong(string name, string artistName, int yearMade, int yearRank){
    Song* newSong = new Song(name, artistName, yearMade, yearRank);//make song object
    if(m_head == nullptr){//if nothing in playlist new song object is first index
        m_head = newSong;
    }else{
        Song* end = m_head;
        while(end -> GetNext()){//until it reaches the end; song is placed at the end and its next is null
            end = end -> GetNext();
        }
        end -> SetNext(newSong);
    }
    m_size++;
}
  // Name: GetPlaylistDetails()
  // Desc - Returns a song object from a specific location
  // Preconditions - Playlist populated
  // Postconditions - Returns the data (does not output it)
Song* Playlist::GetPlaylistDetails(int location){
    Song* cur = m_head;
    int count = 0;
    while(cur){
        if(count == location){//iterates until counter equals the passed index
            return cur;
        }
        count++;
        cur = cur -> GetNext();//iterator
    }
    return cur;
}
//return size
int Playlist::Size(){
    return m_size;
}
  // Name: PlayAt
  // Desc - Passed the song that is to be played from the playlist
  //       "Plays" a song by removing it from the playlist at a specific location
  // Recommendations - Code this function last (dead last)
  // Preconditions - Playlist has been populated
  // Hint: Do not forget about removing from the front, middle, or end of the list
  //       Could also remove the only node
void Playlist::PlayAt(int location){
    Song* temp = m_head;
    Song* prev = m_head;
    int counter = 0;
    if(m_head == nullptr){
        return;
    }
    if(location == 0){//if the first node delete the node and set m_head to the next link
        m_head = temp -> GetNext();
        delete temp;
    }else if(location == Size() - 1){//deletes the last node
        while(temp != m_tail){//iterates until it reaches the last node
            prev = temp;
            temp = temp -> GetNext();
        }
        prev -> SetNext(nullptr);
        m_tail = prev;
        delete temp;//delete until it reaches the end;
    }else{
        while(temp != nullptr){//while iterating through if counter equal the location set the links next to equal the next link and then delete the first link
            if(counter == location){
                prev -> SetNext(temp -> GetNext());
                delete temp;
                m_size--;
                return;
            }
            counter++;//bottom are just itterators
            prev = temp;
            temp = temp -> GetNext();
        }
    }
    m_size--;
}
