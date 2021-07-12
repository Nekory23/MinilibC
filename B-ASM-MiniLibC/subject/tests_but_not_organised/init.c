/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** tests
*/

#include "tests.h"

void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else {
		my_strlen = dlsym(handle, "strlen");
		my_strcmp = dlsym(handle, "strcmp");
		my_strncmp = dlsym(handle, "strncmp");
		my_strcasecmp = dlsym(handle, "strcasecmp");
		my_strchr = dlsym(handle, "strchr");
		my_strcspn = dlsym(handle, "strcspn");
		my_rindex = dlsym(handle, "rindex");
		my_strstr = dlsym(handle, "strstr");
		my_strpbrk = dlsym(handle, "strpbrk");
		my_memset = dlsym(handle, "memset");
		my_memcpy = dlsym(handle, "memcpy");
	}
}

Test(strlen, simple, .init=init)
{
    char *str = "well hello there";

    cr_assert(my_strlen(str) == strlen(str));
}

Test(strlen, empty, .init=init)
{
    char *str = "";

    cr_assert(my_strlen(str) == strlen(str));
}

Test(strlen, special_characters, .init=init)
{
    char *str = "\t\n";

    cr_assert(my_strlen(str) == strlen(str));
}

Test(strlen, mix, .init=init)
{
    char *str = "hello\nthere\thi\n";

    cr_assert(my_strlen(str) == strlen(str));
}

Test(memcpy, simple, .init=init)
{
    char dest[500] = "dest";
    char src[500] = "i am src";

    cr_assert(my_memcpy(dest, src, strlen(src)) == memcpy(dest, src, strlen(src)));
}

Test(memset, fill_char, .init=init)
{
    char str[200];

    cr_assert(my_memset(str, '*', 50) == memset(str, '*', 50));
}

Test(memset, fill_zero_int, .init=init)
{
    int nbr[5];
    int to_fill = 0;

    cr_assert(my_memset(nbr, to_fill, 5 * sizeof(int)) == memset(nbr, to_fill, 5 * sizeof(int)));
}

Test(memset, fill_zeros_char, .init=init)
{
    char str[200];

    cr_assert(my_memset(str, 0, 50) == memset(str, 0, 50));
}

Test(memset, fill_int, .init=init)
{
    int nbr[5];
    int to_fill = 1;

    cr_assert(my_memset(nbr, to_fill, 5 * sizeof(int)) == memset(nbr, to_fill, 5 * sizeof(int)));
}

Test(rindex, first_char, .init=init)
{
    char *str = "abcd";
    char c = 'a';

    cr_assert(my_rindex(str, c) == rindex(str, c));
}

Test(rindex, last_char, .init=init)
{
    char *str = "abcd";
    char c = 'd';

    cr_assert(my_rindex(str, c) == rindex(str, c));
}

Test(rindex, in_the_middle, .init=init)
{
    char *str = "abcd";
    char c = 'b';

    cr_assert(my_rindex(str, c) == rindex(str, c));
}

Test(rindex, special_char, .init=init)
{
    char *str = "abcd\nlmao";
    char c = '\n';

    cr_assert(my_rindex(str, c) == rindex(str, c));
}

Test(rindex, not_in_str_char, .init=init)
{
    char *str = "abcd";
    char c = 'e';

    cr_assert(my_rindex(str, c) == rindex(str, c));
}

Test(rindex, not_a_char, .init=init)
{
    char *str = "abcd";
    int c = 600;

    cr_assert(my_rindex(str, c) == rindex(str, c));
}

Test(strcasecmp, equal_low, .init=init)
{
    char *s1 = "hey";
    char *s2 = "hey";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_up, .init=init)
{
    char *s1 = "HEY";
    char *s2 = "HEY";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_low_up, .init=init)
{
    char *s1 = "hey";
    char *s2 = "HEY";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_up_low, .init=init)
{
    char *s1 = "HEY";
    char *s2 = "hey";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_mixed, .init=init)
{
    char *s1 = "HeY";
    char *s2 = "hEy";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_non_alpha, .init=init)
{
    char *s1 = " \n  \t";
    char *s2 = " \n  \t";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_w_non_alpha, .init=init)
{
    char *s1 = "hello\n  \thow are you\n";
    char *s2 = "hEllO\n  \tHoW ARE you\n";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, greater, .init=init)
{
    char *s1 = "ab";
    char *s2 = "aa";

    cr_assert(my_strcasecmp(s1, s2) > 0);
}

Test(strcasecmp, lesser, .init=init)
{
    char *s1 = "aa";
    char *s2 = "ab";

    cr_assert(my_strcasecmp(s1, s2) < 0);
}

Test(strchr, not_found, .init=init)
{
    char *str = "abcdef";
    char c = 'z';

    cr_assert(my_strchr(str, c) == strchr(str, c));
}

Test(strchr, first_letter, .init=init)
{
    char *str = "abcdef";
    char c = 'a';

    cr_assert(my_strchr(str, c) == strchr(str, c));
}

Test(strchr, middle, .init=init)
{
    char *str = "abcdef";
    char c = 'c';

    cr_assert(my_strchr(str, c) == strchr(str, c));
}

Test(strchr, special_char, .init=init)
{
    char *str = "abcdef\nhello";
    char c = '\n';

    cr_assert(my_strchr(str, c) == strchr(str, c));
}

