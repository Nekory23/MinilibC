/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** test memset
*/

#include "tests.h"

void *(*my_memset)(void *, int, size_t);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_memset = dlsym(handle, "memset");
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