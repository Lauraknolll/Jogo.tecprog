#include "../Entidade.h"
#include "../Colisao.h"
#include "../Gerenciador/GerenciadorGrafico.h"
#include "../CoordTl.h"

namespace Obstaculos{
    class Obstaculo : public Entidade
    {
    protected:
        int w, h;
    public:
        Obstaculo(float x = 0, float y = 0, float ww = 0, float hh = 0);
        ~Obstaculo();

        virtual void executar(const float dt) = 0;
        virtual void imprimir() = 0;
        virtual int const getTipo() const = 0;
        //virtual void obstacular(Personagem* pP, int dir) = 0;
    };
    
}