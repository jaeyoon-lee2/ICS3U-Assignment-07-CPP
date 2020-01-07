// Copyright (c) 2019 St. Mother Teresa HS All rights reserved.
//
// Created by: Jaeyoon (Jay) Lee
// Created on: Dec 2019
// This program concatenate two lists

#include <iostream>
#include <array>
#include <string>
#include <sstream>


template<size_t N>
std::array<std::string, 6>* ConcatenateList(std::string firstThings,
                            std::string secondThings) {
    std::array<std::string, 3> firstList;
    std::array<std::string, 3> secondList;
    std::array<std::string*, 6> concatenatedList;

    std::stringstream firstSplit(firstThings);
    std::string token1;
    int counter1 = 0;

    while (getline(firstSplit, token1, '_')) {
      firstList[counter1] = token1;
      counter1 += 1;
    }
    std::stringstream secondSplit(secondThings);
    std::string token2;
    int counter2 = 0;

    while (getline(secondSplit, token2, '_')) {
      secondList[counter2] = token2;
      counter2 += 1;
    }

    for (int counter = 0; counter < 6; counter++) {
        if (counter < 3) {
            concatenatedList[counter] = firstList[counter];
        } else {
            concatenatedList[counter] = secondList[counter-3];
        }
    }
    return concatenatedList;
}


main() {
    // this function concatenate two lists

    std::array<std::string*, 6> concatenatedList;
    std::string firstThings;
    std::string secondThings;
    std::string firstListName;
    std::string secondListName;
    std::string concatenatedListName;

    // input
    std::cout << "Enter the name of first list: ";
    std::cin >> firstListName;
    std::cout << "Enter the name of second list: ";
    std::cin >> secondListName;
    std::cout << "Enter the name of concatenated list: ";
    std::cin >> concatenatedListName;

    std::cout << "Enter three things to put in "<< firstListName
              <<" (Separated by '_'): ";
    std::cin >> firstThings;

    std::cout << "Enter three things to put in "<< secondListName
              <<" (Separated by '_'): ";
    std::cin >> secondThings;

    concatenatedList = ConcatenateList(firstThings, secondThings);

    // output
    std::cout << "" << std::endl;
    std::cout << concatenatedListName <<" are " << std::endl;

    for (int loop_counter = 0; loop_counter < 6; loop_counter++) {
        std::cout << concatenatedList[loop_counter] << " ";
    }
}
