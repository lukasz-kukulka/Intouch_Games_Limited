#include "catch_amalgamated.hpp"
#include "Calculator.hpp"

#include <algorithm>
#include <vector>

SCENARIO("Check Add function" "[Sum][Add]") {
    GIVEN("function") {
        Calculator calc;

        WHEN("Give data without delimeter") {
            auto result = calc.Add("4,4");
        
            THEN("Add numbers") {
                REQUIRE(result == 8);
            }
        }
    }
}