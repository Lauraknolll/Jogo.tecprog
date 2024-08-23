#include "../../../include/Entidades/Obstaculos/Obstaculo.h"

Obstaculos::Obstaculo::Obstaculo(float xxx, float y, float ww, float hh, Entidades::ID id): 
Entidade(xxx, y, ww, hh, id)
{

}

Obstaculos::Obstaculo::~Obstaculo()
{

}

void Obstaculos::Obstaculo::executar()
{
    
}
void Obstaculos::Obstaculo::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    
}
int const Obstaculos::Obstaculo::getTipo() const
{
    return 0;
}
