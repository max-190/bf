#ifndef BF_CONSTANTS_H
#define BF_CONSTANTS_H

const int MAX_TAPE_LENGTH = 30000;

enum class BFCommands {
    Null,
    IncrementPointer,
    DecrementPointer,
    IncrementByte,
    DecrementByte,
    OutputByte,
    InputByte,
    LoopStart,
    LoopEnd
};

struct BFToken {
    BFCommands command;
    int data;
};

#endif