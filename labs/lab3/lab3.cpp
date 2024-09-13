/*****************************************
** File:    lab3.cpp
** Project: CMSC 202 Lab 3, Fall 2022
**
** Lab 3 involves using arrays. In this file you need to
** implement the flipArray() function as well as populate the array
** and keep track of the length of the array.
**
***********************************************/
#include <iostream>
using namespace std;

// Function Prototype for flipArray HERE********
void flipArray(int array[], int size); //Provided

//Implement global constants HERE********
int MAX_INPUT = 100;

//Implement main HERE*********
int main(){
    int userInput;
    int counter = 0;
    int userNum[MAX_INPUT];
    do{
        cout << "Enter a number (0 when done): ";
        cin >> userInput;
        userNum[counter] = userInput;
        counter++;
    }while(userInput != 0);
    cout << "Original Array: " << endl;
    for(int i = 0; i < counter; i++){
        cout << userNum[i] << " ";
    }
    flipArray(userNum, counter);
}

    // Declare your necessary variables.




    // Populate your array.



    // Display the original array, call flipArray(), display modified array.





// Implement flipArray() here
// Hint: only need to iterate through half of the array.
void flipArray(int array[], int size){
    int start = 0;
    int end = size-1;
    while(start < end){
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
    cout << endl << "Flipped Array" << endl;
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

