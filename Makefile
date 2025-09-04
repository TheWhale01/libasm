ASM=nasm
AR=ar rc
CC=clang

NAME=libasm
OBJ_DIR=obj/
SRC_DIR=src/
INCLUDES_DIR=includes/

ASM_SRCS= $(addprefix $(SRC_DIR), ft_strlen.s ft_write.s ft_strcpy.s ft_strcmp.s \
	ft_read.s ft_strdup.s)
ASM_OBJS= $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(ASM_SRCS))

C_SRCS= $(addprefix $(SRC_DIR), main.c tests/read.c tests/write.c tests/strcpy.c \
	tests/strcmp.c tests/strdup.c tests/strlen.c)
C_OBJS= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(C_SRCS))

ASMFLAGS=-f elf64
C_FLAGS=-Wall -Wextra -Werror -I $(INCLUDES_DIR) -g

$(OBJ_DIR)%.o: $(SRC_DIR)%.s
	@mkdir -p $(dir $@)
	$(ASM) $(ASMFLAGS) $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME).a: $(ASM_OBJS)
	$(AR) $(NAME).a $(ASM_OBJS)

all: $(NAME).a

clean:
	rm -rf $(OBJ_DIR)

exec: $(C_OBJS) all
	$(CC) $(C_FLAGS) $(C_OBJS) $(ASM_OBJS) $(NAME).a -o $(NAME)

re_exec: fclean exec

fclean: clean
	rm -rf $(NAME).a
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re exec re_exec
