#include <iostream>
#include <string>
using namespace std;
int main() {
    int choices = 0;
    int age;
    string name;
    int userInput;
    cout << "What is your cat's name" << endl;
    getline(cin, name);
    cout << "How old is your cat?" << endl;
    cin >> age;
    bool tryAgain = cin.fail();
    while (tryAgain || age > 22 || age < 0) {
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Please Enter your cat's age, it should be an integer between 0 and 22" << endl;
        cin >> age;
        tryAgain = cin.fail();
    }
    cout << "Cat Name = " << name << endl;
    cout << "Cat's Age = " << age << endl;

    while (choices < 3) {
        cout << "What would you like to do?" << endl << "1.Pet Kitty" << endl << "2.Feed Kitty" << endl << "3.Chase Kitty" << endl
            << "Enter your choice" << endl;
        cin >> userInput;
        bool flag = cin.fail();
        while (flag || userInput < 1 || userInput > 3) {
            cout << "1.Pet Kitty" << endl << "2.Feed Kitty" << endl << "3.Chase Kitty" << endl << "Enter your choice (1-3)" << endl;
            cin.clear();
            cin.ignore(500, '\n');
            cin >> userInput;
            flag = cin.fail();
        }

        if (userInput == 1) {
            choices++;
            cout << "You pet kitty and they purr" << endl;
        }
        else if (userInput == 2) {
            choices++;
            cout << "Kitty meows gently as you feed them" << endl;
        }
        else if (userInput == 3) {
            choices++;
            cout << "You chase after Kitty and they hiss and try to bite." << endl;
        }
    }
    cout << "That is enough for today. Good-bye" << endl;
}






    
