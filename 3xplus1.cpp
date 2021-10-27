//Copyright 2021 Leif Gunhus
#include <iostream>

using namespace std;

unsigned int numEnter; //Maximum is 2^32

int main()
{
    cout << "Welcome to 3x+1. ";
    while (true) {
        cout << "Please enter an integer.\n";
        cin >> numEnter;
        if (numEnter and numEnter > 0) {

            unsigned int numTemp = numEnter;
            unsigned int steps = 0;
            unsigned int highest = numEnter;

            while (true) { //Loop until broken
                steps++; //Add 1 to steps each time another step is taken
                unsigned int numOld = numTemp;
                if (numTemp % 2 == 1) { //if numTemp is odd, multiply by 3 and add 1
                    numTemp = (numTemp * 3) + 1;
                    cout << "\nStep " << steps << ": " << numOld << " times 3 plus 1 equals " << numTemp << endl;

                    if (numTemp > highest) {
                        highest = numTemp;
                    }
                }
                else { //if numTemp is even, divide by 2
                    numTemp = numTemp / 2;
                    cout << "\nStep " << steps << ": " << numOld << " divided by 2 equals " << numTemp << endl;
                }
                if (numTemp == 1) {
                    break;
                }
                else if (numTemp == 0) {
                    return 1; //Leftover from when numEnter was signed, not sure whether this can be removed safely.
                }
            }
            cout << "\nIt took " << steps << " steps to reach 1 from " << numEnter << ".\nThe highest value reached was " << highest << ".\nEnter another number? (Y/N)\n";
            string answer;
            while (true) {
                cin >> answer;
                if (answer == "Yes" or answer == "y" or answer == "Y") {
                    break; //Breaks current loop, bringing the program back to the beginning of the main loop
                }
                else if (answer == "No" or answer == "n" or answer == "N") {
                    return 0; //Program ends by user input
                }
                else {
                    cout << "\nIllegitimate entry\n";
                }
            }
        }
        else { //If a non-number is entered, cin enters an error state.
            cout << "\nIllegitimate entry\n";
            cin.clear(); //cin.clear() clears the error state
            cin.ignore(1000,'\n'); //cin.ignore(int,char) ignores the next [int] chars or ignores until it reaches [char]
        }
    }
    cout << "\nSomething unexpected went wrong.";
    return 2; //Should ideally never happen
}

