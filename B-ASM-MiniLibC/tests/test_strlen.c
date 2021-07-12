/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** unit tests for strlen
*/

#include "tests.h"

size_t (*my_strlen)(const char *);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strlen = dlsym(handle, "strlen");
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