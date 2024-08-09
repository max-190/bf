#include <iostream>
#include <string>

#include "../inc/bf.hpp"

int main(int argc, char *argv[]) {
    std::string filename;
    if (argc == 1) {
        std::cout << "Enter name of input file: ";
        std::cin >> filename;
    } else if (argc == 2) {
        filename = argv[1];
    } else {
        std::invalid_argument("Invalid number of arguments.");
    }

    if (!BrainFuck(filename)) {
        return 1;
    }

    return 0;
}