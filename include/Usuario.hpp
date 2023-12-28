#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Usuario{
    private:
        int _Id;
        string _Nome;
        string _Email;
        string _Senha;

    public:
        Usuario(int Id, string Nome, string Email, string Senha);
        virtual ~Usuario();
        
        virtual void Imprimir_Informacoes();
        virtual void Editar_Informacoes(string Nome, string Email, string Senha) = 0;

        int getId();
        string getNome();
        string getEmail();
        string getSenha();

        void setNome(string Nome);
        void setEmail(string Email);
        void setSenha(string Senha);
};

namespace UsuarioErros{
    struct Email_Invalido : public exception{
        const char* what() const throw(){
            return "E-mail digitado é invalido";
        }
    };

    struct Senha_Invalida : public exception{
        const char* what() const throw(){
            return "Senha digitada e invalida";
        }
    };     
}

#endif