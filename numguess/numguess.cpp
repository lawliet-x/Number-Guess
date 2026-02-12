// numguess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cctype>
#include <iostream>
#include <random>
#include <windows.h>

int randomNumGen() {
    using namespace std;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1,10);
    int randomValue = distrib(gen);
    return randomValue;
}

void coreGame(int* counter) {
    int guessedNum; int ranNum;
    std::cout << "Pick a number 1-10: ";
    std::cin >> guessedNum;
    ranNum = randomNumGen();
    if (ranNum == guessedNum) {
        (*counter)++;
        std::cout << "Congrats, your guess " << guessedNum << " was correct!" << '\n' << " Correct guesses: " << *counter << "\n";
    }
    else {
        std::cout << "Sorry, the correct number was " << ranNum << '\n' << "Correct guesses: " << *counter << "\n";
    }
}

int main()
{
    char playerChoice; int counter = 0;

    while (true) {
        std::cout << "[any input to play; q to quit]: ";
        std::cin >> playerChoice;
        std::cin.ignore(1000, '\n');
        if (tolower(playerChoice) == 'q') {
            std::cout << "Final score: [" << counter << "] Bye! ;3";
            Sleep(5000);
            break;
        }
        else {
            coreGame(&counter);
        }
    }
}