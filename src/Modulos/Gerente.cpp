#include "Gerente.hpp"

/**
 * @brief Construtor da classe Gerente.
 * @param Id O ID do gerente.
 * @param Codigo O código do gerente.
 * @param Nome O nome do gerente.
 * @param Email O email do gerente.
 * @param Senha A senha do gerente.
 * @throws GerenteErros::Codigo_Invalido se o código tiver menos de 12 caracteres.
 */
Gerente::Gerente(int Id, string Codigo, string Nome, string Email, string Senha) : Usuario(Id, Nome, Email, Senha){
    if(Codigo.size() < 12)
        throw GerenteErros::Codigo_Invalido();
        
    _Codigo = Codigo;
}


Gerente::~Gerente(){
    cout << "Gerente demitido" << endl;
}


/**
 * @brief Imprime as informações do gerente.
 */
void Gerente::Imprimir_Informacoes(){
    cout << "====================" << endl;
    cout << "Gerente" << endl;
    Usuario::Imprimir_Informacoes();
    cout << "Codigo: " << this->getCodigo() << endl;
    cout << "====================" << endl;
}


/**
 * @brief Edita as informações do gerente.
 * @param Nome O novo nome do gerente.
 * @param Email O novo email do gerente.
 * @param Senha A nova senha do gerente.
 */
void Gerente::Editar_Informacoes(string Nome, string Email, string Senha){
    this->setNome(Nome);
    this->setEmail(Email);
    this->setSenha(Senha);

    cout << "Informacoes editadas com sucesso" << endl;
}


string Gerente::getCodigo(){return _Codigo;}