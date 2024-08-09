#include "../inc/interpreter.hpp"

#include <iostream>

bool bf_interpreter(std::vector<BFToken> tokens) {
    for (auto token : tokens) {
        switch (token.command) {
            case BFCommands::IncrementPointer:
                for (int i = 0; i < token.data; i++) {
                    std::cout << ">";
                }
                break;
            case BFCommands::DecrementPointer:
            for (int i = 0; i < token.data; i++) {
                    std::cout << "<";
                }
                break;
            case BFCommands::IncrementByte:
                for (int i = 0; i < token.data; i++) {
                    std::cout << "+";
                }
                break;
            case BFCommands::DecrementByte:
            for (int i = 0; i < token.data; i++) {
                    std::cout << "-";
                }
                break;
            case BFCommands::OutputByte:
                std::cout << ".";
                break;
            case BFCommands::InputByte:
                std::cout << ",";
                break;
            case BFCommands::LoopStart:
                std::cout << "[";
                break;
            case BFCommands::LoopEnd:
                std::cout << "]";
                break;
        }
        
    }
    std::cout << "\n" << tokens.size() << std::endl;


    char A[30000] = {0};
    int data_p = 0;
    int instr_p = 0;
    while (instr_p != tokens.size()) {
        switch (tokens[instr_p].command) {
            case BFCommands::IncrementPointer:
                data_p += tokens[instr_p].data;
                break;
            case BFCommands::DecrementPointer:
                data_p -= tokens[instr_p].data;
                break;
            case BFCommands::IncrementByte:
                A[data_p] += tokens[instr_p].data;
                break;
            case BFCommands::DecrementByte:
                A[data_p] -= tokens[instr_p].data;
                break;
            case BFCommands::OutputByte:
                std::cout << A[data_p];
                break;
            case BFCommands::InputByte:
                A[data_p] = std::cin.get();
                break;
            case BFCommands::LoopStart:
            case BFCommands::LoopEnd:
                if (A[data_p] == 0) {
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