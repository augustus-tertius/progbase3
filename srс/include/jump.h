#ifndef JUMP
#define JUMP

class Jump {
    bool jumped;
    float timeInJump;
    float speedAtStart;

    public:
        Jump();
        void started();
        void update(float timePassed);
        void ended();
};

#endif