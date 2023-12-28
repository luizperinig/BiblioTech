#include "Acervo.hpp"

Acervo::~Acervo(){
    for(auto&& i : _Livros)
        delete i;
}

/**
 * @brief Adiciona um novo livro à lista de livros do acervo.
 * @param Nome O nome do livro.
 * @param Genero O gênero do livro.
 * @param Nome_Autor O nome do autor do livro.
 * @param Nome_Editora O nome da editora do livro.
 * @param Data_Publicacao A data de publicação do livro.
 * @return Nenhum valor de retorno.
 * @note Esta função requer permissão 2 para ser executada.
 */
void Acervo::Adicionar_Livro(string Nome, string Genero, string Nome_Autor, string Nome_Editora, string Data_Publicacao){
    Livro* Livro_aux = new Livro(this->_Id, Nome, Genero, Nome_Autor, Nome_Editora, Data_Publicacao);
    _Livros.push_back(Livro_aux);

    this->_Id++;
    cout<< "Livro adicionado com sucesso" << endl;
}


/**
 * @brief Remove um livro da lista com base no ID fornecido.
 * @param Id O ID do livro a ser removido.
 * @return Nenhum valor de retorno.
 * @throws AcervoErros::Nenhum_Livro Se a lista de livros estiver vazia.
 * @throws AcervoErros::Livro_Nao_Encontrado Se o livro com o ID fornecido não for encontrado.
 * @note Esta função requer permissão 2 para ser executada.
 */
void Acervo::Remover_Livro(int Id){
    if(_Livros.size() == 0)
        throw AcervoErros::Nenhum_Livro();

    list<Livro*>::iterator index = _Livros.begin();

    for(; index != _Livros.end(); ++index){
        if((*index)->getId() == Id){
            delete *index;
            _Livros.erase(index);
            return;
        }    
    }

    throw AcervoErros::Livro_Nao_Encontrado();
}


/**
 * @brief Edita as informações de um livro na lista com base no ID fornecido.
 * @param Id O ID do livro a ser editado.
 * @param Nome O novo nome do livro.
 * @param Genero O novo gênero do livro.
 * @param Nome_Autor O novo nome do autor do livro.
 * @param Nome_Editora O novo nome da editora do livro.
 * @param Data_Publicacao A nova data de publicação do livro.
 * @return Nenhum valor de retorno.
 * @throws AcervoErros::Nenhum_Livro Se a lista de livros estiver vazia.
 * @throws AcervoErros::Livro_Nao_Encontrado Se o livro com o ID fornecido não for encontrado.
 * @note Esta função requer permissão 2 para ser executada.
 */
void Acervo::Editar_Livro(int Id, string Nome, string Genero, string Nome_Autor, string Nome_Editora, string Data_Publicacao){
    if(_Livros.size() == 0)
        throw AcervoErros::Nenhum_Livro();
    
    list<Livro*>::iterator index = _Livros.begin();

    for(; index != _Livros.end(); ++index){
        if((*index)->getId() == Id){
            (*index)->setNome(Nome);
            (*index)->setGenero(Genero);
            (*index)->setNomeAutor(Nome_Autor);
            (*index)->setNomeEditora(Nome_Editora);
            (*index)->setDataPublicacao(Data_Publicacao);
            return;
        }    
    }

    throw AcervoErros::Livro_Nao_Encontrado();
}


/**
 * @brief Organiza a lista de livros em ordem alfabética e imprime as informações de cada livro.
 * @return Nenhum valor de retorno.
 * @throws AcervoErros::Nenhum_Livro Se a lista de livros estiver vazia.
 * @note Esta função requer permissão 0 para ser executada.
 */
void Acervo::Listar_Acervo(){
    if(_Livros.size() == 0)
        throw AcervoErros::Nenhum_Livro();

    _Livros.sort([](Livro* a, Livro* b){
        return a->getNome() < b->getNome();
    });

    list<Livro*>::iterator index = _Livros.begin();
    for(; index != _Livros.end(); ++index)
        (*index)->Imprimir_Informacoes();
}


/**
 * @brief Organiza a lista de livros em ordem decrescente da avaliação e imprime as informações de cada livro.
 * @return Nenhum valor de retorno.
 * @throws AcervoErros::Nenhum_Livro Se a lista de livros estiver vazia.
 * @note Esta função requer permissão 0 para ser executada.
 */
