#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;
    t_list *cur;

    if (!*lst)
        return;
    cur = *lst;
    while (cur)
    {
        tmp = cur->next;
        ft_lstdelone(cur, del);
        cur = tmp;
    }
    *lst = (NULL);
}