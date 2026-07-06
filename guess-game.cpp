#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int secretNumber , guess,attempts = 0;

    srand(time(0));
    secretNumber = rand() % 100 + 1;
    cout << " ==== NUMBER GUESSING GAME ====" << endl;
    cout << " i have choosen a number between 1 and 100." << endl;
    cout << " try to guess it!" << endl;
 
    while(true)
    { 
        cout << " \nEnter your guess : ";
        cin >> guess;
        attempts++;

        if( guess > secretNumber)
        {
            cout << "Too High! Try again. " << endl;
        }
        else if( guess < secretNumber)
        {
            cout << " Too Low! Try again. " << endl;
        }
        else
        {
            cout << " \nCONGRATULATONs! You Won! " << endl;
            cout << " The correct number was: " << secretNumber << endl;
            cout << " You guessed it in " << attempts << " attempts. " << endl;
            break;
        }
    }
return 0;
}
