#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>

#include "Cliente.hpp"
#include "BancoFuncionarios.hpp"
#include "BancoClientes.hpp"
#include "Bibliotecario.hpp"
#include "Gerente.hpp"

using namespace std;

class Login{
    private:
        Cliente* _Cliente = nullptr;
        Bibliotecario* _Bibliotecario = nullptr;
        Gerente* _Gerente = nullptr;
        
    public:
        ~Login();
        void Login_Cliente(BancoClientes* Clientes, string Email, string Senha);                            //Logar como Cliente
        void Login_Bibliotecario(BancoFuncionarios* Funcionarios, string email, string Senha);              //Logar como Bibliotecário
        void Login_Gerente(BancoFuncionarios* Funcionarios, string Codigo, string email,  string Senha);    //Logar como Gerente

        int Checar_Logado();
        void Logout();

        Usuario* getLogado();
};

namespace LoginErros{
    struct Ninguem_Logado : public exception{
        const char* what() const throw(){
            return "Nenhum usuario logado no sistema";
        }
    }; 

    struct Ja_Logado : public exception{
        const char* what() const throw(){
            return "Ja esta logado no sistema";
        }
    }; 

    struct Credenciais_Incorretas : public exception{
        const char* what() const throw(){
            return "E-mail ou senha inseridos incorretos";
        }
    };

    struct Permissao_Negada : public exception{
        const char* what() const throw(){
            return "Voce nao tem permissao para fazer isso";
        }
    };
}

#endif