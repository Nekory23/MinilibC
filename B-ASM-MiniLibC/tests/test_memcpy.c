/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** test memcpy
*/

#include "tests.h"

void *(*my_memcpy)(void *, void *, size_t);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_memcpy = dlsym(handle, "memcpy");
}

Test(memcpy, simple, .init=init)
{
    char *dest = strdup("dest");
    char *src = strdup("i am src");

    cr_assert(my_memcpy(dest, src, strlen(src)) == memcpy(dest, src, strlen(src)));
}

Test(memcpy, basic, .init=init)
{
	char *test = strdup("test");
	char *test2 = strdup("test");
	char *copy = strdup("copy");
	char *copy2 = strdup("copy");

	cr_assert(!strcmp(memcpy(test, copy, 4), my_memcpy(test2, copy2, 4)));
}

Test(memcpy, empty_string, .init=init)
{
	char *test = strdup("I'm a sandwich");
	char *test2 = strdup("");

	cr_assert(my_memcpy(test, test2, 10) == test);
}

Test(memcpy, empty_string2, .init=init)
{
	char *test = strdup("");
	char *test2 = strdup("I'm a sandwich");

	cr_assert(my_memcpy(test, test2, 10) == test);
}

Test(memcpy, full_null, .init=init)
{
	char *test = strdup("");
	char *test2 = strdup("");

	cr_assert(my_memcpy(test, test2, 1) == test);
}