NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g
RM          := rm -f
MKDIR_P     := mkdir -p

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a
INCLUDES    := -Iincludes -I$(LIBFT_DIR)/includes

SRC_DIR     := srcs
OBJ_DIR     := obj

BOLD        := \033[1m
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
CYAN        := \033[0;36m
RESET       := \033[0m

SRC_FILES := \
	algo.c \
	builtins.c \
	chunk_algo.c \
	chunk_builtins.c \
	error.c \
	instructs_all.c \
	instructs.c \
	push_swap.c \
	quick_sort.c \
	utils.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(CYAN)[📦] Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(CYAN)[🔧] Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $@
	@echo "$(GREEN)[✅] Executable built: $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR_P) $(dir $@)
	@echo "$(YELLOW)[⚙️ ] Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(CYAN)[🧹] Removing push_swap object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)[🗑] Removing $(NAME) and cleaning libft...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
