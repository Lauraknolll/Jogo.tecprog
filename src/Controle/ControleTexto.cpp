//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#include "../../include/Controle/ControleTexto.h"

#include <iostream>

namespace Controle {

    ControleTexto::ControleTexto() :
    Observador() { }

    ControleTexto::~ControleTexto() { }

    void ControleTexto::anunciaPressionado(std::string key) {
        if (key == "Enter" || 
            key == "Right" || 
            key == "Left" || 
            key == "Up" || 
            key == "Down" || 
            key == "Escape" || 
            key == "Control" || 
            key == "Shift" || 
            key == "RControl" || 
            key == "RShift" || 
            key == "Tab"||
            key == "Unknown") {
            return;
        }

        if (key == "BackSpace") {
            if (texto.size() > 0)
                texto.pop_back();
        } 

        else if (key == "Space") {
            texto += " ";
        }

        else {
            texto += key;
        }
    }

    void ControleTexto::anunciaSolto(std::string key) { }

    std::string ControleTexto::getString() const{
        return texto;
    }

    void ControleTexto::reset(){
        texto = "";
    }

}