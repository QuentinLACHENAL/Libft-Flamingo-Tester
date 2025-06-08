#include "libft.h"
#include <stdio.h>
#include <string.h> // For original string functions
#include <stdlib.h> // For malloc, free
#include <limits.h> // For INT_MAX and INT_MIN
#include <fcntl.h>  // For open
#include <unistd.h> // For read, write, close, remove
#include <ctype.h>

// Color codes for the output
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"
#define YELLOW  "\033[95m"

	/**
 * @brief Prints a magnificent flamingo to celebrate the end of the tests.
 */
void	print_flamingo_art(void)
{
	printf(YELLOW);
	printf("\n");
	printf("                    __\n");
	printf("`       `          .^ o ~\\  `    `    `         `\n");
	printf("         ``  `    Y /'~) }      _____           `     `` `\n");
	printf("          `       l/  / /    ,-~     ~~--.,_    `       `   ``\n");
	printf("     `           `   ( (    /  ~-._         ^.\n");
	printf("     ``      `        \\ \"--'--.   \"-._      \\    `     `\n");
	printf("       `           `   \"-.________     ~--.,__ ^.          `\n");
	printf("               `    `            \\\"~r-.,___.-'-. ^.\n");
	printf("         `   `             `     YI    \\\\    ~-.\\   `     `\n");
	printf("                `         `      ||     \\\\       `\\\n");
	printf("          `          `           ||     //\n");
	printf("        `      `           `     ||    //\n");
	printf("        `          `        `    ()   //\n");
	printf("                  `        `     ||  //      `    `\n");
	printf("                 `               || ( c       `\n");
	printf("             `      ___._ __  ___I|__`--__._ __  _\n");
	printf("                 \"~   ~ \"~  \"\"   ~~\"   ~  ~~\n");
	printf("\n");
	printf("                       LIBFT FLAMINGO TESTER - QLACHENA\n");
	printf(RESET);
}


/**
 * @brief Compares the result of the original function with yours and prints status.
 * @param test_num The number of the test.
 * @param original The result from the original libc function.
 * @param yours The result from your ft_ function.
 * @param comment A detailed description of the test case.
 */
void	print_result(int test_num, int original, int yours, const char *comment)
{
	printf("Test %d: %s... ", test_num, comment);
	// Ctype functions return 0 for FALSE and a non-zero value for TRUE.
	// This comparison checks if both are zero or both are non-zero.
	if ((original > 0) == (yours > 0))
	{
		printf(GREEN "[OK]\n" RESET);
	}
	else
	{
		printf(RED "[KO]\n" RESET);
		printf("      -> Original's return: %d, Your return: %d\n", original, yours);
	}
}

#ifdef TEST_BONUS_ON


void	del_content(void *content)
{
	free(content);
}

