#include "../../../include/Entidades/Personagens/Inimigo.h"

Personagens::Inimigo::Inimigo(float xx, float yy, float ww, float hh, Entidades::ID id) :
    Personagem(xx, yy, ww, hh, id), vivo(true)
{

}

Personagens::Inimigo::~Inimigo()
{
    
}

int Personagens::Inimigo::getNumVidas()
{
    return 0; 
}