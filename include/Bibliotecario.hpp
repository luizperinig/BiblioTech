#ifndef BIBLIOTECARIO_H
#define BIBLIOTECARIO_H

#include "Usuario.hpp"
#include <iostream>
#include <string>

using namespace std;

class Bibliotecario : public Usuario{
    private:


    public:
        Bibliotecario(int Id, string Nome, string Email, string Senha);
        virtual ~Bibliotecario();

        virtual void Imprimir_Informacoes();
        void Editar_Informacoes(string Nome, string Email, string Senha) override;
};

#endif