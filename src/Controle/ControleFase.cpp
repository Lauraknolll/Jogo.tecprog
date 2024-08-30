#include "../../include/Controle/ControleFase.h"
#include "../../include/Fases/Fase.h"

Controle::ControleFase::ControleFase(Fases::Fase* pM):
Observador()
{
    pFase = pM;
}

Controle::ControleFase::~ControleFase()
{
    pFase = NULL;
}

void Controle::ControleFase::anunciaPressionado(std::string key)
{
    if (pFase == NULL) {
        std::cout << "ERROR pointer to Menu NULL on MenuControle::notify()." << std::endl;
        exit(1);
    }

    if (key == "Escape")
        pFase->sair();
    if (key == "T")
        pFase->segundoJogador();
}

void Controle::ControleFase::anunciaSolto(std::string key)
{

}

void Controle::ControleFase::setFase(Fases::Fase* p)
{
    pFase = p;
}