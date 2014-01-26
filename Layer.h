#ifndef LAYER_H
#define LAYER_H

#include "SDL.h"
#include "Sprite.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


class Layer
{
public:
    Layer();
    void addSprite(Sprite *s);
    void sortSprites();
    std::vector<Sprite*> sprites;
};

#endif // LAYER_H
