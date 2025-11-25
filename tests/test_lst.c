/* ************************************************************************** */
/*                                                                            */
/*   test_lst.c - Comprehensive tests for linked-list bonus functions        */
/*   Tests cover empty lists, del/f callbacks, edge cases                    */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int      g_callback_count = 0;
static int      g_del_count = 0;
static int      g_map_call_count = 0;

void test_ft_lstnew(void)
{
        t_list  *node;
        char    *content;

        printf("Testing ft_lstnew...\n");
        content = "Hello";
        node = ft_lstnew(content);
        assert(node != NULL);
        assert(node->content == content);
        assert(node->next == NULL);
        free(node);
        node = ft_lstnew(NULL);
        assert(node != NULL);
        assert(node->content == NULL);
        free(node);
        printf("  ✓ ft_lstnew passed\n");
}

void test_ft_lstadd_front(void)
{
        t_list  *list;
        t_list  *node1;
        t_list  *node2;

        printf("Testing ft_lstadd_front...\n");
        list = NULL;
        node1 = ft_lstnew("First");
        ft_lstadd_front(&list, node1);
        assert(list == node1);
        node2 = ft_lstnew("Second");
        ft_lstadd_front(&list, node2);
        assert(list == node2);
        assert(list->next == node1);
        free(node1);
        free(node2);
        printf("  ✓ ft_lstadd_front passed\n");
}

void test_ft_lstsize(void)
{
        t_list  *list;
        t_list  *node1;
        t_list  *node2;
        t_list  *node3;

        printf("Testing ft_lstsize...\n");
        assert(ft_lstsize(NULL) == 0);
        node1 = ft_lstnew("1");
        list = node1;
        assert(ft_lstsize(list) == 1);
        node2 = ft_lstnew("2");
        node1->next = node2;
        assert(ft_lstsize(list) == 2);
        node3 = ft_lstnew("3");
        node2->next = node3;
        assert(ft_lstsize(list) == 3);
        free(node1);
        free(node2);
        free(node3);
        printf("  ✓ ft_lstsize passed\n");
}

void test_ft_lstlast(void)
{
        t_list  *list;
        t_list  *node1;
        t_list  *node2;
        t_list  *node3;

        printf("Testing ft_lstlast...\n");
        assert(ft_lstlast(NULL) == NULL);
        node1 = ft_lstnew("1");
        list = node1;
        assert(ft_lstlast(list) == node1);
        node2 = ft_lstnew("2");
        node1->next = node2;
        assert(ft_lstlast(list) == node2);
        node3 = ft_lstnew("3");
        node2->next = node3;
        assert(ft_lstlast(list) == node3);
        free(node1);
        free(node2);
        free(node3);
        printf("  ✓ ft_lstlast passed\n");
}

void test_ft_lstadd_back(void)
{
        t_list  *list;
        t_list  *node1;
        t_list  *node2;

        printf("Testing ft_lstadd_back...\n");
        list = NULL;
        node1 = ft_lstnew("First");
        ft_lstadd_back(&list, node1);
        assert(list == node1);
        node2 = ft_lstnew("Second");
        ft_lstadd_back(&list, node2);
        assert(list == node1);
        assert(list->next == node2);
        free(node1);
        free(node2);
        printf("  ✓ ft_lstadd_back passed\n");
}

void del_content(void *content)
{
        free(content);
}

void test_ft_lstdelone(void)
{
        t_list  *node;
        char    *content;

        printf("Testing ft_lstdelone...\n");
        content = ft_strdup("Test");
        node = ft_lstnew(content);
        ft_lstdelone(node, del_content);
        printf("  ✓ ft_lstdelone passed\n");
}

void test_ft_lstclear(void)
{
        t_list  *list;
        t_list  *node1;
        t_list  *node2;
        t_list  *node3;

        printf("Testing ft_lstclear...\n");
        node1 = ft_lstnew(ft_strdup("1"));
        node2 = ft_lstnew(ft_strdup("2"));
        node3 = ft_lstnew(ft_strdup("3"));
        node1->next = node2;
        node2->next = node3;
        list = node1;
        ft_lstclear(&list, del_content);
        assert(list == NULL);
        list = NULL;
        ft_lstclear(&list, del_content);
        assert(list == NULL);
        printf("  ✓ ft_lstclear passed\n");
}

void count_callback(void *content)
{
        (void)content;
        g_callback_count++;
}

void test_ft_lstiter(void)
{
        t_list  *list;
        t_list  *node1;
        t_list  *node2;
        t_list  *node3;

        printf("Testing ft_lstiter...\n");
        node1 = ft_lstnew("First");
        node2 = ft_lstnew("Second");
        node3 = ft_lstnew("Third");
        node1->next = node2;
        node2->next = node3;
        list = node1;
        g_callback_count = 0;
        ft_lstiter(list, count_callback);
        assert(g_callback_count == 3);
        g_callback_count = 0;
        ft_lstiter(NULL, count_callback);
        assert(g_callback_count == 0);
        free(node1);
        free(node2);
        free(node3);
        printf("  ✓ ft_lstiter passed\n");
}

void *duplicate_content(void *content)
{
        return (ft_strdup((char *)content));
}

void    del_count(void *content)
{
        g_del_count++;
        free(content);
}

void    *map_fail_on_second(void *content)
{
        g_map_call_count++;
        if (g_map_call_count == 2)
                return (NULL);
        return (ft_strdup((char *)content));
}

void test_ft_lstmap(void)
{
        t_list  *list;
        t_list  *new_list;
        t_list  *node1;
        t_list  *node2;
        t_list  *node3;

        printf("Testing ft_lstmap...\n");
        node1 = ft_lstnew("First");
        node2 = ft_lstnew("Second");
        node3 = ft_lstnew("Third");
        node1->next = node2;
        node2->next = node3;
        list = node1;
        new_list = ft_lstmap(list, duplicate_content, del_content);
        assert(new_list != NULL);
        assert(new_list != list);
        assert(strcmp((char *)new_list->content, "First") == 0);
        assert(strcmp((char *)new_list->next->content, "Second") == 0);
        assert(strcmp((char *)new_list->next->next->content, "Third") == 0);
        assert(new_list->next->next->next == NULL);
        assert(ft_lstsize(new_list) == 3);
        ft_lstclear(&new_list, del_content);
        assert(new_list == NULL);
        new_list = ft_lstmap(NULL, duplicate_content, del_content);
        assert(new_list == NULL);
        g_map_call_count = 0;
        g_del_count = 0;
        new_list = ft_lstmap(list, map_fail_on_second, del_count);
        assert(new_list == NULL);
        assert(g_del_count == 1);
        assert(node1->next == node2);
        free(node1);
        free(node2);
        free(node3);
        printf("  ✓ ft_lstmap passed\n");
}

int     main(void)
{
        printf("\n=== LINKED-LIST BONUS FUNCTIONS TEST SUITE ===\n\n");
        test_ft_lstnew();
        test_ft_lstadd_front();
        test_ft_lstsize();
        test_ft_lstlast();
        test_ft_lstadd_back();
        test_ft_lstdelone();
        test_ft_lstclear();
        test_ft_lstiter();
        test_ft_lstmap();
        printf("\n=== ALL TESTS PASSED ===\n\n");
        return (0);
}
