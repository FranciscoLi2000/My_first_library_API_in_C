/* ************************************************************************** */
/*                                                                            */
/*   demo.c - Demonstration of mylib library usage                           */
/*   Shows practical examples of libft, get_next_line, and ft_printf         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/get_next_line.h"
#include "../include/ft_printf.h"
#include <fcntl.h>

static void	demo_string_funcs(void)
{
	char	*str;

	str = ft_strdup("Hello, World!");
	ft_printf("Original string: %s\n", str);
	ft_printf("String length: %d\n", ft_strlen(str));
	free(str);
	str = ft_substr("Hello, World!", 7, 5);
	ft_printf("Substring (7, 5): %s\n", str);
	free(str);
	str = ft_strjoin("Hello", " World");
	ft_printf("String join: %s\n", str);
	free(str);
}

static void	demo_split_itoa(void)
{
	char	**words;
	char	*str;
	int		i;

	words = ft_split("apple,banana,cherry", ',');
	ft_printf("Split by comma:\n");
	i = 0;
	while (words[i])
	{
		ft_printf("  - %s\n", words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	str = ft_itoa(42);
	ft_printf("Integer to string: %s\n", str);
	free(str);
}

void	demo_libft(void)
{
	ft_printf("\n=== LIBFT DEMO ===\n\n");
	demo_string_funcs();
	demo_split_itoa();
}

void	demo_get_next_line(void)
{
	int		fd;
	char	*line;
	FILE	*fp;

	ft_printf("\n=== GET_NEXT_LINE DEMO ===\n\n");
	fp = fopen("demo_file.txt", "w");
	fprintf(fp, "First line\nSecond line\nThird line\n");
	fclose(fp);
	fd = open("demo_file.txt", O_RDONLY);
	ft_printf("Reading file line by line:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("  > %s", line);
		free(line);
	}
	close(fd);
	unlink("demo_file.txt");
}

void	demo_ft_printf(void)
{
	int	x;

	x = 42;
	ft_printf("\n=== FT_PRINTF DEMO ===\n\n");
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, World!");
	ft_printf("Pointer: %p\n", &x);
	ft_printf("Decimal: %d\n", 42);
	ft_printf("Integer: %i\n", -42);
	ft_printf("Unsigned: %u\n", 42);
	ft_printf("Hexadecimal (lower): %x\n", 255);
	ft_printf("Hexadecimal (upper): %X\n", 255);
	ft_printf("Percent: %%\n");
	ft_printf("Mixed: %s has %d apples at %p\n", "Alice", 5, &x);
}

int	main(void)
{
	ft_printf("\n");
	ft_printf("╔══════════════════════════════════════╗\n");
	ft_printf("║   MYLIB - Professional C Library     ║\n");
	ft_printf("║   Demonstration Program              ║\n");
	ft_printf("╚══════════════════════════════════════╝\n");
	demo_libft();
	demo_get_next_line();
	demo_ft_printf();
	ft_printf("\n=== DEMO COMPLETE ===\n\n");
	return (0);
}
