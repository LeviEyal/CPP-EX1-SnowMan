#include <iostream>
#include <vector>
#include <stdexcept>
#include "snowman.hpp"

using namespace std;

const int validInputNumber = 8;

/**
 * All snowman body parts: head=0, nose=1, ... , base=7.
 */
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

/**
 * @brief converting char '1'-'5' to its integer representation
 *        after that it decrease 1 from the number to fit the arrays range 0-4.
 *        Example: with the input char '1' the function returns 0.  
 *        Example: with the input char '5' the function returns 4.
 *        etc.  
 * 
 * @param c the char range from '1' to '5'
 * @return int input char represnted as int, minus 1.
 */
int toDigit(char c){
    return (c-'0')-1; 
}

namespace ariel{
    /**
     * @brief The function gets a 8-digits number with each digit range from 1 to 4.
     *        It generates a string representation of a so-called 'snowman',
     *        with each digit of the input number represnt different part of the snowman.
     *        For the full documentation visit:
     *        https://codegolf.stackexchange.com/questions/49671/do-you-want-to-code-a-snowman
     * 
     * @param num a 8-digits integer with each digit range from 1 to 4
     * @return a string representation of the correspond snowman
     */
	string snowman(int num){
        string n = to_string(num);
        if(n.size() != validInputNumber){
            throw invalid_argument{"The input number must be positive and have 8 digits range from 1 to 4!\n"};
        }

        //If some digit is NOT in the range 0-3, then an exception will be thrown.
        return H.at(toDigit(n[head])) + "\n"
            + X1.at(toDigit(n[leftArm])) + "(" + L.at(toDigit(n[leftEye])) + N.at(toDigit(n[nose]))+ R.at(toDigit(n[rightEye])) + ")" + Y1.at(toDigit(n[rightArm])) + "\n"
            + X2.at(toDigit(n[leftArm])) + "(" + T.at(toDigit(n[torso])) + ")" + Y2.at(toDigit(n[rightArm])) + "\n"
            + " (" + B.at(toDigit(n[base])) + ") ";
    }
};