#include "../inc/optimizer.hpp"

#include <stack>

bool bf_optimizer(std::vector<BFCommands> &commands, std::vector<BFToken> &tokens) {
    int increment_counter;
    std::stack<int> bracket_stack;
    for (std::vector<BFCommands>::iterator it = commands.begin(); it != commands.end(); it++) {
        switch (*it) {
            case BFCommands::IncrementPointer:
            case BFCommands::DecrementPointer:
                increment_counter = 0;
                while (it != commands.end()) {
                    if (*it == BFCommands::IncrementPointer) {
                        increment_counter++;
                    } else if (*it == BFCommands::DecrementPointer) {
                        increment_counter--;
                    } else {
                        break;
                    }
                    it++;
                }
                tokens.push_back({BFCommands::IncrementPointer, increment_counter});
                it--;
                break;
            case BFCommands::IncrementByte:
            case BFCommands::DecrementByte:
                increment_counter = 0;
                while (it != commands.end()) {
                    if (*it == BFCommands::IncrementByte) {
                        increment_counter++;
                    } else if (*it == BFCommands::DecrementByte) {
                        increment_counter--;
                    } else {
                        break;
                    }
                    it++;
                }
                tokens.push_back({BFCommands::IncrementByte, increment_counter});
                it--;
                break;
            case BFCommands::LoopStart:
                bracket_stack.push(tokens.size());
                tokens.push_back({BFCommands::LoopStart, 0});
                break;
            case BFCommands::LoopEnd:
                if (bracket_stack.empty()) {
                    return false;
                }
                tokens[bracket_stack.top()].data = tokens.size();
                tokens.push_back({BFCommands::LoopEnd, bracket_stack.top()});
                bracket_stack.pop();
                break;
            case BFCommands::OutputByte:
                tokens.push_back({BFCommands::OutputByte, 0});
                break;
            case BFCommands::InputByte:
                tokens.push_back({BFCommands::InputByte, 0});
                break;
            default:
                return false;
        }
    }
    return true;
}
