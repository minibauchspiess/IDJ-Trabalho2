
#ifndef STATE_H
#define STATE_H


#include <iostream>
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Music.h"
#include "Sprite.h"
#include <memory>

using namespace std;

class State
{
public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();

    void Input();
    void AddObject(int mouseX, int mouseY);

private:
    //Sprite bg;
    Music music;
    bool quitRequested;

    vector<unique_ptr<GameObject>> objectArray;
};

#endif
