#include "Ente.h"

class Entidade : public Ente
{
    protected:
        int x;
        int y;
    public:
        Entidade();
        ~Entidade();
        virtual void executar() = 0;
        virtual void salvar() = 0;
};