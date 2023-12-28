#include "Usuario.hpp"

/**
 * @brief Construtor da classe Usuario.
 * @param Id O ID do usuário.
 * @param Nome O nome do usuário.
 * @param Email O email do usuário.
 * @param Senha A senha do usuário.
 * @throws Email_Invalido Caso o formato do email seja inválido.
 * @throws Senha_Invalida Caso o formato da senha seja inválido.
 */
Usuario::Usuario(int Id, string Nome, string Email, string Senha){
    regex email_modelo("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");
    regex senha_modelo(".{5,20}");

    if(!regex_match(Email, email_modelo))
        throw UsuarioErros::Email_Invalido();

    if(!regex_match(Senha, senha_modelo))
        throw UsuarioErros::Senha_Invalida();

    _Id = Id;
    _Nome = Nome;
    _Email = Email;
    _Senha = Senha;
}

Usuario::~Usuario(){}

/**
 * @brief Imprime as informações do usuário.
 */
void Usuario::Imprimir_Informacoes(){
    cout << "Nome: " << _Nome << endl;
    cout << "Email: " << _Email << endl;
    cout << "Senha: " << _Senha << endl;
}


int Usuario::getId(){return _Id;}
string Usuario::getNome(){return _Nome;}
string Usuario::getEmail(){return _Email;}
string Usuario::getSenha(){return _Senha;}

void Usuario::setNome(string Nome){_Nome = Nome;}
void Usuario::setSenha(string Senha){_Senha = Senha;}
void Usuario::setEmail(string Email){_Email = Email;}