NAME = parser
FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

LINKS = -I$(INCLUDE) -I$(LIBFT_DIR) 
INCLUDE = include
SRC_DIR = src
LIBFT_DIR = libft
BUILD_DIR = build

SRC_FILES = Main.c Charltr.c Node.c Parser.c

all: $(NAME)

OBJ = $(patsubst %.c, %.o, $(SRC_FILES))

$(NAME): submodules_init_update libft_add $(OBJ) 
	$(CC) $(FLAGS) $(LINKS) -L$(LIBFT_DIR) -lft -o $@ $(OBJ) 
	
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
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
