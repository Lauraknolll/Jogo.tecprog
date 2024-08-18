#pragma once

namespace Gerenciador
{
    class GerenciadorEvento
    {
        private:
        GerenciadorGrafico* pGGrafico;
        /* Usando o padrão de projeto Singleton para que haja apenas uma instancia do gerenciador gráfico */
        static GerenciadorEvento* pInstanciaGE;
        GerenciadorEvento();
        public:
        ~GerenciadorEvento();
        /* Parte do Singleton */
        static GerenciadorEvento* getGerenciadorEventos();
        void executar();
    };
}