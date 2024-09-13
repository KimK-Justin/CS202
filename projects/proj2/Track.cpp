#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Track.h"
using namespace std;
//Sets all racers default start at 0
Track::Track(){
    m_length = 4;
    for(int i =0 ; i < NUM_RACERS; i ++){
        m_track[i] = 0;
    }
}
void Track::SetLength(int length){
    m_length = length;
}
//Sets a series of random obstacles in every element up to the length of the total game
void Track::PopulateObstacles(){
    srand(time(NULL));
    for(int i = 0; i < m_length; i++){
        int randomMove = rand() % 3;
        m_obstacle[i] = randomMove;
    }
}
//race status press 1 to see this
void Track::GetStatus(){
    for(int i = 0; i < NUM_RACERS; i++){
        if(i == 0){
            cout << "You are on a " << ConvertObstacle(0) << " obstacle in (" << m_track[i]+1 << " of " << m_length << ")" << endl;
        }else{
            cout << "Player " << i << " is on a " << ConvertObstacle(i) << " obstacle in (" << m_track[i]+1 << " of " << m_length << ")" << endl;
        }
    }
}
//requirement is to have you win when tied so your if statement goes first 
int Track::CheckWin(){
    if(m_track[0] >= m_length){
        return 0;
    }else if(m_track[1] >= m_length){
        return 1;
    }else if(m_track[2] >= m_length){
        return 2;
    }else if(m_track[3] >= m_length){
        return 3;
    }
    return -1;
}
int Track::GetObstacle(int location){
    return m_obstacle[location];
}
void Track::IncrementLocation(int player){
    m_track[player] += 1;
}
void Track::ResetLocation(){
    for(int i = 0; i < NUM_RACERS; i ++){
        m_track[i] = 0;
    }
}
  // Name: ConvertObstacle
  // Desc - Returns the string name of the obstacle using the OBSTACLE_TYPE
  //        array for a specific player
  // Preconditions - Player exists in m_track
  // Postconditions - Pulls the location from m_track for a provided player
  //                  then returns the obstacle at that location
string Track::ConvertObstacle(int player){
    int numObstacle = GetObstacle(m_track[player]);
    if(numObstacle == 0){
        return "speed";
    }else if(numObstacle == 1){
        return "agility";
    }else if(numObstacle == 2){
        return "jump";
    }
    return "not working";
}
