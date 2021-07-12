/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** tests strchr
*/

#include "tests.h"

char *(*my_strchr)(const char *, int);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strchr = dlsym(handle, "strchr");
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

Test(strchr, null_char, .init=init)
{
    char *str = "abcdef\nhello";

    cr_assert(my_strchr(str, '\0') == strchr(str, '\0'));
}