void Acervo::Organizar_Avaliacao(){
    if(_Livros.size() == 0)
        throw AcervoErros::Nenhum_Livro();
    
    _Livros.sort([](Livro* a, Livro* b){
        return a->getAvaliacao() > b->getAvaliacao();
    });

    list<Livro*>::iterator index = _Livros.begin();
    for(; index != _Livros.end(); ++index){
        (*index)->Imprimir_Informacoes();
    }
}

/**
 * @brief Organiza a lista de livros em ordem decrescente da quantidade de buscas e imprime as informações de cada livro.
 * @throws AcervoErros::Nenhum_Livro Se não houver livros no acervo.
 * @note É necessária a permissão 0 para executar esta função.
 */
void Acervo::Organizar_Buscas(){
    if(_Livros.size() == 0)
        throw AcervoErros::Nenhum_Livro();
    
    _Livros.sort([](Livro* a, Livro* b){
        return a->getBuscas() > b->getBuscas();
    });

    list<Livro*>::iterator index = _Livros.begin();
    for(; index != _Livros.end(); ++index)
        (*index)->Imprimir_Informacoes();
}


/**
 * @brief Organiza a lista de livros em ordem decrescente da quantidade de leitores e imprime as informações de cada livro.
 * @return Nenhum valor de retorno.
 * @throws AcervoErros::Nenhum_Livro Se a lista de livros estiver vazia.
 * @note Esta função requer permissão 0 para ser executada.
 */
void Acervo::Organizar_Leitores(){
    if(_Livros.size() == 0)
        throw AcervoErros::Nenhum_Livro();
    
    _Livros.sort([](Livro* a, Livro* b){
        return a->getLeitores() > b->getLeitores();
    });

    list<Livro*>::iterator index = _Livros.begin();
    for(; index != _Livros.end(); ++index)
        (*index)->Imprimir_Informacoes();
}


/**
 * @brief Retorna todos os livros da lista que possuem o mesmo nome passado e imprime suas informações.
 * @param Nome O nome a ser pesquisado.
 * @return Nenhum valor de retorno.
 * @throws AcervoErros::Nenhum_Livro Se a lista de livros estiver vazia.
 * @throws AcervoErros::Livro_Nao_Encontrado Se nenhum livro com o nome fornecido for encontrado.
 * @note Esta função requer permissão 0 para ser executada.
 */
void Acervo::Pesquisar_Nome(string Nome){
    if(_Livros.size() == 0)
        throw AcervoErros::Nenhum_Livro();
    
    bool aux = false;
    list<Livro*>::iterator index = _Livros.begin();

    for(; index != _Livros.end(); ++index){
        if((*index)->getNome() == Nome){
            (*index)->Acrescentar_Buscas();
            (*index)->Imprimir_Informacoes();
            aux = true;
        }
    }

    if(aux == false)
        throw AcervoErros::Livro_Nao_Encontrado();
}


/**
 * @brief Retorna todos os livros da lista que possuem o mesmo autor passado e imprime suas informações.
 * @param Autor O autor a ser pesquisado.
 * @return Nenhum valor de retorno.
 * @throws AcervoErros::Nenhum_Livro Se a lista de livros estiver vazia.
 * @throws AcervoErros::Livro_Nao_Encontrado Se nenhum livro com o autor fornecido for encontrado.
 * @note Esta função requer permissão 0 para ser executada.
 */
void Acervo::Pesquisar_Autor(string Autor){
    if(_Livros.size() == 0)
        throw AcervoErros::Nenhum_Livro();
    
    bool aux = false;
    list<Livro*>::iterator index = _Livros.begin();
    
    for(; index != _Livros.end(); ++index){
        if((*index)->getNomeAutor() == Autor){
            (*index)->Acrescentar_Buscas();
            (*index)->Imprimir_Informacoes();
            aux = true;
        }
    }

    if(aux == false)
        throw AcervoErros::Livro_Nao_Encontrado();
}


/**
 * @brief Retorna o ponteiro para um livro dado o Id passado.
 * @param Id O Id do livro a ser obtido.
 * @return Um ponteiro para o livro correspondente ao Id fornecido. Retorna nullptr se nenhum livro for encontrado.
 */
