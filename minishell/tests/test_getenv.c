#include <criterion/criterion.h>

#include "../includes/global.h"

Test(getenv, getenv_get_environ_va_extra)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    my_initenv(env);
    cr_assert_str_eq(my_getenv("PATH"), "/bin:/src");
    my_clearenv();
}

Test(getenv, getenv_get_environ_va_extra_no_exist)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    my_initenv(env);
    cr_assert_eq(my_getenv("NOT_FOUND"), NULL);
    my_clearenv();
}
