#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -w

all: $(NOM)

$(NOM): $(OBJ)
	ar -c -r $(NOM) $(OBJ)
	ranlib $(NOM)
	@printf "%-30b%b" "\033[2K\r\033[32m  minilibx" "\033[1m[OK]\033[0m\n"

$(OBJ):	Makefile mlx.h mlx_png.h mlx_opengl.h mlx_new_window.h mlx_int.h

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@printf "\033[2K\r\033[31mminilibx: All objects files have been deleted. $(_END)\n"

re: clean all