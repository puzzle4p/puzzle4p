#include "Layer.h"

Layer::Layer(){}

void Layer::addSprite(Sprite *s)
{
    std::cout << s->destinationOfImage << " / " << s->priority << " / " << s << "\n";
    sprites.push_back(s);
}

struct sortByPriority
{
    bool operator()(Sprite *i, Sprite *j)
    {
        return i->priority < j->priority;
    }
};

void Layer::sortSprites()
{
    std::sort(sprites.begin(), sprites.end(), sortByPriority());
}

