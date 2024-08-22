#include "../../include/Gerenciador/GerenciadorColisoes.h"

#include "../../include/CoordTl.h"
//#include "Entities/MovingEntity.h"
//#include "States/Level.h"
#include "math.h"



    GerenciadorColisoes::GerenciadorColisoes(Lista::ListaEntidade* movingEntities, Lista::ListaEntidade* staticEntities/*, States::Level* plvl*/) :
    movingEntities(movingEntities),
    staticEntities(staticEntities)/*,
    plvl(plvl) */{ }

    GerenciadorColisoes::~GerenciadorColisoes() {
        movingEntities = nullptr;
        staticEntities = nullptr;
    }

    void GerenciadorColisoes::colide() {
        Entidade* ent1 = nullptr;
        Entidade* ent2 = nullptr;
        CoordF intersect;
        CoordF centerDistance;
        int i, j;

        /* Collide non-moving entities with moving entities */
        for (i = 0; i < staticEntities->getSize(); i++) {
            for (j = 0; j < movingEntities->getSize(); j++) {
                ent1 = (*staticEntities)[i];
                ent2 = (*movingEntities)[j];

                centerDistance.x = ent2->getPosicao().x - ent1->getPosicao().x;
                centerDistance.y = ent2->getPosicao().y - ent1->getPosicao().y;

                intersect.x = fabs(centerDistance.x) - (ent1->getTamanho().x / 2.0f + ent2->getTamanho().x / 2.0f);
                intersect.y = fabs(centerDistance.y) - (ent1->getTamanho().y / 2.0f + ent2->getTamanho().y / 2.0f);

                if (intersect.x < 0.0f && intersect.y < 0.0f) { // Condition to collide...
                    ent2->colide(ent1, intersect);
                }
            }
        }

        /* Collide moving entities with moving entities - diagonally */
        for (i = 0; i < movingEntities->getSize(); i++) {
            for (j = i + 1; j < movingEntities->getSize(); j++) {
                ent1 = (*movingEntities)[i];
                ent2 = (*movingEntities)[j];

                centerDistance.x = ent2->getPosicao().x - ent1->getPosicao().x;
                centerDistance.y = ent2->getPosicao().y - ent1->getPosicao().y;

                intersect.x = fabs(centerDistance.x) - (ent1->getTamanho().x / 2.0f + ent2->getTamanho().x / 2.0f);
                intersect.y = fabs(centerDistance.y) - (ent1->getTamanho().y / 2.0f + ent2->getTamanho().y / 2.0f);

                if (intersect.x < 0.0f && intersect.y < 0.0f) { // Condition to collide...
                    ent2->colide(ent1, intersect);
                    ent1->colide(ent2, intersect);
                }
            }
        }

        //clear();
    }

    /* Function to deallocate entities after collision */
    /*void GerenciadorColisoes::clear() {
        Entities::MovingEntity* pAux = nullptr;
        for (int i = 0; i < movingEntities->getSize(); i++) {
            pAux = static_cast<Entities::MovingEntity*>((*movingEntities)[i]);
            if (pAux != nullptr) {
                if (!pAux->isActive()) {
                    if (pAux->getId() != Entities::ID::coin)
                        plvl->coinBomb(pAux->getPosition());
                    movingEntities->deleteEntity(pAux);
                    i--;
                    if (i < 0)
                        i = -1;
                }
            }
        }
    }
*/
 // namespace Manager