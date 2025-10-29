/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:26:10 by lprado-l          #+#    #+#             */
/*   Updated: 2025/10/29 12:31:14 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void test_substr(const char *s, unsigned int start, size_t len)
{
    char *result = ft_substr(s, start, len);

    printf("ft_substr(\"%s\", %u, %zu) → ", s, start, len);
    if (result)
    {
        printf("\"%s\"\n", result);
        free(result);
    }
    else
        printf("NULL (allocation failed)\n");
}

static void test_strjoin(const char *s1, const char *s2)
{
    char *result = ft_strjoin(s1, s2);

    printf("ft_strjoin(");
    if (s1)
        printf("\"%s\", ", s1);
    else
        printf("NULL, ");
    if (s2)
        printf("\"%s\") → ", s2);
    else
        printf("NULL) → ");

    if (result)
    {
        printf("\"%s\"\n", result);
        free(result);
    }
    else
        printf("NULL (allocation failed or NULL input)\n");
}

int main(void)
{
    printf("=== Testing ft_substr ===\n\n");

    // ✅ Basic tests
    test_substr("Hello, world!", 0, 5);          // "Hello"
    test_substr("Hello, world!", 7, 5);          // "world"
    test_substr("Hello, world!", 3, 20);         // "lo, world!"

    // ⚠️ Edge cases
    test_substr("Hello", 0, 0);                  // ""
    test_substr("Hello", 10, 3);                 // start > strlen
    test_substr("Hello", 5, 3);                  // start == strlen
    test_substr("", 0, 5);                       // empty string
    test_substr("42 Network", 2, 0);             // len = 0

    // 🧠 Stress test with big len
    test_substr("abcdef", 2, 100);               // "cdef"

    printf("\n=== Testing ft_strjoin ===\n\n");

    // ✅ Basic tests
    test_strjoin("Hello, ", "world!");           // "Hello, world!"
    test_strjoin("42", "Network");               // "42Network"
    test_strjoin("", "world!");                  // "world!"
    test_strjoin("Hello", "");                   // "Hello"
    test_strjoin("", "");                        // ""

    // ⚠️ Edge cases
    test_strjoin(NULL, "world!");                // Expected: NULL (if you handle it)
    test_strjoin("Hello", NULL);                 // Expected: NULL
    test_strjoin(NULL, NULL);                    // Expected: NULL

    // 🧠 Stress test
    test_strjoin("abc", "defghijklmnopqrstuvwxyz"); // "abcdefghijklmnopqrstuvwxyz"

    return 0;
}
