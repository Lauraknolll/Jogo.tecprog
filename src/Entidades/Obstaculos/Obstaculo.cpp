#include "../../../include/Entidades/Obstaculos/Obstaculo.h"

Obstaculo::Obstaculo(float xxx, float y, float ww, float hh): 
Entidade(xxx, y, ww, hh)
{

}

Obstaculo::~Obstaculo()
{

}

void Obstaculo::executar(const float dt)
{
    
}
void Obstaculo::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    
}
int const Obstaculo::getTipo() const
{
    return 0;
}