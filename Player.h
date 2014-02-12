#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
    private:
        std::string name;
        int hitpoints;
    public:
        Player(std::string name);
        virtual ~Player();
        void dealDamage(int amount);
};

#endif // PLAYER_H
