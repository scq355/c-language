//
// Created by scq on 2019/11/16.
//

#ifndef C_LANAGUE_CHAPTER10_H
#define C_LANAGUE_CHAPTER10_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 100
#define MAX_TOWN 10
#define LENGTH 50

void try_input(char *prompt, char *fromat);

void eatspace(void);
bool getinteger(int *n);
char *getname(char *name, size_t length);
bool isnewline(void);

int chapter1001(void);
int	chapter1002(void);
int chapter1005(void);
int chapter1006(void);
int chapter1007(void);
int chapter1010(void);
int chapter1009(void);
int chapter1010(void);
int chapter1011(void);

#endif //C_LANAGUE_CHAPTER10_H
