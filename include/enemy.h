#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "engine/texture.h"
#include "engine/text.h"
#include "sprite.h"
#include "world.h"

// Probabilidade de que, em cada passo, o inimigo vá em direção do tesouro
#define ENEMY_PROBABILITY 0.5
#define ENEMY_RANDOM_ATTEMPTS 10

class Enemy: private Sprite{
private:
    World *world;
    Text *text;

    int points = 0;

    std::string name;

public:
    Enemy(World *world, Text *text, std::string name, int id, int x, int y);

    void render();
    void renderName();
    void update();

    int getPoints();
};

#endif
