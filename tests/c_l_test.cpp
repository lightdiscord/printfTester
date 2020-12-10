extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 90

int iTest = 1;
bool showTest = false;

static void generate_width_test(const char *fmt, int ac, int testNumber, int *count, int width)
{
	if (ac == 1 || testNumber == (*count += 1)) print(fmt, width, L'\0');
	if (ac == 1 || testNumber == (*count += 1)) print(fmt, width, L'$');
	if (ac == 1 || testNumber == (*count += 1)) print(fmt, width, L'¢');
	if (ac == 1 || testNumber == (*count += 1)) print(fmt, width, L'ह');
	if (ac == 1 || testNumber == (*count += 1)) print(fmt, width, L'𐍈');
	if (ac == 1 || testNumber == (*count += 1)) print(fmt, width, 0xFFFFFFFF);
}

int main(int ac, char ** av)
{
	int testNumber;
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "[c_l]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl;

	int count = 0;

	if (ac == 1 || testNumber == ++count) print("test: %lc", L'\0');
	if (ac == 1 || testNumber == ++count) print("test: %lc", L'$');
	if (ac == 1 || testNumber == ++count) print("test: %lc", L'¢');
	if (ac == 1 || testNumber == ++count) print("test: %lc", L'ह');
	if (ac == 1 || testNumber == ++count) print("test: %lc", L'𐍈');
	if (ac == 1 || testNumber == ++count) print("test: %lc", 0xFFFFFFFF);

	generate_width_test("test: %*lc", ac, testNumber, &count, 1);
	generate_width_test("test: %*lc", ac, testNumber, &count, 2);
	generate_width_test("test: %*lc", ac, testNumber, &count, 3);
	generate_width_test("test: %*lc", ac, testNumber, &count, 4);
	generate_width_test("test: %*lc", ac, testNumber, &count, 5);
	generate_width_test("test: %*lc", ac, testNumber, &count, 6);
	generate_width_test("test: %*lc", ac, testNumber, &count, 7);

	generate_width_test("test: %-*lc", ac, testNumber, &count, 1);
	generate_width_test("test: %-*lc", ac, testNumber, &count, 2);
	generate_width_test("test: %-*lc", ac, testNumber, &count, 3);
	generate_width_test("test: %-*lc", ac, testNumber, &count, 4);
	generate_width_test("test: %-*lc", ac, testNumber, &count, 5);
	generate_width_test("test: %-*lc", ac, testNumber, &count, 6);
	generate_width_test("test: %-*lc", ac, testNumber, &count, 7);
	cout << ENDL;
	return (0);
}
