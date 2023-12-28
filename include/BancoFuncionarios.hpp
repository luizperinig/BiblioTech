#ifndef BANCOFUNCIONARIOS_H
#define BANCOFUNCIONARIOS_H

#include <iostream>
#include <string>
#include <list>

#include "Bibliotecario.hpp"
#include "Gerente.hpp"

using namespace std;

class BancoFuncionarios{
    private:
        int _Id = 1;
        list<Bibliotecario*> _Bibliotecarios;
        Gerente* _Gerente = nullptr;

    public:
        ~BancoFuncionarios();
        void Contratar_Gerente(string Codigo, string Nome, string Email, string Senha);
        
        void Adicionar_Bibliotecario(string Nome, string Senha, string Email);
        void Demitir_Bibliotecario(int Id);
        void Listar_Bibliotecarios();

        Bibliotecario* getBibliotecario(string Email, string Senha);
        Gerente* getGerente(string Codigo, string Email, string Senha);
};

namespace BancoFuncionariosErros{
    struct Bibliotecario_Nao_Encontrado : public exception{
        const char* what() const throw(){
            return "Bibliotecario nao encontrado no banco de dados";
        }
    };

    struct Nenhum_Bibliotecario : public exception{
        const char* what() const throw(){
            return "Nenhum bibliotecario registrado no banco de dados";
        }
    };  

    struct Email_Utilizado : public exception{
        const char* what() const throw(){
            return "E-mail digitado ja esta em uso";
        }
    };
}

#endif