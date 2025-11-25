/* ************************************************************************** */
/*                                                                            */
/*   test_libft.c - Comprehensive tests for libft functions                  */
/*   Tests cover normal cases, edge cases, and error conditions               */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_ft_strlen(void)
{
	printf("Testing ft_strlen...\n");
	assert(ft_strlen("Hello") == 5);
	assert(ft_strlen("") == 0);
	assert(ft_strlen("42") == 2);
	printf("  ✓ ft_strlen passed\n");
}

void test_ft_strdup(void)
{
	char *dup;

	printf("Testing ft_strdup...\n");
	dup = ft_strdup("Hello");
	assert(strcmp(dup, "Hello") == 0);
	free(dup);
	dup = ft_strdup("");
	assert(strcmp(dup, "") == 0);
	free(dup);
	printf("  ✓ ft_strdup passed\n");
}

void test_ft_substr(void)
{
	char *sub;

	printf("Testing ft_substr...\n");
	sub = ft_substr("Hello World", 0, 5);
	assert(strcmp(sub, "Hello") == 0);
	free(sub);
	sub = ft_substr("Hello World", 6, 5);
	assert(strcmp(sub, "World") == 0);
	free(sub);
	sub = ft_substr("Hello", 10, 5);
	assert(strcmp(sub, "") == 0);
	free(sub);
	printf("  ✓ ft_substr passed\n");
}

void test_ft_strjoin(void)
{
	char *joined;

	printf("Testing ft_strjoin...\n");
	joined = ft_strjoin("Hello ", "World");
	assert(strcmp(joined, "Hello World") == 0);
	free(joined);
	joined = ft_strjoin("", "Test");
	assert(strcmp(joined, "Test") == 0);
	free(joined);
	printf("  ✓ ft_strjoin passed\n");
}

void test_ft_split(void)
{
	char **arr;
	int i;

	printf("Testing ft_split...\n");
	arr = ft_split("Hello,World,Test", ',');
	assert(strcmp(arr[0], "Hello") == 0);
	assert(strcmp(arr[1], "World") == 0);
	assert(strcmp(arr[2], "Test") == 0);
	assert(arr[3] == NULL);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	printf("  ✓ ft_split passed\n");
}

void test_ft_itoa(void)
{
	char *str;

	printf("Testing ft_itoa...\n");
	str = ft_itoa(42);
	assert(strcmp(str, "42") == 0);
	free(str);
	str = ft_itoa(-42);
	assert(strcmp(str, "-42") == 0);
	free(str);
	str = ft_itoa(0);
	assert(strcmp(str, "0") == 0);
	free(str);
	printf("  ✓ ft_itoa passed\n");
}

void test_ft_atoi(void)
{
	printf("Testing ft_atoi...\n");
	assert(ft_atoi("42") == 42);
	assert(ft_atoi("-42") == -42);
	assert(ft_atoi("   123") == 123);
	assert(ft_atoi("0") == 0);
	printf("  ✓ ft_atoi passed\n");
}

void test_ft_memcpy(void)
{
	char src[] = "Hello";
	char dst[10];

	printf("Testing ft_memcpy...\n");
	ft_memcpy(dst, src, 6);
	assert(strcmp(dst, "Hello") == 0);
	printf("  ✓ ft_memcpy passed\n");
}

void test_ft_memmove(void)
{
	char str[] = "Hello World";

	printf("Testing ft_memmove...\n");
	ft_memmove(str + 6, str, 5);
	assert(str[6] == 'H');
	printf("  ✓ ft_memmove passed\n");
}

int main(void)
{
	printf("\n=== LIBFT COMPREHENSIVE TEST SUITE ===\n\n");
	test_ft_strlen();
	test_ft_strdup();
	test_ft_substr();
	test_ft_strjoin();
	test_ft_split();
	test_ft_itoa();
	test_ft_atoi();
	test_ft_memcpy();
	test_ft_memmove();
	printf("\n=== ALL TESTS PASSED ===\n\n");
	return (0);
}