void	iter_func(void *content)
{
	char *str = (char *)content;
	while(*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

void	*map_func(void *content)
{
	char *new_str = ft_strjoin((char *)content, " MAPPED");
	return (new_str);
}


#endif

int	main(void)
{
		printf("\n");
	printf(YELLOW "--- The flamingo will now test your work. Beware of the almighty flamingo! ---\n");
	print_flamingo_art();
		printf("\n");
	printf(YELLOW "--- Starting tests for CTYPE functions ---\n\n" RESET);

	// --- 1. ft_isalpha ---
	printf("--- Testing ft_isalpha ---\n");
	print_result(1, isalpha('a'), ft_isalpha('a'), "Input: lowercase 'a'. Expected: TRUE");
	print_result(2, isalpha('Z'), ft_isalpha('Z'), "Input: uppercase 'Z'. Expected: TRUE");
	print_result(3, isalpha('5'), ft_isalpha('5'), "Input: digit '5'. Expected: FALSE");
	print_result(4, isalpha('\t'), ft_isalpha('\t'), "Input: control character '\\t'. Expected: FALSE");
	print_result(5, isalpha(0), ft_isalpha(0), "Input: NULL character (ASCII 0). Expected: FALSE");
	printf("\n");

	// --- 2. ft_isdigit ---
	printf("--- Testing ft_isdigit ---\n");
	print_result(1, isdigit('7'), ft_isdigit('7'), "Input: digit '7'. Expected: TRUE");
	print_result(2, isdigit('0'), ft_isdigit('0'), "Input: digit '0'. Expected: TRUE");
	print_result(3, isdigit('a'), ft_isdigit('a'), "Input: letter 'a'. Expected: FALSE");
	print_result(4, isdigit(' '), ft_isdigit(' '), "Input: space character. Expected: FALSE");
	printf("\n");

	// --- 3. ft_isalnum ---
	printf("--- Testing ft_isalnum ---\n");
	print_result(1, isalnum('b'), ft_isalnum('b'), "Input: letter 'b'. Expected: TRUE");
	print_result(2, isalnum('8'), ft_isalnum('8'), "Input: digit '8'. Expected: TRUE");
	print_result(3, isalnum('$'), ft_isalnum('$'), "Input: symbol '$'. Expected: FALSE");
	print_result(4, isalnum('~'), ft_isalnum('~'), "Input: punctuation '~'. Expected: FALSE");
	printf("\n");

	// --- 4. ft_isascii ---
	printf("--- Testing ft_isascii ---\n");
	print_result(1, isascii(127), ft_isascii(127), "Input: upper bound of ASCII range (127). Expected: TRUE");
	print_result(2, isascii(0), ft_isascii(0), "Input: lower bound of ASCII range (0). Expected: TRUE");
	print_result(3, isascii(128), ft_isascii(128), "Input: first value outside range (128). Expected: FALSE");
	print_result(4, isascii(-1), ft_isascii(-1), "Input: negative value (-1). Expected: FALSE");
	printf("\n");

	// --- 5. ft_isprint ---
	printf("--- Testing ft_isprint ---\n");
	print_result(1, isprint(' '), ft_isprint(' '), "Input: first printable character, space (ASCII 32). Expected: TRUE");
	print_result(2, isprint('~'), ft_isprint('~'), "Input: last printable character, tilde (ASCII 126). Expected: TRUE");
	print_result(3, isprint('\n'), ft_isprint('\n'), "Input: non-printable control char, newline (ASCII 10). Expected: FALSE");
	print_result(4, isprint(31), ft_isprint(31), "Input: non-printable control char (ASCII 31). Expected: FALSE");
	printf("\n");

	// --- 6. ft_toupper ---
	// For these, we compare the final characters directly.
	printf("--- Testing ft_toupper ---\n");
	print_result(1, toupper('a') == ft_toupper('a'), 1, "Input: lowercase 'a'. Expected output: 'A'");
	print_result(2, toupper('z') == ft_toupper('z'), 1, "Input: lowercase 'z'. Expected output: 'Z'");
	print_result(3, toupper('A') == ft_toupper('A'), 1, "Input: uppercase 'A'. Expected output: 'A'");
	print_result(4, toupper('5') == ft_toupper('5'), 1, "Input: non-alphabetic char '5'. Expected output: '5'");
	printf("\n");

	// --- 7. ft_tolower ---
	printf("--- Testing ft_tolower ---\n");
	print_result(1, tolower('B') == ft_tolower('B'), 1, "Input: uppercase 'B'. Expected output: 'b'");
	print_result(2, tolower('Z') == ft_tolower('Z'), 1, "Input: uppercase 'Z'. Expected output: 'z'");
	print_result(3, tolower('b') == ft_tolower('b'), 1, "Input: lowercase 'b'. Expected output: 'b'");
	print_result(4, tolower('*') == ft_tolower('*'), 1, "Input: non-alphabetic char '*'. Expected output: '*'");
	printf("\n");

	printf(YELLOW "--- CTYPE tests are complete. ---\n" RESET);
	print_flamingo_art();
	printf(YELLOW "\n--- Starting tests for STRING functions ---\n\n" RESET);

	// --- 8. ft_strlen ---
	printf("--- Testing ft_strlen ---\n");
	print_result(1, strlen("Hello") == ft_strlen("Hello"), 1, "Input: \"Hello\". Expected: 5");
	print_result(2, strlen("") == ft_strlen(""), 1, "Input: empty string \"\". Expected: 0");
	printf("\n");

	// --- 9. ft_memset & ft_bzero ---
	printf("--- Testing ft_memset & ft_bzero ---\n");
	char buffer_orig[20];
	char buffer_ft[20];
	memset(buffer_orig, 'A', 10);
	ft_memset(buffer_ft, 'A', 10);
	print_result(1, memcmp(buffer_orig, buffer_ft, 10) == 0, 1, "ft_memset: Fill 10 chars with 'A'");
	bzero(buffer_orig, 5);
	ft_bzero(buffer_ft, 5);
	print_result(2, memcmp(buffer_orig, buffer_ft, 10) == 0, 1, "ft_bzero: Zero out the first 5 chars");
	printf("\n");

	// --- 10. ft_memcpy & ft_memmove ---
	printf("--- Testing ft_memcpy & ft_memmove ---\n");
	char src[] = "SourceString";
	memcpy(buffer_orig, src, strlen(src) + 1);
	ft_memcpy(buffer_ft, src, strlen(src) + 1);
	print_result(1, memcmp(buffer_orig, buffer_ft, strlen(src) + 1) == 0, 1, "ft_memcpy: Basic copy");
	// Test for memmove (overlapping memory)
	char move_orig[] = "123456789";
	char move_ft[] = "123456789";
	memmove(move_orig + 2, move_orig, 5); // "121234589"
	ft_memmove(move_ft + 2, move_ft, 5);
	print_result(2, strcmp(move_orig, move_ft) == 0, 1, "ft_memmove: Overlapping memory (dst > src)");
	char move_orig2[] = "123456789";
	char move_ft2[] = "123456789";
	memmove(move_orig2, move_orig2 + 2, 5); // "345676789"
	ft_memmove(move_ft2, move_ft2 + 2, 5);
	print_result(3, strcmp(move_orig2, move_ft2) == 0, 1, "ft_memmove: Overlapping memory (src > dst)");
	printf("\n");

// --- 11. ft_strlcpy & ft_strlcat ---
	printf("--- Testing ft_strlcpy & ft_strlcat ---\n");
	char cpy_dest_ft[20];
	size_t res_ft;
	// Test 1: Full copy
	bzero(cpy_dest_ft, 20); // Reset buffer
	res_ft = ft_strlcpy(cpy_dest_ft, "Hello", 20);
	print_result(1, res_ft == 5 && strcmp(cpy_dest_ft, "Hello") == 0, 1, "ft_strlcpy: Full copy. Expected ret 5, dest \"Hello\"");
	// Test 2: Truncated copy
	bzero(cpy_dest_ft, 20); // Reset buffer
	res_ft = ft_strlcpy(cpy_dest_ft, "World", 4);
	print_result(2, res_ft == 5 && strcmp(cpy_dest_ft, "Wor") == 0, 1, "ft_strlcpy: Truncated to size 4. Expected ret 5, dest \"Wor\"");
	// Test 3: strlcat
	char cat_dest_ft[20] = "Start-";
	res_ft = ft_strlcat(cat_dest_ft, "End", 20);
	print_result(3, res_ft == 9 && strcmp(cat_dest_ft, "Start-End") == 0, 1, "ft_strlcat: Basic concatenation. Expected ret 9, dest \"Start-End\"");
	printf("\n");

	// --- 12. ft_strchr & ft_strrchr ---
	printf("--- Testing ft_strchr & ft_strrchr ---\n");
	const char *search_str = "find the needle here";
	print_result(1, strchr(search_str, 'n') == ft_strchr(search_str, 'n'), 1, "ft_strchr: Find first 'n'");
	print_result(2, strchr(search_str, 'z') == ft_strchr(search_str, 'z'), 1, "ft_strchr: Find non-existent 'z'");
	print_result(3, strrchr(search_str, 'e') == ft_strrchr(search_str, 'e'), 1, "ft_strrchr: Find last 'e'");
	print_result(4, strrchr(search_str, '\0') == ft_strrchr(search_str, '\0'), 1, "ft_strrchr: Find the null terminator");
	printf("\n");

	// --- 13. ft_strncmp & ft_memcmp ---
	printf("--- Testing ft_strncmp & ft_memcmp ---\n");
	const char *s1 = "TestA";
	const char *s2 = "TestB";
	const char *s3 = "TestA";
	print_result(1, (strncmp(s1, s2, 5) < 0) == (ft_strncmp(s1, s2, 5) < 0), 1, "ft_strncmp: s1 < s2");
	print_result(2, (strncmp(s1, s3, 5) == 0) == (ft_strncmp(s1, s3, 5) == 0), 1, "ft_strncmp: s1 == s3");
	print_result(3, (strncmp(s1, s2, 4) == 0) == (ft_strncmp(s1, s2, 4) == 0), 1, "ft_strncmp: s1 == s2 up to n=4");
	print_result(4, (memcmp(s1, s2, 5) < 0) == (ft_memcmp(s1, s2, 5) < 0), 1, "ft_memcmp: mem1 < mem2");
	printf("\n");

	// --- 14. ft_memchr ---
	printf("--- Testing ft_memchr ---\n");
	const char *mem_search = "abc\0def";
	print_result(1, memchr(mem_search, 'c', 5) == ft_memchr(mem_search, 'c', 5), 1, "ft_memchr: Find 'c' before null");
	print_result(2, memchr(mem_search, 'd', 3) == ft_memchr(mem_search, 'd', 3), 1, "ft_memchr: Fail to find 'd' within n=3");
	print_result(3, memchr(mem_search, '\0', 4) == ft_memchr(mem_search, '\0', 4), 1, "ft_memchr: Find the null terminator");
	printf("\n");

	// --- 15. ft_strnstr ---
	printf("--- Testing ft_strnstr ---\n");
	const char *haystack = "one two three";
	const char *needle = "two";
	print_result(1, ft_strnstr(haystack, needle, 10) == (haystack + 4), 1, "ft_strnstr: Find 'two' within len 10. Pointer should be haystack + 4");
	print_result(2, ft_strnstr(haystack, needle, 5) == NULL, 1, "ft_strnstr: Fail to find 'two' within len 5. Pointer should be NULL");
	print_result(3, ft_strnstr(haystack, "z", 10) == NULL, 1, "ft_strnstr: Find non-existent 'z'. Pointer should be NULL");
	print_result(4, ft_strnstr(haystack, "", 5) == haystack, 1, "ft_strnstr: Find empty needle. Pointer should be haystack");
	printf("\n");

	// --- 16. ft_strdup (stdlib) ---
	printf("--- Testing ft_strdup ---\n");
	char *dup_orig = strdup("Duplicate me!");
	char *dup_ft = ft_strdup("Duplicate me!");
	print_result(1, dup_orig != NULL && dup_ft != NULL && strcmp(dup_orig, dup_ft) == 0, 1, "ft_strdup: Basic duplication");
	free(dup_orig);
	free(dup_ft);
	dup_orig = strdup("");
	dup_ft = ft_strdup("");
	print_result(2, dup_orig != NULL && dup_ft != NULL && strcmp(dup_orig, dup_ft) == 0, 1, "ft_strdup: Duplicate empty string");
	free(dup_orig);
	free(dup_ft);
	printf("\n");

	// --- 17. ft_calloc (stdlib) ---
	printf("--- Testing ft_calloc ---\n");
	size_t count = 10;
	size_t size = sizeof(int);
	int *arr_ft = ft_calloc(count, size);
	int *arr_check = calloc(count, size); // create a clean array to compare
	print_result(1, arr_ft != NULL, 1, "ft_calloc: Allocation is not NULL");
	print_result(2, memcmp(arr_ft, arr_check, count * size) == 0, 1, "ft_calloc: Memory is zeroed out");
	free(arr_ft);
	free(arr_check);
	printf("\n");
	
		printf(YELLOW "--- STRING(S) tests are complete. ---\n" RESET);
	print_flamingo_art();
	printf(YELLOW "\n--- Starting tests for Atoi and Non-Standard functions ---\n\n" RESET);

	// --- 18. ft_atoi (stdlib) ---
	printf("--- Testing ft_atoi ---\n");
	print_result(1, atoi("42") == ft_atoi("42"), 1, "Input: \"42\" (Simple positive)");
	print_result(2, atoi("-42") == ft_atoi("-42"), 1, "Input: \"-42\" (Simple negative)");
	print_result(3, atoi("  \t\n+42") == ft_atoi("  \t\n+42"), 1, "Input: \"  \\t\\n+42\" (Leading whitespace and sign)");
	print_result(4, atoi("-42abc") == ft_atoi("-42abc"), 1, "Input: \"-42abc\" (Text after number)");
	print_result(5, atoi("abc42") == ft_atoi("abc42"), 1, "Input: \"abc42\" (Text before number)");
	print_result(6, atoi("2147483647") == ft_atoi("2147483647"), 1, "Input: INT_MAX");
	print_result(7, atoi("-2147483648") == ft_atoi("-2147483648"), 1, "Input: INT_MIN");
	printf("\n");

	// --- 19. ft_substr ---
	printf("--- Testing ft_substr ---\n");
	char *substr_res;
	substr_res = ft_substr("Hello World", 6, 5);
	print_result(1, strcmp(substr_res, "World") == 0, 1, "Input: (\"Hello World\", 6, 5). Expected: \"World\"");
	free(substr_res);
	substr_res = ft_substr("Test", 0, 10);
	print_result(2, strcmp(substr_res, "Test") == 0, 1, "Input: (\"Test\", 0, 10). Len is bigger than string");
	free(substr_res);
	substr_res = ft_substr("Test", 10, 5);
	print_result(3, strcmp(substr_res, "") == 0, 1, "Input: (\"Test\", 10, 5). Start is out of bounds");
	free(substr_res);
	printf("\n");

	// --- 20. ft_strjoin ---
	printf("--- Testing ft_strjoin ---\n");
	char *join_res;
	join_res = ft_strjoin("Hello, ", "World!");
	print_result(1, strcmp(join_res, "Hello, World!") == 0, 1, "Input: (\"Hello, \", \"World!\")");
	free(join_res);
	join_res = ft_strjoin("", "Second");
	print_result(2, strcmp(join_res, "Second") == 0, 1, "Input: (\"\", \"Second\")");
	free(join_res);
	join_res = ft_strjoin("First", "");
	print_result(3, strcmp(join_res, "First") == 0, 1, "Input: (\"First\", \"\")");
	free(join_res);
	printf("\n");

	// --- 21. ft_strtrim ---
	printf("--- Testing ft_strtrim ---\n");
	char *trim_res;
	trim_res = ft_strtrim("xxxyyyxxx", "x");
	print_result(1, strcmp(trim_res, "yyy") == 0, 1, "Input: (\"xxxyyyxxx\", \"x\"). Trim from both ends");
	free(trim_res);
	trim_res = ft_strtrim("   Hello ", " ");
	print_result(2, strcmp(trim_res, "Hello") == 0, 1, "Input: (\"   Hello \", \" \"). Trim spaces");
	free(trim_res);
	trim_res = ft_strtrim("NoTrim", "z");
	print_result(3, strcmp(trim_res, "NoTrim") == 0, 1, "Input: (\"NoTrim\", \"z\"). No chars to trim");
	free(trim_res);
	printf("\n");

	// --- 22. ft_split ---
	printf("--- Testing ft_split ---\n");
	char **split_res;
	split_res = ft_split("word1 word2 word3", ' ');
	print_result(1, strcmp(split_res[0], "word1") == 0 && strcmp(split_res[1], "word2") == 0 && strcmp(split_res[2], "word3") == 0 && split_res[3] == NULL, 1, "Input: \"word1 word2 word3\", ' '. Basic split");
	// A small helper to free the array is needed for clean code
	int i = 0; while(split_res[i]) free(split_res[i++]); free(split_res);
	split_res = ft_split("  leading spaces", ' ');
	print_result(2, strcmp(split_res[0], "leading") == 0 && strcmp(split_res[1], "spaces") == 0, 1, "Input with leading delimiters");
	i = 0; while(split_res[i]) free(split_res[i++]); free(split_res);
	split_res = ft_split("no-delimiter", 'z');
	print_result(3, strcmp(split_res[0], "no-delimiter") == 0 && split_res[1] == NULL, 1, "Input with no delimiters");
	i = 0; while(split_res[i]) free(split_res[i++]); free(split_res);
	printf("\n");

	// --- 23. ft_itoa ---
	printf("--- Testing ft_itoa ---\n");
	char *itoa_res;
	itoa_res = ft_itoa(12345);
	print_result(1, strcmp(itoa_res, "12345") == 0, 1, "Input: 12345");
	free(itoa_res);
	itoa_res = ft_itoa(-12345);
	print_result(2, strcmp(itoa_res, "-12345") == 0, 1, "Input: -12345");
	free(itoa_res);
	itoa_res = ft_itoa(0);
	print_result(3, strcmp(itoa_res, "0") == 0, 1, "Input: 0");
	free(itoa_res);
	itoa_res = ft_itoa(INT_MIN);
	print_result(4, strcmp(itoa_res, "-2147483648") == 0, 1, "Input: INT_MIN");
	free(itoa_res);
	printf("\n");

	// --- 24. ft_strmapi & ft_striteri ---
	printf("--- Testing ft_strmapi & ft_striteri ---\n");
	// A simple mapping function for the test
	char test_map_func(unsigned int i, char c) { (void)i; return (c + 1); }
	char *mapi_res = ft_strmapi("abc", test_map_func);
	print_result(1, strcmp(mapi_res, "bcd") == 0, 1, "ft_strmapi: increment each char");
	free(mapi_res);
	// A simple iteration function for the test
	void test_iter_func(unsigned int i, char *c) { (void)i; *c = *c + 1; }
	char striteri_str[] = "abc";
	ft_striteri(striteri_str, test_iter_func);
	print_result(2, strcmp(striteri_str, "bcd") == 0, 1, "ft_striteri: increment each char in place");
	printf("\n");
	
	// --- 25. FD functions ---
	printf("--- Testing FD functions ---\n");
	int fd;
	char read_buffer[100] = {0};
	// Test ft_putchar_fd
	fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putchar_fd('Z', fd);
		close(fd);
		fd = open("test_output.txt", O_RDONLY);
		read(fd, read_buffer, 100);
		close(fd);
		print_result(1, strcmp(read_buffer, "Z") == 0, 1, "ft_putchar_fd: write 'Z' to a file");
	}
	// Test ft_putstr_fd
	bzero(read_buffer, 100);
	fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putstr_fd("Success!", fd);
		close(fd);
		fd = open("test_output.txt", O_RDONLY);
		read(fd, read_buffer, 100);
		close(fd);
		print_result(2, strcmp(read_buffer, "Success!") == 0, 1, "ft_putstr_fd: write 'Success!' to a file");
	}
	// Test ft_putendl_fd
	bzero(read_buffer, 100);
	fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putendl_fd("Line", fd);
		close(fd);
		fd = open("test_output.txt", O_RDONLY);
		read(fd, read_buffer, 100);
		close(fd);
		print_result(3, strcmp(read_buffer, "Line\n") == 0, 1, "ft_putendl_fd: write 'Line\\n' to a file");
	}
	// Test ft_putnbr_fd
	bzero(read_buffer, 100);
	fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(-4242, fd);
		close(fd);
		fd = open("test_output.txt", O_RDONLY);
		read(fd, read_buffer, 100);
		close(fd);
		print_result(4, strcmp(read_buffer, "-4242") == 0, 1, "ft_putnbr_fd: write '-4242' to a file");
	}
	remove("test_output.txt"); // Clean up the test file
	printf("\n");
			printf(YELLOW "--- ft_atoi and non-standards tests are complete. ---\n" RESET);
		print_flamingo_art();
		
	
