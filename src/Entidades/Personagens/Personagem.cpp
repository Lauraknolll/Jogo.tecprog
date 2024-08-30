#include "../../../include/Entidades/Personagens/Personagem.h"

Personagens::Personagem::Personagem(float xx, float yy, float ww, float hh, Entidades::ID id) :
    Entidade(xx, yy, ww, hh, id), vivo(true)
{

}

Personagens::Personagem::~Personagem()
{

}

