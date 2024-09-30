# Style
_END		:=	\033[0m
_BOLD		:=	\033[1m
_UNDER		:=	\033[4m
_REV		:=	\033[7m

# Colors
_GREY		:=	\033[30m
_RED		:=	\033[31m
_GREEN		:=	\033[32m
_YELLOW		:=	\033[33m
_BLUE		:=	\033[34m
_PURPLE		:=	\033[35m
_CYAN		:=	\033[36m
_WHITE		:=	\033[37m

CC := gcc

CFLAGS := -Wall -Wextra -Werror

PROJECT := so_long

HEADER_SRCS := includes/so_long.h libft/libft.h minilibx-linux/mlx_int.h minilibx-linux/mlx.h

SRCS :=		game.c \
			map/parse.c \
			map/check.c \
			init/init.c \
			init/check.c \
			print/print_textures.c \
			movement/move.c \
			movement/check_movement.c

OBJS := $(addprefix objs/, $(SRCS:.c=.o))

OBJS_DIRS := $(sort $(dir $(OBJS)))

INCLUDE := $(sort $(addprefix -I,$(dir $(HEADER_SRCS))))

NAME := $(PROJECT)

all: libft mlibx $(NAME)
	@printf "\033[2K\r$(_GREEN)$(_BOLD)Done.\n"

$(NAME): Makefile libft/libft.a minilibx-linux/libmlx.a $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) libft/libft.a minilibx-linux/libmlx.a -lX11 -lXext -lm -o $@
	@printf "%-30b%b" "\033[2K\r$(_GREEN)  $@" "$(_BOLD)[OK]$(_END)\n\n"

$(OBJS): | $(OBJS_DIRS)

$(OBJS_DIRS):
	@mkdir -p $@
	@printf "%-30b%b" "\033[2K\r$(_GREEN)  $(NAME)" "$(_CYAN)[$@ created]$(_END)\n"

objs/%.o: srcs/%.c libft/libft.a minilibx-linux/libmlx.a $(HEADER_SRCS)
	@printf "%-30b%b" "\033[2K\r$(_YELLOW)  $(NAME)" "\033[1m[$<]\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

libft:
	@printf "$(_CYAN)$(_BOLD)Compilation:$(_END)\n"
	@$(MAKE) -s -C libft

mlibx:
	@printf "%-30b%b" "\033[2K\r$(_YELLOW)  minilibx-linux" "\033[1m[compiling...]\033[0m"
	@$(MAKE) -s -C minilibx-linux

clean:
	@rm -rf $(OBJS)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C minilibx-linux
	@printf "\033[2K\r$(_RED)$(NAME): All objects files have been deleted. $(_END)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft
	@printf "\033[2K\r$(_RED)$(NAME): '"$(NAME)"' has been deleted. $(_END)\n\n"

ffclean:
	@rm -rf $(OBJS_DIRS)
	@$(RM) $(NAME)
	@$(MAKE) ffclean -C libft
	@$(MAKE) clean -C minilibx-linux
	@printf "\033[2K\r$(_RED)$(NAME): objs folder has been deleted. $(_END)\n"
	@printf "\033[2K\r$(_RED)$(NAME): '"$(NAME)"' has been deleted. $(_END)\n"

re: fclean all

norme:
	@norminette srcs includes libft

.PHONY: all libft mlibx clean fclean ffclean re norme