/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

char* permissions(mode_t mode)
{
    static char perms[11];
    perms[0] = (S_ISDIR(mode)) ? 'd' : '-';
    perms[1] = (mode & S_IRUSR) ? 'r' : '-';
    perms[2] = (mode & S_IWUSR) ? 'w' : '-';
    perms[3] = (mode & S_IXUSR) ? 'x' : '-';
    perms[4] = (mode & S_IRGRP) ? 'r' : '-';
    perms[5] = (mode & S_IWGRP) ? 'w' : '-';
    perms[6] = (mode & S_IXGRP) ? 'x' : '-';
    perms[7] = (mode & S_IROTH) ? 'r' : '-';
    perms[8] = (mode & S_IWOTH) ? 'w' : '-';
    perms[9] = (mode & S_IXOTH) ? 'x' : '-';
    perms[10] = '\0';
    return perms;
}

char* timestamp(time_t t)
{
    static char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%b %d %H:%M", localtime(&t));
    return timestamp;
}

void show_files(client_t *client)
{
    DIR *dir = opendir(client->pwd);
    struct dirent *entry = NULL;
    struct stat file_stat;
    struct passwd* pw;
    struct group* gr;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0) continue;
        if (strcmp(entry->d_name, "..") == 0) continue;
        char buffer[2048];
        snprintf(buffer, 2048, "%s/%s", client->pwd, entry->d_name);
        lstat(buffer, &file_stat);
        pw = getpwuid(file_stat.st_uid);
        gr = getgrgid(file_stat.st_gid);
        snprintf(buffer, 2048, "%s %2ld %-8s %-8s %8ld %s %s",
permissions(file_stat.st_mode), file_stat.st_nlink, pw->pw_name,
gr->gr_name, file_stat.st_size, timestamp(file_stat.st_mtime), entry->d_name);
        send_command(client->data_socket, buffer, -1);
    }
}
