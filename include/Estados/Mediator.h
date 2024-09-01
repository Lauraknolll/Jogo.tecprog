#include "../Estados/Estados.h"
namespace Estados{
class Mediator
{
    private:

    public:
        Mediator();
        ~Mediator();

        virtual void mudarEstadoAtual(EstadoID id) = 0;
        virtual void inserirEstado(Estado* pestado) = 0;

    };
}