#include "../Entidade.h"
#include "../Colisao.h"
#include "../Gerenciador/GerenciadorGrafico.h"

namespace Obstaculos{
    class Obstaculo : public Entidade
    {
    protected:
        Gerenciador::GerenciadorGrafico *gG;
    public:
        Obstaculo(float x = 0, float y = 0, float w = 0, float h = 0);
        ~Obstaculo();

        virtual void executar(const float dt) = 0;
        virtual void imprimir() = 0;
        virtual int const getTipo() const = 0;
        //virtual void obstacular(Personagem* pP, int dir) = 0;
    };
    
}