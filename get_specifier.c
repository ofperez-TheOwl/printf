#include "main.h"

/**
 * get_specifier - find the specifier and the adequate
 * printer function
 * @c: pointer to char; identifier of the specifier
 *
 * Return: SPEC type object containing the printer function
 * TheOwl
 */

SPEC get_specifier(char *c)
{
	int i = 0;
	SPEC spec_list[] = {
		{'c', _putchar},
		{'s', print_string},
		{'%', _putchar},
		{NULL, print_norm}
	};

	while ((spec_list[i]).id != NULL)
	{
		if (*c == (spec_list[i]).id)
			return (spec_list[i]);
		i++;
	}
	return (spec_list[i]);
}

