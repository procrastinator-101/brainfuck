#include <stdio.h>

int brainfuck(char **ptr, char *instruction, int i)
{
	int k;

	k = i;
	if (instruction[i] == '>')
		(*ptr)++;
	else if (instruction[i] == '<')
		(*ptr)--;
	else if (instruction[i] == '+')
		(**ptr)++;
	else if (instruction[i] == '-')
		(**ptr)--;
	else if (instruction[i] == ',')
		**ptr = getc(stdin);
	else if (instruction[i] == '.')
		printf("%c",(**ptr));
	else if (instruction[i] == '[')
	{
		k = i + 1;
		while (instruction[k] != ']' || **ptr != 0)
		{
			k = brainfuck(ptr, instruction, k);
			k++;
			if (instruction[k - 1] == ']' && **ptr != 0)
				k = i + 1;
		}
	}
	return (k);
}

int check_brakets(char *str)
{
	int open;
	int close;
	int i;

	i = 0;
	open = 0;
	close = 0;
	while (*(str + i))
	{
		if (str[i] == '[')
			open++;
		else if (str[i] == ']')
			close++;
		i++;
	}
	if (open == close)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	char *instruction;
	char tab[20];
	char **ptr;
	char *pointer;
	int i;
	int k;

	if (argc < 2)
		return (0);
	instruction = argv[1];
	k = check_brakets(instruction);
	if (k)
	{
		printf("brakets unmatched\n");
		return (0);
	}
	i = 0;
	while (i < 20)
	{
		tab[i] = 0;
		i++;
	}
	pointer = tab;
	ptr = &pointer;
	i = 0;
	while(instruction [i])
	{
		i = brainfuck(ptr, instruction, i);
		i++;
	}
}
