#ifndef BF_PREPROCESSOR_H
#define BF_PREPROCESSOR_H

#include <list>
#include <vector>

#include "constants.hpp"

bool bf_preprocessor(std::list<BFCommands> &commands, std::vector<BFToken> &tokens);

#endif