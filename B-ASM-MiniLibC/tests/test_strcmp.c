/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** test strcmp
*/

#include "tests.h"

int (*my_strcmp)(const char *, const char *);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strcmp = dlsym(handle, "strcmp");
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