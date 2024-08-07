#include "../inc/bf.hpp"
#include "../inc/tokenizer.hpp"
#include "../inc/preprocessor.hpp"
#include "../inc/interpreter.hpp"

#include <fstream>
#include <list>
#include <cstring>
#include <vector>

bool BrainFuck(std::string filename) {
    std::ifstream f(filename);
    if (f.fail()) {
        throw std::invalid_argument("The provided file '" + filename + "' could not be read.");
    }

    std::list<BFCommands> commands;
    char invalid;
    if (!bf_tokenizer(f, commands, invalid)) {
        throw std::invalid_argument("Input file contained invalid character '" + std::string(1, invalid) + "'.");
    }

    std::vector<BFToken> tokens;
    if (!bf_preprocessor(commands, tokens)) {
        throw std::runtime_error("Error occurred while preprocessing source code.");
    }

    return bf_interpreter(tokens);
}