#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::stoi;
#include <experimental/random>
#include <stdlib.h>
using std::abs;

void usage(){
    cout << "\n---Instuctios for use---\n";
    cout << "./hot_cold [<max_value>]\n";
    cout << "Type in a max_value belonging to the range [1,100]. If no arguments is entered, the max_value will be 30.\n";
}

int main(int argc, char *argv[]){

    int max_value;
    if(argc>2){
        cout << ">>> Excess of arguments.\n";
        usage();
        return 1;
    }else if(argc==1){
        max_value = 30;
    }else{
        max_value = stoi(argv[1]);
        if(max_value<1 || max_value>100){
            cout << "Invalid threshold value. Choose a value belonging to the range [1,100].\n";
            usage();
            return 1;
        }
    }
    cout << "===================================================\n";
    cout << "Welcome to the Hot-Cold Guess game, copyright 2020.\n";
    cout << "---------------------------------------------------\n";
    cout << "\n";
    cout << "There are the game rules:\n";
    cout << "\t* I'll choose a random number in [1," << max_value << "]. Your job is to guess that number.\n";
    cout << "\t* From the second guess onward, I'll tell you if your guess is hot (closer than the previous guess) or cold (farther from the previous guess).\n";
    cout << "\t* If you wish to quit the game, just type in a number out of range [1," << max_value << "].\n";
    cout << "\n";
    cout << "Good luck!\n";
    cout << "---------------------------------------------------\n";
    cout << "\n";
    int secret_number = std::experimental::randint(1,max_value);
    int guess;
    cout << ">>> Guess the number: ";
    cin >> guess;
    if(guess<1 || guess>max_value){
        cout << "The value does not belong to the range [1," << max_value << "]. Therefore, you will leave the game.\n";
        return 0;
    }
    if(guess != secret_number){
        cout << "Nop,try again: ";
    }else{
        cout << ">>> Yeah, correct guess!\n";
    }
    while(guess != secret_number){
        int previous_guess = guess;
        cin >> guess;
        if(guess<1 || guess>max_value){
            cout << "The value does not belong to the range [1," << max_value << "]. Therefore, you will leave the game.\n";
            return 0;
        }
        if(guess == secret_number){
            cout << ">>> Yeah, correct guess!\n";
            cout << "\n";
            cout << "Thanks for playing.\n";
            return 0;
        }
        if(abs(secret_number-guess)>abs(secret_number-previous_guess)){
            cout << "Nop, it's getting cold, try again: ";
        }else{
            cout << "Nop, it's hot though, try again: ";
        }
    }

    return 0;
}