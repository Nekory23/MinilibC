/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** test rindex
*/

#include "tests.h"

char *(*my_rindex)(const char *, int);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_rindex = dlsym(handle, "rindex");
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