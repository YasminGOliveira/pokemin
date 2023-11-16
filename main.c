#include "manipulaStrings.h"
#include "gerenciarPokemons.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void salvarDados(char *pokedexUsuario, Pokedex *pokedex, int tamanho) {
    FILE *arquivo = fopen(pokedexUsuario, "wb");
    if (arquivo != NULL) {
        fwrite(pokedex, sizeof(Pokedex), tamanho, arquivo);
        fclose(arquivo);
    }
}

void carregarDados(char *pokedexUsuario, Pokedex *pokedex, int tamanho) {
    FILE *arquivo = fopen(pokedexUsuario, "rb");
    if (arquivo != NULL) {
        fread(pokedex, sizeof(Pokedex), tamanho, arquivo);
        fclose(arquivo);
    }
}

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


void excluiPokemon(Pokedex pokedex[], Colecao colecao){
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
        for(int i = 0; i < colecao.tamanho; i++){
            if(colecao.pokemons[i] == codigoPokemonExcluir){
                indiceColecaoExcluir = i;
                break;
            }//if
        }//for
//verifica se o pokémon está na coleção
        if(indiceColecaoExcluir==-1){
            printf("Esse pokémon não faz parte da sua coleção!\n");
        } else {
            //move os códigos após o índiceColecaoExcluir uma posição para trás, já que excluímos um código
            for(int i=indiceColecaoExcluir; i < colecao.tamanho-1; i++){
                colecao.pokemons[i] = colecao.pokemons[i + 1];//transfere a posição dos códigos para uma casa anterior
            }//for

            //realocar dinamicamente o espaço para a coleção
            colecao.pokemons = realloc(colecao.pokemons, (colecao.tamanho-1)* sizeof(int));

            //verifica se a realocação está correta
            if(colecao.pokemons == NULL && colecao.tamanho > 0){
                printf("Erro ao realocar memória!\n");
                exit(1);
            }//if

            printf("Pokémon excluído com sucesso!\n");
        }//else interno
    }//else externo
}//excluiPokemon

//função para excluir os dados de um pokémon
void comparaPokemon(Colecao *colecao, Mochila *mochila, int posicao){
    //variavel
    char nome[20];
    int indiceBuscar = -1;
    int indiceIncluir = -1;
    int indiceIncluir2 = -1;
    int codigoPokemonAdicionar;

 //receber as informações do usuario
    printf("Digite o nome do pokémon que deseja colocar na mochila:");
    leString(nome, 20);

    //transforma o nome do pokémon para código
    for(int i=0; i<pokedex->tamanho; i++){
    if(strcasecmp(nome, minhaPokedex[i].nome)==0){
        indiceIncluir = i;
            break;
        }//if
    }//for

    codigoPokemonAdicionar = minhaPokedex[indiceIncluir].numero;

    for(int i=0; i<colecao->tamanho; i++){
        if(codigoPokemonAdicionar = colecao->pokemons){
            indiceIncluir2 = i;
            break;
        }//if para verificar se o codigo existe na mochila

    }//for

    //verifica se há ou não o pokemon a ser adicionado
    if(indiceIncluir2==-1){
        printf("Você não capturou este pokemon ainda, tente novamente!\n");
    } else {
        codigoPokemonAdicionar = mochila.pokemons[posicao];
    
    }//else externo
}//buscaPokemon


// Função para remover um Pokémon da mochila pelo código
void removerPokemon(Mochila *mochila, int codigo) {

    int codigoPokemonRemover;
    int indiceExcluir = -1;
    int indiceExcluir2 = -1;
    int indiceExcluir3 = -1;

    //transforma o nome do pokémon para código
        for(int i=0; i<pokedex->tamanho; i++){
        if(strcasecmp(nome, minhaPokedex[i].nome)==0){
            indiceExcluir = i;
                break;
            }//if
        }//for

    codigoPokemonRemover = minhaPokedex[indiceExcluir].numero;


    if(indiceExcluir == -1){

        printf("Este pokemon não esta disponivel ainda. Tente novamente!\n");
    }else{
        for(int i=0; i<colecao->tamanho; i++){
                if(codigoPokemonRemover == colecao->pokemons[i]){
                        indiceExcluir2 = i;
                        break;

                }//if
        }//for
    }//else

    if(indiceExcluir2 == -1){
        printf("Este pokemon não foi capturado ainda!\n");

    }else {
       for(int i=0; i<6; i++){
            if(codigoPokemonRemover == mochila.pokemons[i]){
                    indiceExcluir3 = i;
                    break;
            }//if

       }//for

    }//if

    if(indiceExcluir3 == -1){
        printf("Este pokemon não está na mochila!\n");

    }else {
       mochila.pokemons[indiceExcluir3] = NULL;
        printf("Pokemon excluido com sucesso!\n");
    }//if

}

