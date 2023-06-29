//
// Created by hsume on 28/06/2023.
//

#ifndef MATHCOMPILER_COMPILER_H
#define MATHCOMPILER_COMPILER_H

char** lexer(const char* code, int* numTokens);
void parser(char** tokens, int numTokens);
char* code_generator(char** tokens, int numTokens);
char* compiler(char* code);

#endif //MATHCOMPILER_COMPILER_H
