#include "libft.h"

void del(void *content)
{
    if (content)
        free(content);
}
void print_content(void *content)
{
    if (content)
        printf("%s\n", (char *)content);
}

void *duplicate_uppercase(void *content)
{
    if (!content)
        return NULL;
    char *str = strdup(content);
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return str;
}

void test_list_operations(void)
{
    t_list *list = NULL;
    t_list *mapped = NULL;
    t_list *last;
    t_list *tmp;
    int size;

    printf("=== TEST: Empty list ===\n");
    printf("Size: %d\n", ft_lstsize(list));
    last = ft_lstlast(list);
    printf("Last: %p\n", (void *)last);

    printf("\n=== TEST: Add nodes ===\n");
    ft_lstadd_back(&list, ft_lstnew(strdup("one")));
    ft_lstadd_front(&list, ft_lstnew(strdup("zero")));
    ft_lstadd_back(&list, ft_lstnew(strdup("two")));

    size = ft_lstsize(list);
    printf("Size after adding nodes: %d\n", size);

    printf("List contents:\n");
    ft_lstiter(list, print_content);

    last = ft_lstlast(list);
    printf("Last element: %s\n", (char *)last->content);

printf("\n=== TEST: Delete one node ===\n");
tmp = list->next; 
list->next = tmp->next; 
ft_lstdelone(tmp, del);
ft_lstiter(list, print_content);
printf("Size after deletion: %d\n", ft_lstsize(list));

    printf("\n=== TEST: Map list to uppercase ===\n");
    mapped = ft_lstmap(list, duplicate_uppercase, free);
    ft_lstiter(mapped, print_content);

    printf("\n=== TEST: Clear lists ===\n");
    ft_lstclear(&list, free);
    ft_lstclear(&mapped, free);
    printf("Lists cleared. list=%p, mapped=%p\n", (void *)list, (void *)mapped);
}

int main(void)
{
    test_list_operations();
    return 0;
}

