//
// Created by hsume on 28/06/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para executar o código compilado
int executeCode(char* compiledCode)
{
    Queue queue;
    initializeQueue(&queue);

    char* instruction = strtok(compiledCode, "\n");
    while (instruction != NULL)
    {
        printf("instruction: %s\n", instruction);
        if (strcmp(instruction, "ADD") == 0) {
            int operand2 = dequeue(&queue);
            int operand1 = dequeue(&queue);
            if(operand1 == NULL){
                enqueue(&queue, operand2);
            }else{
                int result = operand1 + operand2;
                enqueue(&queue, result);
            }
        } else if (strcmp(instruction, "SUB") == 0) {
            int operand2 = dequeue(&queue);
            int operand1 = dequeue(&queue);
            if(operand1 == NULL){
                enqueue(&queue, operand2);
            }else{
                int result = operand1 - operand2;
                enqueue(&queue, result);
            }
        } else if (strcmp(instruction, "MUL") == 0) {
            int operand2 = dequeue(&queue);
            int operand1 = dequeue(&queue);
            if(operand1 == NULL){
                enqueue(&queue, operand2);
            }else{
                int result = operand1 * operand2;
                enqueue(&queue, result);
            }
        } else if (strcmp(instruction, "DIV") == 0) {
            int operand2 = dequeue(&queue);
            int operand1 = dequeue(&queue);
            if(operand1 == NULL){
                enqueue(&queue, operand2);
            }else{
                int result = operand1 / operand2;
                enqueue(&queue, result);
            }
        } else {
            int value = atoi(instruction + strlen("PUSH "));
            enqueue(&queue, value);
        }

        instruction = strtok(NULL, "\n");
    }

    // Exibir o resultado
    int result = dequeue(&queue);
    return result;
}