#ifdef TEST_BONUS_ON
	
	printf(YELLOW "\n--- Starting tests for BONUS List functions ---\n\n" RESET);

	// We need a dummy delete function for list tests
	void	del_content(void *content)
	{
		free(content);
	}

	// --- Bonus Setup ---
	t_list *head = NULL;
	t_list *node1;
	t_list *node2;
	t_list *last_node;

	printf("--- Testing ft_lstnew & ft_lstadd_front ---\n");
	// Test 1: ft_lstnew
	node1 = ft_lstnew(strdup("Node 1"));
	print_result(1, node1 != NULL && strcmp(node1->content, "Node 1") == 0 && node1->next == NULL, 1, "ft_lstnew: Create a single node");
	
	// Test 2: ft_lstadd_front
	ft_lstadd_front(&head, node1);
	print_result(2, head == node1, 1, "ft_lstadd_front: Add first node to list");
	node2 = ft_lstnew(strdup("Node 2"));
	ft_lstadd_front(&head, node2);
	print_result(3, head == node2 && head->next == node1, 1, "ft_lstadd_front: Add a second node to the front");
	printf("\n");

	// --- Testing ft_lstsize ---
	printf("--- Testing ft_lstsize ---\n");
	print_result(1, ft_lstsize(head) == 2, 1, "ft_lstsize: List with 2 nodes. Expected size: 2");
	print_result(2, ft_lstsize(NULL) == 0, 1, "ft_lstsize: NULL list. Expected size: 0");
	printf("\n");

	// --- Testing ft_lstlast & ft_lstadd_back ---
	printf("--- Testing ft_lstlast & ft_lstadd_back ---\n");
	last_node = ft_lstlast(head);
	print_result(1, last_node == node1, 1, "ft_lstlast: Find the last node (Node 1)");
	t_list *node0 = ft_lstnew(strdup("Node 0"));
	ft_lstadd_back(&head, node0);
	last_node = ft_lstlast(head);
	print_result(2, last_node == node0 && ft_lstsize(head) == 3, 1, "ft_lstadd_back: Add Node 0 to the end. It should now be the last");
	printf("\n");

	// --- Testing ft_lstiter ---
	printf("--- Testing ft_lstiter ---\n");
	// A simple iteration function for the test
	void iter_func(void *content)
	{
		char *str = (char *)content;
		while(*str)
		{
			*str = ft_toupper(*str);
			str++;
		}
	}
	ft_lstiter(head, iter_func);
	print_result(1, strcmp(head->content, "NODE 2") == 0 && strcmp(head->next->content, "NODE 1") == 0 && strcmp(head->next->next->content, "NODE 0") == 0, 1, "ft_lstiter: Convert all node content to uppercase");
	printf("\n");
	
	// --- Testing ft_lstmap ---
	printf("--- Testing ft_lstmap ---\n");
	// A simple mapping function for the test
	void *map_func(void *content)
	{
		char *new_str = ft_strjoin((char *)content, " MAPPED");
		return (new_str);
	}
	t_list *mapped_list = ft_lstmap(head, map_func, del_content);
	print_result(1, ft_lstsize(mapped_list) == 3, 1, "ft_lstmap: New list should have the same size (3)");
	print_result(2, mapped_list != NULL && strcmp(mapped_list->content, "NODE 2 MAPPED") == 0, 1, "ft_lstmap: Check content of first mapped node");
	print_result(3, mapped_list->next != NULL && strcmp(mapped_list->next->content, "NODE 1 MAPPED") == 0, 1, "ft_lstmap: Check content of second mapped node");
	printf("\n");

	// --- Testing ft_lstdelone & ft_lstclear ---
	printf("--- Testing ft_lstdelone & ft_lstclear ---\n");
	t_list *node_to_del = ft_lstnew(strdup("Delete me"));
	ft_lstdelone(node_to_del, del_content);
	print_result(1, 1, 1, "ft_lstdelone: Called on a single node (check for crash with valgrind)");
	// Now, we clear both lists to free all memory
	ft_lstclear(&head, del_content);
	ft_lstclear(&mapped_list, del_content);
	print_result(2, head == NULL && mapped_list == NULL, 1, "ft_lstclear: Both lists should be NULL after clearing");
	printf("\n");

#endif

	printf(YELLOW "--- Tests are now over. The flamingo is proud of you!---\n");
	printf("\n");
	return (0);
}
