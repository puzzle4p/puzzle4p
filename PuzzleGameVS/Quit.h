#ifndef QUIT_H
#define QUIT_H
#include "State.h"
class Quit : public State
{
public:
	Quit();
	void onMouseDown(int pointerX, int pointerY);
	void update();
	~Quit();
};
#endif

