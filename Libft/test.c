#include "libft.h"
#define MAX_SIZE 10

void print_mem_block(void *ptr, size_t size)
{
    unsigned char *p = (unsigned char *)ptr;
    for (size_t i = 0; i < size; i++)
    {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

void print_strdup_result(int test_num, const char *original, const char *copy, const char *msg)
{
	
    // Print the test description first, matching the ft_atoi/ft_strnstr style
    printf("%d. %s (Original: \"%s\")\n", test_num, msg, original);

    // Check for allocation failure
    if (copy == NULL) {
        printf("ft_strdup: (NULL) | FAILED (Allocation error)\n");
        return;
    }

    // 1. Check if the content is correct using strcmp
    if (strcmp(original, copy) == 0)
    {
        // 2. Check if the pointer is unique (i.e., new memory was allocated)
        if (original != copy)
        {
            printf("ft_strdup: \"%s\" | PASSED (New memory allocated)\n", copy);
        }
        else
        {
            // This is a logic failure for ft_strdup, as it must allocate new memory
            printf("ft_strdup: \"%s\" | FAILED (Pointers are the same, no new allocation)\n", copy);
        }
    }
    else
    {
        // Content Mismatch Failure
        printf("ft_strdup: FAILED (Content mismatch. Got: \"%s\")\n", copy);
        // Note: The ugly output you saw is due to your ft_strdup likely not null-terminating
        // correctly, or copying garbage. The layout is now fixed, but your implementation
        // may still show bad content here until fixed.
    }

    // Clean up allocated memory (IMPORTANT!)
    free((void *)copy);
}

int main(void)
{
    const char  *long_src = "A very long source string for truncation test.";
    const char  *cat_src = "ABCDE";

    char        strlcpy_dest_ft[MAX_SIZE];
    char        strlcpy_dest_std[MAX_SIZE];

    char        strlcat_dest_ft[MAX_SIZE] = "123"; 
    char        strlcat_dest_std[MAX_SIZE] = "123"; 

    int         num = 12;
    char        s[10] = "ghjkl";
    void        *memset_ft = malloc(20);
    void        *bzero_ft = malloc(15);
    const void  *memcpy_src = "dfghjkl;'dfghjkl;dfghjk";
    void        *memcpy_dest_ft = malloc(30);
    void        *memmove_dest_ft = malloc(30);
    const void  *memmove_src = "sdfghjklxcvbnm,djdafkhfkjhdkfjshdkfjhsdkjffhskdjfskhddbs djfhskldfk";

    int         std_num = 12;
    char        std_s[10] = "ghjkl";
    void        *memset_std = malloc(20);
    void        *bzero_std = malloc(15);
    void        *memcpy_dest_std = malloc(30);
    void        *memmove_dest_std = malloc(30);

    int lower_char = 'a';
    int upper_char = 'Z';
    int non_alpha = '5';

    const char *strchr_src = "Hello World!";
    int char_to_find_1 = 'o';
    int char_to_find_2 = '!';
    int char_to_find_3 = 'z';
    int null_char = '\0';

    const char *strrchr_src = "banana boat";

    const char *cmp_s1 = "abcdefgh";
    const char *cmp_s2 = "abcdeFGH";
    const char *cmp_s3 = "abc";   
    const char *cmp_s4 = "abC";    

    char memchr_src[15] = "hello\0world\0\0";
    int byte_to_find_1 = 'o';
    int byte_to_find_2 = '\0';
    int byte_to_find_3 = 'z';

    char memcmp_s1[15] = "aB\0cdefgh";
    char memcmp_s2[15] = "ab\0cdefgh";
    char memcmp_s3[15] = "aB\0cdeZYX";

    const char *haystack = "Foo Bar Baz Foo";
    const char *needle1 = "Bar";
    const char *needle2 = "Foo";
    const char *needle3 = "QuX";
    size_t len1 = 15;
    size_t len2 = 5;
    size_t len3 = 3;     
    
    const char *atoi_s1 = "12345";
    const char *atoi_s2 = "  \t\n-42";
    const char *atoi_s3 = "+99bottles";
    const char *atoi_s4 = "words-10";
    const char *atoi_s5 = "0";
    const char *atoi_s6 = "-2147483648"; 
    const char *atoi_s7 = ""; 

    // --- Variables for ft_calloc tests ---
    int     *ft_c_arr = NULL;
    int     *std_c_arr = NULL;
    size_t  c_nmemb = 5;
    size_t  c_size = sizeof(int);
    size_t  c_i;
    size_t  total_c_size = c_nmemb * c_size;

    if (!memset_ft || !bzero_ft || !memcpy_dest_ft || !memmove_dest_ft ||
        !memset_std || !bzero_std || !memcpy_dest_std || !memmove_dest_std)
    {
        printf("Error: Malloc failed.\n");
        return 1;
    }

    // --- Malloc/Calloc variables that need to be freed later ---
    void    *calloc_ft_ptr = NULL;
    void    *calloc_std_ptr = NULL;
    void    *calloc_null_check = NULL;

    char    *dup_ptr = NULL;

    if (!memset_ft || !bzero_ft || !memcpy_dest_ft || !memmove_dest_ft ||
        !memset_std || !bzero_std || !memcpy_dest_std || !memmove_dest_std)
    {
        printf("Error: Malloc failed.\n");
        return 1;
    }

    printf("\n--- Char Checks (Arg: 12) ---\n");
    printf("ft_isalpha: %d | isalpha: %d\n", ft_isalpha(num), isalpha(std_num));
    printf("ft_isdigit: %d | isdigit: %d\n", ft_isdigit(num), isdigit(std_num));
    printf("ft_isalnum: %d | isalnum: %d\n", ft_isalnum(num), isalnum(std_num));
    printf("ft_isascii: %d | isascii: %d\n", ft_isascii(num), isascii(std_num));
    printf("ft_isprint: %d | isprint: %d\n", ft_isprint(num), isprint(std_num));

    printf("\n--- String/Memory ---\n");
    printf("ft_strlen : %zu | strlen: %zu\n", ft_strlen(s), strlen(std_s));

    printf("\n- ft_memset.c (Sets to '0', ASCII 48) -\n");
    printf("ft_memset: %s\n", (char*)ft_memset(memset_ft, 48, 20));
    printf("  memset: %s\n", (char*)memset(memset_std, 48, 20));

    printf("\n- ft_bzero.c (Sets to 0) -\n");
    ft_bzero(bzero_ft, 15);
    bzero(bzero_std, 15);
    printf("ft_bzero (hex): "); print_mem_block(bzero_ft, 15);
    printf("  bzero (hex):  "); print_mem_block(bzero_std, 15);

    printf("\n- ft_memcpy.c (Copies 30 bytes) -\n");
    printf("ft_memcpy: %s\n", (char*)ft_memcpy(memcpy_dest_ft, memcpy_src, 30));
    printf("  memcpy: %s\n", (char*)memcpy(memcpy_dest_std, memcpy_src, 30));

    printf("\n- ft_memmove.c (Copies 14 bytes) -\n");
    printf("ft_memmove: %s\n", (char*)ft_memmove(memmove_dest_ft, memmove_src, 14));
    printf("  memmove: %s\n", (char*)memmove(memmove_dest_std, memmove_src, 14));

    printf("\n- ft_strlcpy.c (Dest Size: %zu) -\n", (size_t)MAX_SIZE);
    size_t ft_ret = ft_strlcpy(strlcpy_dest_ft, long_src, MAX_SIZE);
    size_t std_ret = strlcpy(strlcpy_dest_std, long_src, MAX_SIZE);
    printf("ft_strlcpy Dest: %s | Ret Val: %zu\n", strlcpy_dest_ft, ft_ret);
    printf("  strlcpy Dest: %s | Ret Val: %zu\n", strlcpy_dest_std, std_ret);

    printf("\n- ft_strlcat.c (Dest Size: %zu) -\n", (size_t)MAX_SIZE);
    size_t ft_cat_ret = ft_strlcat(strlcat_dest_ft, cat_src, MAX_SIZE);
    size_t std_cat_ret = strlcat(strlcat_dest_std, cat_src, MAX_SIZE);
    printf("ft_strlcat Dest: %s | Ret Val: %zu\n", strlcat_dest_ft, ft_cat_ret);
    printf("  strlcat Dest: %s | Ret Val: %zu\n", strlcat_dest_std, std_cat_ret);

    printf("\n--- ft_toupper/ft_tolower ---\n");
    printf("- toupper - (Source: %c, %c, %c)\n", lower_char, upper_char, non_alpha);
    printf("ft_toupper ('a'): %c | toupper: %c\n", ft_toupper(lower_char), toupper(lower_char));
    printf("ft_toupper ('Z'): %c | toupper: %c\n", ft_toupper(upper_char), toupper(upper_char));
    printf("ft_toupper ('5'): %c | toupper: %c\n", ft_toupper(non_alpha), toupper(non_alpha));

    printf("- tolower - (Source: %c, %c, %c)\n", lower_char, upper_char, non_alpha);
    printf("ft_tolower ('a'): %c | tolower: %c\n", ft_tolower(lower_char), tolower(lower_char));
    printf("ft_tolower ('Z'): %c | tolower: %c\n", ft_tolower(upper_char), tolower(upper_char));
    printf("ft_tolower ('5'): %c | tolower: %c\n", ft_tolower(non_alpha), tolower(non_alpha));

    printf("\n--- ft_strchr.c (Source: \"%s\") ---\n", strchr_src);
    printf("ft_strchr ('%c'): %s | strchr: %s\n",
        char_to_find_1,
        ft_strchr(strchr_src, char_to_find_1),
        strchr(strchr_src, char_to_find_1));
    printf("ft_strchr ('%c'): %s | strchr: %s\n",
        char_to_find_2,
        ft_strchr(strchr_src, char_to_find_2),
        strchr(strchr_src, char_to_find_2));
    printf("ft_strchr ('%c'): %p | strchr: %p\n",
        char_to_find_3,
        (void *)ft_strchr(strchr_src, char_to_find_3),
        (void *)strchr(strchr_src, char_to_find_3));
    printf("ft_strchr ('\\0'): %p | strchr: %p\n",
        (void *)ft_strchr(strchr_src, null_char),
        (void *)strchr(strchr_src, null_char));

    char_to_find_1 = 'a';
    char_to_find_2 = 'b';
    char_to_find_3 = 'z';
    printf("\n--- ft_strrchr.c (Source: \"%s\") ---\n", strrchr_src);
    printf("ft_strrchr ('%c'): %s | strrchr: %s\n",
        char_to_find_1,
        ft_strrchr(strrchr_src, char_to_find_1),
        strrchr(strrchr_src, char_to_find_1));
    printf("ft_strrchr ('%c'): %s | strrchr: %s\n",
        char_to_find_2,
        ft_strrchr(strrchr_src, char_to_find_2),
        strrchr(strrchr_src, char_to_find_2));
    printf("ft_strrchr ('%c'): %p | strrchr: %p\n",
        char_to_find_3,
        (void *)ft_strrchr(strrchr_src, char_to_find_3),
        (void *)strrchr(strrchr_src, char_to_find_3));
    printf("ft_strrchr ('\\0'): %p | strrchr: %p\n",
        (void *)ft_strrchr(strrchr_src, null_char),
        (void *)strrchr(strrchr_src, null_char));

    printf("\n--- ft_strncmp.c ---\n");
    printf("1. S1: \"%s\", S2: \"%s\", N: 5\n", cmp_s1, cmp_s2);
    printf("ft_strncmp: %d | strncmp: %d\n",
        ft_strncmp(cmp_s1, cmp_s2, 5),
        strncmp(cmp_s1, cmp_s2, 5));
    printf("2. S1: \"%s\", S2: \"%s\", N: 8\n", cmp_s1, cmp_s2);
    printf("ft_strncmp: %d | strncmp: %d\n",
        ft_strncmp(cmp_s1, cmp_s2, 8),
        strncmp(cmp_s1, cmp_s2, 8));
    printf("3. S1: \"%s\", S3: \"%s\", N: 0\n", cmp_s1, cmp_s3);
    printf("ft_strncmp: %d | strncmp: %d\n",
        ft_strncmp(cmp_s1, cmp_s3, 0),
        strncmp(cmp_s1, cmp_s3, 0));
    printf("4. S1: \"%s\", S3: \"%s\", N: 10\n", cmp_s1, cmp_s3);
    printf("ft_strncmp: %d | strncmp: %d\n",
        ft_strncmp(cmp_s3, cmp_s1, 10),
        strncmp(cmp_s3, cmp_s1, 10));
    printf("5. S4: \"%s\", S3: \"%s\", N: 3\n", cmp_s4, cmp_s3);
    printf("ft_strncmp: %d | strncmp: %d\n",
        ft_strncmp(cmp_s4, cmp_s3, 3),
        strncmp(cmp_s4, cmp_s3, 3));

    printf("\n--- ft_memchr.c (Source: [h][e][l][l][o][\\0][w]...) ---\n");
    printf("1. ft_memchr ('%c', N=6): %p | memchr: %p\n",
        byte_to_find_1,
        (void *)ft_memchr(memchr_src, byte_to_find_1, 6),
        (void *)memchr(memchr_src, byte_to_find_1, 6));
    printf("2. ft_memchr ('\\0', N=8): %p | memchr: %p\n",
        (void *)ft_memchr(memchr_src, byte_to_find_2, 8),
        (void *)memchr(memchr_src, byte_to_find_2, 8));
    printf("3. ft_memchr ('%c', N=10): %p | memchr: %p\n",
        byte_to_find_3,
        (void *)ft_memchr(memchr_src, byte_to_find_3, 10),
        (void *)memchr(memchr_src, byte_to_find_3, 10));
    printf("4. ft_memchr ('w', N=6): %p | memchr: %p\n",
        (void *)ft_memchr(memchr_src, 'w', 6),
        (void *)memchr(memchr_src, 'w', 6));
    
    printf("\n--- ft_memcmp.c ---\n");
    printf("1. S1 vs S2 (N=5): [aB\\0cd] vs [ab\\0cd]\n");
    printf("ft_memcmp: %d | memcmp: %d\n", 
        ft_memcmp(memcmp_s1, memcmp_s2, 5), 
        memcmp(memcmp_s1, memcmp_s2, 5));
    printf("2. S1 vs S3 (N=2): [aB] vs [aB]\n");
    printf("ft_memcmp: %d | memcmp: %d\n", 
        ft_memcmp(memcmp_s1, memcmp_s3, 2), 
        memcmp(memcmp_s1, memcmp_s3, 2));
    printf("3. S1 vs S2 (N=3): [aB\\0] vs [ab\\0]\n");
    printf("ft_memcmp: %d | memcmp: %d\n", 
        ft_memcmp(memcmp_s1, memcmp_s2, 3), 
        memcmp(memcmp_s1, memcmp_s2, 3));
    printf("4. S1 vs S3 (N=6): [aB\\0cdef] vs [aB\\0cdeZ]\n");
    printf("ft_memcmp: %d | memcmp: %d\n", 
        ft_memcmp(memcmp_s1, memcmp_s3, 6), 
        memcmp(memcmp_s1, memcmp_s3, 6));
    printf("5. S1 vs S2 (N=0): [] vs []\n");
    printf("ft_memcmp: %d | memcmp: %d\n", 
        ft_memcmp(memcmp_s1, memcmp_s2, 0), 
        memcmp(memcmp_s1, memcmp_s2, 0));

    printf("\n--- ft_strnstr.c (Haystack: \"%s\") ---\n", haystack);
    printf("1. Needle: \"%s\", Len: %zu\n", needle1, len1);
    printf("ft_strnstr: %s | strnstr: %s\n", 
        ft_strnstr(haystack, needle1, len1), 
        strnstr(haystack, needle1, len1));
    printf("2. Needle: \"%s\", Len: %zu\n", needle1, len2);
    printf("ft_strnstr: %p | strnstr: %p\n", 
        (void *)ft_strnstr(haystack, needle1, len2), 
        (void *)strnstr(haystack, needle1, len2));
    printf("3. Needle: \"%s\", Len: %zu\n", needle2, len1);
    printf("ft_strnstr: %s | strnstr: %s\n", 
        ft_strnstr(haystack, needle2, len1), 
        strnstr(haystack, needle2, len1));
    printf("4. Needle: \"%s\", Len: %zu\n", needle3, len1);
    printf("ft_strnstr: %p | strnstr: %p\n", 
        (void *)ft_strnstr(haystack, needle3, len1), 
        (void *)strnstr(haystack, needle3, len1));
    printf("5. Needle: \"%s\", Len: %zu\n", needle2, len3);
    printf("ft_strnstr: %s | strnstr: %s\n", 
        ft_strnstr(haystack, needle2, len3), 
        strnstr(haystack, needle2, len3));
    printf("6. Needle: \"\", Len: %zu\n", len1);
    printf("ft_strnstr: %p | strnstr: %p\n", 
        (void *)ft_strnstr(haystack, "", len1), 
        (void *)strnstr(haystack, "", len1));

    printf("\n--- ft_atoi.c ---\n");
    printf("1. Str: \"%s\"\n", atoi_s1);
    printf("ft_atoi: %d | atoi: %d\n", ft_atoi(atoi_s1), atoi(atoi_s1));
    printf("2. Str: \"%s\" (Whitespace/Neg)\n", atoi_s2);
    printf("ft_atoi: %d | atoi: %d\n", ft_atoi(atoi_s2), atoi(atoi_s2));
    printf("3. Str: \"%s\" (Plus sign/Trailing chars)\n", atoi_s3);
    printf("ft_atoi: %d | atoi: %d\n", ft_atoi(atoi_s3), atoi(atoi_s3));
    printf("4. Str: \"%s\" (No leading digit)\n", atoi_s4);
    printf("ft_atoi: %d | atoi: %d\n", ft_atoi(atoi_s4), atoi(atoi_s4));
    printf("5. Str: \"%s\" (Zero)\n", atoi_s5);
    printf("ft_atoi: %d | atoi: %d\n", ft_atoi(atoi_s5), atoi(atoi_s5));
    printf("6. Str: \"%s\" (INT_MIN)\n", atoi_s6);
    printf("ft_atoi: %d | atoi: %d\n", ft_atoi(atoi_s6), atoi(atoi_s6));
    printf("7. Str: \"%s\" (EMPTHY)\n", atoi_s7);
    printf("ft_atoi: %d | atoi: %d\n", ft_atoi(atoi_s7), atoi(atoi_s7));
    
 printf("\n--- ft_calloc.c ---\n");

    // Test 1: Basic allocation (5 ints, 20 bytes) and zero check
    ft_c_arr = ft_calloc(c_nmemb, c_size);
    std_c_arr = calloc(c_nmemb, c_size);
    printf("1. Alloc %zu ints (%zu total bytes):\n", c_nmemb, total_c_size);
    printf("   ft_calloc (hex): "); print_mem_block(ft_c_arr, total_c_size);
    printf("   calloc (hex):   "); print_mem_block(std_c_arr, total_c_size);

    // Test 2: Check values are 0 (e.g., ft_arr[3] should be 0)
    for (c_i = 0; c_i < c_nmemb; c_i++)
    {
        if (ft_c_arr[c_i] != 0)
        {
            printf("FAIL: ft_arr[%zu] is %d (expected 0)\n", c_i, ft_c_arr[c_i]);
            break;
        }
    }
    if (c_i == c_nmemb)
        printf("2. Data Check: PASS (All %zu elements initialized to 0)\n", c_nmemb);
    
    // Free the allocated blocks from Test 1 & 2
    free(ft_c_arr);
    free(std_c_arr);
    
    // Test 3: Zero-size allocation (should return a valid pointer or NULL, matching standard)
    calloc_ft_ptr = ft_calloc(0, sizeof(int));
    calloc_std_ptr = calloc(0, sizeof(int));
    printf("3. Zero-size (0, sizeof(int)) Test:\n");
    printf("   ft_calloc: %p | calloc: %p (match expected)\n", calloc_ft_ptr, calloc_std_ptr);
    // Note: The C standard allows both NULL or a non-NULL pointer for malloc(0)/calloc(0, X), 
    // but they must be freed. The test just checks that they both return *something*.
    
    // Test 4: Overflow Check (big_nmemb * overflow_size > SIZE_MAX)
    // The test relies on your ft_calloc's SIZE_MAX check (as discussed previously).
    size_t big_nmemb = 2; 
    size_t overflow_size = ((size_t)-1) / 2 + 1;
    calloc_null_check = ft_calloc(big_nmemb, overflow_size);
    printf("4. Overflow Check (big numbers):\n");
    if (calloc_null_check == NULL)
        printf("   ft_calloc: %p (PASS: Correctly returned NULL on overflow)\n", calloc_null_check);
    else
    {
        printf("   ft_calloc: %p (FAIL: Returned pointer on overflow)\n", calloc_null_check);
        free(calloc_null_check); // Clean up if it failed to return NULL
    }
    
    
    printf("\n--- ft_strdup.c ---\n");
    const char *s1_dup = "Hello, Libft!";
    dup_ptr = ft_strdup(s1_dup);
    print_strdup_result(1, s1_dup, dup_ptr, "Basic String");

    // Test 2: Empty String Duplication (Crucial edge case)
    const char *s2_dup = "";
    dup_ptr = ft_strdup(s2_dup);
    print_strdup_result(2, s2_dup, dup_ptr, "Empty String");

    // Test 3: String with spaces and numbers
    const char *s3_dup = " 42 Porto is cool 2024 ";
    dup_ptr = ft_strdup(s3_dup);
    print_strdup_result(3, s3_dup, dup_ptr, "Spaces and Numbers");

    // Test 4: Long string
    const char *s4_dup = "A very long string to check if the allocation can handle large lengths correctly and efficiently for several dozen bytes.";
    dup_ptr = ft_strdup(s4_dup);
    print_strdup_result(4, s4_dup, dup_ptr, "Long String");

    // --------------------------------------------------------------------------

    free(memset_ft);
    free(bzero_ft);
    free(memcpy_dest_ft);
    free(memmove_dest_ft);

    free(memset_std);
    free(bzero_std);
    free(memcpy_dest_std);
    free(memmove_dest_std);

    // Free all calloc test pointers
    if (calloc_ft_ptr) 
	    free(calloc_ft_ptr);
    if (calloc_std_ptr) 
	    free(calloc_std_ptr);
    // calloc_null_check is already handled above
    return (0);
}
