cmake_minimum_required(VERSION 3.10)
project(Calc)


set(FILES
    Sum.cpp
    Calculator.cpp)

add_library(${PROJECT_NAME}-lib ${FILES})
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME}-lib PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_features(${PROJECT_NAME}-lib PRIVATE cxx_std_20)
