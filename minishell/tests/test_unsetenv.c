#include <criterion/criterion.h>

#include <stdio.h>
#include "../includes/global.h"

Test(unsetenv, exist)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    my_initenv(env);
    my_unsetenv("PATH");
    cr_assert_str_eq(my_getenv("PWD"), "/");
    cr_assert_eq(my_getenv("PATH"), NULL);
    cr_assert_eq(my_lengthenv(my_environ()), 1);
    my_clearenv();
}

Test(unsetenv, do_not_exist)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    my_initenv(env);
    my_unsetenv("HELLO");
    cr_assert_str_eq(my_getenv("PWD"), "/");
    cr_assert_str_eq(my_getenv("PATH"), "/bin:/src");
    cr_assert_eq(my_lengthenv(my_environ()), 2);
    my_clearenv();
}
