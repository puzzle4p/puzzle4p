#include "Util.h"
#include <iostream>

class stateManager
{
public:
    void update();
    void changeState(global_States state);
    void onMouseDown();
private:
    global_States current_state;
};
