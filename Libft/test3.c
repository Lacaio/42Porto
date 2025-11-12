/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:04:35 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/12 20:31:25 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

// // ----------------------------------------------------------------------------
// --- Function to test writing an integer to a temporary file descriptor (ft_putnbr_fd) ---
// ----------------------------------------------------------------------------
static void test_putnbr_to_file(int n, const char *test_name)
{
    const char *filepath = "temp_output_nbr.txt";
    int write_fd = -1;
    int read_fd = -1;
    char buffer[50] = {0}; // Enough to hold any 64-bit integer as string
    ssize_t bytes_read;
    char expected[50];

    // Convert number to string using snprintf for comparison
    snprintf(expected, sizeof(expected), "%d", n);

    printf("Test Case: %s\n", test_name);
    printf("  Number to write: %d\n", n);

    // 1. OPEN for writing
    write_fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (write_fd < 0)
    {
        perror("  ❌ FAIL: Could not open file for writing");
        return;
    }

    // 2. EXECUTE: Call ft_putnbr_fd
    ft_putnbr_fd(n, write_fd);

    // 3. CLEANUP & PREPARE FOR READING
    close(write_fd);
    read_fd = open(filepath, O_RDONLY);
    if (read_fd < 0)
    {
        perror("  ❌ FAIL: Could not open file for reading");
        unlink(filepath);
        return;
    }

    // 4. VERIFY: Read bytes
    bytes_read = read(read_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0)
    {
        perror("  ❌ FAIL: Error reading file");
        close(read_fd);
        unlink(filepath);
        return;
    }
    buffer[bytes_read] = '\0'; // Null-terminate

    // 5. Check result
    if (strcmp(buffer, expected) == 0)
    {
        printf("  Result: \"%s\" (✅ PASS)\n", buffer);
    }
    else
    {
        printf("  Result: \"%s\" (❌ FAIL, Expected: \"%s\")\n", buffer, expected);
    }

    // 6. Final Cleanup
    close(read_fd);
    if (unlink(filepath) != 0)
        perror("  Warning: Failed to delete temporary file");
    printf("\n");
}
// --- Function to test writing a single character to a temporary file descriptor (ft_putchar_fd) ---
static void test_putchar_to_file(char c, const char *test_name)
{
    // Define the temporary file path
    const char *filepath = "temp_output.txt";
    int write_fd = -1;
    int read_fd = -1;
    char buffer[2] = {0}; // Buffer size 2: 1 char + null terminator

    printf("Test Case: %s\n", test_name);
    // Use readable string representation for the null character
    printf("  Character to write: '%s'\n", c == '\0' ? "\\0" : (char[]){c, '\0'});

    // 1. OPEN for writing (O_CREAT: create if not exists, O_TRUNC: truncate to 0 length)
    // Mode 0644 gives owner read/write, others read permission.
    write_fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    
    if (write_fd < 0)
    {
        perror("  ❌ FAIL: Could not open file for writing");
        return;
    }

    // 2. EXECUTE: Call ft_putchar_fd
    ft_putchar_fd(c, write_fd);

    // 3. CLEANUP & PREPARE FOR READING: Close the write file descriptor
    close(write_fd);

    // 4. OPEN for reading
    read_fd = open(filepath, O_RDONLY);

    if (read_fd < 0)
    {
        perror("  ❌ FAIL: Could not open file for reading");
        unlink(filepath); // Try to delete anyway
        return;
    }

    // 5. VERIFY: Read one byte from the file into the buffer
    ssize_t bytes_read = read(read_fd, buffer, 1);
    
    // 6. Final checks
    if (bytes_read == 1)
    {
        // Null-terminate the buffer for safe printing
        buffer[1] = '\0'; 
        
        if (buffer[0] == c)
        {
            // Use descriptive text if the character is null
            const char *display_c = c == '\0' ? "\\0" : (char[]){c, '\0'};
            printf("  Result: '%s' (✅ PASS)\n", display_c);
        }
        else
        {
            // Use descriptive text if the character is null
            const char *display_read = buffer[0] == '\0' ? "\\0" : (char[]){buffer[0], '\0'};
            const char *display_expected = c == '\0' ? "\\0" : (char[]){c, '\0'};
            printf("  Result: '%s' (❌ FAIL, Expected: '%s')\n", display_read, display_expected);
        }
    }
    else
    {
        printf("  ❌ FAIL: Expected 1 byte, Read %zd bytes (File empty/Error)\n", bytes_read);
    }
    
    // 7. Final Cleanup: Close the read FD and delete the temporary file
    close(read_fd);
    if (unlink(filepath) != 0)
    {
        perror("  Warning: Failed to delete temporary file");
    }
    printf("\n");
}

