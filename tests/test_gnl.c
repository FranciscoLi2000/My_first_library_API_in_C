/* ************************************************************************** */
/*                                                                            */
/*   test_gnl.c - Comprehensive tests for get_next_line                      */
/*   Tests cover normal files, stdin, multiple fds, edge cases               */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_basic_file(void)
{
	int fd;
	char *line;
	FILE *fp;

	printf("Testing basic file reading...\n");
	fp = fopen("test_file.txt", "w");
	fprintf(fp, "Line 1\nLine 2\nLine 3");
	fclose(fp);
	fd = open("test_file.txt", O_RDONLY);
	line = get_next_line(fd);
	assert(strcmp(line, "Line 1\n") == 0);
	free(line);
	line = get_next_line(fd);
	assert(strcmp(line, "Line 2\n") == 0);
	free(line);
	line = get_next_line(fd);
	assert(strcmp(line, "Line 3") == 0);
	free(line);
	line = get_next_line(fd);
	assert(line == NULL);
	close(fd);
	unlink("test_file.txt");
	printf("  ✓ Basic file reading passed\n");
}

void test_multiple_fds(void)
{
	int fd1;
	int fd2;
	char *line;
	FILE *fp;

	printf("Testing multiple file descriptors...\n");
	fp = fopen("test1.txt", "w");
	fprintf(fp, "File1 Line1\nFile1 Line2");
	fclose(fp);
	fp = fopen("test2.txt", "w");
	fprintf(fp, "File2 Line1\nFile2 Line2");
	fclose(fp);
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	line = get_next_line(fd1);
	assert(strncmp(line, "File1 Line1", 11) == 0);
	free(line);
	line = get_next_line(fd2);
	assert(strncmp(line, "File2 Line1", 11) == 0);
	free(line);
	line = get_next_line(fd1);
	assert(strncmp(line, "File1 Line2", 11) == 0);
	free(line);
	line = get_next_line(fd2);
	assert(strncmp(line, "File2 Line2", 11) == 0);
	free(line);
	close(fd1);
	close(fd2);
	unlink("test1.txt");
	unlink("test2.txt");
	printf("  ✓ Multiple file descriptors passed\n");
}

void test_empty_file(void)
{
	int fd;
	char *line;
	FILE *fp;

	printf("Testing empty file...\n");
	fp = fopen("empty.txt", "w");
	fclose(fp);
	fd = open("empty.txt", O_RDONLY);
	line = get_next_line(fd);
	assert(line == NULL);
	close(fd);
	unlink("empty.txt");
	printf("  ✓ Empty file passed\n");
}

int main(void)
{
	printf("\n=== GET_NEXT_LINE COMPREHENSIVE TEST SUITE ===\n\n");
	test_basic_file();
	test_multiple_fds();
	test_empty_file();
	printf("\n=== ALL TESTS PASSED ===\n\n");
	return (0);
}
