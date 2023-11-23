#ifndef MANIPULASTRINGS_H
#define MANIPULASTRINGS_H
#include <string.h>
#include <stdio.h>

// função para ler srings
    void leString(char string[], int tamanho){
        setbuf(stdin, NULL);
        fgets(string, tamanho, stdin);
        string[strcspn(string, "\n")]= '\0';
    }// função para ler strings

// função para remover espaçoes em branco de uma string
    void removeEspacos(char* str) {
        int cont = 0;

        for (int i = 0; str[i]; i++) {
            if (str[i] != ' ')
                str[cont++] = str[i];
        }

        str[cont] = '\0';
    }// função para remover espaços em branco


#endif
