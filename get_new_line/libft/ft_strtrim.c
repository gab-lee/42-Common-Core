#include "libft.h"

static int ft_instr(char c, const char *set);

char *ft_strtrim(char const *s1, char const *set)
{
    char *tstr;
    int tsize;
    const char *tmp;
    int i;
    int j;

    i = -1;
    j = 0;
    tmp = s1;
    tsize = 0;
    while (++i, tmp[i])
    {
        if (ft_instr(tmp[i], set))
            tsize++;
    }
    if (!(tstr = malloc((ft_strlen(s1) - tsize + 1) * sizeof(char))))
        return (NULL);
    i = -1;
    while (++i, s1[i])
    {
        if (!ft_instr(s1[i], set))
            tstr[j++] = s1[i];
    }
    tstr[j] = '\0';
    return (tstr);
}
static int ft_instr(char c, const char *set)
{
    int i;
    i = -1;
    while (++i, set[i])
    {
        if (set[i] == c)
            return (1);
    }
    return (0);
}