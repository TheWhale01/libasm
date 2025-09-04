ASM=nasm
LD=ld

NAME=libasm
OBJ_DIR=obj/
SRC_DIR=src/

SRCS= $(addprefix $(SRC_DIR), main.s ft_strlen.s ft_write.s ft_strcpy.s ft_strcmp.s)
OBJS= $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(SRCS))

ASMFLAGS=-f elf64 -g
LDFLAGS=

$(OBJ_DIR)%.o: $(SRC_DIR)%.s
	@mkdir -p $(dir $@)
	$(ASM) $(ASMFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
