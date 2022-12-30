#include "main.h"

/**
 * spec_num - find number of specifier in input message
 * @format: pointer to string; string to process
 *
 * Return: int; number of specifiers
 */
int spec_num(const char *format)
{
	int i, j = 0;

	for (i = 0; *(format + i) != '\0'; i++)
	{
		if (*(format + i) == '%' && (*(format + j + 1) == 'c' ||
					*(format + j + 1) == 's' ||
					*(format + j + 1) == '%'))
		{
			j++;
		}
	}
	return (j);
}

/**
 * _printf - prints any given input with the right format
 * @format: pointer to constant string; message to process and print
 *
 * Return: number of char printed; -1 if failure
 * TheOwl
 */
int _printf(const char *format, ...)
{
	int i = 0, j, n_spec;
	char *c;
	void *val_c;
	va_list spec_list;
	SPEC *cur_spec;

	n_spec = spec_num(format);/* number of specifier argument */
	if (n_spec == 0)/* if there is no specifier */
	{
		for (j = 0; *(format + j) != '\0'; j++)
			_putchar(*(format + j));
		_putchar('\n');
		return (j);
	}
	/* if there is at least one specifier */
	va_start(spec_list, format);/* initializing list of specifier value */
	cur_spec = malloc(sizeof(SPEC));
	if (cur_spec == NULL)/* malloc validation */
		return (-1);
	for (j = 0; *(format + j) != '\0'; j++)
	{
		if (*(format + j) != '%')/* print normal characters */
		{
			_putchar(*(format + j));
			i++;
		}
		else/* identify specifier and print value */
		{
			c = format + j + 1;
			cur_spec = get_specifier(c);
			if (cur_spec.id == NULL)/* if % is not followed by an identifier */
			{
				_putchar(*(format + j));
				i++;
			}
			/* if argument is a char or a string */
			else if (cur_spec->id == 'c' || cur_spec->id == 's')
			{
				val_c = va_arg(spec_list, char *);
				i = i + cur_spec.printer(val_c);
				j++;
			}
			else if (cur_spec.id == '%')
			{
				_putchar('%');
				i++;
				j++;
			}
		}
	}
	va_end(spec_list);
	free(cur_spec);
	_putchar('\n');
	return (i);
}
