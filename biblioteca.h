#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

//-----------------------estruturas básicas-------------------------------------------------------------------------
//definição da estrutra da pokedex
typedef struct{
    //básico
    int numero;
    char nome[21];
    char tipo1[20];
    char tipo2[20];
    //informações para a luta
    int total;
    int hp;
    int ataque;
    int defesa;
    int ataqueEspecial;
    int defesaEspecial;
    int velocidade;
    bool lendario;
    //tabela de informações gerais
    int geracao;
    char cor[15];
    float altura;
    float peso;
    int taxaCaptura;
    int proximaEvolucao;
    int preEvolucao;
}Pokedex;

//definição da estrutura da Mochila
typedef struct{
    int pokemons[6];
    int pokebolas;
}Mochila;

//definição da estrutura coleção
typedef struct{
    int *pokemons;
    int tamanho;
    Mochila mochila;
} Colecao ;

//---------------------------------funções genéricas--------------------------------------------------------------------
void salvarDados(char *pokedexUsuario, Pokedex *pokedex, int tamanho);
void carregarDados(char *pokedexUsuario, Pokedex *pokedex, int tamanho);
//função que recebe um nome e transforma em código, retorna o indice encontrado
int transformaNomeEmCodigo (char nome, Pokedex* minhaPokedex, int tamanho);
void leString(char string[], int tamanho);
void removeEspacos(char* str);
void capturaPokemon(int nivel, Pokedex minhaPokedex[], Mochila* minhaMochila);

//---------------------------------funções da pokedex--------------------------------------------------------------------
Pokedex cadastrarPokemonPokedex();
void listarPokedex(Pokedex pokedex[], int tamanho);
void pesquisarPokedex(Pokedex pokedex[], int tamanho);
Pokedex alterarPokedex(Pokedex pokedex[], int tamanho);
void excluir(Pokedex registros, int *tamanho);
void exportarDadosPokedexCSV(Pokedex pokedex[], int tamanho);

//---------------------------------funções da coleção--------------------------------------------------------------------
void inicializarColecao(Colecao *colecao);
void adicionaPokemon(Colecao *colecao, int codigo);
void listaPokemons(Colecao *colecao, Pokedex *pokedex);
void pesquisaPokemon(Pokedex *pokedex);
void excluiPokemon(Pokedex *pokedex, Colecao *colecao);
void liberarColecao(Colecao *colecao);


//---------------------------------funções da mochila--------------------------------------------------------------------
void adicionaPokemonMochila(Pokedex *minhaPokedex ,Colecao *colecao, Mochila *mochila, int posicao);
void removerPokemonMochila(Pokedex * minhaPokedex, Mochila *mochila, int codigo);


#endif
