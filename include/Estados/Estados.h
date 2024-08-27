#pragma once

namespace Estados {

    class GerenciadorEstado;

    enum EstadoID {
        unknown = -1,
        mainMenu = 0,
        fase1,
        fase2
    };

    class Estado {

    protected:
        GerenciadorEstado* pSM;
        EstadoID id;

    public:
        Estado(GerenciadorEstado* pSM = nullptr, EstadoID id = unknown);

        virtual ~Estado();

        void setGerenciadorEstados(GerenciadorEstado* pSM);

        void changeEstado(EstadoID id);

        EstadoID getID() const;

        virtual void atualizar() = 0;

        virtual void render() = 0;

        virtual void resetEstado() = 0;
    };

}