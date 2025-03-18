#include <criterion/criterion.h>

#include <stdio.h>
#include "../includes/global.h"

Test(putenv, already_exist)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    my_initenv(env);
    my_putenv("PATH=/src");
    cr_assert_str_eq(my_getenv("PATH"), "/src");
    my_clearenv();
}

Test(putenv, no_exist)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    my_initenv(env);
    my_putenv("HELLO=WORLD");
    cr_assert_str_eq(my_getenv("HELLO"), "WORLD");
    cr_assert_eq(my_lengthenv(my_environ()), 3);
    my_clearenv();
}
