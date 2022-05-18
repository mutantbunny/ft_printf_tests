CC = gcc
REMOVE = rm -f
CFLAGS_TEST = -ggdb -Wall -Wextra -Werror \
         -I /home/coder/criterion-2.4.0/include \
         -L /home/coder/criterion-2.4.0/lib -lcriterion

SRC_FILES = ../ft_printf.c ../gen_parsers.c ../int_parsers.c ../utils.c utils_test.c int_parsers_test.c gen_parsers_test.c ft_printf_test.c test_utils.c
BONUS_SRC_FILES =
DEBUG_SRC_FILE = debug.c

OBJ_FILES = $(SRC_FILES:.c=.o)
BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)
DEBUG_OBJ_FILE = $(DEBUG_SRC_FILE:.c=.o)

HEADER_FILES = ../ft_printf.h test.h
BONUS_HEADER_FILES =
LIBFT_DIR = ../libft
NAME = ft_printf_test

all: $(NAME) run

$(NAME): $(OBJ_FILES) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS_TEST) -o $@ $(OBJ_FILES) $(LIBFT_DIR)/libft.a

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR) all

bonus: $(NAME:=_bonus)

$(NAME:=_bonus): $(BONUS_OBJ_FILES)
	$(CC) $(CFLAGS_TEST) -o $(NAME:=_bonus) $(BONUS_OBJ_FILES)

%_bonus.o: %_bonus.c $(BONUS_HEADER_FILES)
	$(CC) $(CFLAGS_TEST) -c $< -o $@

$(DEBUG_OBJ_FILE): $(DEBUG_SRC_FILE) $(HEADER_FILES)
	$(CC) $(CFLAGS_TEST) -c $< -o $@

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS_TEST) -c $< -o $@

clean:
	$(REMOVE) $(OBJ_FILES) $(BONUS_OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(REMOVE) $(NAME) $(NAME:=_bonus)
	make -C $(LIBFT_DIR) fclean

debug_bonus:  $(BONUS_OBJ_FILES) $(DEBUG_OBJ_FILE)
	$(CC) $(CFLAGS_TEST) -o $(NAME:=_debug)  $(BONUS_OBJ_FILES) $(DEBUG_OBJ_FILE)

debug: $(OBJ_FILES) $(DEBUG_OBJ_FILE)
	$(CC) $(CFLAGS_TEST) -o $(NAME:=_debug) $(OBJ_FILES) $(DEBUG_OBJ_FILE) $(LIBFT_DIR)/libft.a

valgrind: $(NAME)
	valgrind --leak-check=full --trace-children=yes ./$(NAME) --verbose

re:	fclean all

norm:
	norminette

run:
	./$(NAME) --verbose

.PHONY: all bonus clean debug debug_bonus fclean norm re run valgrind