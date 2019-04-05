#include "include/Face.h"

#define START_HP 30

Face::Face(GameObject& associated) : Component (associated)
{
    hitpoints = START_HP;
}

void Face::Damage(int damage){
    hitpoints = hitpoints - damage;

    //When dies, delete "enemy"
    if (hitpoints <= 0){
        associated.RequestDelete();
        //Play sound associated to its defeat
    }
}

void Face::Update(float dt){

}

void Face::Render(){

}

bool Face::Is(string type){
    return !type.compare("Face");
}
