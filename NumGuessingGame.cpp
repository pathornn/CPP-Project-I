#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


int main(){
    cout << "\n\t\t\t Welcome to GuessTheNumber GAME!"
            << endl;
    cout << "You have to guess a number between 1 and 100. "
            << "You'll have limited choices based on the "
            << "level you choose. Good Luck!"
            << endl;

    while (true) {
        cout << "\nEnter the difficulty level: \n";
        cout << "1 for easy!\n";
        cout << "2 for medium!\n";
        cout << "3 for difficult!\n";
        cout << "0 for ending the game!\n\n";

        int difficultyChoice;
        cout << "Enter the number : ";
        cin >> difficultyChoice;

        srand(time(0));
        int secretNumber = 1 + (rand() % 100);
        int playerChoice, postChoiceLeft, choiceLeft;

        switch(difficultyChoice){
            case 0:
                exit(0);
                break;
            case 1:
                postChoiceLeft = 10;
                break;
            case 2:
                postChoiceLeft = 7;
                break;
            case 3:
                postChoiceLeft = 5;
                break;
            default:
                cout << "Wrong choice, Enter valid choice to play the game! (0,1,2,3)";
                break;
        }

        choiceLeft = postChoiceLeft;
        cout << "\nYou have " << choiceLeft << " choices for finding the "
                << "secret number between 1 and 100.";

        for (int i = 1; i <= postChoiceLeft; i++){
            cout << "\n\nEnter the number : ";
            cin >> playerChoice;

            if (playerChoice == secretNumber){
                cout << "Well played! You won, " << playerChoice << " is the secret number"
                        << endl;
                cout << "\t\t\t Thanks for playing..."
                        << endl;
                break;
                }
            else {
                cout << "Nope, " << playerChoice << " is not the right number\n";

                if (playerChoice > secretNumber) {
                    cout << "The secret number is smaller than the number you have chosen\n";
                }
                else {
                    cout << "The secret number is greater than the number you have chosen\n";
                }
            }
            choiceLeft--;
            cout << choiceLeft << " choice left. ";

            if (choiceLeft == 0){
                cout << "\n\nYou couldn't find the secret number, it was " << secretNumber << ", You lose!! \n\n";
            }
        }
    }
    return 0;
}
