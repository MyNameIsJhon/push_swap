NAME        := libft.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar rcs
RM          := rm -f
MKDIR_P     := mkdir -p
INCLUDES    := -Iincludes
OBJ_DIR     := obj

BOLD        := \033[1m
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
CYAN        := \033[0;36m
RESET       := \033[0m

LIBFT_DIR   := libft
PRINTF_DIR  := ft_printf
FILEFT_DIR  := fileft
ARENA_DIR   := arena_allocator
VECTOR_DIR  := vector

LIBFT_SRC := \
	ft_abs.c ft_abs_f.c ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c \
	ft_count_char.c ft_free.c ft_hexlen.c ft_hexlen_l.c ft_inrange.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isincharset.c \
	ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c \
	ft_lstnew.c ft_lstnew_chr.c ft_lstnew_i.c ft_lstnew_long.c ft_lstsize.c \
	ft_malloc.c ft_max.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_nbrlen.c ft_nbrlen_u.c ft_putchar.c ft_puterror.c \
	ft_putnbr.c ft_putnbr_hex.c ft_putnbr_hex_ulong.c ft_putnbr_unsigned.c \
	ft_putstr.c ft_realloc.c ft_revstr.c ft_sgn.c ft_sgn_f.c ft_sign_f.c \
	ft_sizeof.c ft_split.c ft_split_charset.c ft_strappend.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strisdigit.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strsfree.c ft_strslen.c ft_strtrim.c ft_substr.c \
	ft_swap.c ft_swap_p.c quick_sort.c binary_search.c count_params.c \
	freestrs.c

PRINTF_SRC := \
	ft_printf.c handler_base10.c handler_chr.c handler_lower_hex.c \
	handler_percent.c handler_pointer.c handler_string.c handler_unsigned.c \
	handler_upper_hex.c p_builtins.c

FILEFT_SRC := \
	ft_countline_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c get_file.c get_next_line.c

ARENA_SRC := \
	arena_allocator.c

VECTOR_SRC := \
	vector.c

LIBFT_SRC   := $(addprefix $(LIBFT_DIR)/,   $(LIBFT_SRC))
PRINTF_SRC  := $(addprefix $(PRINTF_DIR)/,  $(PRINTF_SRC))
FILEFT_SRC  := $(addprefix $(FILEFT_DIR)/,  $(FILEFT_SRC))
ARENA_SRC   := $(addprefix $(ARENA_DIR)/,   $(ARENA_SRC))
VECTOR_SRC  := $(addprefix $(VECTOR_DIR)/,  $(VECTOR_SRC))

SRC := $(LIBFT_SRC) $(PRINTF_SRC) $(FILEFT_SRC) $(ARENA_SRC) $(VECTOR_SRC)

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CYAN)[🔧] Archiving into $(NAME)...$(RESET)"
	@$(AR) $@ $^
	@echo "$(GREEN)[✅] Build complete.$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR_P) $(dir $@)
	@echo "$(YELLOW)[⚙️] Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(CYAN)[🧹] Removing object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)[💥] Removing binary: $(NAME)$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
