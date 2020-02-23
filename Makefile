NAME = printf.a

SRCS = function_dispatch_table.c \
		check_prepend.c \
		jump_table.c \
		parse.c \
		printf2.c

OBJS = function_dispatch_table.o \
		check_prepend.o \
		jump_table.o \
		parse.o \
		printf2.o

LIBFT=-L libft -l ft

FLAGS =-g -Wall -Werror -Wextra
INCLUDES=-I libft/incl/ -I incl/

all : $(NAME)

objcts/%.o: $(SRCS)
	gcc $(FLAGS) -C $(INCLUDES) $<o

$(NAME)	:	
	make -C libft
	ar -rc $(NAME) $(OBJECTS) libft/*.o

clean :
	rm -rf objects

fclean : clean
	rm -f $(NAME)

re: fclean all