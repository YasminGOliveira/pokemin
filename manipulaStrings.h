/*Defina uma estrutura Coleção que deve armazenar a relação dos Pokémons já
capturados, para isso armazene apenas o número(códigos). Essa relação deve
aumentar e diminuir dinamicamente. Você deve prever o caso de Pokémons duplicados.
O sistema deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) os pokémons
já capturados.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "manipulaStrings.h"
#include "gerenciarPokemons.h"


typedef struct{
    int *pokemons;
    int tamanho;
} Colecao ;

//função para inicializar a coleção, excluindo a possibilidade de ter um valor lixo
void inicializarColecao(Colecao *colecao) {
    colecao->pokemons = NULL;
    colecao->tamanho = 0;
}//inicializarColecao

//função para adicionar um pokémon a coleção
void adicionaPokemon(Colecao *colecao, int codigo){
    //alocar dinamicamente o espaço para um novo pokémon
    colecao->pokemons = realloc(colecao->pokemons, (colecao->tamanho + 1) * sizeof(int));

    //verifica se a alocação está correta
    if (colecao->pokemons == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }//if

    //atribui o código(número do pokemon) ao último elemento da coleção
    colecao->pokemons[colecao->tamanho] = codigo;
}//adicionaPokemon

//função para listar os pokémons da coleção
void listaPokemons(Colecao *colecao, Pokedex *pokedex){
    //variavel
    int indiceListar;

    //transformar os códigos em nomes e exibir os pokemons
    printf("Pokémons na coleção: ");
    for(int i=0; i<colecao->tamanho; i++){
        for(int j=0; j<721; j++){
            if(colecao->pokemons[i] == pokedex[j].numero){
                indiceListar = j;
                printf("%s ", pokedex[indiceListar].nome);
            }//if
        }//for interno
    }//for exetrno
    printf("\n");
}//listaPokemons

//função para pesquisar o pokémon
void pesquisaPokemon(Pokedex *pokedex){
    //variavel
    char nomePesquisa[20];
    int indicePesquisa = -1;

    //pede as informações do usuário
    printf("Digite o nome do pokémon que deseja pesquisar: ");
    leString(nomePesquisa, 20);

    //busca as informações do pokemon requisitado
    for(int i=0; i<721; i++){
        if(strcasecmp(nomePesquisa, pokedex[i].nome)==0){
            indicePesquisa = i;
            break;
        }//if
    }//for

    //exibe resultado da pesquisa
    printf("Resultados da pesquisa:\n");
    if(indicePesquisa==-1){
        printf("Pokemon não encontrado!\n");
    } else {
        printf("Nome: %s\n", nomePesquisa);
        printf("Número: %d\n", pokedex[indicePesquisa].numero);
        printf("Tipo 1: %s e tipo 2: %s\n", pokedex[indicePesquisa].tipo1, pokedex[indicePesquisa].tipo2);
        printf("Cor: %s\n", pokedex[indicePesquisa].cor);
        printf("Altura: %.2f\n", pokedex[indicePesquisa].altura);
        printf("Peso: %.2f\n", pokedex[indicePesquisa].peso);
        printf("Hp: %d\n", pokedex[indicePesquisa].hp);
        printf("Ataque: %d e ataque especial: %d\n", pokedex[indicePesquisa].ataque, pokedex[indicePesquisa].ataqueEspecial);
        printf("Defesa: %d e defesa especial: %d\n", pokedex[indicePesquisa].defesa, pokedex[indicePesquisa].defesaEspecial);
        printf("Velocidade: %d\n", pokedex[indicePesquisa].velocidade);
        printf("Taxa de captura: %d\n", pokedex[indicePesquisa].taxaCaptura);
        printf("Próxima evolução: %d\n", pokedex[indicePesquisa].proximaEvolucao);
        printf("Pré evolução: %d\n", pokedex[indicePesquisa].preEvolucao);
    }//else
}//pesquisaPokemon

//altera os dados de um pokémon
void alteraPokemon(Pokedex *pokedex){

}//alteraPokemon

//função para excluir os dados de um pokémon
void excluiPokemon(Pokedex *pokedex, Colecao *colecao){
    //variavel
    char nomeExcluir[20];
    int indiceExcluir = -1;
    int codigoPokemonExcluir;
    int indiceColecaoExcluir = -1;

    //receber as informações do usuario
    printf("Digite o nome do pokémon que deseja excluir:");
    leString(nomeExcluir, 20);

    //busca as informações do pokemon requisitado
    for(int i=0; i<721; i++){
        if(strcasecmp(nomeExcluir, pokedex[i].nome)==0){
            indiceExcluir = i;
            break;
        }//if
    }//for

    //verifica se há ou não o pokemon a ser excluido
    if(indiceExcluir==-1){
        printf("Esse pokémon não existe, tente novamente!\n");
    } else {
        codigoPokemonExcluir = pokedex[indiceExcluir].numero;

        //encontra o índice do Pokémon na coleção
        for(int i = 0; i < colecao->tamanho; i++){
            if(colecao->pokemons[i] == codigoPokemonExcluir){
                indiceColecaoExcluir = i;
                break;
            }//if
        }//for
    
        //verifica se o pokémon está na coleção
        if(indiceColecaoExcluir==-1){
            printf("Esse pokémon não faz parte da sua coleção!\n");
        } else {
            //move os códigos após o índiceColecaoExcluir uma posição para trás, já que excluímos um código
            for(int i=indiceColecaoExcluir; i < colecao->tamanho-1; i++){
                colecao->pokemons[i] = colecao->pokemons[i + 1];//transfere a posição dos códigos para uma casa anterior
            }//for

            //realocar dinamicamente o espaço para a coleção
            colecao->pokemons = realloc(colecao->pokemons, (colecao->tamanho-1)* sizeof(int));

            //verifica se a realocação está correta
            if(colecao->pokemons == NULL && colecao->tamanho > 0){
                printf("Erro ao realocar memória!\n");
                exit(1);
            }//if

            printf("Pokémon excluído com sucesso!\n");
        }//else interno
    }//else externo
}//excluiPokemon

// Função para liberar a memória alocada pela coleção
void liberarColecao(Colecao *colecao) {
    free(colecao->pokemons);
    colecao->pokemons = NULL;
    colecao->tamanho = 0;
}//liberarColecao

int main(){

    //variaveis
    int escolhaMenu;
    char incluirPokemon[20];
    int codigoPokemonIncluir;
    int indiceIncluir = -1;
    int codiogoPokemonExcluir;

    Pokedex minhaPokedex[721];
    Colecao minhaColecao;

    //chamar a função para iniciar a coleção
    inicializarColecao(&minhaColecao);

    //menu para escolher a ação desejada
    printf("Pressione a tecla correspondente para escolher o que se deseja:\n");
    printf("1-Inserir um novo pokémon.\n");
    printf("2-Listar todos os pokémons.\n");
    printf("3-Pesquisar um pokémon.\n");
    printf("4-Alterar um pokémon.\n");
    printf("5-Excluir os dados de um pokémon.\n");
    scanf("%d", &escolhaMenu);

    //receber o número de 1 a 5
    do{
        switch (escolhaMenu){
            
            case 1:
                //pede ao usuário o nome do pokémon que deseja incluir 
                printf("Digite o nome do pokémon que deseja incluir na coleção: ");
                leString(incluirPokemon, 20);

                //transforma o nome do pokémon para código
                for(int i=0; i<721; i++){
                    if(strcasecmp(incluirPokemon, minhaPokedex[i].nome)==0){
                        indiceIncluir = i;
                        break;
                    }//if
                }//for

                //verifica se há ou não pokemon a ser adicionado
                if(indiceIncluir==-1){
                    Printf("Esse pokémon não existe, tente novamente!\n");
                } else {
                    //atribui o número do código a ser adicionado
                    codigoPokemonIncluir = minhaPokedex[indiceIncluir].numero;
                    //chama a função e passa os argumentos
                    adicionaPokemon(&minhaColecao, codigoPokemonIncluir);  
                }//else
                break;

            case 2:
                listaPokemons(&minhaColecao, &minhaPokedex);
                break;

            case 3:
                pesquisaPokemon(&minhaPokedex);
                break;

            case 4:
                alteraPokemon(&minhaColecao);
                break;
                
            case 5:
                excluiPokemon(&minhaPokedex, &minhaColecao);
                break;

            default:
                printf("Número incompatível!\n");
                break;
        }//switch
    }while(escolhaMenu<1 || escolhaMenu>5);

    //liberar a memória alocada dinamicamente
    liberarColecao(&minhaColecao);

    return 0;
}//main



typedef struct {

} Mochila ;
