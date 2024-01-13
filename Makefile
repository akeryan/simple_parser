NAME = parser
FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

LINKS = -I$(INCLUDE) -I$(LIBFT_DIR) 
INCLUDE = include
SRC_DIR = src
LIBFT_DIR = libft
BUILD_DIR = build

SRC_FILES = Main.c Node.c Parser.c Charltr.c
HDR_FILES = Charltr.h Node.h Parser.h Scanner.h Token.h

all: $(NAME)

OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))

$(NAME): submodules_init_update libft_add $(OBJ_FILES) 
	$(CC) $(FLAGS) $(LINKS) -L$(LIBFT_DIR) -lft $(OBJ_FILES) -o $@  
	
%.o: $(SRC_DIR)/%.c 
	$(CC) $(FLAGS) $(LINKS) -c $< -o $@ 

libft_add:
	if [ ! -f $(LIBFT_DIR)/libft.a ]; then \
		make -C $(LIBFT_DIR); \
	fi

submodules_init_update:
	git submodule update --init

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_FILES)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
