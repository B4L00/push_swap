CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

NAME		:= libftprintf.a

SRCS_D		:= srcs/

LIBFT_D		:= ../

SRCS_F		:= ft_printf ft_printf_utils ft_putnbr_base ft_putnbr_ui ft_bin_comp2 ft_bin_to_hex ft_convert_base put_fd_printf

SRCS		:= $(addprefix $(SRCS_D), $(addsuffix .c, $(SRCS_F)))
OBJ			:= $(addprefix $(SRCS_D), $(addsuffix .o, $(SRCS_F)))

all: 		$(NAME)

$(NAME): 	$(OBJ)
				ar rcs $(NAME) $(OBJ)

clean:
				rm -f $(OBJ)

fclean:		 clean
				rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re bonus