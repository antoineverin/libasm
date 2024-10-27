NAME		:= libasm.a
TEST		:= test
ASMC		:= nasm
ASMFLAGS	:= -f elf64

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
	$(ASMC) $(ASMFLAGS) -o $@ $<

$(TEST): $(NAME) $(TESTS_SRCS)
	cc $(TESTS_SRCS) $(NAME) -I $(TESTS_DIR) -o $(TEST)

run_test: $(TEST)
	./$(TEST)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(TEST_NAME)

re: fclean $(NAME)
