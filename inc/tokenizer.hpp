#ifndef BF_TOKENIZER_H
#define BF_TOKENIZER_H

#include <fstream>
#include <list>

#include "constants.hpp"

bool bf_tokenizer(std::ifstream &f, std::list<BFCommands> &commands, char &invalid);

#endif