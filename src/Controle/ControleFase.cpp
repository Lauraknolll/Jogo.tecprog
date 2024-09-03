//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#include "../../include/Controle/ControleFase.h"
#include "../../include/Fases/Fase.h"

Controle::ControleFase::ControleFase(Fases::Fase* pF):
Observador()
{
    pFase = pF;
}

Controle::ControleFase::~ControleFase()
{
    pFase = NULL;
}

void Controle::ControleFase::anunciaPressionado(std::string key)
{
    if (pFase == NULL) {
        std::cout << "ERRO : ponteiro nulo" << std::endl;
        exit(1);
    }

    if (key == "Escape")
        pFase->sair();
    if (key == "T")
        pFase->segundoJogador();
    if (key == "P")
        pFase->pause();
}

void Controle::ControleFase::anunciaSolto(std::string key)
{

}

void Controle::ControleFase::setFase(Fases::Fase* p)
{
    pFase = p;
}