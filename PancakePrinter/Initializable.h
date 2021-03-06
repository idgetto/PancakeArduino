#ifndef INITIALIZABLE_H
#define INITIALIZABLE_H

class Initializable {
    public:
        void init();

    protected:
        virtual void _init() = 0;
        void assertInitialized();
        bool _initialized;
};

#endif
