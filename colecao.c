#include "colecao.h"

int transformaNomeEmCodigo (char nome, Pokedex* minhaPokedex){
    //transforma o nome do pokémon para código
    int indice;
    for(int i=0; i<pokedex->tamanho; i++){
        if(strcasecmp(nome, minhaPokedex[i].nome)==0){
            indice = i;
            break;
        }//if
    }//for
return indice;
}//transformaNomeEmCodigo

//função para receber uma string
void leString(char string[], int tamanho){
    setbuf(stdin, NULL);
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")]= '\0';
}//leString

//função para inicializar a coleção, excluindo a possibilidade de ter um valor lixo
void inicializarColecao(Colecao *colecao) {
    colecao->pokemons = (int*) mallonar oc (1 * sizeof(int));
    colecao->tamanho = 0;
}//inicializarColecao

//função para adicium pokémon a coleção
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
        for(int j=0; j<pokedex->tamanho; j++){
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
    for(int i=0; i<pokedex->tamanho; i++){
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
    for(int i=0; i<pokedex->tamanho; i++){
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
