/**
 * print_string - print a string to output
 * @val_c: string of char; string to print
 *
 * Return: number of char printed except last '\0'
 */
int print_string(char val_c)
{
	int i = 0;

	while (val_c[i] != '\0')
	{
		_putchar(val_c[i]);
		i++;
	}
	return (i);
}

/* TheOwl */
