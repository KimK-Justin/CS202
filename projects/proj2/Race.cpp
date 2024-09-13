#include <fstream>
#include <iostream>
#include <iomanip>
#include "Player.h" //User defined class required by Race
#include "Track.h" //User defined class required by Race
#include "Race.h"
using namespace std;

Race::Race(){
//nothing to see here
}
// Name: StartRace()
// 1. Resets length of race
// 2. Increments the number of races for the player
// 3. Sets up track (user chooses length of track) and populates obstacles
// 4. Calls RaceOptions and calls GetStatus or calls ProgressRace (passes the user's choice)
// 5. Checks to see if someone won (their location exceeds the length of the race)
// 6. Displays the winner of race. If human player wins, increases a stat and increases wins 
// Preconditions - Race conditions set up
// Postconditions - Race completed
void Race::StartRace(){
    int HowLong;
    int choice;
    bool win = 0;
    int winner;
    do{
        cout << "How long would you like the race?" << endl;
        cin >> HowLong;
    }while(HowLong < 0 || HowLong > 100);
    m_track.SetLength(HowLong);
    m_track.PopulateObstacles();
    //while loop calls raceOptions then depending on choice calls either getStatus or ProgressRace
    while(win == 0){
        do{
            choice = RaceOptions(); 
        }while(choice < 1 || choice > 4);
        if(choice == 1){
            m_track.GetStatus();
        }else{
            ProgressRace(choice);
        }
        //if anyone won this if statment triggers
        if((winner = m_track.CheckWin()) >= 0){
            //finishes the while loop showing the end of game
            win = 1;
            if(winner == 0){
                cout << "You won the race!" << endl;
                m_myPlayer.IncreaseStat();
                m_myPlayer.IncreaseWins();
            }else{
                cout << "Player " << winner << " won the race!" << endl;
            }
            m_track.ResetLocation();
            m_myPlayer.SetRaces(m_myPlayer.GetRaces() + 1);
        }
    }
}
  // Name: GetRacerInfo()
  // Desc - Gets the racer's name and populates the racer's name
  // Preconditions - Populates m_name in Racer
  // Postconditions - m_name is populated
void Race::GetRacerInfo(){
    string userName;
    cout << "what is your racer's name? " << endl;
    cin >> userName;
    m_myPlayer.SetName(userName);
}
  // Name: ProgressRace()
  // Desc - Does the following:
  // 1. Deals with the human player first.
  // 2. Randomly assigns (1 - 100) difficlty to all obstacles (regardless of location,
  //    all players have the same level difficulty for each round)
  // 3. Compares the BASE_SKILL + (5 * stat) to the obstacle difficulty to see if successfully
  //    navigated. Indicates if successful and increments location. If not successful,
  //    falls and increments falls
  // 4. Calls ProgressComputer to deal with computer
  // Preconditions - Player in race
  // Postconditions - Each racer either progresses to the next obstacle, or falls
void Race::ProgressRace(int choice){
    int tempStat;
    int working;
    cout << "You are trying to progress the race!" << endl;
    //gets random number from 1 -100
    srand(time(NULL));
    int difficult = rand() % 100 + 1;
    tempStat = m_myPlayer.GetStat(choice - 2);
    if(choice == 2 && m_track.ConvertObstacle(0) == "speed"){
        working = BASE_SKILL + (5*tempStat);
    }else if(choice == 3 && m_track.ConvertObstacle(0) == "agility"){
        working = BASE_SKILL + (5*tempStat);
    }else if(choice == 4 && m_track.ConvertObstacle(0) == "jump"){
        working = BASE_SKILL + (5*tempStat);
    }else{
        working = BASE_SKILL;
    }
    //if the players stats beat the systems difficulty setting then the player passes
    if(working >= difficult){
        cout << "You made it through the " << m_track.ConvertObstacle(0) << " obstacle!" <<endl;
        m_track.IncrementLocation(0);
    }else{
        cout << "You fell!" << endl;
        m_myPlayer.SetFalls(m_myPlayer.GetFalls() + 1);
    }
    ProgressComputer(difficult);
}
  // Name: MainMenu()
  // Desc - Displays and manages menu
  // Preconditions - None
  // Postconditions - Returns number including exit
bool Race::MainMenu(){
    int userInput = 0;
    cout << "What would you like to do?" << endl << "1. Start New Race\n2. View Racer History\n3. Quit" << endl;
    cin >> userInput;
    if(userInput == 1){
        StartRace();
        return 1;
    }else if(userInput == 2){
        m_myPlayer.DisplayStatus();
        return 1;
    }
    return 0;
}
  // Name: RaceOptions()
  // Desc - Displays the race menu (display status, choose speed, choose agility, or choose jump)
  // Preconditions - None
  // Postconditions - Returns integer of user choice (status = 1, speed = 2, agility = 3, jump = 4)
int Race::RaceOptions(){
    int userChoice;
    cout << "What would you like to do?\n1. Get Race Status\n2. Try to Sprint (Speed)\n3. Try to Dodge (Agility)\n4. Try to Jump (Jump)" << endl;
    cin >> userChoice;
    return userChoice;
}
  // Name: ManageGame
  // Desc - Calls RaceTitle, then calls GetRacerInfo. Continually calls MainMenu
  //        until the user chooses quit then it thanks the user and quits
  // Preconditions - Game instantiated
  // Postconditions - Calls RaceTitle, then calls GetRacerInfo. Continually calls MainMenu
  //                  until the user chooses quit then it thanks the user and quits
void Race::ManageGame(){
    RaceTitle();
    GetRacerInfo();
    bool running = 1;
    while(running){
        //if the user doesnt quit the menu will play after every game
        running = MainMenu();
    }
    cout << "Thanks for playing UMBC Race!" << endl;
}
  // Name: ProgressComputer
  // Desc - Iterates over each computer player (players 2, 3, and 4) to see if they
  //        successfully navigate through an obstacle. Indicates if they make it or fall.
  //        Compares a random number between COMP_MIN and COMP_MAX to the obstacle difficulty
  //        to see if they are successful
  // Preconditions - obstacleDifficulty is already calculated and passed to this function
  // Postconditions - For each computer player, they either make it and increment their
  //                  location or fall and remain on the same obstacle
void Race::ProgressComputer(int obstacleDifficulty){
    int chances;
    srand(time(NULL));
    for(int i = 2; i < 5; i ++){
        chances = rand() % ((COMP_MAX - COMP_MIN) + 1) + COMP_MIN;
        if(chances >= obstacleDifficulty){
            cout << "Player " << i-1 << " made it through the " << m_track.ConvertObstacle(i-1) << " obstacle! " << endl;
            m_track.IncrementLocation(i-1);
        }else{
            cout << "Player " << i-1 << " fell! " << endl;
        }
    }

}
void RaceTitle(){
    cout << "*****************************************************************" << endl;
    cout << "U   U   M   M   BBB   CCCC   RRR     AA    CCCC   EEEE   RRR     " << endl;
    cout << "U   U   MM MM   B  B  C      R  R   A  A   C      E      R  R    " << endl;
    cout << "U   U   M M M   BBBB  C      RRR    AAAA   C      EEEE   RRR     " << endl;
    cout << "U   U   M   M   B  B  C      R R    A  A   C      E      R R     " << endl;
    cout << "UUUUU   M   M   BBB   CCCC   R  R   A  A   CCCC   EEEE   R  R    " << endl;
    cout << "*****************************************************************" << endl;
}