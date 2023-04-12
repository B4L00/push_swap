CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror

NAME			:= libft.a

PRINTF_D		:= srcs/ft_printf/

SRCS_D_LIBFT	:= srcs/

SRCS_F_LIBFT	:= ft_atoi\
					ft_bzero\
					ft_calloc\
					ft_isalnum\
					ft_isalpha\
					ft_isascii\
					ft_isdigit\
					ft_isprint\
					ft_itoa\
					ft_memchr\
					ft_memcmp\
					ft_memcpy\
					ft_memmove\
					ft_memset\
					ft_putchar_fd\
					ft_putendl_fd\
					ft_putnbr_fd\
					ft_putstr_fd\
					ft_split\
					ft_strchr\
					ft_strdup\
					ft_striteri\
					ft_strjoin\
					ft_strlcat\
					ft_strlcpy\
					ft_strlen\
					ft_strmapi\
					ft_strncmp\
					ft_strnstr\
					ft_strrchr\
					ft_strtrim\
					ft_substr\
					ft_tolower\
					ft_toupper\
					ft_lstnew\
					ft_lstadd_front\
					ft_lstsize\
					ft_lstlast\
					ft_lstadd_back\
					ft_lstdelone\
					ft_lstclear\
					ft_lstiter\
					ft_lstmap

SRCS		:= $(addprefix $(SRCS_D_LIBFT), $(addsuffix .c, $(SRCS_F_LIBFT)))
OBJ			:= $(addprefix $(SRCS_D_LIBFT), $(addsuffix .o, $(SRCS_F_LIBFT)))

all: 	$(NAME)
	
$(NAME): $(OBJ)
		make -C $(PRINTF_D)
		cp $(PRINTF_D)/libftprintf.a .
		mv libftprintf.a $(NAME)
		ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_D)

re: fclean all

.PHONY: all clean fclean re