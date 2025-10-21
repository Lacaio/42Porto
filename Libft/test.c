#include "libft.h"
#define MAX_SIZE 10

/*int	main(void)
{
	int	num = 12;
	char	s[10] = "ghjkl";
	void	*memset = malloc(20);
	void	*bzero = malloc(15);
	void	*memcpy_src = "dfghjkl;'dfghjkl;dfghjk";
	void	*memcpy_dest = malloc(30);
	void	*memmove_dest = malloc(30);
	void	*memmove_src = "sdfghjklxcvbnm,djdafkhfkjhdkfjshdkfjhsdkjffhskdjfskhddbs djfhskldfk";
	printf("ft_isalpha.c: %d\n", ft_isalpha(num));
	printf("ft_isdigit.c: %d\n", ft_isdigit(num));
	printf("ft_isalnum.c: %d\n", ft_isalnum(num));
	printf("ft_isascii.c: %d\n", ft_isascii(num));
	printf("ft_isprint.c: %d\n", ft_isprint(num));
	printf("ft_strlen.c: %zu\n", ft_strlen(s));
	printf("ft_memset.c: %s\n", (char*)ft_memset(memset, 48, 20));
	ft_bzero(bzero, 15);
	printf("ft_bzero.c: %s\n", (char*)bzero);
	printf("ft_memcpy.c: %s\n", (char*)ft_memcpy(memcpy_dest, memcpy_src, 30));
	printf("ft_memmove.c: %s\n", (char*)ft_memmove(memmove_dest, memmove_src, 14));
	free(memset);
	free(bzero);
	free(memcpy_dest);
	free(memmove_dest);
	return (0);

}*/

void print_mem_block(void *ptr, size_t size)
{
    unsigned char *p = (unsigned char *)ptr;
    for (size_t i = 0; i < size; i++)
    {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

size_t strlcpy_safe_wrapper(char *dst, const char *src, size_t size)
{
    size_t src_len = strlen(src);
    size_t copy_len = (src_len < size) ? src_len : size - 1;

    if (size > 0)
    {
        memcpy(dst, src, copy_len);
        dst[copy_len] = '\0';
    }
    return src_len;
}

size_t strlcat_safe_wrapper(char *dst, const char *src, size_t size)
{
    size_t dst_len = strlen(dst);
    size_t src_len = strlen(src);
    size_t total_len = dst_len + src_len;
    size_t copy_limit;

    if (size == 0 || dst_len >= size)
        return total_len;

    copy_limit = size - dst_len - 1;

    strncpy(dst + dst_len, src, copy_limit);

    dst[dst_len + copy_limit] = '\0';

    return total_len;
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
    size_t std_ret = strlcpy_safe_wrapper(strlcpy_dest_std, long_src, MAX_SIZE);
    printf("ft_strlcpy Dest: %s | Ret Val: %zu\n", strlcpy_dest_ft, ft_ret);
    printf("  strlcpy Dest: %s | Ret Val: %zu\n", strlcpy_dest_std, std_ret);

    printf("\n- ft_strlcat.c (Dest Size: %zu) -\n", (size_t)MAX_SIZE);
    size_t ft_cat_ret = ft_strlcat(strlcat_dest_ft, cat_src, MAX_SIZE);
    size_t std_cat_ret = strlcat_safe_wrapper(strlcat_dest_std, cat_src, MAX_SIZE);
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

    free(memset_ft);
    free(bzero_ft);
    free(memcpy_dest_ft);
    free(memmove_dest_ft);

    free(memset_std);
    free(bzero_std);
    free(memcpy_dest_std);
    free(memmove_dest_std);

    return (0);
}
