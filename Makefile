NAME			=	miniRT

SRC_DIR			=	src/
LIB_DIR			=	lib/libft/
GNL_DIR			=	gnl/get_next_line/

REG_OBJ_FILES 	=	main.o greeter.o
BONUS_OBJ_FILES =	loud_greeter_bonus.o
HEADER_FILES	=	greeter.h
CC				=	gcc
CFLAGS 			=	-Wall -Wextra -Werror

ifeq ($(OS), Linux)
	MINILIBX_DIR = lib/minilibx_mms
	OPENGL = -lm -lbsd -lX11 -lXext
endif
ifeq ($(OS), Darwin)
	MINILIBX_DIR = lib/minilibx_opengl
	OPENGL = -lz -framework OpenGL -framework AppKit
endif

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)
else
OBJ_FILES = $(REG_OBJ_FILES)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) -o $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re