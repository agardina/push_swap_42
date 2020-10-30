#FORMATTING

GREEN = "\\033[32m"
BOLD = "\\033[1m"
RESET_FORMAT = "\\033[0m"
ERASE_LINE = "\\033[A\\033[K\\033[A"

#COMPILATION

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CHECKER_NAME = checker
PUSH_SWAP_NAME = push_swap

LIB_DIR = ./libft/
LIB_INC = $(LIB_DIR)inc
LIB_NAME = libft.a
LIB_FLAGS = -L $(LIB_DIR) -lft
LIB = $(addprefix $(LIB_DIR), $(LIB_NAME))

SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRC_FILES = apply_instr.c check_args.c check_args2.c check_instr.c check_order.c \
				chunk_sort.c chunk_sort2.c ft_p.c ft_r.c ft_rr.c ft_s.c \
				main_checker.c main_push_swap.c replace_values_by_rank.c selection_sort.c \
				sort_last_three.c utils.c utils2.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

CHECKER_OBJ_FILES = apply_instr.o \
						check_args.o \
						check_args2.o \
						check_instr.o \
						check_order.o \
						ft_p.o \
						ft_r.o \
						ft_rr.o \
						ft_s.o \
						main_checker.o \
						utils.o \
						utils2.o

CHECKER_OBJ = $(addprefix $(OBJ_DIR), $(CHECKER_OBJ_FILES))
PUSH_SWAP_OBJ_FILES = apply_instr.o \
						check_args.o \
						check_args2.o \
						check_order.o \
						chunk_sort.o \
						chunk_sort2.o \
						ft_p.o \
						ft_r.o \
						ft_rr.o \
						ft_s.o \
						main_push_swap.o \
						replace_values_by_rank.o \
						selection_sort.o \
						sort_last_three.o \
						utils.o \
						utils2.o
PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_OBJ_FILES))

HDR_DIR = ./inc/
HDR_FILES = prototypes.h structs.h
HDR = $(addprefix $(HDR_DIR), $(HDR_FILES))

all: $(OBJ_DIR) $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJ) $(LIB)
	@echo "Object files related to checker created"
	@$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIB_FLAGS) -o $(CHECKER_NAME)
	@echo "$(BOLD)$(CHECKER_NAME)$(RESET_FORMAT) [$(GREEN)OK$(RESET_FORMAT)]"

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ) $(LIB)
	@echo "Object files related to push_swap created"
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIB_FLAGS) -o $(PUSH_SWAP_NAME)
	@echo "$(BOLD)$(PUSH_SWAP_NAME)$(RESET_FORMAT) [$(GREEN)OK$(RESET_FORMAT)]"

$(LIB): FORCE
	@make -C $(LIB_DIR)

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR)
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -I$(LIB_INC) -c -o $@ $<
	@echo "Compiled: $*.o [$(GREEN)OK$(RESET_FORMAT)]"
	@echo "$(ERASE_LINE)"

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "Object files related to push_swap and checker deleted"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(CHECKER_NAME)
	@rm -rf $(PUSH_SWAP_NAME)
	@echo "$(PUSH_SWAP_NAME) deleted"
	@echo "$(CHECKER_NAME) deleted"

re:
	@$(MAKE) fclean
	@echo ""
	@$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE
