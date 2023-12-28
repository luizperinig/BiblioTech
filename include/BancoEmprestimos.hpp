#ifndef BANCOEMPRESTIMOS_H
#define BANCOEMPRESTIMOS_H

#include <iostream>
#include <string>
#include <list>

#include "Emprestimo.hpp"
#include "Cliente.hpp"
#include "Livro.hpp"

using namespace std;

class BancoEmprestimos{
    private:
        int _Id = 1;
        list<Emprestimo*> _Emprestimos;

    public:
        ~BancoEmprestimos();
        
        void Listar_Emprestimos(int Permissao, int Id);
        void Criar_Emprestimo(Data Data_Aluguel, Cliente* Cliente, Livro* Livro);
        void Encerrar_Emprestimo(int Id);
        void Renovar_Emprestimo(int Id);
        void Checar_Multas(Data DataAtual);
};

namespace BancoEmprestimosErros{
    struct Emprestimo_Nao_Encontrado : public exception{
        const char* what() const throw(){
            return "Emprestimo não encontrado no banco de dados";
        }
    };

    struct Nenhum_Emprestimo : public exception{
        const char* what() const throw(){
            return "Nenhum emprestimo registrado no banco de dados";
        }
    };  

    struct Livro_Indisponivel : public exception{
        const char* what() const throw(){
            return "Livro indisponivel para aluguel";
        }
    };

    struct Limite_Livros : public exception{
        const char* what() const throw(){
            return "Limite de livros alugados atingido";
        }
    };
}

#endif