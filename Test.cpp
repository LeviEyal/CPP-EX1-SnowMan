#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <vector>

using namespace ariel;

TEST_CASE("number digits out of range"){
    CHECK_THROWS(snowman(18273572));
    CHECK_THROWS(snowman(11111119));
    CHECK_THROWS(snowman(11111110));
    CHECK_THROWS(snowman(12532111));
    CHECK_THROWS(snowman(29211234));
}

TEST_CASE("Input number too small"){
    CHECK_THROWS(snowman(2321435));
    CHECK_THROWS(snowman(2314321));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(1));
}

TEST_CASE("Input number too big"){
    CHECK_THROWS(snowman(232142735));
    CHECK_THROWS(snowman(111111111));
    CHECK_THROWS(snowman(123412341));
    CHECK_THROWS(snowman(444444444));
}

TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(33232124) == string("   _   \n  /_\\  \n\\(o_O) \n (] [)>\n (   ) "));
    CHECK(snowman(12222212) == string("       \n _===_ \n\\(o.o)/\n ( : ) \n (\" \") "));
    CHECK(snowman(32443333) == string("   _   \n  /_\\  \n (-.-) \n/(> <)\\\n (___) "));
    CHECK(snowman(44444432) == string("  ___  \n (_*_) \n (- -) \n (> <) \n (\" \") "));
    CHECK(snowman(44242123) == string("  ___  \n (_*_) \n\\(o -) \n (] [)>\n (___) "));
    CHECK(snowman(41341144) == string("  ___  \n (_*_) \n (O,-) \n<(   )>\n (   ) "));
    CHECK(snowman(11111111) == string("       \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(snowman(22222222) == string("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(snowman(33333333) == string("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___) "));
    CHECK(snowman(44444444) == string("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) "));
}

TEST_CASE("bad snowman code") {
    CHECK(snowman(11114411) != string(" _===_ \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(33232124) != string("   _   \n  /_\\  \n\\(0_O) \n (] [)>\n (   ) "));
    CHECK(snowman(12222212) != string("       \n _===_\n\\(o.o)/\n ( : ) \n (\" \") "));
    CHECK(snowman(32443333) != string("   _   \n  /_\\  \n (-.-) \n/(> <)\\ \n (___) "));
    CHECK(snowman(44444432) != string("  ___  \n (_*_) \n (- -) \n (> <) \n ( \") "));
    CHECK(snowman(44242123) != string("  ___ \n (_*_) \n\\(o -) \n (] [)>\n (___) "));
    CHECK(snowman(41341144) != string("  ___  \n (_*_) \n (O, -) \n<(  )>\n (   ) "));
    CHECK(snowman(11111111) != string("      \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(snowman(22222222) != string("  ___  \n .... \n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(snowman(33333333) != string("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___)"));
    CHECK(snowman(44444444) != string("  ___  \n (_*_) \n (- -) \n (  ) \n (   ) "));
}


// TEST_CASE("Testing the number of options to compbine snowmen:"){
//     vector<string> snowmen;
//     for(int i=11111111; i<=44444444; i++){
//         try
//         {
//             snowmen.push_back(snowman(i));
//         }
//         catch(const std::exception& e)
//         {
//         }
//     }
//     CHECK_EQ(snowmen.size(), 4*4*4*4*4*4*4*4);
// }
