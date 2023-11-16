#include "manipulaStrings.h"
#ifndef GERENCIARPOKEMONS_H
#define GERENCIARPOKEMONS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct{
//basico
    int numero;
    char nome[21];
    char tipo1[20];
    char tipo2[20];

    //info p/luta
    
    int total;
    int hp;
    int ataque;
    int defesa;
    int ataqueEspecial;
    int defesaEspecial;
    int velocidade;
    
    //lendario boleano fazer;
    bool lendario;

    //tabela de infos gerais
    int geracao;
    char cor[15];
    float altura;
    float peso;
    int taxaCaptura;
    int proximaEvolucao;
    int preEvolucao;
    
}Pokedex;

// Definição da estrutura da Mochila
typedef struct{
    // estrutura Pokemon coleção colocar(chamar)
    int pokemons[6];
}Mochila;

//estrutura colecao
typedef struct{
    int *pokemons;
    int tamanho;
    Mochila mochila;
} Colecao ;

// ------------------------------- Funções para a Pokedex ---------------------------------------------------------
// função para cadastar pokemons
Pokedex cadastrarPokemonPokedex(){
    
    Pokedex pokedex;       
    // variaveis
    char line[1024];

    // abrir os arquivos
    FILE *csvFile = fopen("pokedex.csv", "r");
    FILE *txtFile = fopen("PokemonCadastrado.txt", "a+");


        //verificar se os arquivos estão abrindo ou sendo criados corretamente
        if(csvFile == NULL || txtFile == NULL){
            txtFile = fopen("PokemonCadastrado.txt","a");
        
        if (csvFile == NULL || txtFile == NULL) {
            perror("Erro ao abrir os arquivos.");
            exit(1);
        }

        }// if para começar o array
    // pedir ao usuario para inserir o nome do pokemon que deseja cadastar
      printf("Insira o nome do pokemon que deseja cadastrar: ");
                leString(pokedex.nome,21);

                // ler todos os pokemons presentes no arquivo csv
                while(fgets(line, sizeof(line), csvFile)) {
                    

                // Atribuir as strings presentes no arquivo para uma variavel temporaria i
                char *leitura = strtok(line, ",");
        
                // numero do pokemon
                int numero = atoi(leitura);
                leitura = strtok(NULL, ",");
            

                // nome do pokemon da linha que está sendo lida
                char nome[1024];
                strcpy(nome, leitura);
                

                // remover os espaços em branco presentes na string lida
                removeEspacos(nome);

                // if para comparar o nome que esta sendo lido com o nome do pokemon que o usuario inseriu e verificqar se é esse pokemon que o usuario quer cadastrar
                if(strcasecmp(nome,pokedex.nome)==0){

                        // se o pokemon foi encontrado, atribuimos as informações presentes no arquivo csv para a estrutura do usuario

                            // numero
                            pokedex.numero = numero;
                            // tipo 1
                            leitura = strtok(NULL, ",");
                            
                            strcpy(pokedex.tipo1, leitura);
                            
                            // tipo 2
                            leitura = strtok(NULL, ",");
                            strcpy(pokedex.tipo2, leitura);

                            //total
                            leitura = strtok(NULL, ",");
                            pokedex.total = atoi(leitura);

                            //hp
                            leitura = strtok(NULL, ",");
                            pokedex.hp = atoi(leitura);

                            //ataque
                            leitura = strtok(NULL, ",");
                            pokedex.ataque = atoi(leitura);

                            //defesa
                            leitura = strtok(NULL, ",");
                            pokedex.defesa = atoi(leitura);

                            // ataque especial
                            leitura = strtok(NULL, ",");
                            pokedex.ataqueEspecial = atoi(leitura);

                            //defesa especial
                            leitura = strtok(NULL, ",");
                            pokedex.defesaEspecial = atoi(leitura);

                            // velocidade
                            leitura = strtok(NULL, ",");
                            pokedex.velocidade = atoi(leitura);

                            //geração
                            leitura = strtok(NULL, ",");
                            pokedex.geracao = atoi(leitura);

                            //lendario
                            leitura = strtok(NULL, ",");
                            pokedex.lendario = atoi(leitura);

                            // cor
                            leitura = strtok(NULL, ",");
                            strcpy(pokedex.cor,leitura);

                            //altura
                            //token = strtok(NULL, ",");
                            // pegar o valor de altura 
                        
                            //peso
                            // taxa de captura


                            // Exibir os dados dos pokemons
                            fprintf(txtFile, "Numero: %d\n", pokedex.numero);
                            fprintf(txtFile, "Nome: %s\n", pokedex.nome);
                            fprintf(txtFile, "Tipo 1: %s\n", pokedex.tipo1);
                            fprintf(txtFile, "Tipo 2: %s\n", pokedex.tipo2);
                            fprintf(txtFile, "Total: %d\n", pokedex.total);
                            fprintf(txtFile, "Hp: %d\n", pokedex.hp);
                            fprintf(txtFile, "Ataque: %d\n", pokedex.ataque);
                            fprintf(txtFile, "Defesa: %d\n", pokedex.defesa);
                            fprintf(txtFile, "Ataque Especial: %d\n", pokedex.ataqueEspecial);
                            fprintf(txtFile, "Defesa Especial: %d\n", pokedex.defesaEspecial);
                            fprintf(txtFile, "Velocidade: %d\n", pokedex.velocidade);
                            fprintf(txtFile, "Geração: %d\n", pokedex.geracao);
                            fprintf(txtFile, "Lendario: %d\n", pokedex.lendario);
                            fprintf(txtFile, "Cor: %s\n", pokedex.cor);

                            fprintf(txtFile, "\n");  // Adicione uma linha em branco entre os registros, se desejar
                           return pokedex;
                }// if para encontrar o pokemon
            }// while

            // fechar os aarquivos

            fclose(csvFile);
            fclose(txtFile);
            return pokedex;
}// função para cadastrar os pokemons


