#include <criterion/criterion.h>

#include "../includes/global.h"

Test(initenv, start_the_environ)
{
    char *env[] = {"PWD=/", "PATH=/bin:/src", NULL};
    char **new_env = my_initenv(env);
    for (size_t i = 0; new_env[i] != NULL; i++) {
        cr_assert_str_eq(env[i], new_env[i]);
    }
    my_clearenv();
}
