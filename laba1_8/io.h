#pragma once
#include "stdio.h"

int scan(const char* _f, void* _x);

void try_get(char*);

void trim(char*);

void try_getf(FILE* f, char* s);
