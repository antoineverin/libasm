#include "test.h"

void print_test(char *name) {
	printf(GRAY " === %s ===\n" RESET, name);
}

void test_read() {
	print_test("ft_read");
	int pfd[2];
	pipe(pfd);
	do_read("basic", pfd[1], pfd[0], "hello world", 12);
	do_read("less", pfd[1], pfd[0], "hello world", 5);
	do_read("wfd", pfd[1], -1, "hello world", 12);
}

void test_strcmp() {
	print_test("ft_strcmp");
	do_strcmp("basic", "hello", "hello");
	do_strcmp("less", "hello", "hell");
	do_strcmp("ssel", "hell", "hello");
	do_strcmp("empty", "", "");
	do_strcmp("oempty", "hello", "");
	do_strcmp("emptyo", "", "hello");
}

void test_strcpy() {
	print_test("ft_strcpy");
	do_strcpy("basic", "hello world");
	do_strcpy("empty", "");
}

void test_strdup() {
	print_test("ft_strdup");
	do_strdup("basic", "hello world");
	do_strdup("empty", "");
}

void test_strlen() {
	print_test("ft_strlen");
	do_strlen("basic", "hello world");
	do_strlen("empty", "");
}

void test_write() {
	print_test("ft_write");
	int pfd[2];
	pipe(pfd);
	do_write("basic", pfd[1], "hello world", 12, pfd[0]);
	do_write("wfd", -1, "hello world", 12, -1);			close (pfd[0]);
	do_write("bpipe", pfd[1], "hello world", 12, -1);	(close(pfd[1]), pipe(pfd));
	do_write("null", pfd[1], NULL, 1, -1);				(close(pfd[1]), close(pfd[0]));
}

#ifdef BONUS

void test_list_size() {
	print_test("ft_list_size");
	do_list_size("basic", (int[5]) {1, 2, 3, 4, 5}, 5);
	do_list_size("empty", (int[1]) {1}, 1);
	do_list_size("empty", NULL, 0);
}

#endif

int main() {
	signal(SIGPIPE, SIG_IGN);

	test_read();
	test_strcmp();
	test_strcpy();
	test_strdup();
	test_strlen();
	test_write();

#ifdef BONUS
	test_list_size();
#endif
}