int main(){

    
    // variaveis
    char incluirPokemon[20];
    int codigoPokemonIncluir;
    int indiceIncluir = -1;
    int codiogoPokemonExcluir;

    //menus
    char opcao_1;
    char opcao_2;
    char opcao_3;
    int tamanho = 2;

    //chamar estruturas
    Pokedex pokedex[tamanho];    
    Colecao colecao;
    //*pokedexP = malloc(tamanho * sizeof(Pokedex));
 
    //alocação da pokedex

    
    // carregar dados do usuario
    carregarDados("pokedexUsuario.dat",&pokedex, tamanho);

     do {
        printf("------------ Bem - vindo! ------------\n");
        printf("------------ Menu Principal -----------\n");
        printf("\nEscolha uma opção:\n");
        printf("1. Menu da Pokedex\n");
        printf("2. Menu da Coleção\n");
        printf("3. Menu da Mochila\n");
        printf("0. Sair\n");
        scanf("%d", &opcao_1);

        switch (opcao_1){
            // case para caso o usuario tenha escolhido a opção 
            case 1:
                    printf("--------- Menu da Pokedex ----------\n");
                    printf("-- A. Cadastrar Pokemon\n");
                    printf("-- B. Listar Pokemons\n");
                    printf("-- C. Pesquisar Pokemon\n");
                    printf("-- D. Alterar Pokemon\n");
                    printf("-- E. Excluir Pokemon\n");
                    printf("-- F. Exportar os dados para um arquivo csv\n");
                    printf("-- S. sair\n");
                    scanf(" %c", &opcao_2);

                                switch(opcao_2){
                                    
                                    case 'a':
                                    case 'A':

                                    pokedex[tamanho] = cadastrarPokemonPokedex();
                                    tamanho+=1; 
                                               
                                    
                                     break;

                                    case 'b':
                                    case 'B':

                                        listarPokedex(pokedex, tamanho);
                                        break;

                                    case 'c':
                                    case 'C':

                                        pesquisarPokedex(pokedex, tamanho);
                                        break;
                                    case 'd':
                                    case 'D':
                                        alterarPokedex(pokedex, tamanho);
                                        break;
                                    case 'e':
                                    case 'E':
                                    
                                        break;
                                    case 'f':
                                    case 'F':
                                        exportarDadosPokedexCSV(pokedex, tamanho);
                                        break;
                                    case 's':
                                    case 'S':
                                        printf("Voltando para o Menu Principal! ");
                                    default:
                                        printf("Opção invalida!\n");
                                        break; // default
                                        }// switch da função das Pokedex

                    break;// break do case 1

            // case para caso o usuario escolha a opção 
            case 2:
                        printf("--------- Menu da Coleção ----------\n");
                        printf("-- A. Cadastrar Pokemons\n");
                        printf("-- B. Listar Pokemons\n");
                        printf("-- C. Pesquisar Pokemon\n");
                        printf("-- D. Alterar Pokemon\n");
                        printf("-- E. Excluir os dados de um Pokemon\n");
                        printf("-- F. Exportar dados para um arquivo CSV\n");
                        scanf(" %c", &opcao_2);

                            switch (opcao_2)
                            {
                            case 'a':
                            case 'A':
                                    //pede ao usuário o nome do pokémon que deseja incluir 
                                    printf("Digite o nome do pokémon que deseja incluir na coleção: ");
                                    leString(incluirPokemon, 20);

                                    //transforma o nome do pokémon para código
                                    for(int i=0; i<721; i++){
                                        if(strcasecmp(incluirPokemon, pokedex[i].nome)==0){
                                            indiceIncluir = i;
                                            break;
                                        }//if
                                    }//for

                                    //verifica se há ou não pokemon a ser adicionado
                                    if(indiceIncluir==-1){
                                        printf("Esse pokémon não existe, tente novamente!\n");
                                    } else {
                                        //atribui o número do código a ser adicionado
                                        codigoPokemonIncluir = pokedex[indiceIncluir].numero;
                                        //chama a função e passa os argumentos
                                        adicionaPokemon(&colecao, codigoPokemonIncluir);  
                                    }//else
                                
                                break;
                            case 'b':
                            case 'B':
                                listaPokemonsColecao(colecao, pokedex); 
                                break;
                            case 'c':
                            case 'C':
                                pesquisarPokedex(pokedex, tamanho);
                                break;
                                case 'e':
                                case 'E':
                                    excluiPokemon(&pokedex, &colecao);
                                     break;
                                case 'v':
                                case 'V':
                                    printf("Voltando para o Menu Principal! ");
                                    break;
                                default:
                                    printf("Opção Invalida!\n");
                                    break;
                                }// switch para as opções da coleção
                break;//break do case2
            case 3:
                                    do {
                    printf("\nMenu:\n");
                    printf("1. Colocar um Pokemon na mochila\n");
                    printf("2. Remover um Pokemon da mochila\n");
                    printf("3. Verificar os pokemons que há na mochila\n");
                    printf("4. Sair\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao);
            
                    switch (opcao) {
                        case 1:
                            if (mochila.pokemons < 6) {
                                for(int i =0; i<6; i++){
                                comparaPokemon(&colecao, &mochila, i);
                                }//for para 6 pokemons   
                            } else {
                                printf("A mochila está cheia!\n");
                            }
                            break;
                        case 2:
                            if (mochila.pokemons > 0) {
                                printf("Digite o codigo do Pokemon que deseja remover da mochila: ");
                                scanf("%d", &codigo);
                                removerPokemon(&mochila, codigo);
                            } else {
                                printf("A mochila esta vazia!\n");
                            }
                            break;
                        case 3:
                                printf("Pokemons na mochila:\n");
                                for (int i = 0; i < mochila.pokemons; i++) {
                                printf("Pokemon %d: Codigo %d\n", i + 1, colecao.mochila[i].codigo);
                            }
                            break;
                        case 4:
                            printf("Saindo do programa.\n");
                            break;
                        default:
                            printf("Opcao invalida! Escolha novamente.\n");
                            break;
                    }
                } while (opcao != 4);
                
            break;//break do case3
            
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
            break;

        }// switch menu principal

        
     }while (opcao_1 != 0); 

        // salvar os dados da pokedex do usuario
        salvarDados("pokedexUsuario.dat",&pokedex, tamanho);
        
   // free(pokedex);
                
    return 1;

}//main
