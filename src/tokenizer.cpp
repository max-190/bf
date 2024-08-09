#include <list>
#include<limits>

#include "../inc/tokenizer.hpp"

bool bf_tokenizer(std::ifstream &f, std::vector<BFCommands> &commands, char &c) {
    while (f.get(c)) {
        switch (c) {
            case '>':
                commands.push_back(BFCommands::IncrementPointer);
                break;
            case '<':
                commands.push_back(BFCommands::DecrementPointer);
                break;
            case '+':
                commands.push_back(BFCommands::IncrementByte);
                break;
            case '-':
                commands.push_back(BFCommands::DecrementByte);
                break;
            case '.':
                commands.push_back(BFCommands::OutputByte);
                break;
            case ',':
                commands.push_back(BFCommands::InputByte);
                break;
            case '[':
                commands.push_back(BFCommands::LoopStart);
                break;
            case ']':
                commands.push_back(BFCommands::LoopEnd);
            case ';':
                f.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            case ' ':
            case '\n':
                continue;
            default:
                continue;
        }
    }
    return true;
}