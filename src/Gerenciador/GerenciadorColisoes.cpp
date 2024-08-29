#include "../../include/Gerenciador/GerenciadorColisoes.h"

#include <iostream>
using namespace std;
// #include "Entities/MovingEntity.h"
// #include "States/Level.h"
#include "math.h"
#include "../../include/Entidades/Personagens/Jogador.h"

Gerenciador::GerenciadorColisoes::GerenciadorColisoes(list<Entidades::Entidade *> Jogador1, list<Entidades::Entidade *> Obstaculos1, vector<Entidades::Entidade *> Inimigos1 /*, States::Level* plvl*/) :
    Jogadores(Jogador1), Obstaculos(Obstaculos1), Inimigos(Inimigos1) /*,  plvl(plvl) */ {}

Gerenciador::GerenciadorColisoes::~GerenciadorColisoes()
{
    Jogadores.clear();
    Obstaculos.clear();
    Inimigos.clear();
}

void Gerenciador::GerenciadorColisoes::tratarColisoesJogadoresObstaculos()
{
    Entidades::Entidade *ent1 = nullptr;
    Entidades::Entidade *ent2 = nullptr;
    list<Entidades::Entidade *>::iterator it1;
    list<Entidades::Entidade *>::iterator it2;

    /* Colisão entre os jogadores e os obstáculos */
    for (it1 = Jogadores.begin(); it1 != Jogadores.end(); it1++)
    {
        for (it2 = Obstaculos.begin(); it2 != Obstaculos.end(); it2++)
        {
            ent1 = (*it1);
            ent2 = (*it2);

            sf::RectangleShape corpo1 = ent1->getCorpo();
            sf::RectangleShape corpo2 = ent2->getCorpo();

            sf::Vector2f pos1 = corpo1.getPosition();
            sf::Vector2f pos2 = corpo2.getPosition();

            sf::Vector2f tam1 = corpo1.getSize();
            sf::Vector2f tam2 = corpo2.getSize();

            sf::Vector2f distanciaEntreCentros(
                fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
                fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));
            //printf("Distancia entre centros: %f\n", distanciaEntreCentros.y);

            sf::Vector2f somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
            sf::Vector2f intersecao = sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);

            /*  Condição pra colisão*/
            if (intersecao.x < 0.0f && intersecao.y < 0.0f)
            {
                //printf("entrou");
                ent1->colide(ent2, intersecao);
            }
        }
    }
}

void Gerenciador::GerenciadorColisoes::tratarColisoesJogadoresInimigos()
{
    Entidades::Entidade *ent1 = nullptr;
    Entidades::Entidade *ent2 = nullptr;
    list<Entidades::Entidade *>::iterator it1;

    /* Colisão entre os jogadores e os inimigos */
    for (it1 = Jogadores.begin(); it1 != Jogadores.end(); it1++)
    {
        for (int j = 0; j < Inimigos.size(); j++)
        {
            ent1 = (*it1);
            ent2 = Inimigos[j];

            sf::RectangleShape corpo1 = ent1->getCorpo();
            sf::RectangleShape corpo2 = ent2->getCorpo();

            sf::Vector2f pos1 = corpo1.getPosition();
            sf::Vector2f pos2 = corpo2.getPosition();

            sf::Vector2f tam1 = corpo1.getSize();
            sf::Vector2f tam2 = corpo2.getSize();

            sf::Vector2f distanciaEntreCentros(
                fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
                fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

            sf::Vector2f somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
            sf::Vector2f intersecao = sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);

            /*  Condição pra colisão*/
            if (intersecao.x < 0.0f && intersecao.y < 0.0f)
            {
                ent1->colide(ent2, intersecao);
                ent2->colide(ent1, intersecao);
            }
        }
    }

    //clean(); problemas com isso
}

void Gerenciador::GerenciadorColisoes::colide()
{

    tratarColisoesJogadoresObstaculos();
    tratarColisoesJogadoresInimigos();

}

// Function to deallocate entities after collision
void Gerenciador::GerenciadorColisoes::clean()
{
    vector<Entidades::Entidade *>::iterator it1;
    Personagens::Personagem* paux = nullptr;
    for(int i = 0; i < Inimigos.size(); i++)
    {
        paux = static_cast<Personagens::Personagem*>(Inimigos[i]);
        *it1 = Inimigos[i];
        if(paux != nullptr)
        {
            if(paux->getNumVidas() <= 0)
            {
                Inimigos.erase(it1);
                //i--;
                if(i < 0)
                    i = -1;
            }
        }
    }
//Entities::MovingEntity* pAux = nullptr;
    /*for (int i = 0; i < Jogador->getSize(); i++) {
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
