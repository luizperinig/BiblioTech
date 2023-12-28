#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <list>

#include "Livro.hpp"
#include "Usuario.hpp"

using namespace std;

class Cliente : public Usuario{
    private:
        string _Cpf;
        double _Multa = 0.0;

        list<Livro*> _Livros_Alugados;
        list<Livro> _Livros_Lidos;

    public:
        Cliente(int Id, string Nome, string Email, string Senha, string Cpf);
        virtual ~Cliente();

        virtual void Imprimir_Informacoes();
        void Editar_Informacoes(string Nome, string Email, string Senha) override;

        void Mostrar_Historico();
        void Mostrar_Livros();
        void Adicionar_Historico(Livro Livro);

        void Somar_Multa(double Multa);
        void Quitar_Multa();
        void Alugar_Livro(Livro* Livro);
        void Avaliar_Livro(int Id, int Avaliacao);
        
        string getCpf();
        int getLivrosAlugados();
        double getMulta();
};

namespace ClienteErros{
    struct Cpf_Invalido : public exception{
        const char* what() const throw(){
            return "Cpf digitado e invalido";
        }
    };

    struct Nenhum_Livro_Alugado : public exception{
        const char* what() const throw(){
            return "Nenhum livro alugado no momento";
        }
    };

    struct Historico_Vazio : public exception{
        const char* what() const throw(){
            return "Nenhum livro foi alugado antes";
        }
    };

    struct Livro_Ja_Avaliado : public exception{
        const char* what() const throw(){
            return "Voce ja avaliou este livro";
        }
    };

    struct Avaliacao_Invalida : public exception{
        const char* what() const throw(){
            return "Avaliacao invalida";
        }
    };

    struct Livro_Nao_Alugado : public exception{
        const char* what() const throw(){
            return "Este livro nao foi alugado por voce";
        }
    };    

}

#endif