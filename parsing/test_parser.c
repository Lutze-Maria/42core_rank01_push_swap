#include <stdio.h>
#include "push_swap.h"

void print_tokens(char **t)
{
	int i = 0;
	while (t[i])
	{
		printf("[%d] '%s'\n", i, t[i]);
		i++;
	}
	printf("\n----\n\n");
}
/*
int main(int argc, char **argv)
{
	t_config cfg;
	char **tokens;

	cfg = parse_config(argc, argv);
	tokens = parse_input(argc, argv, cfg.start);

	if (!tokens)
	{
		printf("ERROR\n");
		return 1;
	}

    //for (int i = 0; argv[i]; i++)
	//    printf("argv[%d] = '%s'\n", i, argv[i]);
    printf("cfg.start = %d\n", cfg.start);
	print_tokens(tokens);
	return 0;
}*/