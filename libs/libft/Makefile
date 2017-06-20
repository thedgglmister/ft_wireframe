NAME = libft.a

SRCS = ft_memccpy.c ft_strchr.c ft_strnequ.c ft_atoi.c ft_memchr.c ft_strclr.c ft_strnew.c ft_bzero.c ft_memcmp.c ft_strcmp.c ft_strnstr.c ft_isalnum.c ft_memcpy.c ft_strcpy.c ft_strrchr.c ft_isalpha.c ft_memdel.c ft_strdel.c ft_strstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strsub.c ft_isdigit.c ft_memset.c ft_strequ.c ft_tolower.c ft_isprint.c ft_putchar.c ft_striter.c ft_toupper.c ft_itoa.c ft_putchar_fd.c ft_striteri.c ft_lstadd.c ft_putendl.c ft_strlcat.c ft_lstdel.c ft_putendl_fd.c ft_strlen.c ft_lstdelone.c ft_putnbr.c ft_strmap.c ft_strjoin.c ft_lstiter.c ft_putnbr_fd.c ft_strmapi.c ft_strsplit.c ft_lstmap.c ft_putstr.c ft_strncat.c ft_strtrim.c ft_lstnew.c ft_putstr_fd.c ft_strncmp.c ft_memalloc.c ft_strcat.c ft_strncpy.c ft_list_find.c ft_str_resize.c ft_list_remove_if.c ft_strndup.c ft_atoi_base.c ft_gnl.c ft_arrlen2.c ft_arrlen3.c ft_arrdel2.c ft_arrdel3.c ft_open.c ft_close.c ft_read.c ft_error.c ft_crash.c ft_itoa_base.c ft_isupper.c ft_islower.c ft_power.c

OBJS = $(SRCS:.c=.o) 

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -I includes -c $(SRCS)
	@ar rc libft.a $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
