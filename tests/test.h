#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define BUFF_SIZE 100
#define RED "\033[31m"
#define GREEN "\033[32m"
#define GRAY "\033[90m"
#define RESET "\033[0m"

extern ssize_t ft_read(int fd, void *buf, size_t count);
extern int ft_strcmp(const char *s1, const char *s2);
extern char *ft_strcpy(char *dst, const char *src);
extern char *ft_strdup(const char *src);
extern size_t ft_strlen(const char *s);
extern ssize_t ft_write(int fd, const void *buf, size_t count);

void do_read(char *name, int ifd, int ofd, char *str, size_t count);
void do_strcmp(char *name, char *str1, char *str2);
void do_strcpy(char *name, char *source);
void do_strdup(char *name, char *source);
void do_strlen(char *name, char *source);
void do_write(char *name, int fd, char *str, size_t count, int ofd);

#ifdef BONUS

typedef struct s_list {
	void			*data;
	struct s_list	*next;
}	t_list;

extern size_t ft_list_size(t_list *lst);

void do_list_size(char *name, int *data, size_t expect);

#endif
