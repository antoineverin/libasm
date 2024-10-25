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
