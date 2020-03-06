#ifndef ULS_HEADER_H
#define ULS_HEADER_H

#include "libmx.h"
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <dirent.h>
#include "string.h"

#define MX_IS_BLK(mode) (((mode) & S_IFMT) == S_IFBLK)
#define MX_IS_CHR(mode) (((mode) & S_IFMT) == S_IFCHR)
#define MX_IS_DIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#define MX_IS_LNK(mode) (((mode) & S_IFMT) == S_IFLNK)
#define MX_IS_SOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)
#define MX_IS_FIFO(mode) (((mode) & S_IFMT) == S_IFIFO)
#define MX_IS_WHT(mode) (((mode) & S_IFMT) == S_IFWHT)
#define MX_IS_REG(mode) (((mode) & S_IFMT) == S_IFREG)
#define MX_IS_EXEC(mode) ((mode) & S_IXUSR)

#define LS_COLOR_RED        "\x1b[31m"
#define LS_COLOR_RESET      "\x1b[0m"

typedef struct fl {
    int l;
    int C;
    int x;
    int R;
    int r;
    int t;
    int u;
    int c;
    int S;
    int a;
    int A;
    int force;
    int m;
    int files;
    int G;
    int T;
    int g;
    int o;
    int ex;
} st_fl;

typedef struct s_sz {
    int lnk;
    int sz;
    int group;
    int usr;
    bool is_dev;
} t_sz;

typedef struct s_li {
    char *name;
    char *path;
    char *err;
    struct stat info;
    struct s_li **open;
} t_li;

typedef struct n_type {
    int n_f;
    int n_d;
    int n_e;
    int i;
} s_type;

void mx_join(char **res, char *s2);
void mx_printstr_g(t_li *args);
int mx_max_len_names(t_li **names);
void mx_print_tab(int len, int maxlen);
void mx_del_arr_arr(t_li ***args);
void mx_printcharerr(char c);
void mx_nulloutput(st_fl **fl);
void mx_err_flag(st_fl **fl, char flag);
int mx_max_len_n_g(t_li **names);
void mx_print_spaces_g(int len, int maxlen);

t_li **mx_get_names(int argc, char **argv, int i);
void mx_opendir(t_li ***args, st_fl *fl);
void mx_out_put_all(t_li ***args, st_fl *fl);
void mx_sort(t_li ***disp, st_fl *fl);
t_li **mx_get_files(t_li ***args, st_fl *fl);
void mx_del_files(t_li ***args, st_fl *fl);
void mx_del_liarr(t_li ***args, t_li **dirs);


void mx_out_put_menu(t_li ***names, st_fl *fl, int flag);
void mx_out_err(t_li ***error, st_fl *fl);
void mx_output_x(t_li **names);
void mx_output_c(t_li **names);
void mx_output_m(t_li **names, st_fl *fl);
void mx_output_g(t_li **names, st_fl *fl);
void mx_long_out(t_li **names, st_fl *fl, int flag);

char *mx_get_minor(t_li *print);
char *mx_get_major(t_li *print);
bool mx_check_device(t_li **names, t_sz *size);
char mx_get_file_acl(t_li *print);

void mx_print_permission(t_li *print);
char mx_check_per(t_li *print);
void mx_get_user_name(t_li *print, int usr);
void mx_get_group_name(t_li *print, int group);
void mx_edit_time(t_li *print, char *t, st_fl *fl);
void mx_print_lnk(t_li *print, t_sz *size);
void mx_print_size(t_li *print, t_sz *size);
void mx_print_symblink(t_li *print);
void mx_print_total(t_li *total, int blk_size);
void mx_print_all(t_li *print, t_sz *size, st_fl *fl);

st_fl *mx_get_flags(char *argv[], int *i);
void mx_add_flags(st_fl **fl, char flag);
void mx_add_flags_output(st_fl **fl, char flag);
void mx_add_flags_sec(st_fl **fl, char flag);

void mx_create_fd_op(t_li ***dirs, t_li ***args);
t_li *mx_create_file_node(t_li *arg);

void mx_if_ex(st_fl *fl);
void mx_is_direct(t_li **args, s_type *num, t_li ***files, t_li ***dirs);
s_type *mx_create_num();
void mx_create_fd_er(t_li ***files, t_li ***dirs,
                        t_li ***errors, t_li ***args);
t_li *mx_create_file_node(t_li *arg);

t_li *mx_create_li_node(char *data);
t_li **mx_create_list(char **name, int count);
char **mx_names(int argc, char **argv, int i, int *count);

int mx_check_a(char *name, st_fl *fl);
int mx_count_read(t_li **arg, st_fl *fl);
t_li *mx_create_sec_node(char *name, char *path);
void mx_open_dir(t_li ***args, st_fl *fl);

void mx_outputerropen(t_li **args, st_fl *fl);
void mx_out_put1(t_li **names, st_fl *fl);

void mx_printcols(t_li **names, int rows, int num, int maxlen);
void mx_print_names(t_li **names, int maxlen, int wincol);

void mx_print_names2(t_li **names, int maxlen, int wincol, st_fl *fl);
void mx_printrow_g(t_li **names, int maxlen);
void mx_printcols_x(t_li **names, int rows, int cols, int maxlen);
void mx_printcols_c(t_li **names, int rows, int num, int maxlen);

void mx_print_names3(t_li **names, int wincol, st_fl *fl);
void mx_printn(int *len);

void mx_print_names4(t_li **names, int maxlen, int wincol);
void mx_printcols_xx(t_li **names, int rows, int cols, int maxlen);
char *mx_check_grp(t_li *total);
char *mx_check_pw(t_li *total);
void mx_count_size(t_sz *size, t_li *total);
void mx_size_null(t_sz *size);
void mx_long_out(t_li **names, st_fl *fl, int flag);


#endif
