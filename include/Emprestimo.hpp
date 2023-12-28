#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <iostream>
#include <string>

#include "Cliente.hpp"
#include "Livro.hpp"
#include "Data.hpp"

using namespace std;

class Emprestimo{
    private:
        int _Id;
        Data _Data_Aluguel;
        Data _Data_Vencimento;

        Cliente* _Cliente;
        Livro* _Livro;

    public:
        Emprestimo(int Id, Data Data_Aluguel, Cliente* Cliente, Livro* Livro);
        ~Emprestimo();

        void Aplicar_Multa(Data Data);
        void Imprimir_Informacoes();
        void Prolongar_Emprestimo();

        int getId();
        Data getDataAluguel();
        Data getDataVencimento();
        Cliente* getCliente();
        Livro* getLivro();
};

#endif