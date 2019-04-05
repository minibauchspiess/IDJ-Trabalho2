
#include "../include/Sprite.h"
#include "../include/Game.h"
#include <iostream>

using namespace std;

Sprite::Sprite(GameObject& associated) : Component(associated)
{
    texture = nullptr;
}

Sprite::Sprite(string file, GameObject& associated) : Component(associated){
    texture =nullptr;
    Open(file);
}

Sprite::~Sprite(){
    if (texture != nullptr){
        SDL_DestroyTexture(texture);
    }
}

void Sprite::Update(float dt){}

bool Sprite::Is(string type){
    return (!type.compare("string"));
}

void Sprite::Open(string file){

    int width, height;

    Game& instance = Game::GetInstance();

    //Check if texture already exists
    if (texture != nullptr){
        SDL_DestroyTexture(texture);
    }

    //Load texture
    texture = IMG_LoadTexture(instance.GetRenderer(), file.c_str());
    if (texture == nullptr){
        cout<<"Error loading image"<<endl;
        cout<<SDL_GetError()<<endl;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    associated.box.w = width;
    associated.box.h = height;
    SetClip(0, 0, width, height);

}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x=x;
    clipRect.y=y;
    clipRect.w=w;
    clipRect.h=h;
}

void Sprite::Render(){
    Game& instance = Game::GetInstance();

    SDL_Rect dstrect;
    dstrect.x = associated.box.x;
    dstrect.y = associated.box.y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;

    SDL_RenderCopy(instance.GetRenderer(), texture, &clipRect, &dstrect);
}

int Sprite::GetWidth(){
    return associated.box.w;
}

int Sprite::GetHeight(){
    return associated.box.h;
}

bool Sprite::IsOpen(){
    if (texture != nullptr){
        return true;
    }
    else{
        return false;
    }
}




