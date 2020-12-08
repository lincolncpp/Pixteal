#include <iostream>
#include <string>
#include "../include/engine/engine.h"
#include "../include/engine/texture.h"
#include "../include/engine/font.h"
#include "../include/engine/text.h"
#include "../include/sprite.h"
#include "../include/player.h"
#include "../include/world.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 568

// Engine
Engine *engine;

// Variáveis do jogo
World *world;

// Texturas
Texture *texture_1px;

// Fonte e texto
Font *font;
Text *text_name;

// Jogador
Player *player;

// Thread 0 (renderização)
void render(){
    // Atualizando
    player->update();

    // Renderizando terreno
    world->render();

    // Renderizando interface
    texture_1px->setColor(50, 60, 57);
    texture_1px->setWidth(WINDOW_WIDTH);
    texture_1px->setHeight(88);
    texture_1px->render();

    player->render();

    text_name->render();
}

// Thread 1 (entradas)
void event(SDL_Event e){

    if (e.type == SDL_KEYDOWN){
        std::cout << "down" << std::endl;
    }
    // sprite_player->move(CHR_RIGHT);
}

int main(){

    // Criando engine
    engine = new Engine(WINDOW_WIDTH, WINDOW_HEIGHT, "Pixteal");

    // Carregando textura dos personagens
    Sprite::loadTexture(new Texture(engine, "gfx/sprites.png"));

    // Carregando terreno
    world = new World(engine, "gfx/ground.png");

    // Criando objeto de jogador principal
    player = new Player(rand(), 5, 5);

    // Carregando fonte e objeto para renderização de texto
    font = new Font("gfx/font.ttf", 16);
    text_name = new Text(engine, font, "Thread 0");
    text_name->setColor(20, 19, 30);
    text_name->setPos(5*32-16, 88+5*32-20);

    // Carregando texturas
    texture_1px = new Texture(engine, "gfx/1px.png");

    // Iniciando engine
    engine->start(render, event);

    // Aguardando a finalização das threads da engine
    engine->join();

    // Destruindo componentes
    delete world;
    delete player;
    delete font;
    delete text_name;
    delete texture_1px;
    Sprite::unloadTexture();
    delete engine;

    return 0;
}