// ----------------------------------------------------------------------------
// --- Function to test writing a string to a temporary file descriptor (ft_putstr_fd) ---
// ----------------------------------------------------------------------------
static void test_putstr_to_file(const char *s, const char *test_name)
{
    const char *filepath = "temp_output_str.txt";
    int write_fd = -1;
    int read_fd = -1;
    size_t len = s ? strlen(s) : 0;
    char *buffer = NULL;
    ssize_t bytes_read;

    printf("Test Case: %s\n", test_name);
    printf("  String to write: \"%s\"\n", s ? s : "(NULL)");

    // Handle NULL string case for ft_putstr_fd
    if (!s)
    {
        printf("  Note: Testing with NULL string. Should ideally do nothing or handle safely.\n\n");
        return; 
    }

    // 1. OPEN for writing
    write_fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    
    if (write_fd < 0)
    {
        perror("  ❌ FAIL: Could not open file for writing");
        return;
    }

    // 2. EXECUTE: Call ft_putstr_fd
    // Casting 's' to 'char *' to match the non-const function prototype assumed in libft.h
    ft_putstr_fd((char *)s, write_fd);

    // 3. CLEANUP & PREPARE FOR READING: Close the write file descriptor
    close(write_fd);

    // 4. OPEN for reading
    read_fd = open(filepath, O_RDONLY);

    if (read_fd < 0)
    {
        perror("  ❌ FAIL: Could not open file for reading");
        unlink(filepath);
        return;
    }
    
    // Allocate buffer large enough for the string and null terminator
    buffer = (char *)malloc(len + 1);
    if (!buffer)
    {
        perror("  ❌ FAIL: Memory allocation failed");
        close(read_fd);
        unlink(filepath);
        return;
    }
    memset(buffer, 0, len + 1); // Clear buffer

    // 5. VERIFY: Read the expected number of bytes
    bytes_read = read(read_fd, buffer, len + 1); // Read up to len + 1

    // 6. Final checks
    if (bytes_read == (ssize_t)len)
    {
        if (strcmp(buffer, s) == 0)
        {
            printf("  Result: \"%s\" (✅ PASS)\n", buffer);
        }
        else
        {
            printf("  Result: \"%s\" (❌ FAIL, Expected: \"%s\")\n", buffer, s);
        }
    }
    else
    {
        printf("  ❌ FAIL: Expected %zu bytes, Read %zd bytes (File content mismatch/Error)\n", len, bytes_read);
    }
    
    // 7. Final Cleanup
    free(buffer);
    close(read_fd);
    if (unlink(filepath) != 0)
    {
        perror("  Warning: Failed to delete temporary file");
    }
    printf("\n");
}

// ----------------------------------------------------------------------------
// --- NEW FUNCTION: Function to test writing a string + newline (ft_putendl_fd) ---
// ----------------------------------------------------------------------------
static void test_putendl_to_file(const char *s, const char *test_name)
{
    const char *filepath = "temp_output_endl.txt";
    int write_fd = -1;
    int read_fd = -1;
    size_t len = s ? strlen(s) : 0;
    size_t expected_len = len + 1; // +1 for the appended newline
    char *buffer = NULL;
    ssize_t bytes_read;
    int success = 0;

    printf("Test Case: %s\n", test_name);
    printf("  String to write: \"%s\"\\n\n", s ? s : "(NULL)");

    if (!s)
    {
        printf("  Note: Testing with NULL string. Should ideally do nothing or handle safely.\n\n");
        return; 
    }

    // 1. OPEN for writing
    write_fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    
    if (write_fd < 0)
    {
        perror("  ❌ FAIL: Could not open file for writing");
        return;
    }

    // 2. EXECUTE: Call ft_putendl_fd
    // Casting 's' to 'char *' to match the non-const function prototype assumed in libft.h
    ft_putendl_fd((char *)s, write_fd);

    // 3. CLEANUP & PREPARE FOR READING: Close the write file descriptor
    close(write_fd);

    // 4. OPEN for reading
    read_fd = open(filepath, O_RDONLY);

    if (read_fd < 0)
    {
        perror("  ❌ FAIL: Could not open file for reading");
        unlink(filepath);
        return;
    }
    
    // Allocate buffer large enough for the string + newline + null terminator
    buffer = (char *)malloc(expected_len + 1);
    if (!buffer)
    {
        perror("  ❌ FAIL: Memory allocation failed");
        close(read_fd);
        unlink(filepath);
        return;
    }
    memset(buffer, 0, expected_len + 1); // Clear buffer

    // 5. VERIFY: Read the expected number of bytes
    bytes_read = read(read_fd, buffer, expected_len + 1); 

    // 6. Final checks
    if (bytes_read == (ssize_t)expected_len)
    {
        // Check if the last character is '\n' AND the preceding characters match 's'
        if (buffer[expected_len - 1] == '\n' && strncmp(buffer, s, len) == 0)
        {
            success = 1;
            printf("  Result: \"%s\\n\" (✅ PASS)\n", s);
        }
    }

    if (!success)
    {
        printf("  ❌ FAIL: Expected: \"%s\\n\" (%zu bytes), Read %zd bytes.\n", s, expected_len, bytes_read);
        if (bytes_read > 0)
        {
            // For visibility in case of failure, display what was actually read
            buffer[bytes_read] = '\0';
            printf("  Actual content read (including null byte at the end): \"%s\"\n", buffer);
        }
    }
    
    // 7. Final Cleanup
    free(buffer);
    close(read_fd);
    if (unlink(filepath) != 0)
    {
        perror("  Warning: Failed to delete temporary file");
    }
    printf("\n");
}


