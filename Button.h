#ifndef BUTTON_H
#define BUTTON_H

#include "Gui.h"
#include <string>
#include "SDL.h"

class Button : public Gui
{
public:
    Button(int x, int y, int width, int height);
};

#endif // BUTTON_H
