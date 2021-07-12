/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** test strpbrk
*/

#include "tests.h"

char *(*my_strpbrk)(const char *, const char *);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strpbrk = dlsym(handle, "strpbrk");
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