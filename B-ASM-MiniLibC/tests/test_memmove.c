/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** tests memmove
*/

#include "tests.h"

void *(*my_memmove)(void *, void *, size_t);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_memmove = dlsym(handle, "memmove");
}

Test(memmove, basic, .init = init)
{
	char *test = strdup("test");
	char *test2 = strdup("test");
	char *copy = strdup("copy");
	char *copy2 = strdup("copy");

	cr_assert(!strcmp(memmove(test, copy, 4), my_memmove(test2, copy2, 4)));
}

Test(memmove, empty_string, .init = init)
{
	char *test = strdup("hello there u");
	char *test2 = strdup("");

	cr_assert(my_memmove(test, test2, 1) == test);
}

Test(memmove, empty_string2, .init = init)
{
	char *test = strdup("");
	char *test2 = strdup("hello there u");

	cr_assert(my_memmove(test, test2, 1) == test);
}

Test(memmove, full_null, .init = init)
{
	char *test = strdup("");
	char *test2 = strdup("");

	cr_assert(my_memmove(test, test2, 1) == test);
}