int main(void)
{
    // ==========================================
    //          Testing ft_putchar_fd
    // ==========================================
    printf("==========================================\n");
    printf("          Testing ft_putchar_fd\n");
    printf("==========================================\n\n");

    // --- Visual Check (fd 1 - STDOUT) ---
    printf("--- Visual Check (fd 1 - STDOUT) ---\n");
    printf("Expected output on the next line is: 'H E L L O'\n");
    ft_putchar_fd('H', STDOUT_FILENO); ft_putchar_fd(' ', STDOUT_FILENO);
    ft_putchar_fd('E', STDOUT_FILENO); ft_putchar_fd(' ', STDOUT_FILENO);
    ft_putchar_fd('L', STDOUT_FILENO); ft_putchar_fd(' ', STDOUT_FILENO);
    ft_putchar_fd('L', STDOUT_FILENO); ft_putchar_fd(' ', STDOUT_FILENO);
    ft_putchar_fd('O', STDOUT_FILENO); ft_putchar_fd('\n', STDOUT_FILENO);
    printf("--- End of Visual Check ---\n\n");
    
    // --- Functional Check (Writing to temp file) ---
    printf("--- Functional Check (Writing to temp file) ---\n");
    test_putchar_to_file('a', "Basic lowercase character");
    test_putchar_to_file('\0', "Null terminator (should write a single null byte)");
    printf("==========================================\n");

    // ==========================================
    //          Testing ft_putstr_fd
    // ==========================================
    printf("==========================================\n");
    printf("          Testing ft_putstr_fd\n");
    printf("==========================================\n\n");

    // --- Visual Check (fd 1 - STDOUT) ---
    printf("--- Visual Check (fd 1 - STDOUT) ---\n");
    printf("Expected output on the next line is: 'Hello, World!'\n");
    ft_putstr_fd("Hello, World!", STDOUT_FILENO);
    ft_putchar_fd('\n', STDOUT_FILENO);
    printf("--- End of Visual Check ---\n\n");
    
    // --- Functional Check (Writing to temp file) ---
    printf("--- Functional Check (Writing to temp file) ---\n");
    test_putstr_to_file("42 Porto", "Alphanumeric string");
    test_putstr_to_file("", "Empty string");
    test_putstr_to_file(NULL, "NULL pointer test (should not crash)");
    printf("==========================================\n");


    // ==========================================
    //          Testing ft_putendl_fd
    // ==========================================
    printf("==========================================\n");
    printf("          Testing ft_putendl_fd\n");
    printf("==========================================\n\n");

    // --- Visual Check (fd 1 - STDOUT) ---
    printf("--- Visual Check (fd 1 - STDOUT) ---\n");
    printf("Expected output on the next line is: 'This is a line', followed by a newline.\n");
    ft_putendl_fd("This is a line", STDOUT_FILENO);
    printf("--- End of Visual Check ---\n\n");
    
    // --- Functional Check (Writing to temp file) ---
    printf("--- Functional Check (Writing to temp file) ---\n");
    test_putendl_to_file("Test string with appended newline.", "Basic string test");
    test_putendl_to_file("123", "Short numeric string");
    test_putendl_to_file("", "Empty string (should only write '\\n')");
    test_putendl_to_file(NULL, "NULL pointer test (should not crash)");

    printf("==========================================\n");



// ==========================================
//          Testing ft_putnbr_fd
// ==========================================
printf("==========================================\n");
printf("          Testing ft_putnbr_fd\n");
printf("==========================================\n\n");

// --- Functional Check (Writing to temp file) ---
printf("--- Functional Check (Writing to temp file) ---\n");
test_putnbr_to_file(0, "Zero");
test_putnbr_to_file(42, "Positive number");
test_putnbr_to_file(-12345, "Negative number");
test_putnbr_to_file(2147483647, "INT_MAX");
test_putnbr_to_file(-2147483648, "INT_MIN");
printf("==========================================\n");
    return 0;
}
