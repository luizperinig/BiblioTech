#include "BancoFuncionarios.hpp"

BancoFuncionarios::~BancoFuncionarios(){
    for(auto&& i : _Bibliotecarios)
        delete i;
}

/**
 * @brief Cadastra um novo gerente no sistema.
 * @param Codigo O código do gerente.
 * @param Nome O nome do gerente.
 * @param Email O email do gerente.
 * @param Senha A senha do gerente.
 * @note Esta função requer permissão 0 para ser executada.
 */
void BancoFuncionarios::Contratar_Gerente(string Codigo, string Nome, string Email, string Senha){
    _Gerente = new Gerente(1, Codigo, Nome, Email, Senha);
    cout << "Gerente contratado com sucesso" << endl;
}


/**
 * @brief Adiciona um novo bibliotecário ao banco de funcionários. 
 * @param Nome O nome do bibliotecário.
 * @param Email O email do bibliotecário.
 * @param Senha A senha do bibliotecário.
 * @throws BancoFuncionariosErros::Email_Utilizado Se o email fornecido já estiver em uso.
 * @note Esta função requer permissão 3 para ser executada.
 */
void BancoFuncionarios::Adicionar_Bibliotecario(string Nome, string Email, string Senha){
    for(auto i : _Bibliotecarios)
        if(i->getEmail() == Email)
            throw BancoFuncionariosErros::Email_Utilizado();

    Bibliotecario* Bibliotecario_aux = new Bibliotecario(this->_Id, Nome, Email, Senha);

    _Bibliotecarios.push_back(Bibliotecario_aux);
    this->_Id++;
    cout << "Bibliotecario contratado com sucesso" << endl;
}


/**
 * @brief Remove um bibliotecário da lista com base no ID fornecido.
 * @param Id O ID do bibliotecário a ser demitido.
 * @throws BancoFuncionariosErros::Nenhum_Bibliotecario Se não houver bibliotecários cadastrados.
 * @throws BancoFuncionariosErros::Bibliotecario_Nao_Encontrado Se o bibliotecário com o ID fornecido não for encontrado.
 * @note É necessária a permissão 3 para executar esta função.
 */
void BancoFuncionarios::Demitir_Bibliotecario(int Id){
    if(_Bibliotecarios.size() == 0)
        throw BancoFuncionariosErros::Nenhum_Bibliotecario();

    list<Bibliotecario*>::iterator index = _Bibliotecarios.begin();

    for(; index != _Bibliotecarios.end(); ++index){
        if((*index)->getId() == Id){
            delete *index;
            _Bibliotecarios.erase(index);
            return;
        }    
    }

    throw BancoFuncionariosErros::Bibliotecario_Nao_Encontrado();
}


/**
 * @brief Imprime as informações de todos os bibliotecários da lista.
 * @throws BancoFuncionariosErros::Nenhum_Bibliotecario Se não houver bibliotecários cadastrados.
 * @note É necessária a permissão 3 para executar esta função.
 */
void BancoFuncionarios::Listar_Bibliotecarios(){
    if(_Bibliotecarios.size() == 0)
        throw BancoFuncionariosErros::Nenhum_Bibliotecario();

    list<Bibliotecario*>::iterator index = _Bibliotecarios.begin();
    
    for(; index != _Bibliotecarios.end(); ++index){
        (*index)->Imprimir_Informacoes();
    }
}


/**
 * @brief Retorna o ponteiro para um bibliotecário da lista com base no email e senha fornecidos.
 * @param Email O email do bibliotecário.
 * @param Senha A senha do bibliotecário.
 * @return O ponteiro para o bibliotecário encontrado. Retorna nullptr se nenhum bibliotecário corresponder às credenciais.
 */
Bibliotecario* BancoFuncionarios::getBibliotecario(string Email, string Senha){
    if(_Bibliotecarios.size() == 0){
        return nullptr;
    }
    else{
        Bibliotecario* aux = nullptr;

        list<Bibliotecario*>::iterator index = _Bibliotecarios.begin();
        for(; index != _Bibliotecarios.end(); ++index){
            if((*index)->getEmail() == Email && (*index)->getSenha() == Senha){
                aux =  *index;
                break;
            }    
        }

        return aux;
    }
}


/**
 * @brief Retorna o ponteiro para o gerente com base no código, email e senha fornecidos.
 * @param Codigo O código do gerente.
 * @param Email O email do gerente.
 * @param Senha A senha do gerente.
 * @return O ponteiro para o gerente encontrado. Retorna nullptr se as credenciais não corresponderem ao gerente.
 */
Gerente* BancoFuncionarios::getGerente(string Codigo, string Email, string Senha){
    if(_Gerente == nullptr)
        return nullptr;
    else{
        if(_Gerente->getCodigo() == Codigo && _Gerente->getEmail() == Email && _Gerente->getSenha() == Senha)
            return _Gerente;
        else
            return nullptr;
    }
}