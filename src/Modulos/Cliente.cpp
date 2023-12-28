#include "Cliente.hpp"

/**
 * @brief Construtor da classe Cliente.
 * @param Id O ID do cliente.
 * @param Nome O nome do cliente.
 * @param Email O email do cliente.
 * @param Senha A senha do cliente.
 * @param Cpf O CPF do cliente.
 * @throws ClienteErros::Cpf_Invalido Se o CPF fornecido não estiver no formato válido.
 */
Cliente::Cliente(int Id, string Nome, string Email, string Senha, string Cpf) : Usuario(Id, Nome, Email, Senha){
    regex cpf_modelo(R"(\d{3}\.\d{3}\.\d{3}-\d{2})");

    if(!regex_match(Cpf, cpf_modelo))
        throw ClienteErros::Cpf_Invalido();

    _Cpf = Cpf;
}


Cliente::~Cliente(){
    cout << "Cliente removido" << endl;
}


/**
 * @brief Imprime as informações deste cliente.
 */
void Cliente::Imprimir_Informacoes(){
    cout << "====================" << endl;
    cout << "Cliente " << this->getId() << endl;
    cout << "CPF: " << this->getCpf() << endl;
    Usuario::Imprimir_Informacoes();
    cout << "Multa: " << this->getMulta() << endl;
    cout << "Livros Alugados: " << this->getLivrosAlugados() << endl;
    cout << "====================" << endl;
}


/**
 * @brief Edita as informações deste cliente.
 * @param Nome O novo nome do cliente.
 * @param Email O novo email do cliente.
 * @param Senha A nova senha do cliente.
 */
void Cliente::Editar_Informacoes(string Nome, string Email, string Senha){
    this->setNome(Nome);
    this->setEmail(Email);
    this->setSenha(Senha);

    cout << "Informacoes editadas com sucesso" << endl;
}


/**
 * @brief Imprime as informações de cada livro que já foi lido pelo cliente.
 * @throws ClienteErros::Nenhum_Livro_Alugado Se nenhum livro tiver sido alugado pelo cliente.
 * @note Esta função requer permissão 1 para ser executada.
 */
void Cliente::Mostrar_Historico(){
    if(_Livros_Lidos.size() == 0)
        throw ClienteErros::Nenhum_Livro_Alugado();
    
    list<Livro>::iterator index = _Livros_Lidos.begin();
    for(; index != _Livros_Lidos.end(); ++index){
        (*index).Imprimir_Informacoes();
    }
}


/**
 * @brief Imprime as informações de todos os livros que o cliente tem alugado.
 * @throws ClienteErros::Nenhum_Livro_Alugado Se o cliente não tiver nenhum livro alugado.
 * @note Esta função requer permissão 1 para ser executada.
 */
void Cliente::Mostrar_Livros(){
    if(_Livros_Alugados.size() == 0)
        throw ClienteErros::Nenhum_Livro_Alugado();
    
    list<Livro*>::iterator index = _Livros_Alugados.begin();
    for(; index != _Livros_Alugados.end(); ++index){
        (*index)->Imprimir_Informacoes();
    }
}


/**
 * @brief Adiciona um livro à lista de livros alugados pelo cliente.
 * @param Livro O ponteiro para o livro a ser alugado.
 * @note Esta função requer permissão 1 para ser executada.
 */
void Cliente::Alugar_Livro(Livro* Livro){
    _Livros_Alugados.push_back(Livro);
}


/**
 * @brief Adiciona um livro ao histórico de livros lidos pelo cliente.
 * @param Livro O livro a ser adicionado ao histórico.
 */
void Cliente::Adicionar_Historico(Livro Livro){
    _Livros_Lidos.push_back(Livro);
}


/**
 * @brief Avalia um livro que o cliente possui alugado.
 * @param Id O ID do livro a ser avaliado.
 * @param Avaliacao A avaliação atribuída ao livro (entre 0 e 5).
 * @throws ClienteErros::Nenhum_Livro_Alugado Se o cliente não tiver nenhum livro alugado.
 * @throws ClienteErros::Avaliacao_Invalida Se a avaliação fornecida estiver fora do intervalo válido.
 * @throws ClienteErros::Livro_Ja_Avaliado Se o cliente já tiver avaliado o livro.
 * @throws ClienteErros::Livro_Nao_Alugado Se o livro especificado não estiver alugado pelo cliente.
 * \note Esta função requer permissão 1 para ser executada.
 */
void Cliente::Avaliar_Livro(int Id, int Avaliacao){
    if(_Livros_Alugados.size() == 0)
        throw ClienteErros::Nenhum_Livro_Alugado();

    if(Avaliacao < 0 || Avaliacao > 5)
        throw ClienteErros::Avaliacao_Invalida();

    list<Livro*>::iterator index = _Livros_Alugados.begin();

    for(; index != _Livros_Alugados.end(); ++index){
        if((*index)->getId() == Id){
            for(auto i : (*index)->getAvaliadores())
                if(i == this->getId())
                    throw ClienteErros::Livro_Ja_Avaliado();
            
            (*index)->Calcular_Avaliacao(Avaliacao);
            (*index)->Adicionar_Avaliador(this->getId());

            cout << "Livro avaliado!" << endl;
            return;
        }   
    }

    throw ClienteErros::Livro_Nao_Alugado();
}


/**
 * @brief Soma um valor à multa deste cliente.
 * @param Multa O valor a ser adicionado à multa do cliente.
 */
void Cliente::Somar_Multa(double Multa){
    _Multa += Multa;
}


/**
 * @brief Quita a multa que este cliente possui, zerando o valor da multa.
 */
void Cliente::Quitar_Multa(){
    _Multa = 0;
}


string Cliente::getCpf(){return _Cpf;}
int Cliente::getLivrosAlugados(){return _Livros_Alugados.size();}
double Cliente::getMulta(){return _Multa;}