#ifndef COMMAND_QUEUE_H
#define COMMAND_QUEUE_H

#include <Arduino.h>

#define DEFAULT_CAPACITY 5

class CommandQueue {
    public:
        CommandQueue(size_t capacity = DEFAULT_CAPACITY);
        ~CommandQueue();
        bool empty() const;
        void pushCommand(String command);
        String popCommand();
    private:
        size_t _capacity;
        String *_queue;
        size_t _executeIndex;
        size_t _addIndex;
};

#endif
