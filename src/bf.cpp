#include "../inc/bf.hpp"
#include "../inc/tokenizer.hpp"
#include "../inc/optimizer.hpp"
#include "../inc/interpreter.hpp"

#include <fstream>
#include <cstring>
#include <vector>

bool BrainFuck(std::string filename) {
    std::ifstream f(filename);
    if (f.fail()) {
        throw std::invalid_argument("The provided file '" + filename + "' could not be read.");
    }

    std::vector<BFCommands> commands;
    char invalid;
    if (!bf_tokenizer(f, commands, invalid)) {
        f.close();
        throw std::invalid_argument("Input file contained invalid character '" + std::string(1, invalid) + "'.");
    }
    f.close();

    std::vector<BFToken> tokens;
    if (!bf_optimizer(commands, tokens)) {
        throw std::runtime_error("Error occurred while optimizing source code.");
    }

    if (!bf_interpreter(tokens)) {
        throw std::runtime_error("Error occurred while running program.");
    }
    return true;
}