#include "Bibliotecario.hpp"

Bibliotecario::Bibliotecario(int Id, string Nome, string Email, string Senha) : Usuario (Id, Nome, Email, Senha){}

Bibliotecario::~Bibliotecario(){
    cout << "Bibliotecario demitido" << endl;
}

/**
 * @brief Imprime as informações deste bibliotecário.
 */
void Bibliotecario::Imprimir_Informacoes(){
    cout << "====================" << endl;
    cout << "Bibliotecario " << this->getId() << endl;
    Usuario::Imprimir_Informacoes();
    cout << "====================" << endl;
}


/**
 * @brief Edita as informações deste bibliotecário.
 * 
 * @param Nome O novo nome do bibliotecário.
 * @param Email O novo email do bibliotecário.
 * @param Senha A nova senha do bibliotecário.
 */
void Bibliotecario::Editar_Informacoes(string Nome, string Email, string Senha){
    this->setNome(Nome);
    this->setEmail(Email);
    this->setSenha(Senha);

    cout << "Informacoes editadas com sucesso" << endl;
}