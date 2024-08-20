#include "Ente.h"
#include "Colisao.h"

class Entidade : public Ente
{
    protected:
        float x;
        float y;

    public:
        Entidade(float xx = 0, float yy = 0);
        ~Entidade();
        virtual void executar() = 0;
        virtual void salvar() = 0;
};