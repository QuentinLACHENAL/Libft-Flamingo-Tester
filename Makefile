#                    __
#`       `          .^o ~\  `        `   `                `
#         ``  `    Y /'~) }      _____          `        `` `
#          `       l/  / /    ,-~     ~~--.,_    `         `    ``
#     `           `   ( (    /  ~-._         ^.
#     ``      `        \ "--'--.    "-._       \       `    `
#       `           `   "-.________     ~--.,__ ^.             `
#               `    `            \"~r-.,___.-'-. ^.
#      `    `                 `    YI    \\      ~-.\     `      `
#            `             `       ||     \\        `\
#        `                  `      ||     //
#  `           `                   ||    //
#   `           `          `       ()   //
#                `          `      ||  //     `   `
#           `                      || ( c      `
#            `        ___._ __  ___I|__`--__._ __  _
#                   "~     ~  "~  ""   ~~"    ~  ~~
#
#						LIBFT FLAMINGO TESTER - QLACHENA
#

# The name of your final executable
NAME = test_program

# Compiler and its flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

### IMPORTANT !!

# Set this to 1 or 0 to compile the bonus part of the tester or not
TEST_BONUS = 1

ifeq ($(TEST_BONUS), 1)
	CFLAGS += -DTEST_BONUS_ON
endif
### END !!


# Your libft archive
LIBFT = ./libft/libft.a

# The source file for your test
SRCS = main.c

# Object files derived from source files
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Rule to create the final executable
$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking object files to create $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) is ready to run!"

# Rule to create the libft.a archive by calling its own Makefile
$(LIBFT):
ifeq ($(TEST_BONUS), 1)
	@echo "Compiling Libft with bonus..."
	@make bonus -C ./libft
else
	@echo "Compiling Libft mandatory part..."
	@make -C ./libft
endif


# Rule to clean object files
clean:
	@make clean -C ./libft
	@rm -f $(OBJS)
	@echo "Object files cleaned."

# Rule to clean everything (objects + executable)
fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "Full clean done."

# Rule to recompile everything
re: fclean all

# Phony targets to prevent conflicts with files of the same name
.PHONY: all clean fclean re
