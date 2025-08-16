# === CONFIG ===

NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g  -fsanitize=address
RM          := rm -f
MKDIR_P     := mkdir -p

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a
INCLUDES    := -Iincludes -I$(LIBFT_DIR)/includes

SRC_DIR     := srcs
OBJ_DIR     := obj

SRC         := $(wildcard $(SRC_DIR)/*.c)
OBJ         := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# === COLORS / ICONS ===

BOLD        := \033[1m
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
CYAN        := \033[0;36m
RESET       := \033[0m

# === BUILD RULES ===

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(CYAN)[📦] Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@echo "$(CYAN)[🔧] Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBFT) -o $@
	@echo "$(GREEN)[✅] Executable built: $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR_P) $(dir $@)
	@echo "$(YELLOW)[⚙️ ] Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# === CLEANUP ===

clean:
	@echo "$(CYAN)[🧹] Removing push_swap object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)[🗑] Removing $(NAME) and cleaning libft...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
