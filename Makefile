NAME		:= libasm.a
TEST_NAME	:= test
SC			:= nasm
SFLAGS		:= -f elf64

TESTS_DIR	:= tests
OBJS_DIR	:= objs

SRCS		:= \
	ft_read.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_strlen.s \
	ft_write.s
OBJS		:= $(patsubst %.s, $(OBJS_DIR)/%.o, $(SRCS))
TESTS_SRCS	:= $(addprefix $(TESTS_DIR)/, \
		test.c \
		test_utils.c \
	)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.s | $(OBJS_DIR)
	$(SC) $(SFLAGS) -o $@ $<

$(TEST_NAME): $(NAME) $(TESTS_SRCS)
	cc $(TESTS_SRCS) $(NAME) -I $(TESTS_DIR) -o $(TEST_NAME)

run_test: $(TEST_NAME)
	./$(TEST_NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(TEST_NAME)

re: fclean $(NAME)
