//
// Created by hsume on 28/06/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"

// Função de análise léxica (quebra o código-fonte em tokens)
char** lexer(const char* code, int* numTokens)
{
    char* codeCopy = strdup(code); // Criar uma cópia mutável do código
    int maxTokens = 100; // Número máximo inicial de tokens
    int tokenCount = 0;
    char** tokens = malloc(maxTokens * sizeof(char*));

    char* token = strtok(codeCopy, " ");
    while (token != NULL)
    {
        tokens[tokenCount] = malloc(strlen(token) + 1);
        strcpy(tokens[tokenCount], token);
        tokenCount++;

        // Verificar se excedeu o número máximo de tokens
        if (tokenCount >= maxTokens)
        {
            maxTokens += 100; // Adicionar mais 100 slots para tokens
            tokens = realloc(tokens, maxTokens * sizeof(char*));
        }

        token = strtok(NULL, " ");
    }

    *numTokens = tokenCount;
    free(codeCopy); // Liberar a cópia mutável do código

    return tokens;
}

// Função de análise sintática (verifica a estrutura gramatical)
void parser(char** tokens, int numTokens)
{
    for (int i = 0; i < numTokens; i++)
    {
        if (strcmp(tokens[i], "+") != 0 && strcmp(tokens[i], "-") != 0 &&
            strcmp(tokens[i], "*") != 0 && strcmp(tokens[i], "/") != 0)
        {
            char* endptr;
            strtol(tokens[i], &endptr, 10);

            if (*endptr != '\0')
            {
                fprintf(stderr, "Token invalido: %s\n", tokens[i]);
                exit(1);
            }
        }
    }
}

// Função de geração de código (converte os tokens em código de destino)
char* code_generator(char** tokens, int numTokens)
{
    char* result = malloc(100 * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numTokens; i++)
    {
        if (strcmp(tokens[i], "+") == 0)
        {
            strcat(result, "ADD\n");
        } else if (strcmp(tokens[i], "-") == 0)
        {
            strcat(result, "SUB\n");
        } else if (strcmp(tokens[i], "*") == 0)
        {
            strcat(result, "MUL\n");
        } else if (strcmp(tokens[i], "/") == 0)
        {
            strcat(result, "DIV\n");
        } else {
            strcat(result, "PUSH ");
            strcat(result, tokens[i]);
            strcat(result, "\n");
        }
    }

    return result;
}

// Função principal do compilador
char* compiler(char* code)
{
    int numTokens;
    char** tokens = lexer(code, &numTokens);
    parser(tokens, numTokens);
    char* generatedCode = code_generator(tokens, numTokens);

    for (int i = 0; i < numTokens; i++)
    {
        free(tokens[i]);
    }

    free(tokens);

    return generatedCode;
}