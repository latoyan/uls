#include "uls.h"

static char check_chmode1(char chmod) {
    if (chmod == '-')
        return chmod = 'S';
    else
        return chmod = 's';
}

static char check_chmode2(char *chmod) {
    if (chmod[9] == '-')
        return chmod[9] = 'T';
    else
        return chmod[9] = 't';
}

void mx_print_permission(t_li *print) {
    char chmod[12];

    chmod[0] = mx_check_per(print);
    chmod[1] = (S_IRUSR & print->info.st_mode) ? 'r' : '-';
    chmod[2] = (S_IWUSR & print->info.st_mode) ? 'w' : '-';
    chmod[3] = (S_IXUSR & print->info.st_mode) ? 'x' : '-';
    chmod[4] = (S_IRGRP & print->info.st_mode) ? 'r' : '-';
    chmod[5] = (S_IWGRP & print->info.st_mode) ? 'w' : '-';
    chmod[6] = (S_IXGRP & print->info.st_mode) ? 'x' : '-';
    chmod[7] = (S_IROTH & print->info.st_mode) ? 'r' : '-';
    chmod[8] = (S_IWOTH & print->info.st_mode) ? 'w' : '-';
    chmod[9] = (S_IXOTH & print->info.st_mode) ? 'x' : '-';
    chmod[10] = mx_get_file_acl(print);
    chmod[11] = '\0';
    S_ISUID & print->info.st_mode ? chmod[3] = check_chmode1(chmod[3]) : 0;
    S_ISGID & print->info.st_mode ? chmod[6] = check_chmode1(chmod[6]) : 0;
    S_ISVTX & print->info.st_mode ? chmod[9] = check_chmode2(chmod) : 0;
    for (int i = 0; chmod[i]; i++)
        mx_printchar(chmod[i]);
    mx_printchar(' ');
}
