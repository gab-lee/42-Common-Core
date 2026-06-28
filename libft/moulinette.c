#include "libft.h"
#include <stdio.h>
#include <string.h>

typedef struct s_test
{
	const char	*name;
	void		(*run)(void);
}	t_test;

static void	test_ft_isalpha(void) {}
static void	test_ft_isdigit(void) {}
static void	test_ft_isalnum(void) {}
static void	test_ft_isascii(void) {}
static void	test_ft_isprint(void) {}
static void	test_ft_strlen(void) {}
static void	test_ft_memset(void) {}
static void	test_ft_bzero(void) {}
static void	test_ft_memcpy(void) {}
static void	test_ft_memmove(void) {}
static void	test_ft_strlcpy(void) {}
static void	test_ft_strlcat(void) {}
static void	test_ft_toupper(void) {}
static void	test_ft_tolower(void) {}
static void	test_ft_strchr(void) {}
static void	test_ft_strrchr(void) {}
static void	test_ft_strncmp(void) {}
static void	test_ft_memchr(void) {}
static void	test_ft_memcmp(void) {}
static void	test_ft_strnstr(void) {}
static void	test_ft_atoi(void) {}
static void	test_ft_calloc(void) {}
static void	test_ft_strdup(void) {}
static void	test_ft_substr(void) {}
static void	test_ft_strjoin(void) {}
static void	test_ft_strtrim(void) {}
static void	test_ft_split(void) {}
static void	test_ft_itoa(void) {}
static void	test_ft_strmapi(void) {}
static void	test_ft_striteri(void) {}
static void	test_ft_putchar_fd(void) {}
static void	test_ft_putstr_fd(void) {}
static void	test_ft_putendl_fd(void) {}
static void	test_ft_putnbr_fd(void) {}
static void	test_ft_lstnew(void) {}
static void	test_ft_lstadd_front(void) {}
static void	test_ft_lstsize(void) {}
static void	test_ft_lstlast(void) {}
static void	test_ft_lstadd_back(void) {}
static void	test_ft_lstdelone(void) {}
static void	test_ft_lstclear(void) {}
static void	test_ft_lstiter(void) {}
static void	test_ft_lstmap(void) {}

static t_test	g_tests[] = {
	{"ft_isalpha", test_ft_isalpha},
	{"ft_isdigit", test_ft_isdigit},
	{"ft_isalnum", test_ft_isalnum},
	{"ft_isascii", test_ft_isascii},
	{"ft_isprint", test_ft_isprint},
	{"ft_strlen", test_ft_strlen},
	{"ft_memset", test_ft_memset},
	{"ft_bzero", test_ft_bzero},
	{"ft_memcpy", test_ft_memcpy},
	{"ft_memmove", test_ft_memmove},
	{"ft_strlcpy", test_ft_strlcpy},
	{"ft_strlcat", test_ft_strlcat},
	{"ft_toupper", test_ft_toupper},
	{"ft_tolower", test_ft_tolower},
	{"ft_strchr", test_ft_strchr},
	{"ft_strrchr", test_ft_strrchr},
	{"ft_strncmp", test_ft_strncmp},
	{"ft_memchr", test_ft_memchr},
	{"ft_memcmp", test_ft_memcmp},
	{"ft_strnstr", test_ft_strnstr},
	{"ft_atoi", test_ft_atoi},
	{"ft_calloc", test_ft_calloc},
	{"ft_strdup", test_ft_strdup},
	{"ft_substr", test_ft_substr},
	{"ft_strjoin", test_ft_strjoin},
	{"ft_strtrim", test_ft_strtrim},
	{"ft_split", test_ft_split},
	{"ft_itoa", test_ft_itoa},
	{"ft_strmapi", test_ft_strmapi},
	{"ft_striteri", test_ft_striteri},
	{"ft_putchar_fd", test_ft_putchar_fd},
	{"ft_putstr_fd", test_ft_putstr_fd},
	{"ft_putendl_fd", test_ft_putendl_fd},
	{"ft_putnbr_fd", test_ft_putnbr_fd},
	{"ft_lstnew", test_ft_lstnew},
	{"ft_lstadd_front", test_ft_lstadd_front},
	{"ft_lstsize", test_ft_lstsize},
	{"ft_lstlast", test_ft_lstlast},
	{"ft_lstadd_back", test_ft_lstadd_back},
	{"ft_lstdelone", test_ft_lstdelone},
	{"ft_lstclear", test_ft_lstclear},
	{"ft_lstiter", test_ft_lstiter},
	{"ft_lstmap", test_ft_lstmap},
	{NULL, NULL}
};

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <function_name>\n", argv[0]);
		return (1);
	}
	i = 0;
	while (g_tests[i].name)
	{
		if (strcmp(g_tests[i].name, argv[1]) == 0)
		{
			printf("Running tests for %s...\n", argv[1]);
			g_tests[i].run();
			return (0);
		}
		i++;
	}
	fprintf(stderr, "Unknown function: %s\n", argv[1]);
	return (1);
}