Test(strchr, special_char_bis, .init=init)
{
    char *str = "abcdef\thello";
    char c = '\t';

    cr_assert(my_strchr(str, c) == strchr(str, c));
}

Test(strchr, not_a_character, .init=init)
{
    char *str = "abcdef\nhello";
    int c = 600;

    cr_assert(my_strchr(str, c) == strchr(str, c));
}

Test(strcmp, equal, .init=init)
{
    char *s1 = "hey";
    char *s2 = "hey";

    cr_assert(my_strcmp(s1, s2) == 0);
}

Test(strcmp, equal_special, .init=init)
{
    char *s1 = "hey\n";
    char *s2 = "hey\n";

    cr_assert(my_strcmp(s1, s2) == 0);
}

Test(strcmp, lesser, .init=init)
{
    char *s1 = "a";
    char *s2 = "b";

    cr_assert(my_strcmp(s1, s2) < 0);
}

Test(strcmp, lesser_mul, .init=init)
{
    char *s1 = "aba";
    char *s2 = "abb";

    cr_assert(my_strcmp(s1, s2) < 0);
}

Test(strcmp, greater, .init=init)
{
    char *s1 = "c";
    char *s2 = "b";

    cr_assert(my_strcmp(s1, s2) > 0);
}

Test(strcmp, greater_mul, .init=init)
{
    char *s1 = "abc";
    char *s2 = "abb";

    cr_assert(my_strcmp(s1, s2) > 0);
}

Test(strcspn, first_char_unauthorised, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "w";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, last_char_unauthorised, .init=init)
{
    char *str = "well hello therez";
    char *not_ok = "z";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, nothing_unauthorised_in_str_one, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "z";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, nothing_unauthorised_in_str_mul, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "za\n";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, nothing_unauthorised, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, multiple_unauthorised, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "ol";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, special_char_unauthorised, .init=init)
{
    char *str = "well\nhello there";
    char *not_ok = "\n";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strncmp, equal, .init=init)
{
    char *s1 = "abc";
    char *s2 = "abcde";
    size_t nbr = 3;

    cr_assert(my_strncmp(s1, s2, nbr) == 0);
}

Test(strncmp, equal_special, .init=init)
{
    char *s1 = "ab\ncde";
    char *s2 = "ab\ndef";
    size_t nbr = 3;

    cr_assert(my_strncmp(s1, s2, nbr) == 0);
}

Test(strncmp, lesser, .init=init)
{
    char *s1 = "abac";
    char *s2 = "abbc";
    size_t nbr = 3;

    cr_assert(my_strncmp(s1, s2, nbr) < 0);
}

Test(strncmp, greater, .init=init)
{
    char *s1 = "abcc";
    char *s2 = "abbc";
    size_t nbr = 3;

    cr_assert(my_strncmp(s1, s2, nbr) > 0);
}

Test(strncmp, compare_nothing, .init=init)
{
    char *s1 = "hey";
    char *s2 = "hello";
    size_t nbr = 0;

    cr_assert(my_strncmp(s1, s2, nbr) == 0);
}

Test(strpbrk, one_char_start, .init=init)
{
    char *str = "abcdefghi";
    char *search = "a";

    cr_assert(my_strpbrk(str, search) == strpbrk(str, search));
}

Test(strpbrk, one_char_end, .init=init)
{
    char *str = "abcdefghi";
    char *search = "i";

    cr_assert(my_strpbrk(str, search) == strpbrk(str, search));
}

Test(strpbrk, one_char_middle, .init=init)
{
    char *str = "abcdefghi";
    char *search = "d";

    cr_assert(my_strpbrk(str, search) == strpbrk(str, search));
}

Test(strpbrk, one_char_not_in_str, .init=init)
{
    char *str = "abcdefghi";
    char *search = "z";

    cr_assert(my_strpbrk(str, search) == strpbrk(str, search));
}

Test(strpbrk, mul_char_start, .init=init)
{
    char *str = "abcdefghi";
    char *search = "uza";

    cr_assert(my_strpbrk(str, search) == strpbrk(str, search));
}

Test(strpbrk, mul_char_end, .init=init)
{
    char *str = "abcdefghi";
    char *search = "uzi";

    cr_assert(my_strpbrk(str, search) == strpbrk(str, search));
}

Test(strpbrk, mul_char_middle, .init=init)
{
    char *str = "abcdefghi";
    char *search = "uzd";

    cr_assert(my_strpbrk(str, search) == strpbrk(str, search));
}

Test(strpbrk, mul_char_not_in_str, .init=init)
{
    char *str = "abcdefghi";
    char *search = "uzo";

    cr_assert(my_strpbrk(str, search) == strpbrk(str, search));
}

Test(strstr, first_letter, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "t";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, first_word, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "this";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, last_letter, .init=init)
{
    char *haystack = "this is a super long sentencez";
    char *needle = "z";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, last_word, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "sentence";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, letter_in_middle, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "a";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, word_in_middle, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "super";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, word_not_in_sentence, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "not";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, letter_not_in_sentence, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "z";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, multiple_words_begin, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "this is a";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, multiple_words_middle, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "super long";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, multiple_words_end, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "long sentence";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, special_char, .init=init)
{
    char *haystack = "this is a super long sentence\nand hey";
    char *needle = "\n";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, mix_special_and_char, .init=init)
{
    char *haystack = "this is a super long sentence\nand hey";
    char *needle = "e\nand";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}