#include "Login.hpp"

Login::~Login(){
    cout << "Login limpo" << endl;
}

/**
 * @brief Verifica se há algum usuário logado no sistema.
 *
 * Esta função verifica se há um cliente, bibliotecário ou gerente logado no sistema e retorna um valor correspondente:
 *  - 1: Cliente logado.
 *  - 2: Bibliotecário logado.
 *  - 3: Gerente logado.
 *  - 0: Nenhum usuário logado.
 *
 * @return O valor correspondente ao tipo de usuário logado no sistema.
 */
int Login::Checar_Logado(){
    if(_Cliente != nullptr)
        return 1;
    else if(_Bibliotecario != nullptr)
        return 2;
    else if(_Gerente != nullptr)
        return 3;
    else
        return 0;
}


/**
 * @brief Retorna um ponteiro para o usuário logado no sistema.
 * @return Um ponteiro para o usuário logado no sistema.
 */
Usuario* Login::getLogado(){
    if(_Cliente != nullptr)
        return _Cliente;
    if(_Bibliotecario != nullptr)
        return _Bibliotecario;
    if(_Gerente != nullptr)
        return _Gerente;
    else
        return nullptr;
}


/**
 * @brief Realiza o login de um cliente no sistema.
 * @param Clientes Um ponteiro para o banco de clientes.
 * @param Email O email do cliente para o login.
 * @param Senha A senha do cliente para o login.
 * @throws Ja_Logado Caso já haja algum usuário logado no sistema.
 * @throws Credenciais_Incorretas Caso as credenciais de login sejam incorretas.
 */
void Login::Login_Cliente(BancoClientes* Clientes, string Email, string Senha){
    if(this->Checar_Logado() != 0)
        throw LoginErros::Ja_Logado();

    Cliente* Cliente_aux = Clientes->getCliente(Email, Senha);

    if(Cliente_aux == nullptr)
        throw LoginErros::Credenciais_Incorretas();

    _Cliente = Cliente_aux;
    cout << "Bem-vindo(a) " << this->_Cliente->getNome() << "!" << endl;
}


/**
 * @brief Realiza o login de um bibliotecário no sistema.
 * @param Funcionarios Um ponteiro para o banco de funcionários.
 * @param Email O email do bibliotecário para o login.
 * @param Senha A senha do bibliotecário para o login.
 * @throws Ja_Logado Caso já haja algum usuário logado no sistema.
 * @throws Credenciais_Incorretas Caso as credenciais de login sejam incorretas.
 */
void Login::Login_Bibliotecario(BancoFuncionarios* Funcionarios, string Email, string Senha){
    if(this->Checar_Logado() != 0)
        throw LoginErros::Ja_Logado();
  
    Bibliotecario* Bibliotecario_aux = Funcionarios->getBibliotecario(Email, Senha);

    if(Bibliotecario_aux == nullptr)
        throw LoginErros::Credenciais_Incorretas();
    
    _Bibliotecario = Bibliotecario_aux;
    cout << "Conectado como " << this->_Bibliotecario->getNome() << endl;
}


/**
 * @brief Realiza o login de um gerente no sistema.
 * @param Funcionarios Um ponteiro para o banco de funcionários.
 * @param Codigo O código do gerente para o login.
 * @param Email O email do gerente para o login.
 * @param Senha A senha do gerente para o login.
 * @throws Ja_Logado Caso já haja algum usuário logado no sistema.
 * @throws Credenciais_Incorretas Caso as credenciais de login sejam incorretas.
 */
void Login::Login_Gerente(BancoFuncionarios* Funcionarios, string Codigo, string Email, string Senha){
    if(this->Checar_Logado() != 0)
        throw LoginErros::Ja_Logado();

    Gerente* Gerente_aux = Funcionarios->getGerente(Codigo, Email, Senha);

    if(Gerente_aux == nullptr)
        throw LoginErros::Credenciais_Incorretas();
    
    _Gerente = Gerente_aux;
    cout << "Conectado como " << this->_Gerente->getNome() << endl;
}


/**
 * @brief Desloga o usuário que estiver logado no sistema.
 * @throws Ninguem_Logado Caso não haja nenhum usuário logado no sistema.
 */
void Login::Logout(){
    if(this->Checar_Logado() == 0)
        throw LoginErros::Ninguem_Logado();
    
    _Cliente = nullptr;
    _Gerente = nullptr;
    _Bibliotecario = nullptr;
    cout << "Logout realizado com sucesso" << endl;
}