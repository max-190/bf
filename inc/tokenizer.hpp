#ifndef BF_TOKENIZER_H
#define BF_TOKENIZER_H

#include <fstream>
#include <vector>

#include "constants.hpp"

bool bf_tokenizer(std::ifstream &f, std::vector<BFCommands> &commands, char &c);

#endif