#include "include/Gameobject.h"
#include "include/Component.h"



GameObject::GameObject()
{
    isDead = false;
}

GameObject::~GameObject(){
    components.clear();
}

void GameObject::Update(float dt){
    for (int i = 0; i<components.size(); i++){
        components[i]->Update(dt);
    }
}

void GameObject::Render(){
    for (int i = 0; i<components.size(); i++){
        components[i]->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    for (int i = 0; i < components.size();){
        if (components[i].get() == cpt){
            components.erase(components.begin() + i);
        }
        else{
            i++;
        }
    }
}

Component* GameObject::GetComponent(string type){
    for (int i = 0; i < components.size(); i++){
        if (components[i]->Is(type)){
            return components[i].get();
        }
    }
    return nullptr;
}

