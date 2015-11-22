#ifndef COMMAND_COURIER_H
#define COMMAND_COURIER_H

class CommandCourier {
    public:
        String readCommand() const;
        void requestCommands();
        void reportGot(String command) const;
        void reportComplete(String command) const;

    private:
        static const char NEW_LINE = '\n';

        static const String READY;
        static const String COMMAND;
        static const String GOT_MSG;
        static const String COMPLETED_MSG;
};


#endif
