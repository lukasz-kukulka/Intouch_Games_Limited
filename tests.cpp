#include "catch_amalgamated.hpp"
#include "Calculator.hpp"

#include <algorithm>
#include <vector>

SCENARIO("Check Add function" "[Sum][Add][WithoutDelimiter]") {
    GIVEN("Give class calc") {
        Calculator calc;

        WHEN("Call function Add without delimeter with string = 4,4") {
            auto result = calc.Add("4,4");
        
            THEN("Add numbers") {
                REQUIRE(result == 8);
            }
        }

        WHEN("Call function Add without delimeter with string = 22,15,45") {
            auto result = calc.Add("22,15,45");
        
            THEN("Add numbers") {
                REQUIRE(result == 82);
            }
        }

        WHEN("Call function Add without delimeter with string = 12\n12,12") {
            auto result = calc.Add("12\n12,12");
        
            THEN("Add numbers") {
                REQUIRE(result == 36);
            }
        }

        WHEN("Call function Add without delimeter with string = 10000,22") {
            auto result = calc.Add("10000,22");
        
            THEN("Add numbers") {
                REQUIRE(result == 22);
            }
        }
        
    }
}

SCENARIO("Check Add function" "[Sum][Add][SingleDelimiter]") {
    GIVEN("Give class calc") {
        Calculator calc;

        WHEN("Call function Add with single delimeter with string = 4,4") {
            auto result = calc.Add("//;\n10;10");
        
            THEN("Add numbers") {
                REQUIRE(result == 20);
            }
        }

        WHEN("Call function Add with single delimeter with string = //:::\n33:::33") {
            auto result = calc.Add("//:::\n33:::33");
        
            THEN("Add numbers") {
                REQUIRE(result == 66);
            }
        }

        WHEN("Call function Add with single delimeter with string = //$$$/n44$$$44") {
            auto result = calc.Add("//$$$\n44$$$44");
        
            THEN("Add numbers") {
                REQUIRE(result == 88);
            }
        }

        WHEN("Call function Add with single delimeter with string = //&\n555551&433223333&1") {
            auto result = calc.Add("//&\n555551&433223333&1");
        
            THEN("Add numbers") {
                REQUIRE(result == 1);
            }
        }
        
    }
}