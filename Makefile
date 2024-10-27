NAME		:= libasm.a
NAME_BONUS	:= libasm_bonus.a
TEST		:= test
TEST_BONUS	:= test_bonus
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
SRCS_BONUS	:=
OBJS		:= $(patsubst %.s, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_BONUS	:= $(patsubst %.s, $(OBJS_DIR)/%.o, $(SRCS_BONUS))
TESTS_SRCS	:= $(addprefix $(TESTS_DIR)/, \
		test.c \
		test_utils.c \
	)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME_BONUS) $(OBJS) $(OBJS_BONUS)

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.s | $(OBJS_DIR)
	$(ASMC) $(ASMFLAGS) -o $@ $<

$(TEST): $(NAME) $(TESTS_SRCS)
	cc $(TESTS_SRCS) $(NAME) -I $(TESTS_DIR) -o $(TEST)

$(TEST_BONUS): bonus $(TESTS_SRCS)
	cc -D BONUS -I $(TESTS_DIR) $(TESTS_SRCS) $(NAME_BONUS) -o $(TEST_BONUS)

run_test: $(TEST)
	./$(TEST)

run_test_bonus: $(TEST_BONUS)
	./$(TEST_BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(TEST_NAME) $(NAME_BONUS) $(TEST_BONUS)

re: fclean $(NAME)
