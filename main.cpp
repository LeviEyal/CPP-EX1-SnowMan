/************************************************************************************
 * C++ course, Ariel university.
 * Assignment number 1.
 *
 * AUTHORS: Eyal Levi
 * https://github.com/LeviEyal
 * Date: 2021-03
 ***********************************************************************************/

#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

const string red_line = "\e[1;31m";
const string colors[] {"\e[1;92m", "\e[1;93m", "\e[1;94m", "\e[1;95m", "\e[1;96m"};

string RandomSnowman(){
    int number = 0;
    for (int i = 0; i < 8; i++) {
        number *= 10;
        number += (rand()%4) + 1;
    }
    cout << endl << " Generating random snowman...\n   Snowman(" << number << ") is:" << endl;
    string s = ariel::snowman(number);
    s.insert(0, 1, '\t');
    s.insert(9, 1, '\t');
    s.insert(18, 1, '\t');
    s.insert(27, 1, '\t');
    s.insert(36, 1, '\t');
    return s;
}

int main() {
    srand((unsigned)time(0));
    for(int i=0; true; i++){
        cout << red_line << "-----------------------------";
        cout << colors[i%5] << RandomSnowman() << endl;
        this_thread::sleep_for(chrono::milliseconds(600));
    }
}