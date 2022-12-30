#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdlib.h>
#include <stdarg.h>

int _putchar(char c);

int _printf(const char *format, ...);

int spec_num(const char *format);

typedef struct specifiers
{
	char *id;
	int (*printer)(void *type);
}SPEC;

SPEC get_specifier(char *c);




#endif
