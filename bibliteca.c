#include "biblioteca.h"

Pokedex minhaPokedex[721];
Colecao *minhaColecao;

//----------------------------------------------funções genéricas---------------------------------------------------

int transformaNomeEmCodigo (char nome, Pokedex minhaPokedex[], int tamanho){
    //transforma o nome do pokémon para código
    int indice;
    for(int i=0; i<tamanho; i++){
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

//função para remover espaçoes em branco de uma string
void removeEspacos(char* str){
    int cont = 0;
    for (int i = 0; str[i]; i++){
        if (str[i] != ' ')
        str[cont++] = str[i];
    }//for
    str[cont] = '\0';
}//removeEspacos

void capturaPokemon(int nivel, Pokedex minhaPokedex[], Mochila* minhaMochila){
    //variavel
    int sorteado;
    int indice;
    char nomeSorteado[20];
    int resposta;


    //pokemons disponiveis para captura de acordo com o nível
    switch (nivel){
    case 1:
        //nível 1: pokemons de primeira geração(codigo: 1-151)
        srand((unsigned)time(NULL));

        for (int i=1; i<152; i++){
            sorteado = rand();
        }//for

        //transformar o codigo em nome
        for (int i=1; i<152; i++){
            if(sorteado == minhaPokedex[i].numero){
                indice = i;
            }//if
        }//for
        nomeSorteado[20] = minhaPokedex[indice].nome;

        //aparece pro usuário
        printf("O pokémon %s cruzou o seu caminho! Deseja capturá-lo?\n", nomeSorteado);
        printf("1-Sim, desejo capturá-lo.\n");
        printf("2-Não, deixe ele na natureza.\n");
        scanf("%d", &resposta);

        do{
            if(resposta == 1){
                printf("Pokémon capturado com sucesso!\n");
                minhaMochila->pokebolas--;
            } else {
                continue;
            }//else
        }while(resposta!=1 || resposta!=2);
 
        break;

    case 2:
        //nível 2: pokemons de segunda geração(codigo: 152-252)
        srand((unsigned)time(NULL));

        for (int i=152; i<253; i++){
            sorteado = rand();
        }//for

        //transformar o codigo em nome
        for (int i=152; i<253; i++){
            if(sorteado == minhaPokedex[i].numero){
                indice = i;
            }//if
        }//for
        nomeSorteado[20] = minhaPokedex[indice].nome;

        //aparece pro usuário
        printf("O pokémon %s cruzou o seu caminho! Deseja capturá-lo?\n", nomeSorteado);
        printf("1-Sim, desejo capturá-lo.\n");
        printf("2-Não, deixe ele na natureza.\n");
        scanf("%d", &resposta);

        do{
            if(resposta == 1){
                printf("Pokémon capturado com sucesso!\n");
                minhaMochila->pokebolas--;
            } else {
                continue;
            }//else
        }while(resposta!=1 || resposta!=2);
 
        break;

    case 3:
        //nível 3: pokemons de terceira geração(codigo: 253-387)
        srand((unsigned)time(NULL));

        for (int i=253; i<388; i++){
            sorteado = rand();
        }//for

        //transformar o codigo em nome
        for (int i=253; i<388; i++){
            if(sorteado == minhaPokedex[i].numero){
                indice = i;
            }//if
        }//for
        nomeSorteado[20] = minhaPokedex[indice].nome;

        //aparece pro usuário
        printf("O pokémon %s cruzou o seu caminho! Deseja capturá-lo?\n", nomeSorteado);
        printf("1-Sim, desejo capturá-lo.\n");
        printf("2-Não, deixe ele na natureza.\n");
        scanf("%d", &resposta);

        do{
            if(resposta == 1){
                printf("Pokémon capturado com sucesso!\n");
                minhaMochila->pokebolas--;
            } else {
                continue;
            }//else
        }while(resposta!=1 || resposta!=2);
 
        break;

    case 4:
        //nível 4: pokemons de quarta geração(codigo: 388-494)
        srand((unsigned)time(NULL));

        for (int i=388; i<495; i++){
            sorteado = rand();
        }//for

        //transformar o codigo em nome
        for (int i=388; i<495; i++){
            if(sorteado == minhaPokedex[i].numero){
                indice = i;
            }//if
        }//for
        nomeSorteado[20] = minhaPokedex[indice].nome;

        //aparece pro usuário
        printf("O pokémon %s cruzou o seu caminho! Deseja capturá-lo?\n", nomeSorteado);
        printf("1-Sim, desejo capturá-lo.\n");
        printf("2-Não, deixe ele na natureza.\n");
        scanf("%d", &resposta);

        do{
            if(resposta == 1){
                printf("Pokémon capturado com sucesso!\n");
                minhaMochila->pokebolas--;
            } else {
                continue;
            }//else
        }while(resposta!=1 || resposta!=2);
 
        break;

    case 5:
        //nívelv5: pokemons de quinta e sexta geração(codigo: 495-721)
        srand((unsigned)time(NULL));

        for (int i=495; i<722; i++){
            sorteado = rand();
        }//for

        //transformar o codigo em nome
        for (int i=495; i<722; i++){
            if(sorteado == minhaPokedex[i].numero){
                indice = i;
            }//if
        }//for
        nomeSorteado[20] = minhaPokedex[indice].nome;

        //aparece pro usuário
        printf("O pokémon %s cruzou o seu caminho! Deseja capturá-lo?\n", nomeSorteado);
        printf("1-Sim, desejo capturá-lo.\n");
        printf("2-Não, deixe ele na natureza.\n");
        scanf("%d", &resposta);

        do{
            if(resposta == 1){
                printf("Pokémon capturado com sucesso!\n");
                minhaMochila->pokebolas--;
            } else {
                continue;
            }//else
        }while(resposta!=1 || resposta!=2);
 
        break;

    default:
        printf("Opção inválida!\n");
    break;

    }//switch
}//capturaPokemon

//------------------------------------------------funções da pokedex---------------------------------------------------------------

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

//função para cadastar pokemons
Pokedex cadastrarPokemonPokedex(Pokedex minhaPokedex[], int tamanho){

    //variaveis
    char line[1024];
    char nomeCadastro[21];

    //abrir os arquivos
    FILE *csvFile = fopen("pokedex.csv", "r");
    FILE *txtFile = fopen("PokemonCadastrado.txt", "a+");


    //verificar se os arquivos estão abrindo ou sendo criados corretamente
    if(csvFile == NULL || txtFile == NULL){
        txtFile = fopen("PokemonCadastrado.txt","a");
        if (csvFile == NULL || txtFile == NULL) {
            perror("Erro ao abrir os arquivos.");
            exit(1);
        }//if
    }//if para começar o array

    //pedir ao usuario para inserir o nome do pokemon que deseja cadastar
    printf("Insira o nome do pokemon que deseja cadastrar: ");
    leString(nomeCadastro,21);

    //ler todos os pokemons presentes no arquivo csv
    while(fgets(line, sizeof(line), csvFile)){
        
        //atribuir as strings presentes no arquivo para uma variavel temporaria i
        char *leitura = strtok(line, ",");

        //numero do pokemon
        int numero = atoi(leitura);
        leitura = strtok(NULL, ",");

        //nome do pokemon da linha que está sendo lida
        char nome[1024];
        strcpy(nome, leitura);
        
        //remover os espaços em branco presentes na string lida
        removeEspacos(nome);

        /*if para comparar o nome que esta sendo lido com o nome do pokemon que o usuario inseriu e 
        verificqar se é esse pokemon que o usuario quer cadastrar*/
        if(strcasecmp(nome,nomeCadastro)==0){

            //se o pokemon foi encontrado, atribuimos as informações presentes no arquivo csv para a estrutura do usuario

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

                //ataque especial
                leitura = strtok(NULL, ",");
                pokedex.ataqueEspecial = atoi(leitura);

                //defesa especial
                leitura = strtok(NULL, ",");
                pokedex.defesaEspecial = atoi(leitura);

                //velocidade
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


                //exibir os dados dos pokemons
                fprintf(txtFile, "Numero: %d\n", pokedex.numero);
                fprintf(txtFile, "Nome: %s\n", nomeCadastro);
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
                fprintf(txtFile, "\n");//adiciona uma linha em branco entre os registros, para melhor organização
            return pokedex;
        }//if para encontrar o pokemon
    }//while

    //fechar os aarquivos
    fclose(csvFile);
    fclose(txtFile);

 return pokedex;
}//cadastrarPokemonPokedex


//função para listar todos os registros
void listarPokedex(Pokedex pokedex[], int tamanho){
    printf("Lista de registros:\n");
    for (int i = 0; i < tamanho; i++){
        printf("Numero: %d, Nome: %s\n", pokedex[i].numero, pokedex[i].nome);
    }//for
    return;
}//listarPokedex


//função para pesquisar um pokemon por código
void pesquisarPokedex(Pokedex pokedex[], int tamanho){

    //variavel
    char nomePesquisado[21];

    //receber o nome do pokemon
    printf("Digite o nome do pokemon a ser pesquisado: ");
    leString(nomePesquisado,21);

    //comparar o nome que o usuario quer pesquisar com os nomes persentes na pokedex dele
    for(int contador = 0; contador < tamanho; contador++){
        if(strcasecmp(nomePesquisado, pokedex[contador].nome)==0){
            printf("Pokemon encontrado!\n Código: %d, Nome: %s\n", pokedex[contador].numero, pokedex[contador].nome);
            return;
        }//if
    }//for para achar o pokemon

    printf("Registro não encontrado.\n");
}//pesquisarPokedex


//função para alterar um registro por código
Pokedex alterarPokedex(Pokedex pokedex[], int tamanho){

    //variaveis
    char pokemonAlterado;
    int numeroPokemon;

    //receber do jogador o nome
    printf("Digite o nome do pokemon a ser alterado: ");
    leString(pokemonAlterado, 21);

    //procurando o nome na pokedex
    for(int i = 0; i < tamanho; i++){
        if (strcasecmp(pokemonAlterado, pokedex[i].nome)==0){
            numeroPokemon = i;
            printf("Digite o novo nome: ");
            leString(pokedex[i].nome,21);
            printf("Registro alterado com sucesso!\n");
            printf("Novo nome: %s",pokedex[i].nome);
            return;
        }//if
    }//for

    printf("Registro não encontrado.\n");
    return pokedex[numeroPokemon];
}//alterarPokedex

//função para excluir um registro por código
void excluir(Pokedex registros, int *tamanho){
    //variavel
    int codigo;

    //receber informações do jogador
    printf("Digite o código a ser excluído: ");
    scanf("%d", &codigo);

    for(int i = 0; i < *tamanho; i++){
        if((*registros)[i].numero == codigo){
            for(int j = i; j < *tamanho - 1; j++){
                (*registros)[j] = (*registros)[j + 1];
            }//for interno
            *tamanho -= 1;
            *registros = realloc(*registros, (*tamanho) * sizeof(Pokedex));
            printf("Registro excluído com sucesso!\n");
            return;
        }//if
    }//for exetrno

    printf("Registro não encontrado.\n");
}//excluir


//função para exportar os dados das estruturas para um arquivo csv
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
        //verifica se já existe um pokemon com o mesmo nome no arquivo
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
    }//for para escrever os dados das estruturas no arquivo
        
    fclose(arquivo);
}//exportarDadosPokedexCSV


//------------------------------------------------funções da coleção---------------------------------------------------------------

//função para inicializar a coleção, excluindo a possibilidade de ter um valor lixo
void inicializarColecao(Colecao *colecao) {
    colecao->pokemons = (int*) malloc (1 * sizeof(int));
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

//------------------------------------------funções da mochila-----------------------------------------------------------

//função para excluir os dados de um pokémon
void adicionaPokemonMochila(Pokedex *minhaPokedex ,Colecao *colecao, Mochila *mochila, int posicao){
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
    for(int i=0; i<721; i++){
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
        }//if para verificar se o codigo existe na coleção
    }//for

    //verifica se há ou não o pokemon a ser adicionado
    if(indiceIncluir2==-1){
        printf("Você não capturou este pokemon ainda, tente novamente!\n");
    } else {
        codigoPokemonAdicionar = mochila.pokemons[posicao];//atribui o código daquele pokemon na mochila
    }//else externo
}//adicionaPokemonMochila


//função para remover um Pokémon da mochila
void removerPokemonMochila(Pokedex * minhaPokedex, Mochila *mochila, int codigo){

    //variaveis
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

}//removerPokemonMochila
