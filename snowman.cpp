#include <iostream>
#include "snowman.hpp"

using namespace std;

#define toDigit(c) (c-'0')

const string H[] = {"", "      \n _===_", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const string N[] = {"", ",", ".", "_", " "};
const string L[] = {"", ".", "o", "O", "-"};
const string R[] = {"", ".", "o", "O", "-"};
const string X1[] = {"", " ", "\\", " ", " "};
const string X2[] = {"", "<", " ", "/", " "};
const string Y1[] = {"", " ", "/", " ", " "};
const string Y2[] = {"", ">", " ", "\\", " "};
const string T[] = {"", " : ", "] [", "> <", "   "};
const string B[] = {"", " : ", "" "", "___", "   "};

/*
In the format:
    HNLRXYTB
    01234567
*/
namespace ariel{
	string snowman(long num){
        string n = to_string(num);
        cout << n << endl;
        string ans;
        ans += H[toDigit(n[0])] + "\n";
        ans += X1[toDigit(n[4])] + "(" + L[toDigit(n[2])]+ N[toDigit(n[1])]+ R[toDigit(n[3])] + ")" + Y1[toDigit(n[5])] + "\n";
        ans += X2[toDigit(n[4])] + "(" + T[toDigit(n[6])] + ")" + Y2[toDigit(n[5])] + "\n";
        ans += " (" + B[toDigit(n[7])] + ") \n";
        return ans;
    }
};