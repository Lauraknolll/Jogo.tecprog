#include "../../include/Gerenciador/GerenciadorColisoes.h"

#include "../../include/CoordTl.h"
//#include "Entities/MovingEntity.h"
//#include "States/Level.h"
#include "math.h"



    Gerenciador::GerenciadorColisoes::GerenciadorColisoes(Lista::ListaEntidade* Jogador1, Lista::ListaEntidade* Obstaculos1/*, Lista::ListaEntidade* Inimigos1, States::Level* plvl*/) :
        Jogador(Jogador1),
        Obstaculos(Obstaculos1)
        /*Inimigos(Inimigos1),
    plvl(plvl) */{ }

    Gerenciador::GerenciadorColisoes::~GerenciadorColisoes() 
    {
        Jogador = nullptr;
        Obstaculos = nullptr;
    }

    void Gerenciador::GerenciadorColisoes::colide() {
        Entidades::Entidade* ent1 = nullptr;
        Entidades::Entidade* ent2 = nullptr;
        Entidades::Entidade* ent3 = nullptr;
        CoordF intersecao;
        CoordF distanciaEntreCentros;
        int i, j;

        /* Collide non-moving entities with moving entities */
        for (i = 0; i < Obstaculos->getSize(); i++) 
        {
            for (j = 0; j < Jogador->getSize(); j++) 
            {
                ent1 = (*Obstaculos)[i];
                ent2 = (*Jogador)[j];

                distanciaEntreCentros.x = ent2->getPosicao().x - ent1->getPosicao().x;
                distanciaEntreCentros.y = ent2->getPosicao().y - ent1->getPosicao().y;

                intersecao.x = fabs(distanciaEntreCentros.x) - (ent1->getTamanho().x / 2.0f + ent2->getTamanho().x / 2.0f);
                intersecao.y = fabs(distanciaEntreCentros.y) - (ent1->getTamanho().y / 2.0f + ent2->getTamanho().y / 2.0f);

                if (intersecao.x < 0.0f && intersecao.y < 0.0f) 
                { // Condition to collide...
                    ent2->colide(ent1, intersecao);
                }
            }
        }

        /* Collide moving entities with moving entities - diagonally */
        for (i = 0; i < Jogador->getSize(); i++) 
        {
            for (j = i + 1; j < Jogador->getSize(); j++) 
            {
                ent1 = (*Jogador)[i];
                ent2 = (*Jogador)[j];

                distanciaEntreCentros.x = ent2->getPosicao().x - ent1->getPosicao().x;
                distanciaEntreCentros.y = ent2->getPosicao().y - ent1->getPosicao().y;

                intersecao.x = fabs(distanciaEntreCentros.x) - (ent1->getTamanho().x / 2.0f + ent2->getTamanho().x / 2.0f);
                intersecao.y = fabs(distanciaEntreCentros.y) - (ent1->getTamanho().y / 2.0f + ent2->getTamanho().y / 2.0f);

                if (intersecao.x < 0.0f && intersecao.y < 0.0f) 
                { // Condition to collide...
                    ent2->colide(ent1, intersecao);
                    ent1->colide(ent2, intersecao);
                }
            }
        }

        //clear();
    }

    /* Function to deallocate entities after collision */
    /*void GerenciadorColisoes::clear() {
        Entities::MovingEntity* pAux = nullptr;
        for (int i = 0; i < Jogador->getSize(); i++) {
            pAux = static_cast<Entities::MovingEntity*>((*Jogador)[i]);
            if (pAux != nullptr) {
                if (!pAux->isActive()) {
                    if (pAux->getId() != Entities::ID::coin)
                        plvl->coinBomb(pAux->getPosition());
                    Jogador->deleteEntity(pAux);
                    i--;
                    if (i < 0)
                        i = -1;
                }
            }
        }
    }
*/
