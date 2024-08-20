#pragma once

#include "GerenciadorGrafico.h"

#include "../Obstaculos/Obstaculo.h"
#include "../Jogador.h"

using namespace Obstaculos;


namespace Gerenciadores
{

class GerenciadorColisoes
{
private:
  Jogador* jog;
  Jogador* jog2;
  std::list<Projetil> proj;
  std::list<Obstaculo> obst;
public:
  GerenciadorColisoes();
  ~GerenciadorColisoes();
  void executar();
  void incluir(Jogador j);
  void incluir(Projetil* p);
  void incluir(Obstaculo* o);
  void limpagCOL();
};

}