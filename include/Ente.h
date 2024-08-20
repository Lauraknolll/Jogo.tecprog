#include "Gerenciador/GerenciadorGrafico.h"

class Ente
{
    protected:
        int id;
        GerenciadorGrafico* gG;
    public:
        Ente();
        ~Ente();
        virtual void executar() = 0;
        void desenhar();
};