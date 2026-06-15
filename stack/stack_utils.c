
#include "push_swap.h"

t_stack_node    *find_last_node(t_stack_node *head)
{
    if (!head)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}

// search for last node, append
void	append_node(char **stack, int nbr)
{
	t_stack_node    *node;
    t_stack_node    *last_node;

    if (!stack)
        return ;
    node = malloc(sizeof(t_stack_node));
    if (!node)
        return ;
    node->next = NULL;
    node->value = nbr;
    if (!*stack)
    {
        *stack = node;
        node->prev = NULL:
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

// find the smallest value node
t_stack_node    *find_smallest(t_stack_node *stack)
{
    long            smallest;
    t_stack_node    *smallest_node;

    if (!stack)
        return (NULL);
    smallest = LONG_MAX;
    while (stack)
    {
        if (stack->value < smallest)
        {
            smallest = stack->value;
            smallest_node = stack;
        }
        stack = stack->next;
    }
    return (smallest_node);
}

int stack_len(t_stack_node *stack)
{
    int count;

    if (!stack)
        return (NULL);
    count = 0;
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}

