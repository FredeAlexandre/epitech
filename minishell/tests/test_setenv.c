#include <criterion/criterion.h>

#include <stdio.h>
#include "../includes/global.h"

Test(setenv, already_exist_no_owrite)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    my_initenv(env);
    my_setenv("PATH", "/src", 0);
    cr_assert_str_eq(my_getenv("PATH"), "/bin:/src");
    my_clearenv();
}

Test(setenv, already_exist_overwrite)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    my_initenv(env);
    my_setenv("PATH", "/src", 1);
    cr_assert_str_eq(my_getenv("PATH"), "/src");
    my_clearenv();
}

Test(setenv, no_exist)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    my_initenv(env);
    my_setenv("HELLO", "WORLD", 0);
    cr_assert_str_eq(my_getenv("HELLO"), "WORLD");
    cr_assert_eq(my_lengthenv(my_environ()), 3);
    my_clearenv();
}
