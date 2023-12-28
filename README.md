# 2023-1-TM2-grupo10

Este é o repositório do grupo 10 para o projeto da disciplina "Programação e Desenvolvimento de Software 2" (PDS2) do curso de Engenharia de Controle e Automação da Universidade Federal de Minas Gerais (UFMG), no período letivo de 2023-1.

# Membros do Projeto

Vinicius de Sousa Viana (ViniciusVsV) <br />
Luiz Filipe Perini Giacomin (luizperinig)<br />
Antônio Temponi Marques (antoniotm1)<br />
Leonardo Martins Marques Oliveira (leomarql) 

# Visão Geral
Visão Geral do Código do Sistema de Biblioteca:

O código fornecido é um programa de sistema de biblioteca desenvolvido em C++. Ele permite que os usuários realizem várias operações relacionadas à gestão de uma biblioteca, como cadastrar e gerenciar clientes, funcionários, livros e empréstimos.

A estrutura do programa é organizada em várias bibliotecas (arquivos de cabeçalho) que contêm as classes e funções necessárias para cada aspecto do sistema. 
O programa possui diversas funcionalidades, incluindo:

Cadastro e gerenciamento de clientes: Os usuários podem cadastrar novos clientes, editar informações pessoais e remover contas de clientes existentes.

Cadastro e gerenciamento de funcionários: Os funcionários podem ser cadastrados com diferentes níveis de permissão, como gerente e bibliotecário. As informações pessoais dos funcionários podem ser editadas.

Cadastro e gerenciamento de livros: O sistema permite adicionar, remover e editar informações dos livros presentes na biblioteca.

Empréstimo de livros: Os clientes podem realizar empréstimos de livros, com controle de datas de devolução e possibilidade de renovação de empréstimos.

Avaliação de livros: Os clientes têm a opção de avaliar os livros que eles tenham lido.

Histórico de empréstimos: O sistema mantém um registro de histórico de empréstimos e oferece a possibilidade de listar os empréstimos realizados por clientes.

O programa também inclui recursos de login e logout para diferentes tipos de usuários, garantindo a segurança e controle de acesso às funcionalidades.<br />

# Comandos do sistema
COMANDOS GERAIS
* 'cadastrar gerente'
* 'mostrar meus dados' 
* 'editar meus dados' 
* 'apagar minha conta' 
* 'listar emprestimos'
* 'efetuar logout' 
* 'passar dia'
* 'passar hora'
<br />
PERMISSÃO 0 (NINGUÉM LOGADO)
<br />
 
* 'logar gerente' 
* 'logar bibliotecario' 
* 'logar cliente' 
* 'listar acervo' 
* 'pesquisar por nome' 
* 'pesquisar por autor' 
* 'pesquisar por avaliacao' 
* 'pesquisar por leitores' 
* 'pesquisar por buscas' 
 <br />
PERMISSÃO 1 (CLIENTE)
<br />

* 'mostrar meu historico'
* 'mostrar meus livros'
* 'alugar livro'
* 'avaliar livro'
<br />
PERMISSÃO 2 (BIBLIOTECÁRIO)
<br />

* 'adicionar clientes'
* 'remover cliente'
* 'listar clientes'
* 'adicionar livro'
* 'remover livro'
* 'editar livro'
* 'encerrar emprestimo'
* 'renovar emprestimo'
* 'quitar multa'
* 'preencher acervo'
<br />
PERMISSÃO 3 (GERENTE)
<br />

* 'contratar bibliotecario'
* 'demitir bibliotecario'
* 'listar bibliotecarios'
* 'encerrar sistema'