Livro* Acervo::getLivro(int Id){
    if(_Livros.size() == 0){
        return nullptr;
    }
    else{
        Livro* aux = nullptr;

        list<Livro*>::iterator index = _Livros.begin();
        for(; index != _Livros.end(); ++index){
            if((*index)->getId() == Id){
                aux = *index;
                break;
            }    
        }

        return aux;
    }
}


void Acervo::Preencher_Acervo(){
    //---------------------------------------------------------------------------GENEROS---------------------------------------------------------------------------

    //ROMANCE
    Adicionar_Livro("Orgulho e Preconceito", "Romance", "Jane Austen", "Thomas Egerton", "1813");
    Adicionar_Livro("Romeu e Julieta", "Romance", "William Shakespeare", "Penguin Classics", "1597");
    Adicionar_Livro("O Morro dos Ventos Uivantes", "Romance", "Emily Brontë", "Thomas Cautley Newby", "1847");
    Adicionar_Livro("Como Eu Era Antes de Você", "Romance", "Jojo Moyes", "Intrínseca", "2012");
    Adicionar_Livro("Anna Karenina", "Romance", "Liev Tolstói", "The Russian Messenger", "1877");
    Adicionar_Livro("Me Chame Pelo Seu Nome", "Romance", "André Aciman", "Farrar, Straus and Giroux", "2007");
    Adicionar_Livro("A Culpa É das Estrelas", "Romance", "John Green", "Dutton Books", "2012");
    Adicionar_Livro("Persuasão", "Romance", "Jane Austen", "John Murray", "1818");
    Adicionar_Livro("O Amor nos Tempos do Cólera", "Romance", "Gabriel García Márquez", "Editorial Oveja Negra", "1985");
    Adicionar_Livro("Água para Elefantes", "Romance", "Sara Gruen", "Algonquin Books", "2006");
    
    //FANTASIA
    Adicionar_Livro("O Nome do Vento", "Fantasia", "Patrick Rothfuss", "DAW Books", "2007");
    Adicionar_Livro("O Hobbit", "Fantasia", "J.R.R. Tolkien", "HarperCollins", "1937");
    Adicionar_Livro("Harry Potter e a Pedra Filosofal", "Fantasia", "J.K. Rowling", "Bloomsbury Publishing", "1997");
    Adicionar_Livro("A Guerra dos Tronos", "Fantasia", "George R.R. Martin", "Bantam Spectra", "1996");
    Adicionar_Livro("Assassin's Apprentice", "Fantasia", "Robin Hobb", "Voyager Books", "1995");
    Adicionar_Livro("A Batalha do Apocalipse", "Fantasia", "Eduardo Spohr", "Verus", "2010");
    Adicionar_Livro("A Roda do Tempo: O Olho do Mundo", "Fantasia", "Robert Jordan", "Tor Books", "1990");
    Adicionar_Livro("O Senhor dos Anéis: A Sociedade do Anel", "Fantasia", "J.R.R. Tolkien", "Houghton Mifflin", "1954");
    Adicionar_Livro("A Magia do Império", "Fantasia", "Brandon Sanderson", "Tor Books", "2015");
    Adicionar_Livro("Cemitérios de Dragões", "Fantasia", "Raphael Draccon", "Leya", "2011");

    //TRAGEDIA
    Adicionar_Livro("Romeu e Julieta", "Tragédia", "William Shakespeare", "Penguin Classics", "1597");
    Adicionar_Livro("Édipo Rei", "Tragédia", "Sófocles", "Desconhecido", "Entre 441 a.C. e 429 a.C.");
    Adicionar_Livro("Hamlet", "Tragédia", "William Shakespeare", "Penguin Classics", "1603");
    Adicionar_Livro("Antígona", "Tragédia", "Sófocles", "Desconhecido", "Entre 441 a.C. e 429 a.C.");
    Adicionar_Livro("Macbeth", "Tragédia", "William Shakespeare", "Penguin Classics", "1606");
    Adicionar_Livro("Otelo", "Tragédia", "William Shakespeare", "Penguin Classics", "1603");
    Adicionar_Livro("Édipo em Colono", "Tragédia", "Sófocles", "Desconhecido", "Entre 441 a.C. e 429 a.C.");
    Adicionar_Livro("Rei Lear", "Tragédia", "William Shakespeare", "Penguin Classics", "1606");
    Adicionar_Livro("Medeia", "Tragédia", "Eurípides", "Desconhecido", "431 a.C.");
    Adicionar_Livro("Júlio César", "Tragédia", "William Shakespeare", "Penguin Classics", "1599");
    
    //CONTO
    Adicionar_Livro("Fábulas", "Conto", "Esopo", "Desconhecido", "Século VI a.C.");
    Adicionar_Livro("Contos de Andersen", "Conto", "Hans Christian Andersen", "Desconhecido", "1835-1872");
    Adicionar_Livro("Contos de Fadas", "Conto", "Irmãos Grimm", "Desconhecido", "1812-1857");
    Adicionar_Livro("As Mil e Uma Noites", "Conto", "Vários Autores", "Desconhecido", "Século IX-XVII");
    Adicionar_Livro("O Livro das Mil e Uma Noites", "Conto", "Vários Autores", "Editora Globo", "1704");
    Adicionar_Livro("Dublinenses", "Conto", "James Joyce", "Grant Richards", "1914");
    Adicionar_Livro("Contos", "Conto", "Edgar Allan Poe", "Desconhecido", "1845-1849");
    Adicionar_Livro("Primeiras Estórias", "Conto", "João Guimarães Rosa", "Desconhecido", "1962");
    Adicionar_Livro("O Livro dos Seres Imaginários", "Conto", "Jorge Luis Borges", "Editora Globo", "1957");
    Adicionar_Livro("O Aleph", "Conto", "Jorge Luis Borges", "Editora Globo", "1949");
    
    //COMEDIA
    Adicionar_Livro("As Viagens de Gulliver", "Comédia", "Jonathan Swift", "Desconhecido", "1726");
    Adicionar_Livro("O Guia do Mochileiro das Galáxias", "Comédia", "Douglas Adams", "Pan Books", "1979");
    Adicionar_Livro("Três Homens em um Barco", "Comédia", "Jerome K. Jerome", "J.W. Arrowsmith", "1889");
    Adicionar_Livro("Diário de um Banana", "Comédia", "Jeff Kinney", "Amulet Books", "2007");
    Adicionar_Livro("Piratas!", "Comédia", "Terry Jones", "Penguin Books", "1981");
    Adicionar_Livro("O Morro dos Ventos Azuis", "Comédia", "Branwell Brontë", "Smith, Elder & Co.", "1846");
    Adicionar_Livro("Rumo à Estação Finlândia", "Comédia", "Eugenio Corti", "Rizzoli", "1972");
    Adicionar_Livro("Morto até o Anoitecer", "Comédia", "Charlaine Harris", "Ace Books", "2001");
    Adicionar_Livro("Onde os Fracos Não Têm Vez", "Comédia", "Cormac McCarthy", "Vintage Books", "2005");
    Adicionar_Livro("A Máquina do Tempo", "Comédia", "H.G. Wells", "William Heinemann", "1895");
    
    //POESIA
    Adicionar_Livro("Odes", "Poesia", "Horácio", "Desconhecido", "23 a.C.");
    Adicionar_Livro("Sonetos", "Poesia", "William Shakespeare", "Penguin Classics", "1609");
    Adicionar_Livro("Fernando Pessoa - Obra Poética", "Poesia", "Fernando Pessoa", "Athena Editora", "1914-1935");
    Adicionar_Livro("Antologia Poética", "Poesia", "Carlos Drummond de Andrade", "Companhia das Letras", "1930-1997");
    Adicionar_Livro("Odes Elementales", "Poesia", "Pablo Neruda", "Editorial Losada", "1954");
    Adicionar_Livro("Poemas de Álvaro de Campos", "Poesia", "Álvaro de Campos", "Desconhecido", "1914-1935");
    Adicionar_Livro("A Divina Comédia", "Poesia", "Dante Alighieri", "Desconhecido", "1304-1321");
    Adicionar_Livro("Poemas", "Poesia", "Sophia de Mello Breyner Andresen", "Caminho", "1944-1996");
    Adicionar_Livro("Poesia Completa", "Poesia", "Vinicius de Moraes", "Companhia das Letras", "1933-1980");
    Adicionar_Livro("Poesia Grega", "Poesia", "Vários Autores", "Desconhecido", "Séculos IX-VII a.C.");

    //INFANTIL
    Adicionar_Livro("O Pequeno Príncipe", "Infantil", "Antoine de Saint-Exupéry", "Gallimard", "1943");
    Adicionar_Livro("O Sítio do Picapau Amarelo", "Infantil", "Monteiro Lobato", "Desconhecido", "1920-1947");
    Adicionar_Livro("Alice no País das Maravilhas", "Infantil", "Lewis Carroll", "Macmillan Publishers", "1865");
    Adicionar_Livro("O Livro da Selva", "Infantil", "Rudyard Kipling", "Macmillan Publishers", "1894");
    Adicionar_Livro("A Bruxinha Atrapalhada", "Infantil", "Eva Furnari", "Moderna", "1985");
    Adicionar_Livro("O Menino Maluquinho", "Infantil", "Ziraldo", "Melhoramentos", "1980");
    Adicionar_Livro("Peter Pan", "Infantil", "J.M. Barrie", "Desconhecido", "1904");
    Adicionar_Livro("A Arca de Noé", "Infantil", "Vinicius de Moraes", "Companhia das Letras", "1933");
    Adicionar_Livro("Os Três Porquinhos", "Infantil", "Joseph Jacobs", "Desconhecido", "Século XIX");
    Adicionar_Livro("Chapeuzinho Vermelho", "Infantil", "Irmãos Grimm", "Desconhecido", "1812");

    //DIDATICOS
    Adicionar_Livro("Matemática Básica", "Didático", "Nicolas Bourbaki", "Desconhecido", "1960");
    Adicionar_Livro("Introdução à Física", "Didático", "Albert Einstein", "Desconhecido", "1910");
    Adicionar_Livro("História do Brasil", "Didático", "Boris Fausto", "Editora da USP", "1994");
    Adicionar_Livro("Geografia Geral", "Didático", "Milton Santos", "Editora Hucitec", "1978");
    Adicionar_Livro("Química Orgânica", "Didático", "Paula Yurkanis Bruice", "Pearson Education", "2007");
    Adicionar_Livro("Biologia Celular", "Didático", "Bruce Alberts", "Artmed", "2002");
    Adicionar_Livro("Gramática da Língua Portuguesa", "Didático", "Celso Cunha", "Editora Nova Fronteira", "1985");
    Adicionar_Livro("Economia - Princípios e Aplicações", "Didático", "Mochôn & Mochôn", "Saraiva", "2008");
    Adicionar_Livro("Sociologia Geral", "Didático", "Anthony Giddens", "Penso Editora", "2010");
    Adicionar_Livro("Psicologia Cognitiva", "Didático", "Robert Sternberg", "Cengage Learning", "2011");

    //GASTRONOMIA
    Adicionar_Livro("Mastering the Art of French Cooking", "Gastronomia", "Julia Child", "Alfred A. Knopf", "1961");
    Adicionar_Livro("The Joy of Cooking", "Gastronomia", "Irma S. Rombauer", "Scribner", "1931");
    Adicionar_Livro("Essentials of Classic Italian Cooking", "Gastronomia", "Marcella Hazan", "HarperCollins", "1992");
    Adicionar_Livro("On Food and Cooking: The Science and Lore of the Kitchen", "Gastronomia", "Harold McGee", "Scribner", "1984");
    Adicionar_Livro("The Professional Chef", "Gastronomia", "The Culinary Institute of America", "Wiley", "1979");
    Adicionar_Livro("Salt, Fat, Acid, Heat: Mastering the Elements of Good Cooking", "Gastronomia", "Samin Nosrat", "Simon & Schuster", "2017");
    Adicionar_Livro("The Flavor Bible: The Essential Guide to Culinary Creativity, Based on the Wisdom of America's Most Imaginative Chefs", "Gastronomia", "Karen Page and Andrew Dornenburg", "Little, Brown and Company", "2008");
    Adicionar_Livro("Plenty: Vibrant Vegetable Recipes from London's Ottolenghi", "Gastronomia", "Yotam Ottolenghi", "Chronicle Books", "2010");
    Adicionar_Livro("Modernist Cuisine: The Art and Science of Cooking", "Gastronomia", "Nathan Myhrvold, Chris Young, and Maxime Bilet", "The Cooking Lab", "2011");
    Adicionar_Livro("Baking: From My Home to Yours", "Gastronomia", "Dorie Greenspan", "Houghton Mifflin Harcourt", "2006");

    //TERROR
    Adicionar_Livro("It", "Terror", "Stephen King", "Viking", "1986");
    Adicionar_Livro("O Iluminado", "Terror", "Stephen King", "Doubleday", "1977");
    Adicionar_Livro("Psicose", "Terror", "Robert Bloch", "Simon & Schuster", "1959");
    Adicionar_Livro("O Exorcista", "Terror", "William Peter Blatty", "Harper & Row", "1971");
    Adicionar_Livro("Carmilla", "Terror", "J. Sheridan Le Fanu", "Desconhecido", "1872");
    Adicionar_Livro("O Cemitério", "Terror", "Stephen King", "Doubleday", "1983");
    Adicionar_Livro("Frankenstein", "Terror", "Mary Shelley", "Lackington, Hughes, Harding, Mavor & Jones", "1818");
    Adicionar_Livro("Drácula", "Terror", "Bram Stoker", "Archibald Constable and Company", "1897");
    Adicionar_Livro("O Chamado de Cthulhu", "Terror", "H.P. Lovecraft", "Weird Tales", "1928");
    Adicionar_Livro("O Silêncio dos Inocentes", "Terror", "Thomas Harris", "St. Martin's Press", "1988");

    //---------------------------------------------------------------------------FIM DOS GENEROS---------------------------------------------------------------------------
    
    //REPETIDOS
    Adicionar_Livro("Romeu e Julieta", "Romance", "William Shakespeare", "Penguin Classics", "1597");
    Adicionar_Livro("Romeu e Julieta", "Romance", "William Shakespeare", "Penguin Classics", "1597");
    Adicionar_Livro("Como Eu Era Antes de Você", "Romance", "Jojo Moyes", "Intrínseca", "2012");
    Adicionar_Livro("O Hobbit", "Fantasia", "J.R.R. Tolkien", "HarperCollins", "1937");
    Adicionar_Livro("Harry Potter e a Pedra Filosofal", "Fantasia", "J.K. Rowling", "Bloomsbury Publishing", "1997");
    Adicionar_Livro("O Hobbit", "Fantasia", "J.R.R. Tolkien", "HarperCollins", "1937");
    Adicionar_Livro("Harry Potter e a Pedra Filosofal", "Fantasia", "J.K. Rowling", "Bloomsbury Publishing", "1997");
    Adicionar_Livro("O Senhor dos Anéis: A Sociedade do Anel", "Fantasia", "J.R.R. Tolkien", "Houghton Mifflin", "1954");
    Adicionar_Livro("Otelo", "Tragédia", "William Shakespeare", "Penguin Classics", "1603");
    Adicionar_Livro("O Livro das Mil e Uma Noites", "Conto", "Vários Autores", "Editora Globo", "1704");
    Adicionar_Livro("O Livro das Mil e Uma Noites", "Conto", "Vários Autores", "Editora Globo", "1704");
    Adicionar_Livro("Diário de um Banana", "Comédia", "Jeff Kinney", "Amulet Books", "2007");
    Adicionar_Livro("Diário de um Banana", "Comédia", "Jeff Kinney", "Amulet Books", "2007");
    Adicionar_Livro("Diário de um Banana", "Comédia", "Jeff Kinney", "Amulet Books", "2007");
    Adicionar_Livro("A Divina Comédia", "Poesia", "Dante Alighieri", "Desconhecido", "1304-1321");
    Adicionar_Livro("Os Três Porquinhos", "Infantil", "Joseph Jacobs", "Desconhecido", "Século XIX");
    Adicionar_Livro("Chapeuzinho Vermelho", "Infantil", "Irmãos Grimm", "Desconhecido", "1812");
    Adicionar_Livro("Os Três Porquinhos", "Infantil", "Joseph Jacobs", "Desconhecido", "Século XIX");
    Adicionar_Livro("Chapeuzinho Vermelho", "Infantil", "Irmãos Grimm", "Desconhecido", "1812");  
    Adicionar_Livro("Matemática Básica", "Didático", "Nicolas Bourbaki", "Desconhecido", "1960");
    Adicionar_Livro("Matemática Básica", "Didático", "Nicolas Bourbaki", "Desconhecido", "1960");
    Adicionar_Livro("The Flavor Bible: The Essential Guide to Culinary Creativity, Based on the Wisdom of America's Most Imaginative Chefs", "Gastronomia", "Karen Page and Andrew Dornenburg", "Little, Brown and Company", "2008");
    Adicionar_Livro("O Iluminado", "Terror", "Stephen King", "Doubleday", "1977");
}