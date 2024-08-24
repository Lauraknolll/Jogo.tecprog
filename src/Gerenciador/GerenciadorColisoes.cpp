#include "../../include/Gerenciador/GerenciadorColisoes.h"

#include "../../include/CoordTl.h"
#include <iostream>
using namespace std;
//#include "Entities/MovingEntity.h"
//#include "States/Level.h"
#include "math.h"



    Gerenciador::GerenciadorColisoes::GerenciadorColisoes(Lista::ListaEntidade* Jogador1, Lista::ListaEntidade* Obstaculos1, Lista::ListaEntidade* Inimigos1/*, States::Level* plvl*/) :
        Jogador(Jogador1),  Obstaculos(Obstaculos1), Inimigos(Inimigos1)/*,  plvl(plvl) */{ }

    Gerenciador::GerenciadorColisoes::~GerenciadorColisoes() 
    {
        Jogador = nullptr;
        Obstaculos = nullptr;
    }

    void Gerenciador::GerenciadorColisoes::colide() {
        Entidades::Entidade* ent1 = nullptr;
        Entidades::Entidade* ent2 = nullptr;
        Entidades::Entidade* ent3 = nullptr;
        int i, j;

       
        /* Colisão entre os jogadores e os obstáculos */
        for (i = 0; i < Jogador->getSize(); i++) 
        {
            for (j = 0; j < Obstaculos->getSize(); j++) 
            {
                ent1 = (*Jogador)[i];
                ent2 = (*Obstaculos)[j];

                sf::RectangleShape corpo1 = ent1->getCorpo();
                sf::RectangleShape corpo2 = ent2->getCorpo();

                sf::Vector2f pos1 = corpo1.getPosition();
                sf::Vector2f pos2 = corpo2.getPosition();

                sf::Vector2f tam1 = corpo1.getSize();
                sf::Vector2f tam2 = corpo2.getSize();

            
                sf::Vector2f distanciaEntreCentros(
                    fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
                    fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f))
                );

                sf::Vector2f somaMetadeRetangulo(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);
                sf::Vector2f intersecao = sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);

                /*  Condição pra colisão*/
                if(intersecao.x < 0.0f && intersecao.y < 0.0f)
                {
                    ent1->colide(ent2, intersecao);
                }
            }
        } 


        /* Colisão entre os jogadores e os inimigos */
        for (i = 0; i < Jogador->getSize(); i++) 
        {
            for (j = 0; j < Inimigos->getSize(); j++) 
            {
                ent1 = (*Jogador)[i];
                ent2 = (*Inimigos)[j];

                sf::RectangleShape corpo1 = ent1->getCorpo();
                sf::RectangleShape corpo2 = ent2->getCorpo();

                sf::Vector2f pos1 = corpo1.getPosition();
                sf::Vector2f pos2 = corpo2.getPosition();

                sf::Vector2f tam1 = corpo1.getSize();
                sf::Vector2f tam2 = corpo2.getSize();

                sf::Vector2f distanciaEntreCentros(
                    fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
                    fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f))
                );
                
                sf::Vector2f somaMetadeRetangulo(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);
                sf::Vector2f intersecao = sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);

                /*  Condição pra colisão*/
                if (intersecao.x < 0.0f && intersecao.y < 0.0f) 
                {
                    
                    ent2->colide(ent1, intersecao);
                    ent1->colide(ent2, intersecao);
                }
            }
        }

        clear();
    }

    /* Function to deallocate entities after collision */
    void Gerenciador::GerenciadorColisoes::clear() 
    {
        Personagens::Personagem* paux = nullptr;
        for(int i = 0; i < Inimigos->getSize(); i++)
        {
            paux = static_cast<Personagens::Personagem*>((*Inimigos)[i]);
            if(paux != nullptr)
            {
                if(paux->getNumVidas() <= 0)
                {
                    Inimigos->deleteEntidade(paux);
                    i--;
                    if(i < 0)
                        i = -1;
                }
            }
        }
        /*Entities::MovingEntity* pAux = nullptr;
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
        }*/
    }

