#include <iostream>
#include <vector>
#include <stdexcept>
#include "snowman.hpp"

using namespace std;
const int validInputNumber = 8;
enum parts
{
    head, leftArm, leftEye, nose, rightEye, rightArm, torso, base 
};

const vector<string> H = {"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const vector<string> N = {",", ".", "_", " "};
const vector<string> L = {".", "o", "O", "-"};
const vector<string> R = {".", "o", "O", "-"};
const vector<string> X1 = {" ", "\\", " ", " "};
const vector<string> X2 = {"<", " ", "/", " "};
const vector<string> Y1 = {" ", "/", " ", " "};
const vector<string> Y2 = {">", " ", "\\", " "};
const vector<string> T = {" : ", "] [", "> <", "   "};
const vector<string> B = {" : ", "\" \"", "___", "   "};

bool inputCheck(string n){
    if(n.size() != validInputNumber){
        return false;
    } 
    for (int i = 0; i < n.size(); i++){
        if(n[i] < '1' || n[i] > '4'){
            return false;
        }
    }
    return true;
}

int toDigit(char c){
    return (c-'0')-1; 
}

namespace ariel{
	string snowman(int num){
        string snowman;
        string n = to_string(num);
        if(!inputCheck(n)){
            throw invalid_argument{"The input number must have 8 digits range from 1 to 4!\n"};
        } 

        snowman += H.at(toDigit(n[head])) + "\n";
        snowman += X1.at(toDigit(n[rightEye])) + "(" + L.at(toDigit(n[leftEye]));
        snowman += N.at(toDigit(n[leftArm]))+ R.at(toDigit(n[nose])) + ")" + Y1.at(toDigit(n[rightArm])) + "\n";
        snowman += X2.at(toDigit(n[rightEye])) + "(" + T.at(toDigit(n[torso])) + ")" + Y2.at(toDigit(n[rightArm])) + "\n";
        snowman += " (" + B.at(toDigit(n[base])) + ") ";
        return snowman;
    }
};