#pragma once

namespace Estados 
{

    class GerenciadorEstado;

    enum EstadoID 
    {
        desconhecido = -1,
        mainMenu = 0,
        gameOver,
        fase1,
        fase2
    };

    class Estado 
    {

    protected:
        GerenciadorEstado* pGEstado;
        EstadoID id;

    public:
        Estado(GerenciadorEstado* pGEstado = nullptr, EstadoID id = desconhecido);

        virtual ~Estado();

        void setGerenciadorEstados(GerenciadorEstado* pGEstado1);

        void changeEstado(EstadoID id);

        EstadoID getID() const;

        virtual void atualizar() = 0;

        virtual void render() = 0;

        virtual void resetEstado() = 0;
    };

}