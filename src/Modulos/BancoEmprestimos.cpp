#include "BancoEmprestimos.hpp"

BancoEmprestimos::~BancoEmprestimos(){
    for(auto&& i : _Emprestimos)
        delete i;
}

/**
 * @brief Cria um empréstimo que relaciona um Cliente* e um Livro*.
 * @param Data_Aluguel A data de aluguel do livro.
 * @param Cliente Um ponteiro para o cliente que está realizando o empréstimo.
 * @param Livro Um ponteiro para o livro que está sendo emprestado.
 * @throws BancoEmprestimosErros::Livro_Indisponivel se o livro não estiver disponível para empréstimo.
 * @throws BancoEmprestimosErros::Limite_Livros se o cliente já tiver alugado o máximo de livros permitido.
 */
void BancoEmprestimos::Criar_Emprestimo(Data Data_Aluguel, Cliente* Cliente, Livro* Livro){
    if(Livro->getDisponibilidade() == false)
        throw BancoEmprestimosErros::Livro_Indisponivel();
    
    Emprestimo* Emprestimo_aux = new Emprestimo(this->_Id, Data_Aluguel, Cliente, Livro);

    if(Emprestimo_aux->getCliente()->getLivrosAlugados() == 3)
        throw BancoEmprestimosErros::Limite_Livros();
    
    Emprestimo_aux->getCliente()->Alugar_Livro(Livro);
    Emprestimo_aux->getLivro()->Acrescentar_Leitores();
    Emprestimo_aux->getLivro()->setDisponibilidade();

    _Emprestimos.push_back(Emprestimo_aux);

    this->_Id++;
    cout << "Emprestimo criado com sucesso" << endl;
}


/**
 * @brief Remove um empréstimo do banco de dados.
 * @param Id O ID do empréstimo a ser encerrado.
 * @throws BancoEmprestimosErros::Nenhum_Emprestimo se não houver empréstimos no banco de dados.
 * @throws BancoEmprestimosErros::Emprestimo_Nao_Encontrado se o empréstimo com o ID especificado não for encontrado.
 * @note Esta função requer permissão 2 para ser executada.
 */
void BancoEmprestimos::Encerrar_Emprestimo(int Id){
    if(_Emprestimos.size() == 0)
        throw BancoEmprestimosErros::Nenhum_Emprestimo();
  
    list<Emprestimo*>::iterator index = _Emprestimos.begin();

    for(; index != _Emprestimos.end(); ++index){
        if((*index)->getId() == Id){
            (*index)->getCliente()->Adicionar_Historico(*(*index)->getLivro());
            
            delete *index;
            _Emprestimos.erase(index);
            return;
        }    
    }

    throw BancoEmprestimosErros::Emprestimo_Nao_Encontrado();
}


/**
 * @brief Adiciona mais sete dias à duração do empréstimo.
 * @param Id O ID do empréstimo a ser renovado.
 * @throws BancoEmprestimosErros::Nenhum_Emprestimo se não houver empréstimos no banco de dados.
 * @throws BancoEmprestimosErros::Emprestimo_Nao_Encontrado se o empréstimo com o ID especificado não for encontrado.
 * @note Esta função requer permissão 2 para ser executada.
 */
void BancoEmprestimos::Renovar_Emprestimo(int Id){
    if(_Emprestimos.size() == 0)
        throw BancoEmprestimosErros::Nenhum_Emprestimo();

    list<Emprestimo*>::iterator index = _Emprestimos.begin();

    for(; index != _Emprestimos.end(); ++index){
        if((*index)->getId() == Id){
            (*index)->Prolongar_Emprestimo();
            return;
        }    
    }

    throw BancoEmprestimosErros::Emprestimo_Nao_Encontrado();
}


/**
 * @brief Imprime as informações de todos os empréstimos da lista.
 * @param Permissao O nível de permissão do usuário.
 * @param Id O ID do cliente (apenas usado se o nível de permissão for menor ou igual a 1).
 * @throws BancoEmprestimosErros::Nenhum_Emprestimo se não houver empréstimos no banco de dados.
 * @throws ClienteErros::Nenhum_Livro_Alugado se o cliente com o ID especificado não tiver nenhum livro alugado.
 * @note Esta função requer permissão acima de 0 para ser executada.
 */
void BancoEmprestimos::Listar_Emprestimos(int Permissao, int Id){
    if(Permissao > 1){
        if(_Emprestimos.size() == 0)
            throw BancoEmprestimosErros::Nenhum_Emprestimo();

        for(auto i : _Emprestimos)
            i->Imprimir_Informacoes();
    }
        
    else{
        bool aux = false;

        for(auto i : _Emprestimos)
            if(i->getCliente()->getId() == Id){
                i->Imprimir_Informacoes();
                aux = true;
            }
        
        if(aux == false)
            throw ClienteErros::Nenhum_Livro_Alugado();
    }
}


/**
 * @brief Checa se algum empréstimo passou da data de vencimento e aplica a multa no cliente.
 * @param DataAtual A data atual para comparação.
 */
void BancoEmprestimos::Checar_Multas(Data DataAtual){
    for(auto i : _Emprestimos)
        i->Aplicar_Multa(DataAtual);
}