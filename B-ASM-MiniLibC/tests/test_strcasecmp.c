/*
** EPITECH PROJECT, 2021
** minilibc
** File description:
** test strcasecmp
*/

#include "tests.h"

int (*my_strcasecmp)(const char *, const char *);

static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strcasecmp = dlsym(handle, "strcasecmp");
}

Test(strcasecmp, equal_low, .init=init)
{
    char *s1 = "hey";
    char *s2 = "hey";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_up, .init=init)
{
    char *s1 = "HEY";
    char *s2 = "HEY";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_low_up, .init=init)
{
    char *s1 = "hey";
    char *s2 = "HEY";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_up_low, .init=init)
{
    char *s1 = "HEY";
    char *s2 = "hey";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_mixed, .init=init)
{
    char *s1 = "HeY";
    char *s2 = "hEy";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_non_alpha, .init=init)
{
    char *s1 = " \n  \t";
    char *s2 = " \n  \t";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, equal_w_non_alpha, .init=init)
{
    char *s1 = "hello\n  \thow are you\n";
    char *s2 = "hEllO\n  \tHoW ARE you\n";

    cr_assert(my_strcasecmp(s1, s2) == 0);
}

Test(strcasecmp, greater, .init=init)
{
    char *s1 = "ab";
    char *s2 = "aa";

    cr_assert(my_strcasecmp(s1, s2) > 0);
}

Test(strcasecmp, lesser, .init=init)
{
    char *s1 = "aa";
    char *s2 = "ab";

    cr_assert(my_strcasecmp(s1, s2) < 0);
}