// Função para listar todos os registros

void listarPokedex(Pokedex pokedex[], int tamanho) {
    printf("Lista de registros:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Numero: %d, Nome: %s\n", pokedex[i].numero, pokedex[i].nome);
    }
    return;
}


// função para pesquisar um pokemon por código
void pesquisarPokedex(Pokedex pokedex[], int tamanho) {

    char nomePesquisado[21];

   // receber o nome do pokemon
   printf("Digite o nome do pokemon a ser pesquisado: ");
   leString(nomePesquisado,21);

    // comparar o nome que o usuario quer pesquisar com os nomes persentes na pokedex dele
    for(int contador = 0; contador < tamanho; contador++){

    if(strcasecmp(nomePesquisado, pokedex[contador].nome)==0){
        printf("Pokemon encontrado!\n Código: %d, Nome: %s\n", pokedex[contador].numero, pokedex[contador].nome);
        return;
    }

    }// for para achar o pokemon

    printf("Registro não encontrado.\n");
}


// Função para alterar um registro por código
Pokedex alterarPokedex(Pokedex pokedex[], int tamanho) {

    char pokemonAlterado;
    int numeroPokemon;
    printf("Digite o nome do pokemon a ser alterado: ");
    leString(pokemonAlterado, 21);

    for (int i = 0; i < tamanho; i++) {
        if (strcasecmp(pokemonAlterado, pokedex[i].nome)==0) {
            numeroPokemon = i;
            printf("Digite o novo nome: ");
            leString(pokedex[i].nome,21);
            printf("Registro alterado com sucesso!\n");
            printf("Novo nome: %s",pokedex[i].nome);
            return;
        }
    }

    printf("Registro não encontrado.\n");
    return pokedex[numeroPokemon];
}

// Função para excluir um registro por código
/*
void excluir(Pokedex registros, int *tamanho) {
    int codigo;
    printf("Digite o código a ser excluído: ");
    scanf("%d", &codigo);

    for (int i = 0; i < *tamanho; i++) {
        if ((*registros)[i].numero == codigo) {
            for (int j = i; j < *tamanho - 1; j++) {
                (*registros)[j] = (*registros)[j + 1];
            }
            *tamanho -= 1;
            *registros = realloc(*registros, (*tamanho) * sizeof(Pokedex));
            printf("Registro excluído com sucesso!\n");
            return;
        }
    }

    printf("Registro não encontrado.\n");
}
*/






// função para exportar os dados das estruturas para um arquivo csv
void exportarDadosPokedexCSV(Pokedex pokedex[], int tamanho){

    FILE *arquivo = fopen("dadosPokedex.csv","w");
    
        // testar se o arquivo está abrindo corretamente
        if(arquivo == NULL){
            printf("Erro ao abrir o arquivo!\n");
            exit(1);
            }// if
        fprintf(arquivo,"numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor     \n");

        // copiar os dados para o arquivo csv
            for(int contador =0; contador <tamanho; contador++){
                // verifica se já eiste um pokemon com o mesmo nome no arquivo
                    fprintf(arquivo, "%-7d, ", pokedex[contador].numero);
                    // adicionar virgula
                    fprintf(arquivo, "%-11s,", pokedex[contador].nome);
                    fprintf(arquivo, "%-8s,", pokedex[contador].tipo1);
                    fprintf(arquivo, "%-8s,", pokedex[contador].tipo2);
                    fprintf(arquivo, " %-5d,", pokedex[contador].total);
                    fprintf(arquivo, " %3d,", pokedex[contador].hp);
                    fprintf(arquivo, " %6d,", pokedex[contador].ataque);
                    fprintf(arquivo, " %6d,", pokedex[contador].defesa);
                    fprintf(arquivo, " %15d,", pokedex[contador].ataqueEspecial);
                    fprintf(arquivo, " %15d,", pokedex[contador].defesaEspecial);
                    fprintf(arquivo, " %10d,", pokedex[contador].velocidade);
                    fprintf(arquivo, " %7d,", pokedex[contador].geracao);
                    fprintf(arquivo, " %8d,", pokedex[contador].lendario);
                    fprintf(arquivo, " %7s\n", pokedex[contador].cor);

            }// for paraescrever os dados das estruturas no arquivo
        
    fclose(arquivo);
}


// --------------------------------- funções para a coleçao----------------------------------------------

//função para listar os pokémons da coleção
void listaPokemonsColecao(Colecao colecao, Pokedex pokedex[]){
    //variavel
    int indiceListar;

    //transformar os códigos em nomes e exibir os pokemons
    printf("Pokémons na coleção: ");
    for(int i=0; i<colecao.tamanho; i++){
        for(int j=0; j<721; j++){
            if(colecao.pokemons[i] == pokedex[j].numero){
                indiceListar = j;
                printf("%s ", pokedex[indiceListar].nome);
            }//if
        }//for interno
    }//for exetrno
    printf("\n");
    return;
}//listaPokemons

//função para excluir os dados de um pokémon
Colecao excluiPokemon(Pokedex pokedex[], Colecao colecao){
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
    return colecao;
}//excluiPokemon




#endif
