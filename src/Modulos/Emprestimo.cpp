#include "Emprestimo.hpp"

/**
 * @brief Construtor da classe Emprestimo.
 * @param Id O identificador do empréstimo.
 * @param Data_Aluguel A data de aluguel do livro.
 * @param Cliente O cliente que realizou o empréstimo.
 * @param Livro O livro alugado.
 */
Emprestimo::Emprestimo(int Id, Data Data_Aluguel, Cliente* Cliente, Livro* Livro){
    _Id = Id;
    _Data_Aluguel = Data_Aluguel;
    
    // Adiciona 7 dias à data de aluguel para obter a data de vencimento
    Data_Aluguel.Adicionar_Dias(7);
    _Data_Vencimento = Data_Aluguel;

    _Cliente = Cliente;
    _Livro = Livro;
}


Emprestimo::~Emprestimo(){
    cout << "Emprestimo quitado" << endl;
}


/**
 * @brief Aplica uma multa ao cliente caso o empréstimo esteja vencido.
 * @param Data A data atual.
 */
void Emprestimo::Aplicar_Multa(Data Data){
    // Converte a data atual para o formato tm
    tm tmData = {0};
    tmData.tm_year = Data.ano - 1900;
    tmData.tm_mon = Data.mes - 1;
    tmData.tm_mday = Data.dia;
    tmData.tm_hour = Data.hora;
    time_t DataAtual = mktime(&tmData);

    // Converte a data de vencimento do empréstimo para o formato tm
    tm tmDataVencimento = {0};
    tmDataVencimento.tm_year = _Data_Vencimento.ano - 1900;
    tmDataVencimento.tm_mon = _Data_Vencimento.mes - 1;
    tmDataVencimento.tm_mday = _Data_Vencimento.dia;
    tmDataVencimento.tm_hour = _Data_Vencimento.hora;
    time_t DataVencimento = mktime(&tmDataVencimento);

    // Verifica se o empréstimo está vencido e aplica a multa correspondente
    if(DataAtual == DataVencimento)
        _Cliente->Somar_Multa(5.60);
    else if(DataAtual > DataVencimento)
        _Cliente->Somar_Multa(0.60);
}


/**
 * @brief Prolonga a data de vencimento do empréstimo em mais 7 dias.
 * @note Esta função requer permissão 2 para ser executada.
 */
void Emprestimo::Prolongar_Emprestimo(){
    _Data_Vencimento.Adicionar_Dias(7);
}


void Emprestimo::Imprimir_Informacoes(){
    cout << "========================================" << endl;
    cout << "Emprestimo " << this->getId() << endl;
    cout << "Cliente: " << _Cliente->getNome() << " " << _Cliente->getId() << endl;
    cout << "Livro: " << _Livro->getNome() << " " << _Livro->getId() << endl;
    cout << "Data de Aluguel: " ; _Data_Aluguel.Imprimir_Data();
    cout << "Data de Vencimento: "; _Data_Vencimento.Imprimir_Data();
    cout << "========================================" << endl;
}


int Emprestimo::getId(){return _Id;}
Data Emprestimo::getDataAluguel(){return _Data_Aluguel;}
Data Emprestimo::getDataVencimento(){return _Data_Vencimento;}
Cliente* Emprestimo::getCliente(){return _Cliente;}
Livro* Emprestimo::getLivro(){return _Livro;}