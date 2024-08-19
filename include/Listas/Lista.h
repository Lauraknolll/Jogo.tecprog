template<class TIPO>
class Lista
{
    private:
        Elemento<TIPO>* pontPrimeiro;
        Elemento<TIPO>* pontUltimo;
        class Elemento
        {
            private:
                Elemento<TIPO>* pontProximo;
                TIPO* pontInfo;
            public: 
                Elemento();
                ~Elemento();
                void incluiProximo(Elemento<TIPO>* pP);
                void inluiInfo(TIPO* pI);
        };
    public:
        Lista();
        ~Lista;
        void Inicializa();
        void Limpar();
        bool incluiElemento(Elemento<TIPO>* pontElemento);
        bool incluiInfor(TIPO* pontInfo);
    
};