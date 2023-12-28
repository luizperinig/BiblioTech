#ifndef GERENTE_H
#define GERENTE_H

#include "Usuario.hpp"
#include <iostream>
#include <string>

using namespace std;

class Gerente : public Usuario{
    private:
        string _Codigo;

    public:
        Gerente(int Id, string Codigo, string Nome, string Email, string Senha);
        virtual ~Gerente();

        virtual void Imprimir_Informacoes();
        void Editar_Informacoes(string Nome, string Email, string Senha) override;

        string getCodigo();
};

namespace GerenteErros{
    struct Codigo_Invalido : public exception{
        const char* what() const throw(){
            return "Codigo digitado e invalido";
        }
    };    
}

#endif