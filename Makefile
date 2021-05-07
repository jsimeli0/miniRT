NAME=minirt
REG_OBJ_FILES = main.o greeter.o
BONUS_OBJ_FILES = loud_greeter_bonus.o
HEADER_FILES = greeter.h
CFLAGS = -Wall -Wextra -Werror

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