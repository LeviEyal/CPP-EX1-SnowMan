#include <iostream>
#include <vector>
#include <stdexcept>
#include "snowman.hpp"

using namespace std;

const int validInputNumber = 8;
enum parts { head, nose, leftEye, rightEye, leftArm, rightArm, torso, base };

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

int toDigit(char c){
    return (c-'0')-1; 
}

namespace ariel{
	string snowman(int num){
        string n = to_string(num);
        if(n.size() != validInputNumber){
            throw invalid_argument{"The input number must be positive and have 8 digits range from 1 to 4!\n"};
        } 
        return H.at(toDigit(n[head])) + "\n"
            + X1.at(toDigit(n[leftArm])) + "(" + L.at(toDigit(n[leftEye])) + N.at(toDigit(n[nose]))+ R.at(toDigit(n[rightEye])) + ")" + Y1.at(toDigit(n[rightArm])) + "\n"
            + X2.at(toDigit(n[leftArm])) + "(" + T.at(toDigit(n[torso])) + ")" + Y2.at(toDigit(n[rightArm])) + "\n"
            + " (" + B.at(toDigit(n[base])) + ") ";
    }
};