#include "../../../include/Entidades/Personagens/Chefao.h"

Personagens::Chefao::Chefao() :
    Inimigo()
{

}

Personagens::Chefao::~Chefao()
{

}

void Personagens::Chefao::imprimir(Gerenciador::GerenciadorGrafico* gG)
{
    gG->desenhaEntidade(corpo);
}

void Personagens::Chefao::executar()
{
    
}