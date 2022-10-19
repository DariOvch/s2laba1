#define _CRT_SECURE_NO_WARNINGS
#include "io.h"
#include "stdio.h"
#include "string.h"
#include <crtdbg.h>
#include "stdlib.h"

void myInvalidParamHandler(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, uintptr_t)
{

}

int scan(const char* _f, void* _x)
{
	while (1)
	{
		printf("input: ");
		if (scanf(_f, _x) != 1)
			printf("try again\n");
		else
		{
			if (getchar());
			return 1;
		}
		if (getchar());
	}
}

void try_get(char* s)
{
	_CrtSetReportMode(_CRT_ASSERT, 0);
	_invalid_parameter_handler oldHandler = _set_invalid_parameter_handler(myInvalidParamHandler);
	if (gets_s(s, 200) == nullptr)
	{	
		_set_invalid_parameter_handler(oldHandler);
		throw (char*)"input error thrown, line too short for input\n";
	}
	_set_invalid_parameter_handler(oldHandler);
}


void trim(char* s)
{
	int len = strlen(s);
	s[len - 2] = '\0';
}