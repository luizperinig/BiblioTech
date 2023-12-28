#include "BancoClientes.hpp"

BancoClientes::~BancoClientes(){
    for(auto&& i : _Clientes)
        delete i;
}

/**
 * @brief Cria um novo objeto Cliente* e o adiciona na lista de clientes.
 * @param Nome O nome do cliente.
 * @param Email O email do cliente.
 * @param Senha A senha do cliente.
 * @param Cpf O CPF do cliente.
 * @return Nenhum valor de retorno.
 * @throws BancoClientesErros::Email_Utilizado Se o email fornecido já estiver sendo utilizado por outro cliente.
 * @note Esta função requer permissão 2 para ser executada.
 */
void BancoClientes::Adicionar_Cliente(string Nome, string Email, string Senha, string Cpf){
    for(auto i : _Clientes)
        if(i->getEmail() == Email){
            throw BancoClientesErros::Email_Utilizado();
        }

    Cliente* Cliente_aux = new Cliente(this->_Id,  Nome, Email, Senha, Cpf);

    _Clientes.push_back(Cliente_aux);
    this->_Id++;
    cout << "Cliente adicionado com sucesso" << endl;
}


/**
 * @brief Remove um cliente da lista dado o Id passado.
 * @param Id O Id do cliente a ser banido.
 * @return Nenhum valor de retorno.
 * @throws BancoClientesErros::Nenhum_Cliente Se a lista de clientes estiver vazia.
 * @throws BancoClientesErros::Cliente_Nao_Encontrado Se nenhum cliente com o Id fornecido for encontrado.
 * @note Esta função requer permissão 2 para ser executada.
 */
void BancoClientes::Banir_Cliente(int Id){
    if(_Clientes.size() == 0)
        throw BancoClientesErros::Nenhum_Cliente();
    
    list<Cliente*>::iterator index = _Clientes.begin();

    for(; index != _Clientes.end(); ++index){
        if((*index)->getId() == Id){
            delete *index;
            _Clientes.erase(index);
            return;
        }    
    }

    throw BancoClientesErros::Cliente_Nao_Encontrado();
}


/**
 * @brief Imprime as informações de todos os clientes da lista.
 * @return Nenhum valor de retorno.
 * @throws BancoClientesErros::Nenhum_Cliente Se a lista de clientes estiver vazia.
 * @note Esta função requer permissão 2 para ser executada.
 */
void BancoClientes::Listar_Clientes(){
    if(_Clientes.size() == 0)
        throw BancoClientesErros::Nenhum_Cliente();

    list<Cliente*>::iterator index = _Clientes.begin();
    
    for(; index != _Clientes.end(); ++index)
        (*index)->Imprimir_Informacoes();
}


/**
 * @brief Retorna o ponteiro para um cliente da lista pelo email e senha.
 * @param Email O email do cliente.
 * @param Senha A senha do cliente.
 * @return Um ponteiro para o cliente encontrado ou nullptr se nenhum cliente corresponder ao email e senha fornecidos.
 */
Cliente* BancoClientes::getCliente(string Email, string Senha){
    if(_Clientes.size() == 0){
        return nullptr;
    }
    else{
        Cliente* aux = nullptr;

        list<Cliente*>::iterator index = _Clientes.begin();
        for(; index != _Clientes.end(); ++index){
            if((*index)->getEmail() == Email && (*index)->getSenha() == Senha){
                aux = *index;
                break;
            }    
        }

        return aux;
    }
}


/**
 * @brief Retorna o ponteiro para um cliente da lista pelo Id.
 * @param Id O Id do cliente.
 * @return Um ponteiro para o cliente encontrado ou nullptr se nenhum cliente corresponder ao Id fornecido.
 */
Cliente* BancoClientes::getCliente(int Id){
    if(_Clientes.size() == 0){
        return nullptr;
    }
    else{
        Cliente* aux = nullptr;

        list<Cliente*>::iterator index = _Clientes.begin();
        for(; index != _Clientes.end(); ++index){
            if((*index)->getId() == Id){
                aux = *index;
                break;
            }    
        }

        return aux;
    }
}