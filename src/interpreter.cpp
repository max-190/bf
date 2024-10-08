#include "../inc/interpreter.hpp"

#include <iostream>

bool bf_interpreter(std::vector<BFToken> tokens) {
    char A[30000] = {0};
    int data_p = 0;
    int instr_p = 0;
    while (instr_p != tokens.size()) {
        switch (tokens[instr_p].command) {
            case BFCommands::IncrementPointer:
            case BFCommands::DecrementPointer:
                data_p += tokens[instr_p].data;
                break;
            case BFCommands::IncrementByte:
            case BFCommands::DecrementByte:
                A[data_p] += tokens[instr_p].data;
                break;
            case BFCommands::OutputByte:
                std::cout << A[data_p];
                break;
            case BFCommands::InputByte:
                A[data_p] = std::cin.get();
                break;
            case BFCommands::LoopStart:
                if (A[data_p] == 0) {
                    instr_p = tokens[instr_p].data;
                }
                break;
            case BFCommands::LoopEnd:
                if (A[data_p] != 0) {
                    instr_p = tokens[instr_p].data;
                }
                break;
            default:
                return false;
        }
        instr_p++;
    }
    std::cout << std::endl;
    return true;
}