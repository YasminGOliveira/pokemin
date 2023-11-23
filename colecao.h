#ifndef COLECAO_H
#define COLECAO_H

//definição da estrutura da Mochila
typedef struct{
    int pokemons[6];
}Mochila;

//definição da estrutura coleção
typedef struct{
    int *pokemons;
    int tamanho;
    Mochila mochila;
} Colecao ;

//função que recebe um nome e transforma em código, retrna o indice encontrado
int transformaNomeEmCodigo (char nome, Pokedex* minhaPokedex);

//funçaõ para ler uma string
void leString(char string[], int tamanho);

//função que inicializa a coleção com a alocação dinamica
void inicializarColecao(Colecao *colecao);

//funções sobre a coleção
void adicionaPokemon(Colecao *colecao, int codigo);
void listaPokemons(Colecao *colecao, Pokedex *pokedex);
void pesquisaPokemon(Pokedex *pokedex);
void excluiPokemon(Pokedex *pokedex, Colecao *colecao);

// Função para liberar a memória alocada pela coleção
void liberarColecao(Colecao *colecao);

#endif
