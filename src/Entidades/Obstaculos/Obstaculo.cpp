#include "../../../include/Entidades/Obstaculos/Obstaculo.h"

Obstaculos::Obstaculo::Obstaculo(float xxx, float y, float ww, float hh): 
Entidade(xxx, y, ww, hh)
{

}

Obstaculos::Obstaculo::~Obstaculo()
{

}

void Obstaculos::Obstaculo::executar(const float dt)
{
    
}
void Obstaculos::Obstaculo::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    
}
int const Obstaculos::Obstaculo::getTipo() const
{
    return 0;
}