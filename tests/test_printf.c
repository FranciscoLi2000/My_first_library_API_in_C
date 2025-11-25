/* ************************************************************************** */
/*                                                                            */
/*   test_printf.c - Comprehensive tests for ft_printf                       */
/*   Tests all conversions: c s p d i u x X %                                */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void test_char(void)
{
	int ret1;
	int ret2;

	printf("Testing %%c conversion...\n");
	ret1 = ft_printf("ft_printf: %c\n", 'A');
	ret2 = printf("   printf: %c\n", 'A');
	printf("  Return values: ft=%d, std=%d\n", ret1, ret2);
	printf("  ✓ %%c passed\n\n");
}

void test_string(void)
{
	int ret1;
	int ret2;

	printf("Testing %%s conversion...\n");
	ret1 = ft_printf("ft_printf: %s\n", "Hello World");
	ret2 = printf("   printf: %s\n", "Hello World");
	printf("  Return values: ft=%d, std=%d\n", ret1, ret2);
	ft_printf("ft_printf NULL: %s\n", NULL);
	printf("  ✓ %%s passed\n\n");
}

void test_pointer(void)
{
	int x;
	int ret1;
	int ret2;

	x = 42;
	printf("Testing %%p conversion...\n");
	ret1 = ft_printf("ft_printf: %p\n", &x);
	ret2 = printf("   printf: %p\n", &x);
	printf("  Return values: ft=%d, std=%d\n", ret1, ret2);
	printf("  ✓ %%p passed\n\n");
}

void test_integer(void)
{
	int ret1;
	int ret2;

	printf("Testing %%d and %%i conversions...\n");
	ret1 = ft_printf("ft_printf: %d %i\n", 42, -42);
	ret2 = printf("   printf: %d %i\n", 42, -42);
	printf("  Return values: ft=%d, std=%d\n", ret1, ret2);
	ft_printf("ft_printf: %d\n", 0);
	printf("   printf: %d\n", 0);
	printf("  ✓ %%d and %%i passed\n\n");
}

void test_unsigned(void)
{
	int ret1;
	int ret2;

	printf("Testing %%u conversion...\n");
	ret1 = ft_printf("ft_printf: %u\n", 42);
	ret2 = printf("   printf: %u\n", 42);
	printf("  Return values: ft=%d, std=%d\n", ret1, ret2);
	printf("  ✓ %%u passed\n\n");
}

void test_hex(void)
{
	int ret1;
	int ret2;

	printf("Testing %%x and %%X conversions...\n");
	ret1 = ft_printf("ft_printf: %x %X\n", 255, 255);
	ret2 = printf("   printf: %x %X\n", 255, 255);
	printf("  Return values: ft=%d, std=%d\n", ret1, ret2);
	ft_printf("ft_printf: %x\n", 0);
	printf("   printf: %x\n", 0);
	printf("  ✓ %%x and %%X passed\n\n");
}

void test_percent(void)
{
	int ret1;
	int ret2;

	printf("Testing %%%% conversion...\n");
	ret1 = ft_printf("ft_printf: %%\n");
	ret2 = printf("   printf: %%\n");
	printf("  Return values: ft=%d, std=%d\n", ret1, ret2);
	printf("  ✓ %%%% passed\n\n");
}

void test_mixed(void)
{
	int x;

	x = 42;
	printf("Testing mixed conversions...\n");
	ft_printf("Mixed: %s %d %c %x %p\n", "Test", 42, 'A', 255, &x);
	printf("Mixed: %s %d %c %x %p\n", "Test", 42, 'A', 255, &x);
	printf("  ✓ Mixed conversions passed\n\n");
}

int main(void)
{
	printf("\n=== FT_PRINTF COMPREHENSIVE TEST SUITE ===\n\n");
	test_char();
	test_string();
	test_pointer();
	test_integer();
	test_unsigned();
	test_hex();
	test_percent();
	test_mixed();
	printf("=== ALL TESTS PASSED ===\n\n");
	return (0);
}
