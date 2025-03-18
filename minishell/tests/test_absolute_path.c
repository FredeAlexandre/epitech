#include <criterion/criterion.h>

#include "../includes/global.h"

Test(absolute_path, leave)
{
    char *env[] = {"HOME=/home/alexandre", NULL};
    my_initenv(env);
    char *actual = "/home/alexandre/projects/minishell2";
    char query[] = "..";
    cr_assert_str_eq(absolute_path(actual, query), "/home/alexandre/projects");
    my_clearenv();
}

Test(absolute_path, enter)
{
    char *env[] = {"HOME=/home/alexandre", NULL};
    my_initenv(env);
    char *actual = "/home/alexandre/projects/minishell2";
    char query[] = "libs";
    cr_assert_str_eq(absolute_path(actual, query), "/home/alexandre/projects/minishell2/libs");
    my_clearenv();
}

Test(absolute_path, multiple)
{
    char *env[] = {"HOME=/home/alexandre", NULL};
    my_initenv(env);
    char *actual = "/home/alexandre/projects/minishell2";
    char query[] = "../..";
    cr_assert_str_eq(absolute_path(actual, query), "/home/alexandre");
    my_clearenv();
}

Test(absolute_path, multiple_max)
{
    char *env[] = {"HOME=/home/alexandre", NULL};
    my_initenv(env);
    char *actual = "/home/alexandre/projects/minishell2";
    char query[] = "../../../../../..";
    cr_assert_str_eq(absolute_path(actual, query), "/");
    my_clearenv();
}

Test(absolute_path, weird_query)
{
    char *env[] = {"HOME=/home/alexandre", NULL};
    my_initenv(env);
    char *actual = "/home/alexandre/projects/minishell2";
    char query[] = ".././libs/./enter/..";
    cr_assert_str_eq(absolute_path(actual, query), "/home/alexandre/projects/libs");
    my_clearenv();
}

Test(absolute_path, root)
{
    char *env[] = {"HOME=/home/alexandre", NULL};
    my_initenv(env);
    char *actual = "/home/alexandre/projects/minishell2";
    char query[] = "/home";
    cr_assert_str_eq(absolute_path(actual, query), "/home");
    my_clearenv();
}

Test(absolute_path, home)
{
    char *env[] = {"HOME=/home/alexandre", NULL};
    my_initenv(env);
    char *actual = "/home/alexandre/projects/minishell2";
    char query[] = "~/projects";
    cr_assert_str_eq(absolute_path(actual, query), "/home/alexandre/projects");
    my_clearenv();
}