NAME = uls

CFLG = -std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP = clang

SRCD = src
INCD = inc
OBJD = obj

LMXD = libmx
LMXA := $(LMXD)/libmx.a
LMXI := $(LMXD)/inc

INC = uls.h
INCS = $(addprefix $(INCD)/, $(INC))

SRC = main.c mx_check_device.c mx_del_files.c mx_del_liarr.c \
			mx_edit_time.c mx_get_files.c mx_get_minor.c \
			mx_get_major.c mx_get_names.c mx_join.c mx_opendir.c \
			mx_output_c.c mx_output_g.c mx_output_m.c mx_out_put1.c \
			mx_output_x.c mx_print_all.c mx_get_user_name.c \
			mx_print_lnk.c mx_print_permission.c mx_print_size.c \
			mx_print_symblink.c mx_printcharerr.c mx_printstr_g.c \
			mx_sort.c mx_get_flags.c mx_add_flags.c mx_add_flags_output.c \
			mx_add_flags_sec.c mx_create_file_node.c mx_create_fd_op.c \
			mx_if_ex.c mx_is_direct.c mx_create_num.c mx_create_fd_er.c \
			mx_create_list.c mx_names.c mx_create_li_node.c mx_err_flag.c \
			mx_nulloutput.c mx_print_spaces_g.c mx_max_len_n_g.c \
			mx_open_dir.c mx_create_sec_node.c mx_count_read.c mx_check_a.c \
			mx_outputerropen.c mx_del_arr_arr.c mx_out_put_menu.c \
			mx_out_put_all.c mx_max_len_names.c mx_print_tab.c \
			mx_printcols.c mx_print_names.c mx_printcols_c.c \
			mx_printcols_x.c mx_printrow_g.c mx_print_names2.c \
			mx_print_names3.c mx_printn.c mx_print_names4.c \
			mx_printcols_xx.c mx_get_group_name.c mx_get_file_acl.c \
			mx_check_per.c mx_out_err.c mx_size_null.c mx_long_out.c \
			mx_count_size.c mx_check_pw.c mx_check_grp.c

SRCS = $(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install clean

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)

reinstall: uninstall install
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
