#ifndef ACERVO_H
#define ACERVO_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "Livro.hpp"

using namespace std;

class Acervo{
    private:
        int _Id = 1;
        list<Livro*> _Livros;

    public:
        ~Acervo();
        void Adicionar_Livro(string Nome, string Genero, string Nome_Autor, string Nome_Editora, string Data_Publicacao);
        void Remover_Livro(int Id);
        void Editar_Livro(int Id, string Nome, string Genero, string Nome_Autor, string Nome_Editora, string Data_Publicacao);

        void Listar_Acervo();
        void Pesquisar_Nome(string Nome);
        void Pesquisar_Autor(string Autor);
        void Organizar_Avaliacao();
        void Organizar_Leitores();
        void Organizar_Buscas();
        void Preencher_Acervo();

        Livro* getLivro(int Id);
};

namespace AcervoErros{
    struct Livro_Nao_Encontrado : public exception{
        const char* what() const throw(){
            return "Livro nao encontrado no banco de dados";
        }
    };

    struct Nenhum_Livro : public exception{
        const char* what() const throw(){
            return "Nenhum livro registrado no banco de dados";
        }
    };  
}

#endif