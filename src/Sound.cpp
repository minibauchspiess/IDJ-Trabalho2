#include "include/Sound.h"

Sound::Sound(GameObject& associated) : Component (associated)
{
    chunk = nullptr;
}

Sound::Sound(GameObject& associated, string file) : Sound(associated)
{
   Open(file);
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, chunk, times-1);
}

void Sound::Stop(){
    if (chunk != nullptr){
        Mix_HaltChannel(channel);
    }
}


void Sound::Open(string file){
    chunk = Mix_LoadWAV(file.c_str());
    if (chunk == nullptr){
        cout<<"Sound file "<<file<<" failed to open"<<endl;
    }
}

bool Sound::Is(string type){
    return !type.compare("Sound");
}

void Sound::Update(float dt){}

void Sound::Render(){}

Sound::~Sound(){
    if (chunk != nullptr){
        Mix_HaltChannel(channel);
    }
    Mix_FreeChunk(chunk);
}
