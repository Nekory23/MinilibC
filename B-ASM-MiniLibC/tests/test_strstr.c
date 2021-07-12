/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** test strstr
*/

#include "tests.h"

char *(*my_strstr)(const char *, const char *);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strstr = dlsym(handle, "strstr");
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

Test(strstr, null_haystack, .init=init)
{
    char *haystack = "";
    char *needle = "hello";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, null_needle, .init=init)
{
    char *haystack = "this is a super long sentence";
    char *needle = "";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}

Test(strstr, null_haystack_and_needle, .init=init)
{
    char *haystack = "";
    char *needle = "";

    cr_assert(my_strstr(haystack, needle) == strstr(haystack, needle));
}