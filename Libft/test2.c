/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:26:10 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/06 17:41:31 by lprado-l         ###   ########.fr       */
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
// Helper function to free the array returned by ft_split
void free_split(char **arr)
{
    if (arr)
    {
        for (int i = 0; arr[i] != NULL; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
}

// Function to print a string array
void print_split_array(char **arr, int test_num)
{
    printf("   Test %d Result: [", test_num);
    if (!arr)
    {
        printf("NULL]\n");
        return;
    }
    for (int i = 0; arr[i] != NULL; i++)
    {
        printf("\"%s\"", arr[i]);
        if (arr[i + 1] != NULL)
            printf(", ");
    }
    printf("]\n");
}

void test_ft_strtrim()
{
    char *result;
    printf("--- FT_STRTRIM TESTS ---\n");

    // Test 1: Basic trim
    result = ft_strtrim("  hello world  ", " ");
    printf("Test 1: '  hello world  ' | Expected: 'hello world' | Got: '%s' %s\n", result,
           (strcmp(result, "hello world") == 0 ? "✅ PASS" : "❌ FAIL"));
    free(result);

    // Test 2: Trim from one side only
    result = ft_strtrim("...Hello World!!!", ".");
    printf("Test 2: '...Hello World!!!' | Expected: 'Hello World!!!' | Got: '%s' %s\n", result,
           (strcmp(result, "Hello World!!!") == 0 ? "✅ PASS" : "❌ FAIL"));
    free(result);

    // Test 3: Complex set
    result = ft_strtrim("abCbaHelloabCba", "abcC");
    printf("Test 3: 'abCbaHelloabCba' | Expected: 'Hello' | Got: '%s' %s\n", result,
           (strcmp(result, "Hello") == 0 ? "✅ PASS" : "❌ FAIL"));
    free(result);
    
    // Test 4: String is entirely trimmed
    result = ft_strtrim("zyxw", "wxyz");
    printf("Test 4: 'zyxw' | Expected: '' | Got: '%s' %s\n", result,
           (strcmp(result, "") == 0 ? "✅ PASS" : "❌ FAIL"));
    free(result);

    // Test 5: Empty string input
    result = ft_strtrim("", "abc");
    printf("Test 5: '' | Expected: '' | Got: '%s' %s\n", result,
           (strcmp(result, "") == 0 ? "✅ PASS" : "❌ FAIL"));
    free(result);
}

void test_ft_split()
{
    char **result;
    printf("\n--- FT_SPLIT TESTS ---\n");

    // Test 1: Basic split
    result = ft_split("hello-world-42", '-');
    print_split_array(result, 1);
    // You should manually verify the output, and check for NULL termination
    if (result && result[3] == NULL)
        printf("   Test 1: NULL termination check: ✅ PASS\n");
    else
        printf("   Test 1: NULL termination check: ❌ FAIL\n");
    free_split(result);

    // Test 2: Multiple delimiters (consecutive)
    result = ft_split("one,,two,,,three", ',');
    print_split_array(result, 2);
    free_split(result);
    
    // Test 3: Delimiter at start and end
    result = ft_split("---42--cursus---", '-');
    print_split_array(result, 3);
    free_split(result);
    
    // Test 4: Empty string
    result = ft_split("", ' ');
    print_split_array(result, 4);
    if (result && result[0] == NULL)
        printf("   Test 4: Empty string check: ✅ PASS (returns [NULL])\n");
    else
        printf("   Test 4: Empty string check: ❌ FAIL\n");
    free_split(result);
    
    // Test 5: Only delimiters
    result = ft_split("      ", ' ');
    print_split_array(result, 5);
    if (result && result[0] == NULL)
        printf("   Test 5: Only delimiters check: ✅ PASS (returns [NULL])\n");
    else
        printf("   Test 5: Only delimiters check: ❌ FAIL\n");
    free_split(result);
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
    test_ft_strtrim();
    test_ft_split();
    return 0;
}
