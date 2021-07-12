/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** test strncmp
*/

#include "tests.h"

int (*my_strncmp)(const char *, const char *, size_t);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strncmp = dlsym(handle, "strncmp");
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