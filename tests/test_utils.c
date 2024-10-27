#include "test.h"

void do_read(char *name, int ifd, int ofd, char *str, size_t count) {
	write(ifd, str, count);
	errno = 0;
	char as[BUFF_SIZE] = {0};
	int a = read(ofd, as, count);
	int ar = errno;

	write(ifd, str, count);
	errno = 0;
	char bs[BUFF_SIZE] = {0};
	int b = ft_read(ofd, bs, count);
	int br = errno;

	printf("%s\t", name);
	printf(" return ");
	if (a != b) printf(RED "%d != %d" RESET, a, b);
	else printf(GREEN "OK" RESET);
	printf(" content ");
	if (ofd != -1 && strcmp(as, bs)) printf(RED "%s != %s" RESET, as, bs);
	else printf(GREEN "OK" RESET);
	printf(" errno ");
	if (ar != br) printf(RED "%d != %d" RESET, ar, br);
	else printf(GREEN "OK" RESET);
	printf("\n");
}

void do_strcmp(char *name, char *str1, char *str2) {
	int a = strcmp(str1, str2);
	int b = ft_strcmp(str1, str2);
	printf("%s\t", name);
	printf(" return ");
	if (a != b) printf(RED "%d != %d" RESET, a, b);
	else printf(GREEN "OK" RESET);
	printf("\n");
}

void do_strcpy(char *name, char *source) {
	char as[BUFF_SIZE] = {0};
	char *a = strcpy(as, source);
	char bs[BUFF_SIZE] = {0};
	char *b = ft_strcpy(bs, source);
	printf("%s\t", name);
	printf(" return ");
	if (strcmp(a, b)) printf(RED "%s != %s" RESET, a, b);
	else printf(GREEN "OK" RESET);
	printf(" buff ");
	if (strcmp(as, bs)) printf(RED "%s != %s" RESET, as, bs);
	else printf(GREEN "OK" RESET);
	printf(" source ");
	if (strcmp(bs, source)) printf(RED "%s != %s" RESET, bs, source);
	else printf(GREEN "OK" RESET);
	printf("\n");
}

void do_strdup(char *name, char *source) {
	char *a = strdup(source);
	char *b = ft_strdup(source);
	printf("%s\t", name);
	printf(" return ");
	if (strcmp(a, b)) printf(RED "%s != %s" RESET, a, b);
	else printf(GREEN "OK" RESET);
	printf(" source ");
	if (strcmp(b, source)) printf(RED "%s != %s" RESET, b, source);
	else printf(GREEN "OK" RESET);
	printf("\n"); free(a); free(b);
}

void do_strlen(char *name, char *source) {
	size_t a = strlen(source);
	size_t b = ft_strlen(source);
	printf("%s\t", name);
	printf(" return ");
	if (a != b) printf(RED "%ld != %ld" RESET, a, b);
	else printf(GREEN "OK" RESET);
	printf("\n");
}

#ifdef BONUS

t_list *construct_list(size_t count, int *data) {
	if (!data) return NULL;
	t_list *lst = calloc(1, sizeof(t_list));
	lst->data = &(data[0]);
	t_list *crt = lst;
	for (size_t i = 0; i < count - 1; i++) {
		crt->data = &(data[i]);
		crt->next = calloc(1, sizeof(t_list));
		crt = crt->next;
	}
	return lst;
}

void free_lst(t_list *lst) {
	if (!lst) return;
	while (lst->next) {
		t_list *nxt = lst->next;
		free(lst);
		lst = nxt;
	}
	free(lst);
}

void do_list_push_front(char *name, int *data, size_t size, int new) {
	t_list *lst = construct_list(size, data);
	ft_list_push_front(&lst, &new);
	size_t ns = ft_list_size(lst);
	printf("%s\t", name);
	printf(" size ");
	if (ns != size + 1) printf(RED "%ld != %ld" RESET, size + 1, ns);
	else printf(GREEN "OK" RESET);
	printf(" front ");
	if (*((int *)lst->data) != new) printf(RED "%d != %d" RESET, new, *((int *)lst->data));
	else printf(GREEN "OK" RESET);
	printf("\n");
	free_lst(lst);
}

void do_list_size(char *name, int *data, size_t expect) {
	t_list *lst = construct_list(expect, data);
	size_t got = ft_list_size(lst);
	printf("%s\t", name);
	printf(" result ");
	if (got != expect) printf(RED "%ld != %ld" RESET, expect, got);
	else printf(GREEN "OK" RESET);
	printf("\n");
	free_lst(lst);
}

#endif

void do_write(char *name, int fd, char *str, size_t count, int ofd) {
	errno = 0;
	int a = write(fd, str, count);
	int ar = errno;
	char as[BUFF_SIZE] = {0};
	if (ofd != -1)
		read(ofd, as, BUFF_SIZE);

	errno = 0;
	int b = ft_write(fd, str, count);
	int br = errno;
	char bs[BUFF_SIZE] = {0};
	if (ofd != -1)
		read(ofd, bs, BUFF_SIZE);

	printf("%s\t", name);
	printf(" return ");
	if (a != b) printf(RED "%d != %d" RESET, a, b);
	else printf(GREEN "OK" RESET);
	printf(" content ");
	if (ofd != -1 && strcmp(as, bs)) printf(RED "%s != %s" RESET, as, bs);
	else printf(GREEN "OK" RESET);
	printf(" errno ");
	if (ar != br) printf(RED "%d != %d" RESET, ar, br);
	else printf(GREEN "OK" RESET);
	printf("\n");
}
