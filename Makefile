##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC 	=   utils/my_putchar.c \
		utils/handles_structs.c \
		src/precision/handles_precision.c \
		src/width/handles_num.c \
		utils/get_string_precission.c \
		src/conv/handles_a.c \
		src/conv/handles_A.c \
		src/conv/handles_b.c \
		src/conv/handles_d.c \
		src/conv/handles_c.c \
		src/conv/handles_e.c \
		src/conv/handles_E.c \
		src/conv/handles_f.c \
		src/conv/handles_F.c \
		src/conv/handles_g.c \
		src/conv/handles_G.c \
		src/conv/handles_i.c \
		src/conv/handles_n.c \
		src/conv/handles_o.c \
		src/conv/handles_p.c \
		src/conv/handles_s.c \
		src/conv/handles_S.c \
		utils/is_float.c \
		utils/get_nb_precision.c \
		utils/my_put_nbr.c \
		utils/my_putstr.c \
		utils/my_revstr.c \
		utils/my_strcat.c \
		utils/my_strcpy.c \
		utils/my_str_isalpha.c \
		utils/my_strlen.c \
		utils/my_strncat.c \
		utils/my_int_to_str.c \
		utils/my_long_to_str.c \
		utils/my_strdup.c \
		utils/my_uint_to_str.c \
		utils/my_ulong_long_to_str.c \
		utils/get_nb_width.c \
		utils/is_only_num.c \
		utils/is_num.c \
		my_printf.c \
		utils/include01.c\
		src/conv/handles_X.c \
		utils/cnt_printf.c \
		src/conv/handles_x.c \
		src/conv/handles_u.c


NAME	=	libmy.a

OBJ	=	 $(SRC:.c=.o)

CFLAGS = -I./utils -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
