#include "../../include/Gerenciador/GerenciadorColisoes.h"

#include "../../include/CoordTl.h"
#include <iostream>
using namespace std;
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

        //cout << Jogador->getSize() << endl;
        //cout << Obstaculos->getSize() << endl;
       
        for (i = 0; i < Obstaculos->getSize(); i++) 
        {
            for (j = 0; j < Jogador->getSize(); j++) 
            {
                //cout << "Entrou" << endl; 
                ent1 = (*Obstaculos)[i];
                ent2 = (*Jogador)[j];

                sf::RectangleShape corpo1 = ent1->getCorpo();
                sf::RectangleShape corpo2 = ent2->getCorpo();

                sf::Vector2f pos1 = corpo1.getPosition();
                sf::Vector2f pos2 = corpo2.getPosition();

                //cout << ent1->getPosicao().x << " " << ent1->getPosicao().y << endl;
                //cout << ent2->getPosicao().x << " " << ent2->getPosicao().y << endl;

                sf::Vector2f tam1 = corpo1.getSize();
                sf::Vector2f tam2 = corpo2.getSize();

                


                sf::Vector2f distanciaEntreCentros(
                    fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
                    fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f))
                );

                //printf("Largura:%f - %f \n", corpo1.getSize().x, corpo2.getSize().x);

                sf::Vector2f somaMetadeRectangulo(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);
                sf::Vector2f num = sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x, distanciaEntreCentros.y - somaMetadeRectangulo.y);
                
                //cout << num.x << " " << num.y << endl;

                if(num.x < 0.0f && num.y < 0.0f)
                {
                    //cout << "Entrou" << endl; 
                    //cout << ent1->getPosicao().x << " " << ent1->getPosicao().y << endl;
                    //cout << ent2->getPosicao().x << " " << ent2->getPosicao().y << end
                    ent2->colide(ent1, num);
                }
            }
        } 





        /* Collide moving entities with moving entities - diagonally 
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
        }*/

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
