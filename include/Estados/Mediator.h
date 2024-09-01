#include "../Estados/Estados.h"
namespace Estados{
class Mediator
{
    private:
        //tem que ter algum atributo
    public:
        Mediator();
        ~Mediator();

        virtual void mudarEstadoAtual(EstadoID id) = 0;
        virtual void inserirEstado(Estado* pestado) = 0;

    };
}