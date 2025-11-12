/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:26:10 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/12 19:34:00 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** ft_striteri: Helper Functions (NEW)
** -----------------------------------------------------------------------------
*/

// Iterator 1: Convert to lowercase (in place)
static void iter_tolower(unsigned int i, char *c)
{
	(void)i; // Mark index as unused
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

// Iterator 2: Replace character with index (in place)
static void iter_replace_with_index(unsigned int i, char *c)
{
	*c = (i % 10) + '0'; // '0', '1', '2', etc.
}

// Iterator 3: Change character to 'X' if index is even
static void iter_even_to_X(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = 'X';
}

// Helper function to print string content byte-by-byte for inspection
static void print_string_bytes(const char *str, const char *label)
{
	size_t i = 0;
	
	printf("\n    --- %s Bytes ---\n", label);
	if (!str)
	{
		printf("    (NULL)\n");
		return;
	}

	// Print bytes until the null terminator is found, or a safe limit is reached
	while (i < 25) // Safety limit
	{
		// Print character (or a descriptive label for non-printables)
		if (str[i] == '\0')
			printf("    Byte [%zu]: '\\0' (0)\n", i);
		else if (str[i] == ' ')
			printf("    Byte [%zu]: ' ' (32)\n", i);
		else if (str[i] == '\n')
			printf("    Byte [%zu]: '\\n' (10)\n", i);
		else if (str[i] < 32 || str[i] > 126) // Non-printable characters
			printf("    Byte [%zu]: Non-Printable (%d)\n", i, str[i]);
		else // Printable character
			printf("    Byte [%zu]: '%c' (%d)\n", i, str[i], str[i]);
		
		// Stop after finding the null terminator
		if (str[i] == '\0')
			break;
		
		i++;
	}
}

/*
** -----------------------------------------------------------------------------
** ft_strmapi: Helper Functions (NEW)
** -----------------------------------------------------------------------------
*/

// Test function 1: Convert to uppercase (ignores index)
static char map_toupper(unsigned int i, char c)
{
	(void)i; // Mark index as unused
	return (toupper(c));
}

// Test function 2: Shift character by +1 (ignores index)
static char map_plus_one(unsigned int i, char c)
{
	(void)i; // Mark index as unused
	return (c + 1);
}

// Test function 3: Use index to create a new string (ignores char)
static char map_index_to_char(unsigned int i, char c)
{
	(void)c; // Mark char as unused
	return ((i % 10) + '0'); // '0', '1', '2', etc.
}


static void test_itoa(int n)
{
	char *result = ft_itoa(n);
	char expected[20]; // Buffer large enough for any standard int string

	// Use standard function to determine the expected output
	sprintf(expected, "%d", n);

	printf("ft_itoa(%d) → ", n);
	if (!result)
	{
		printf("NULL (❌ FAIL, Allocation failed)\n");
		return;
	}

	// Compare result with expected string
	if (strcmp(result, expected) == 0)
	{
		printf("\"%s\" (✅ PASS)\n", result);
	}
	else
	{
		printf("\"%s\" (❌ FAIL, Expected: \"%s\")\n", result, expected);
		
		// NEW CODE: Print the byte comparison on failure
		print_string_bytes(result, "YOUR RESULT");
		print_string_bytes(expected, "EXPECTED RESULT");
		printf("\n");
	}

	free(result);
}

/*
** -----------------------------------------------------------------------------
** ft_strmapi: Test Function (NEW)
** -----------------------------------------------------------------------------
*/

static void test_strmapi(const char *s, char (*f)(unsigned int, char), const char *expected, const char *f_name)
{
	// Print the function call
	printf("ft_strmapi(");
	if (s)
		printf("\"%s\"", s);
	else
		printf("NULL");
	printf(", %s) → ", f_name);

	// Call the function
	char *result = ft_strmapi(s, f);

	// --- Check results ---

	// Case 1: Both result and expected are NULL (e.g., NULL input)
	if (result == NULL && expected == NULL)
	{
		printf("NULL (✅ PASS)\n");
	}
	// Case 2: Result is NULL, but expected wasn't (Allocation fail?)
	else if (result == NULL && expected != NULL)
	{
		printf("NULL (❌ FAIL, Expected: \"%s\")\n", expected);
	}
	// Case 3: Result is not NULL, but expected was
	else if (result != NULL && expected == NULL)
	{
		printf("\"%s\" (❌ FAIL, Expected: NULL)\n", result);
		free(result); // Free the unexpected result
	}
	// Case 4: Both are non-NULL, and they match
	else if (strcmp(result, expected) == 0)
	{
		printf("\"%s\" (✅ PASS)\n", result);
		free(result);
	}
	// Case 5: Both are non-NULL, but they don't match
	else
	{
		printf("\"%s\" (❌ FAIL, Expected: \"%s\")\n", result, expected);
		// Use your byte-by-byte printer for details
		print_string_bytes(result, "YOUR RESULT");
		print_string_bytes(expected, "EXPECTED RESULT");
		printf("\n");
		free(result);
	}
}
/*
** -----------------------------------------------------------------------------
** ft_striteri: Test Function (NEW)
** -----------------------------------------------------------------------------
*/

static void test_striteri(const char *s, void (*f)(unsigned int, char *), const char *expected, const char *f_name)
{
	char *modifiable_s;

	// Need a modifiable copy since ft_striteri works in place
	modifiable_s = strdup(s); 
	
	printf("ft_striteri(\"%s\", %s) → ", s, f_name);

	if (!modifiable_s)
	{
		printf("Error: strdup failed.\n");
		return;
	}

	// --- Call the function ---
	if (f)
	{
		ft_striteri(modifiable_s, f);
	}
	else
	{
		// Test case for NULL function (should not crash)
		printf("NULL function passed. ");
	}
	// --- Check results ---

	if (strcmp(modifiable_s, expected) == 0)
	{
		printf("\"%s\" (✅ PASS)\n", modifiable_s);
	}
	else
	{
		printf("\"%s\" (❌ FAIL, Expected: \"%s\")\n", modifiable_s, expected);
		
		// Print the byte comparison on failure
		print_string_bytes(modifiable_s, "YOUR RESULT");
		print_string_bytes(expected, "EXPECTED RESULT");
		printf("\n");
	}

	free(modifiable_s);
}

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
    printf("\n--- Testing ft_itoa ---\n\n");

	// ✅ Basic tests
	test_itoa(12345);
	test_itoa(-42);
	test_itoa(0);
	test_itoa(7);
	test_itoa(-9);

	// ⚠️ Edge cases (INT limits)
	test_itoa(2147483647); // INT_MAX
	test_itoa(-2147483648); // INT_MIN

	// 🧠 Stress tests
	test_itoa(1000000000);
	test_itoa(-1000000000);

	// --- NEW TESTS ---
	printf("\n--- Testing ft_strmapi ---\n\n");

	// ✅ Basic tests
	test_strmapi("hello", map_toupper, "HELLO", "map_toupper");
	test_strmapi("abc", map_plus_one, "bcd", "map_plus_one");

	// ✅ Test using the index
	test_strmapi("0123456789", map_index_to_char, "0123456789", "map_index_to_char");
	test_strmapi("recursion", map_index_to_char, "012345678", "map_index_to_char");

	// ⚠️ Edge cases
	test_strmapi("", map_toupper, "", "map_toupper"); // Empty string
	test_strmapi("test", NULL, NULL, "NULL_function");      // NULL function
	test_strmapi(NULL, map_toupper, NULL, "map_toupper"); // NULL string
	test_strmapi(NULL, NULL, NULL, "NULL_function");      // Both NULL

	// 🧠 Stress test
	test_strmapi("abcdefghijklmnopqrstuvwxyz", map_toupper, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "map_toupper");
	// --- END NEW TESTS ---

	// --- NEW TESTS ---
	printf("\n--- Testing ft_striteri ---\n\n");

	// ✅ Basic tests
	test_striteri("HELLO WORLD!", iter_tolower, "hello world!", "iter_tolower");
	test_striteri("abcde", iter_even_to_X, "XbXdX", "iter_even_to_X");

	// ✅ Test using the index
	test_striteri("AAAAAAAAAA", iter_replace_with_index, "0123456789", "iter_replace_with_index");
	test_striteri("42Network", iter_replace_with_index, "012345678", "iter_replace_with_index");

	// ⚠️ Edge cases
	test_striteri("", iter_tolower, "", "iter_tolower"); // Empty string
	test_striteri("test", NULL, "test", "NULL_function");      // NULL function (should not change string)
	return 0;
}
