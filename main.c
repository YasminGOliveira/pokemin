#include "biblioteca.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){
 
    // variaveis
    char incluirPokemon[20];
    int codigoPokemonIncluir;
    int indiceIncluir = -1;
    int codiogoPokemonExcluir;
    int codigo;

    //menus
    int opcao;
    char opcao_1;
    char opcao_2;
    char opcao_3;
    int tamanho = 0;


    //chamar estruturas
    Pokedex minhaPokedex[721];  
    Colecao minhaColecao;  
    Mochila mochila;
    
 
    //alocação da pokedex

    
    // carregar dados do usuario
    carregarDados("pokedexUsuario.dat",&minhaPokedex, tamanho);

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

                                    minhaPokedex[tamanho] = cadastrarPokemonPokedex();
                                    tamanho+=1; 
                                               
                                    
                                     break;

                                    case 'b':
                                    case 'B':

                                        listarPokedex(minhaPokedex, tamanho);
                                        break;

                                    case 'c':
                                    case 'C':

                                        pesquisarPokedex(minhaPokedex, tamanho);
                                        break;
                                    case 'd':
                                    case 'D':
                                        alterarPokedex(minhaPokedex, tamanho);
                                        break;
                                    case 'e':
                                    case 'E':
                                    
                                        break;
                                    case 'f':
                                    case 'F':
                                        exportarDadosPokedexCSV(minhaPokedex, tamanho);
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
                                        if(strcasecmp(incluirPokemon, minhaPokedex[i].nome)==0){
                                            indiceIncluir = i;
                                            break;
                                        }//if
                                    }//for

                                    //verifica se há ou não pokemon a ser adicionado
                                    if(indiceIncluir==-1){
                                        printf("Esse pokémon não existe, tente novamente!\n");
                                    } else {
                                        //atribui o número do código a ser adicionado
                                        codigoPokemonIncluir = minhaPokedex[indiceIncluir].numero;
                                        //chama a função e passa os argumentos
                                        adicionaPokemon(&minhaColecao, codigoPokemonIncluir);  
                                    }//else
                                
                                break;
                            case 'b':
                            case 'B':
                                listaPokemonsColecao(minhaColecao, minhaPokedex); 
                                break;
                            case 'c':
                            case 'C':
                                pesquisarPokedex(minhaPokedex, tamanho);
                                break;
                                case 'e':
                                case 'E':
                                    excluiPokemon(&minhaPokedex, &minhaColecao);
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
                                            comparaPokemon(&minhaColecao, &mochila, i, &minhaPokedex);
                                            }//for para 6 pokemons   
                                        } else {
                                            printf("A mochila está cheia!\n");
                                        }
                                        break;
                                    case 2:
                                        if (mochila.pokemons > 0) {
                                            printf("Digite o codigo do Pokemon que deseja remover da mochila: ");
                                            scanf("%d", &codigo);
                                            removerPokemon(&mochila, codigo, &minhaPokedex, &minhaColecao);
                                        } else {
                                            printf("A mochila esta vazia!\n");
                                        }
                                        break;
                                    case 3:
                                            printf("Pokemons na mochila:\n");
                                            for (int i = 0; i < mochila.pokemons; i++) {
                                            printf("Pokemon %d: Codigo %d\n", i + 1, minhaColecao.mochila[i].codigo);
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
        salvarDados("pokedexUsuario.dat",&minhaPokedex, tamanho);
        
   // free(pokedex);
                
    return 1;

}//ma
