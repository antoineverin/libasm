NAME		:= libasm.a
SC			:= nasm
SFLAGS		:= -f elf64

OBJS_DIR	:= objs

SRCS		:= \
	ft_read.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_strlen.s \
	ft_write.s
OBJS		:= $(patsubst %.s, $(OBJS_DIR)/%.o, $(SRCS))

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.s | $(OBJS_DIR)
	$(SC) $(SFLAGS) -o $@ $<

test: $(NAME) test.c
	cc test.c $(NAME) -o test

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean $(NAME)
