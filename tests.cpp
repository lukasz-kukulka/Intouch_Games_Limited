#include "catch_amalgamated.hpp"
#include "Calculator.hpp"

#include <algorithm>
#include <vector>

SCENARIO("sort algotithm can be initialize in different way", "std::sort") {
    GIVEN("A vector with some items") {
        std::vector<int> v = {3, 1, 4, 2, 5};
        

        WHEN("sort in base way") {
            std::sort(v.begin(), v.end());

            THEN("check single value in vector") {
                REQUIRE(v[0] == 1);
                REQUIRE(v[1] == 2);
                REQUIRE(v[2] == 3);
                REQUIRE(v[3] == 4);
                REQUIRE(v[4] == 5);
                REQUIRE(std::is_sorted(begin(v), end(v)) == true);
            }
        }

        WHEN("sort in reverse way") {
            std::sort(v.begin(), v.end(), [](int a, int b){ return a > b; });

            THEN("check single value in vector") {
                REQUIRE(v[0] == 5);
                REQUIRE(v[1] == 4);
                REQUIRE(v[2] == 3);
                REQUIRE(v[3] == 2);
                REQUIRE(v[4] == 1);
                REQUIRE(std::is_sorted(rbegin(v), rend(v)) == true);
            }
        }
    }
}

SCENARIO("test") {
    GIVEN("a") {
        Calculator calc;


        WHEN("4") {
            auto result = calc.aaa(4);

            THEN("check single value in vector") {
                REQUIRE(result == 4);
            }
        }
    }
}