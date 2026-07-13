
#include "../push_swap.h"

/*
Valid: "0" "+42" "-42" "123"
Invalid: "" "+" "-" "12a3"
" 42" (handled by split)
"4 2" (handled by split)
*/

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i]) // only "+" or "-"
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	error_duplicate(t_stack_node *a, int new_nbr)
{
	while (a)
	{
		if (a->value == new_nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
