#ifndef STATE_H
#define STATE_H

class State
{
public:
    virtual void onMouseDown(int pointerX, int pointerY) = 0;
};

#endif // STATE_H
