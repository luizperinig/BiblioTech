#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro{
    private:
        int _Id;
        string _Nome;
        string _Genero;
        string _Nome_Editora;
        string _Nome_Autor;
        string _Data_Publicacao;

        double _Avaliacao_Final = 0;
        int _Quantidade_Leitores = 0;
        int _Quantidade_Buscas = 0;

        vector<int> _Avaliacoes;
        vector<int> _Avaliadores;

        bool _Disponivel = 1;

    public:
        Livro(int Id, string Nome, string Genero, string Nome_Autor, string Nome_Editora, string Data_Publicacao);
        ~Livro();

        void Imprimir_Informacoes();
        void Informar_Disponibilidade();
        void Calcular_Avaliacao(int Avaliacao);

        void Acrescentar_Leitores();
        void Acrescentar_Buscas();
        void Adicionar_Avaliador(int Id);

        bool getDisponibilidade();
        int getId();
        double getAvaliacao();
        int getLeitores();
        int getBuscas();
        string getNome();
        string getGenero();
        string getNomeEditora();
        string getNomeAutor();
        string getDataPublicacao();
        vector<int> getAvaliadores();

        void setNome(string Nome);
        void setGenero(string Genero);
        void setNomeEditora(string Nome_Editora);
        void setNomeAutor(string Nome_Autor);
        void setDataPublicacao(string Data_Publicacao);
        void setDisponibilidade();
};

#endif