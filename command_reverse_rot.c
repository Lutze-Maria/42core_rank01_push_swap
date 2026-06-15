
#include "push_swap.h"

// bottom node to top position
/*Before:
head
 ↓
1 <-> 2 <-> 3 <-> 4
  After:
head
 ↓
4 <-> 1 <-> 2 <-> 3
*/

static void rev_rotate(t_stack_node **stack)
{
    t_stack_node    *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    last = find_last_node(*stack);
    // detach last node
    last->prev->next = NULL;
    // move it to front
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}

void    rra(t_stack_node **a, bool checker)
{
    rev_rotate(a);
    if (!checker)
        write(1, "rra\n", 4);
}

void    rrb(t_stack_node **b, bool checker)
{
    rev_rotate(a);
    if (!checker)
        write(1, "rrb\n", 4);
}

void    rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
    rev_rotate(a);
    rev_rotate(b);
    if (!checker)
        write(1, "rrr\n", 4);
}
