/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** test strcspn
*/

#include "tests.h"

size_t (*my_strcspn)(const char *, const char *);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strcspn = dlsym(handle, "strcspn");
}

Test(strcspn, first_char_unauthorised, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "w";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, last_char_unauthorised, .init=init)
{
    char *str = "well hello therez";
    char *not_ok = "z";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, nothing_unauthorised_in_str_one, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "z";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, nothing_unauthorised_in_str_mul, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "za\n";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, nothing_unauthorised, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, multiple_unauthorised, .init=init)
{
    char *str = "well hello there";
    char *not_ok = "ol";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, special_char_unauthorised, .init=init)
{
    char *str = "well\nhello there";
    char *not_ok = "\n";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}

Test(strcspn, empty_str, .init=init)
{
    char *str = "";
    char *not_ok = "hey";

    cr_assert(my_strcspn(str, not_ok) == strcspn(str, not_ok));
}