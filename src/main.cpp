#include "Login.hpp"
#include "Acervo.hpp"
#include "BancoClientes.hpp"
#include "BancoEmprestimos.hpp"
#include "BancoFuncionarios.hpp"

using namespace std;

int main(){
    Acervo* Livros = new Acervo;
    BancoFuncionarios* Funcionarios = new BancoFuncionarios;
    BancoClientes* Clientes = new BancoClientes;
    BancoEmprestimos* Emprestimos = new BancoEmprestimos;
    Login* _Login = new Login;
    
    Data Data;
    Data.Data_Atual();

    string input;
    string nome, email, senha, genero, nomeEditora, nomeAutor, dataPublicacao, codigo, cpf, confirmacao;
    int id, avaliacao;

    cout << "Digite um comando" << endl;
    while(getline(cin, input))
    {
        try{
            if(input == "mostrar meus dados"){
                if(_Login->Checar_Logado() == 0)
                   throw LoginErros::Ninguem_Logado();
                
                _Login->getLogado()->Imprimir_Informacoes();
            }

            else if(input == "editar meus dados"){
                if(_Login->Checar_Logado() == 0)
                    throw LoginErros::Ninguem_Logado();
                
                if(_Login->Checar_Logado() == 1){
                    cout << endl << "Editando informacoes de cliente..." << endl;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Email: ";
                    cin >> email;
                    cout << "Senha: ";
                    cin >> senha;

                    Cliente* aux = dynamic_cast<Cliente*>(_Login->getLogado());
                    aux->Editar_Informacoes(nome, email, senha);
                    
                }

                if(_Login->Checar_Logado() == 2){
                    cout << endl << "Editando informacoes de bibliotecario..." << endl;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Email: ";
                    cin >> email;
                    cout << "Senha: ";
                    cin >> senha;

                    Bibliotecario* aux = dynamic_cast<Bibliotecario*>(_Login->getLogado());
                    aux->Editar_Informacoes(nome, email, senha);
                }

                if(_Login->Checar_Logado() == 3){
                    cout << endl << "Editando informacoes do gerente..." << endl;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Email: ";
                    cin >> email;
                    cout << "Senha: ";
                    cin >> senha;

                    Gerente* aux = dynamic_cast<Gerente*>(_Login->getLogado());
                    aux->Editar_Informacoes(nome, email, senha);
                }
                cin.ignore();
            }

            else if(input == "listar emprestimos"){
                if(_Login->Checar_Logado() == 0)
                    throw LoginErros::Ninguem_Logado();
                
                cout << endl << "Listando emprestimos..." << endl;

                Emprestimos->Listar_Emprestimos(_Login->Checar_Logado(), _Login->getLogado()->getId());
            }
            /////////////////////////////////////////////////////
                
            /////////////////////Permiss?o 0/////////////////////
            else if(input == "cadastrar gerente"){
                cout << endl << "Cadastrando Gerente..." << endl;
            
                cout << "Codigo: ";
                cin >> codigo;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Email: ";
                cin >> email;
                cout << "Senha: ";
                cin >> senha;

                cin.ignore();

                Funcionarios->Contratar_Gerente(codigo, nome, email, senha);
            }

            else if(input == "logar gerente"){
                if(_Login->Checar_Logado() != 0)
                    throw LoginErros::Ja_Logado();
            
                cout << endl << "Logando como Gerente..." << endl;

                cout << "Codigo: ";
                cin >> codigo;
                cout << "Email: ";
                cin >> email;
                cout << "Senha: ";
                cin >> senha;

                cin.ignore();

                _Login->Login_Gerente(Funcionarios, codigo, email, senha);
            }

            else if(input == "logar bibliotecario"){
                if(_Login->Checar_Logado() != 0)
                    throw LoginErros::Ja_Logado();
            
                cout << endl << "Logando como Bibliotecario..." << endl;

                cout << "Email: ";
                cin >> email;
                cout << "Senha: ";
                cin >> senha;

                cin.ignore();

                _Login->Login_Bibliotecario(Funcionarios, email, senha);
            }

            else if(input == "logar cliente"){
                if(_Login->Checar_Logado() != 0)
                    throw LoginErros::Ja_Logado();
            
                cout << endl << "Logando como Cliente..." << endl;

                cout << "Email: ";
                cin >> email;
                cout << "Senha: ";
                cin >> senha;

                cin.ignore();

                _Login->Login_Cliente(Clientes, email, senha);
            }

            else if(input == "listar acervo"){
                cout << endl;
                Livros->Listar_Acervo();
            }

            else if(input == "pesquisar por nome"){
                cout << endl << "Pesquisando pelo nome..." << endl;

                cout << "Nome: ";
                getline(cin, nome);

                Livros->Pesquisar_Nome(nome);
            }

            else if(input == "pesquisar por autor"){
                cout << endl << "Pesquisando pelo autor..." << endl;

                cout << "Nome do Autor: ";
                getline(cin, nomeAutor);

                Livros->Pesquisar_Autor(nomeAutor);
            }

            else if(input == "pesquisar por avaliacao"){
                cout << endl << "Pesquisando pela avaliacao..." << endl;

                Livros->Organizar_Avaliacao();
            }

            else if(input == "pesquisar por leitores"){
                cout << endl << "Pesquisando pela quantidade de leitores..." << endl;

                Livros->Organizar_Leitores();
            }

            else if(input == "pesquisar por buscas"){
                cout << endl << "Pesquisando por buscas..." << endl;

                Livros->Organizar_Buscas();
            }

            else if(input == "efetuar logout"){
                if(_Login->Checar_Logado() == 0)
                    throw LoginErros::Ninguem_Logado();
                
                cout << endl << "Efetuando logout..." << endl;

                _Login->Logout();
            }

            else if(input == "passar dia"){
                Data.Passar_Dia();
                Data.Imprimir_Data();

                Emprestimos->Checar_Multas(Data);
            }

            else if(input == "passar hora"){
                if(Data.Passar_Hora() == true)
                    Emprestimos->Checar_Multas(Data);

                Data.Imprimir_Data();
            }
            /////////////////////////////////////////////////////
            
            /////////////////////Permiss?o 1/////////////////////
            else if(input == "mostrar meu historico"){
                if(_Login->Checar_Logado() != 1)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Mostrando Historico..." << endl;

                Cliente* aux = dynamic_cast<Cliente*>(_Login->getLogado());
                aux->Mostrar_Historico();
            }

            else if(input == "mostrar meus livros"){
                if(_Login->Checar_Logado() != 1)
                    throw LoginErros::Permissao_Negada();
               
                cout << endl << "Mostrando seus Emprestimos..." << endl;

                Cliente* aux = dynamic_cast<Cliente*>(_Login->getLogado());
                aux->Mostrar_Livros();
            }

            else if(input == "alugar livro"){
                if(_Login->Checar_Logado() != 1)
                    throw LoginErros::Permissao_Negada();
            
                cout << endl << "Alugando um Livro..." << endl;

                cout << "Id do Livro: ";
                cin >> id;
                cin.ignore();

                Livro* Livro_aux = Livros->getLivro(id);
                if(Livro_aux == nullptr)
                    throw AcervoErros::Livro_Nao_Encontrado();
                              
                Cliente* Cliente_aux = dynamic_cast<Cliente*>(_Login->getLogado());

                Emprestimos->Criar_Emprestimo(Data, Cliente_aux, Livro_aux);
            }

            else if(input == "avaliar livro"){
                if(_Login->Checar_Logado() != 1)
                    throw LoginErros::Permissao_Negada();
            
                cout << endl << "Avaliando um Livro..." << endl;

                cout << "Id do Livro: ";
                cin >> id;

                cin.ignore();

                Livro* Livro_aux = Livros->getLivro(id);
                if(Livro_aux == nullptr)
                    throw AcervoErros::Livro_Nao_Encontrado();
            
                cout << "Avaliacao(0 a 5 estrelas): ";
                cin >> avaliacao;

                cin.ignore();

                Cliente* Cliente_aux = dynamic_cast<Cliente*>(_Login->getLogado());
                Cliente_aux->Avaliar_Livro(id, avaliacao);                         
            }

            else if(input == "apagar minha conta"){
                if(_Login->Checar_Logado() != 1)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Apagando sua conta..." << endl;

                cout << "Tem certeza de que deseja continuar?" << endl;
                cout << "sim ou nao" << endl;
                cin >> confirmacao;

                cin.ignore();

                if(confirmacao == "nao")
                    cout << "Processo cancelado" << endl;
                else{
                    Cliente* Cliente_aux = dynamic_cast<Cliente*>(_Login->getLogado());
                    _Login->Logout();
                
                    Clientes->Banir_Cliente(Cliente_aux->getId());
                }
            }
            /////////////////////////////////////////////////////

            /////////////////////Permiss?o 2/////////////////////
            else if(input == "adicionar cliente"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Adicionando Cliente..." << endl;

                cout << "Nome: ";
                getline(cin, nome);
                cout << "Email: ";
                cin >> email;
                cout << "Senha: ";
                cin >> senha;
                cout << "Cpf: ";
                cin >> cpf;

                cin.ignore();

                Clientes->Adicionar_Cliente(nome, email, senha, cpf);
            }

            else if(input == "remover cliente"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
            
                cout << endl << "Removendo Cliente..." << endl;

                cout << "Id: ";
                cin >> id;

                cin.ignore();

                Clientes->Banir_Cliente(id);
            }

            else if(input == "listar clientes"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Listando Clientes..." << endl;

                Clientes->Listar_Clientes();
            }

            else if(input == "adicionar livro"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Adicionando Livro..." << endl;

                cout << "Nome: ";
                getline(cin, nome);
                cout << "Genero: ";
                cin >> genero;
                cout << "Nome do Autor: ";
                cin.ignore();
                getline(cin, nomeAutor);
                cout << "Nome da Editora: ";
                getline(cin, nomeEditora);
                cout << "Data de Publica??o: ";
                cin >> dataPublicacao;

                cin.ignore();

                Livros->Adicionar_Livro(nome, genero, nomeAutor, nomeEditora, dataPublicacao);
            }

            else if(input == "remover livro"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
        
                cout << endl << "Removendo livro..." << endl;

                cout << "Id: ";
                cin >> id;

                cin.ignore();

                Livros->Remover_Livro(id);
            }

            else if(input == "editar livro"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Editando Livro..." << endl;

                cout << "Id: ";
                cin >> id;
                cout << "Nome: ";
                getline(cin, nome);
                cout << "G?nero: ";
                cin >> genero;
                cout << "Nome do Autor: ";
                cin.ignore();
                getline(cin, nomeAutor);
                cout << "Nome da Editora: ";
                getline(cin, nomeEditora);
                cout << "Data de Publica??o: ";
                cin >> dataPublicacao;

                cin.ignore();

                Livros->Editar_Livro(id, nome, genero, nomeAutor, nomeEditora, dataPublicacao);
            }

            else if(input == "encerrar emprestimo"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Encerrando empréstimo..." << endl;

                cout << "Id do Emprestimo: ";
                cin >> id;

                cin.ignore();

                Emprestimos->Encerrar_Emprestimo(id);
            }

            else if(input == "renovar emprestimo"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
            
                cout << endl << "Renovando emprestimo..." << endl;

                cout << "Id do Emprestimo: ";
                cin >> id;

                cin.ignore();

                Emprestimos->Renovar_Emprestimo(id);
            }

            else if(input == "quitar multa"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Quitando multa..." << endl;

                cout << "Id do Cliente: ";
                cin >> id;

                cin.ignore();

                Cliente* Cliente_aux = Clientes->getCliente(id);
                if(Cliente_aux == nullptr)
                    throw BancoClientesErros::Cliente_Nao_Encontrado();

                Cliente_aux->Quitar_Multa();
            }

            else if (input == "preencher acervo"){
                if(_Login->Checar_Logado() != 2 && _Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Preenchendo acervo de livros..." << endl;
                Livros->Preencher_Acervo();
            }
            /////////////////////////////////////////////////////

            /////////////////////Permiss?o 3/////////////////////
            else if(input == "contratar bibliotecario"){
                if(_Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl <<  "Contratando Bibliotecario..." << endl;

                cout << "Nome: ";
                getline(cin, nome);
                cout << "Email: ";
                cin >> email;
                cout << "Senha: ";
                cin >> senha;

                cin.ignore();
                
                Funcionarios->Adicionar_Bibliotecario(nome, email, senha);
            }

            else if(input == "demitir bibliotecario"){
                if(_Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Removendo Bibliotecario..." << endl;

                cout << "Id: ";
                cin >> id;

                cin.ignore();
                
                Funcionarios->Demitir_Bibliotecario(id);
            }

            else if(input == "listar bibliotecarios"){
                if(_Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Listando Bibliotecarios..." << endl;

                Funcionarios->Listar_Bibliotecarios();
            }

            else if(input == "encerrar sistema"){
                if(_Login->Checar_Logado() != 3)
                    throw LoginErros::Permissao_Negada();
                
                cout << endl << "Encerrando a operacao do sistema..." << endl;

                break;
            }
            /////////////////////////////////////////////////////
            
            else
                cout << endl << "Comando desconhecido" << endl;
            cout << endl;        
            cout << "Digite o proximo comando" << endl;

        }catch(AcervoErros::Livro_Nao_Encontrado &erro){
            cout << erro.what() << endl;
        }catch(AcervoErros::Nenhum_Livro &erro){
            cout << erro.what() << endl;
        }
        
        catch(BancoClientesErros::Cliente_Nao_Encontrado &erro){
            cout << erro.what() << endl;
        }catch(BancoClientesErros::Nenhum_Cliente &erro){
            cout << erro.what() << endl;
        }catch(BancoClientesErros::Email_Utilizado &erro){
            cout << erro.what() << endl;
        }
        
        catch(BancoEmprestimosErros::Emprestimo_Nao_Encontrado &erro){
            cout << erro.what() << endl;
        }catch(BancoEmprestimosErros::Nenhum_Emprestimo &erro){
            cout << erro.what() << endl;
        }catch(BancoEmprestimosErros::Livro_Indisponivel &erro){
            cout << erro.what() << endl;
        }catch(BancoEmprestimosErros::Limite_Livros &erro){
            cout << erro.what() << endl;
        }

        catch(BancoFuncionariosErros::Bibliotecario_Nao_Encontrado &erro){
            cout << erro.what() << endl;
        }catch(BancoFuncionariosErros::Nenhum_Bibliotecario &erro){
            cout << erro.what() << endl;
        }catch(BancoFuncionariosErros::Email_Utilizado &erro){
            cout << erro.what() << endl;
        }

        catch(ClienteErros::Cpf_Invalido &erro){
            cout << erro.what() << endl;
        }catch(ClienteErros::Avaliacao_Invalida &erro){
            cout << erro.what() << endl;
        }catch(ClienteErros::Historico_Vazio &erro){
            cout << erro.what() << endl;
        }catch(ClienteErros::Livro_Ja_Avaliado &erro){
            cout << erro.what() << endl;
        }catch(ClienteErros::Nenhum_Livro_Alugado &erro){
            cout << erro.what() << endl;
        }catch(ClienteErros::Livro_Nao_Alugado &erro){
            cout << erro.what() << endl;
        }

        catch(LoginErros::Credenciais_Incorretas &erro){
            cout << erro.what() << endl;
        }catch(LoginErros::Ja_Logado &erro){
            cout << erro.what() << endl;
        }catch(LoginErros::Ninguem_Logado &erro){
            cout << erro.what() << endl;
        }catch(LoginErros::Permissao_Negada &erro){
            cout << erro.what() << endl;
        }

        catch(UsuarioErros::Email_Invalido &erro){
            cout << erro.what() << endl;
        }catch(UsuarioErros::Senha_Invalida &erro){
            cout << erro.what() << endl;
        }

        catch(GerenteErros::Codigo_Invalido &erro){
            cout << erro.what() << endl;
        }        
    }   

    delete(Clientes);
    delete(Funcionarios);
    delete(Emprestimos);
    delete(Livros);
    delete(_Login);

    return 0;
}