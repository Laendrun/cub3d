# COLOURS

_END		=	\e[0m
_BOLD		=	\e[1m
_DIM		=	\e[2m
_UNDER		=	\e[4m
_REV		=	\e[7m

_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m

_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m

_MOFF		=	\e[?25l
_MON		=	\e[?25h
_MUP		=	\e[1A
_ERASE		=	\e[K

NAME=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -w

all: $(NAME)

$(NAME):	$(OBJ)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) *~

fclean: clean
	@rm -f $(NAME)
	@rm -f mlx_app

re: clean all

.SILENT: $(OBJ1) $(OBJ) $(NAME)