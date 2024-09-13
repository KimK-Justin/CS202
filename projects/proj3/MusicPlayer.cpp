#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Song.h"
#include "Playlist.h"
#include "MusicPlayer.h"
using namespace std;

  //Name: MusicPlayer - Default Constructor
  //Precondition: None
  //Postcondition: Dynamically creates a new MusicPlayer and populates m_filename FILE_NAME
MusicPlayer::MusicPlayer(){
    m_playList = new Playlist();
}
  //Name: ~MusicPlayer - Destructor
  //Precondition: None
  //Postcondition: Destructs all songs in the catalog and all songs in the playlist
MusicPlayer::~MusicPlayer(){
    long unsigned int counter = 0;
    while(counter < m_songCatalog.size()){//iterates through vecotr and destroys each index
        delete m_songCatalog[counter];
        counter ++;
    }
    delete m_playList; 
}
  //Name: LoadCatalog(string filename)
  //Precondition: Requires filename
  //Postcondition: Loads the file of songs into the m_songCatalog (as song objects) using the DELIMITER
void MusicPlayer::LoadCatalog(string filename){
    string title, artist, year, rank;
    int years, ranks;
    ifstream inFile(filename);
    if(inFile.is_open()){
        while(!inFile.eof()){
            //stores the given variables with string until it hits delimiter
            getline(inFile, title, DELIMITER);
            getline(inFile, artist, DELIMITER);
            getline(inFile, year, DELIMITER);
            years = stoi(year);
            getline(inFile, rank, '\n');//stops at empty line
            ranks = stoi(rank);//changes string to int
            //makes a song object and puts it into the vector
            Song* temp = new Song(title, artist, years, ranks);
            m_songCatalog.push_back(temp);
        }
    }else{
        cout << "could not open file" << endl;
    }
    inFile.close();
    cout << "Songs loaded: " << m_songCatalog.size() - 1 << endl;
}
  //Name: MainMenu
  //Precondition: None
  //Postcondition: Manages the application and the menu. Calls until user chooses to quit.
void MusicPlayer::MainMenu(){
    int userInput;
    cout << "What would you like to do? \n1. Display Songs by Year \n2. Add Song\n3. Display Playlist\n4. Play Song\n5. Quit" << endl;
    cin >> userInput;
    while(userInput != 5){
        if(userInput == 1){
            DisplaySongs();
        }else if(userInput == 2){
            AddSong();
        }else if(userInput == 3){
            DisplayPlaylist();
        }else if(userInput == 4){
            PlaySong();
        }
        cout << "What would you like to do? \n1. Display Songs by Year \n2. Add Song\n3. Display Playlist\n4. Play Song\n5. Quit" << endl;
        cin >> userInput;
    }

}
  //Name: DisplaySongs
  //Precondition: User enters year using constants above (2010-2021)
  //Postcondition: Lists all songs (numbered) for that year by ranking
void MusicPlayer::DisplaySongs(){
    int choice;
    while(!(choice >= LOW_YEAR && choice <= HIGH_YEAR)){
        cout << "Which year would you like to display? (2010 - 2021)" << endl;
        cin >> choice;
    }
    cout << "******" << choice << "******" << endl;
    //mostly formatting
    for(long unsigned int i = 0; i < m_songCatalog.size() - 1; i++){
        if(m_songCatalog[i] -> GetYear() == choice){
            cout << i+1 << ". \"" << m_songCatalog[i] -> GetTitle() << "\" by " << m_songCatalog[i] -> GetArtist() << " " << m_songCatalog[i] -> GetRank() << "/100 from " << m_songCatalog[i] -> GetYear() << endl;
        }
    }
}
  //Name: AddSong
  //Precondition: m_songCatalog is populated and m_playList exists
  //Postcondition: Displays the songs for a specific year. Adds a song to the m_playList by dynamically allocating a new song based on the song in the catalog
  //               and inserting it in the end.
  //               May have duplicate songs on a playlist.
  //               If the user chooses 2010, the user does not have to choose something from 2010 but it does need to be valid (between 1 - 1200)
void MusicPlayer::AddSong(){
    int userChoice;
    DisplayPlaylist();
    cout << "Choose the song you would like to add to the playlist." << endl;
    do{
        DisplaySongs();
        cout << "Enter the number of the song you would like to add:" << endl;
        cin >> userChoice;
    }while(!(userChoice <= 1200 && userChoice >= 1));
    //wanna add the song to playlist linked list
     m_playList -> AddSong(m_songCatalog[userChoice - 1] -> GetTitle(), m_songCatalog[userChoice - 1] -> GetArtist(),  m_songCatalog[userChoice - 1]-> GetYear(),  m_songCatalog[userChoice - 1] -> GetRank());

}
  //Name: DisplayPlaylist
  //Precondition: None (can be empty)
  //Postcondition: Displays the playlist or tells the user it is empty
void MusicPlayer::DisplayPlaylist(){
    Song* temp;
    if(m_playList -> Size() == 0){
        cout << "***Current Playlist is Empty***" << endl;
    }else{
        //iterates through and outputs into a format
        cout << "Your Playlist: " << endl;
        for(int i = 0 ; i < m_playList ->Size(); i++){
            temp = m_playList -> GetPlaylistDetails(i);
            cout << i+1 << ". \"" << temp -> GetTitle() << " by " << temp -> GetArtist() << " " << temp -> GetRank() << "/100 from " << temp -> GetYear() << endl;
        }
    }
}
  //Name: PlaySong
  //Precondition: Playlist should be populated
  //Postcondition: Allows the user to choose a song from the playlist to play.
  //               Removes chosen song from playlist after "played"
void MusicPlayer::PlaySong(){
    Song* played;
    //playlist must have song
    if(m_playList -> Size() > 0){
        int user;
        DisplayPlaylist();
        cout << "Which song would you like to play?" << endl;
        cin >> user;
        user = user -1;
        played = m_playList -> GetPlaylistDetails(user);
        cout << "Played: \"" << played -> GetTitle() << "\" by " << played -> GetArtist() << " " << played -> GetRank() << "/100 from " << played -> GetYear() << endl;
        m_playList -> PlayAt(user);
    }else{
        cout << "There are no songs to play" << endl;
    }
}