#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <vector>

using namespace ariel;

TEST_CASE("testing input number"){
    CHECK_THROWS(snowman(283));
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(111144112));
    CHECK_THROWS(snowman(10114711));
}

TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(33232124) == string("   _   \n  /_\\  \n\\(o_O) \n (] [)>\n (   ) "));
    CHECK(snowman(33232124) == string("   _   \n  /_\\  \n\\(o_O) \n (] [)>\n (   ) "));
}

TEST_CASE("bad snowman code") {
    // cout << string("_===_\n(.,.)\n( : )\n( : )") << endl;
    // CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
    /* Add more checks here */
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
