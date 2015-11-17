#include "CommandQueue.h"

CommandQueue::CommandQueue(size_t capacity) : 
    _capacity{capacity} {
        _queue = new String[capacity];
        for (size_t i = 0; i < capacity; ++i) {
            _queue[i] = "";
        }
}

CommandQueue::~CommandQueue() {
    delete _queue;
}

bool CommandQueue::empty() const {
    return _addIndex == _executeIndex;
}

void CommandQueue::pushCommand(String command) {
    _queue[_addIndex] = command;
    _addIndex = (_addIndex + 1) % _capacity;
}

String CommandQueue::popCommand() {
    String res =  _queue[_executeIndex];
    _executeIndex = (_executeIndex + 1) % _capacity;
    return res;
}
