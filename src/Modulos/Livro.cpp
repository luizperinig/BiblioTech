#include "Livro.hpp"

/**
 * @brief Construtor da classe Livro.
 * @param Id O ID do livro.
 * @param Nome O nome do livro.
 * @param Genero O gênero do livro.
 * @param Nome_Autor O nome do autor do livro.
 * @param Nome_Editora O nome da editora do livro.
 * @param Data_Publicacao A data de publicação do livro.
 */
Livro::Livro(int Id, string Nome, string Genero, string Nome_Autor, string Nome_Editora, string Data_Publicacao){
    _Id = Id;
    _Nome = Nome;
    _Genero = Genero;
    _Nome_Autor = Nome_Autor;
    _Nome_Editora = Nome_Editora;
    _Data_Publicacao = Data_Publicacao;
}


Livro::~Livro(){
    cout << "Livro Removido" << endl;
}

/**
 * @brief Imprime as informações do livro.
 */
void Livro::Imprimir_Informacoes(){
    cout << "==============================" << endl;
    cout << "Livro " << this->getId() << endl;
    cout << "Nome: " << this->getNome() << endl;
    cout << "Genereo: " << this->getGenero() << endl;
    cout << "Autor: " << this->getNomeAutor() << endl;
    cout << "Editora: " << this->getNomeEditora() << endl;
    cout << "Publicado em " << this->getDataPublicacao() << endl;
    this->Informar_Disponibilidade();
    cout << this->getAvaliacao() << " estrelas" << endl;
    cout << this->getAvaliadores().size() << " avaliacoes" << endl;
    cout << this->getBuscas() << " pesquisaram por este livro" << endl;
    cout << this->getLeitores() << " alugaram este livro" << endl;
    cout << "==============================" << endl;
}


/**
 * @brief Adiciona uma avaliação ao vetor e calcula a média.
 * @param Avaliacao A avaliação a ser adicionada.
 */
void Livro::Calcular_Avaliacao(int Avaliacao){
    _Avaliacoes.push_back(Avaliacao);

    int soma = 0;
    for(unsigned int i = 0; i < _Avaliacoes.size(); i++)
        soma += _Avaliacoes[i];
    
    _Avaliacao_Final = static_cast<double>(soma) / _Avaliacoes.size();
}


/**
 * @brief Informa se o livro está disponível para aluguel.
 */
void Livro::Informar_Disponibilidade(){
    if(_Disponivel == true)
        cout << "Disponivel para aluguel" << endl;
    else
        cout << "Indisponivel para aluguel" << endl;
}


/**
 * @brief Aumenta a quantidade de usuários que pesquisaram por este livro.
 */
void Livro::Acrescentar_Buscas(){
    _Quantidade_Buscas++;
}


/**
 * @brief Aumenta a quantidade de usuários que alugaram este livro.
 */
void Livro::Acrescentar_Leitores(){
    _Quantidade_Leitores++;    
}


/**
 * @brief Adiciona um avaliador ao vetor de avaliadores.
 * @param Id O ID do avaliador a ser adicionado.
 */
void Livro::Adicionar_Avaliador(int Id){
    _Avaliadores.push_back(Id);
}


bool Livro::getDisponibilidade(){return _Disponivel;}
int Livro::getId(){return _Id;}
int Livro::getLeitores(){return _Quantidade_Leitores;}
int Livro::getBuscas(){return _Quantidade_Buscas;}
double Livro::getAvaliacao(){return _Avaliacao_Final;}
string Livro::getNome(){return _Nome;}
string Livro::getGenero(){return _Genero;}
string Livro::getNomeEditora(){return _Nome_Editora;}
string Livro::getNomeAutor(){return _Nome_Autor;}
string Livro::getDataPublicacao(){return _Data_Publicacao;}
vector<int> Livro::getAvaliadores(){return _Avaliadores;}

void Livro::setNome(string Nome){_Nome = Nome;}
void Livro::setGenero(string Genero){_Genero = Genero;}
void Livro::setNomeEditora(string Nome_Editora){_Nome_Editora = Nome_Editora;}
void Livro::setNomeAutor(string Nome_Autor){_Nome_Autor = Nome_Autor;}
void Livro::setDataPublicacao(string Data_Publicacao){_Data_Publicacao = Data_Publicacao;}
void Livro::setDisponibilidade(){_Disponivel = !_Disponivel;}