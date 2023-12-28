#ifndef BANCOClienteS_H
#define BANCOClienteS_H

#include <iostream>
#include <string>
#include <list>

#include "Cliente.hpp"

using namespace std;

class BancoClientes{
    private:
        int _Id = 1;
        list<Cliente*> _Clientes;

    public:
        ~BancoClientes();
        void Adicionar_Cliente(string Nome, string Email, string Senha, string Cpf);
        void Banir_Cliente(int Id);
        void Listar_Clientes();

        Cliente* getCliente(string Email, string Senha);
        Cliente* getCliente(int Id);
};

namespace BancoClientesErros{
    struct Cliente_Nao_Encontrado : public exception{
        const char* what() const throw(){
            return "Cliente nao encontrado no banco de dados";
        }
    };

    struct Nenhum_Cliente : public exception{
        const char* what() const throw(){
            return "Nenhum cliente registrado no banco de dados";
        }
    };  

    struct Email_Utilizado : public exception{
        const char* what() const throw(){
            return "E-mail digitado ja esta em uso";
        }
    };
}

#endif