#include "../Ente.h"
#include "../Gerenciador/GerenciadorColisoes.h"

namespace Fases
{
    class Fase : public Ente
    {   
        protected:
            Gerenciador::GerenciadorColisoes* pGColisoes;
        public:
            Fase();
            ~Fase();
            void criarJogadores();
            void criarInimigos();
            void criarPLataformas();
            void executar();
    };
}