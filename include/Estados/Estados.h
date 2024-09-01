#pragma once

namespace Estados 
{

    class Mediator;

    enum EstadoID 
    {
        desconhecido = -1,
        mainMenu = 0,
        placar,
        gameOver,
        fase1,
        fase2,
        telaFim
    };

    class Estado 
    {

    protected:
        Mediator* pGEstado;
        EstadoID id;

    public:
        Estado(Mediator* pGEstado = nullptr, EstadoID id = desconhecido);

        virtual ~Estado();

        void setMediator(Mediator* pGEstado1);

        void changeEstado(EstadoID id);

        EstadoID getID() const;

        virtual void atualizar() = 0;

        virtual void render() = 0;

        virtual void resetEstado() = 0;
    };

}