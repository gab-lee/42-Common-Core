#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int size;
    t_list *tmp;

    size = 0;
    while (lst)
    {
        lst = lst->next;
        size++;
    }
    return (size);
}