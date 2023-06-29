//
// Created by hsume on 27/06/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "execute.h"
#include "compiler.h"

void Compile()
{
    // Exemplo de código-fonte em Minilang
    char* sourceCode = "2 + 3 * 4";

    // Compilar o código-fonte
    char* compiledCode = compiler(sourceCode);

    // Imprimir o código compilado
    printf("Codigo-fonte original: %s\n", sourceCode);
    printf("Codigo compilado:\n%s\n", compiledCode);

    // Executar o código compilado até o ponto de exibir o resultado
    int result = executeCode(compiledCode);
    printf("Resultado: %d\n", result);

    // Liberar memória alocada
    free(compiledCode);
}

int main() {
    Compile();
    return 0;
}
