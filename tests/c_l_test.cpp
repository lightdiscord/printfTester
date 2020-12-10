extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 75

int iTest = 1;
bool showTest = false;

static void generate_width_test(const char *fmt, int ac, int testNumber, int start, int width)
{
	if (ac == 1 || testNumber == start + 1) print(fmt, width, L'\0');
	if (ac == 1 || testNumber == start + 2) print(fmt, width, L'$');
	if (ac == 1 || testNumber == start + 3) print(fmt, width, L'¢');
	if (ac == 1 || testNumber == start + 4) print(fmt, width, L'ह');
	if (ac == 1 || testNumber == start + 5) print(fmt, width, L'𐍈');
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
	if (ac == 1 || testNumber == 1) print("%lc", L'\0');
	if (ac == 1 || testNumber == 2) print("%lc", L'$');
	if (ac == 1 || testNumber == 3) print("%lc", L'¢');
	if (ac == 1 || testNumber == 4) print("%lc", L'ह');
	if (ac == 1 || testNumber == 5) print("%lc", L'𐍈');

	int count = 0;

	generate_width_test("%*lc", ac, testNumber, count += 5, 1);
	generate_width_test("%*lc", ac, testNumber, count += 5, 2);
	generate_width_test("%*lc", ac, testNumber, count += 5, 3);
	generate_width_test("%*lc", ac, testNumber, count += 5, 4);
	generate_width_test("%*lc", ac, testNumber, count += 5, 5);
	generate_width_test("%*lc", ac, testNumber, count += 5, 6);
	generate_width_test("%*lc", ac, testNumber, count += 5, 7);

	generate_width_test("%-*lc", ac, testNumber, count += 5, 1);
	generate_width_test("%-*lc", ac, testNumber, count += 5, 2);
	generate_width_test("%-*lc", ac, testNumber, count += 5, 3);
	generate_width_test("%-*lc", ac, testNumber, count += 5, 4);
	generate_width_test("%-*lc", ac, testNumber, count += 5, 5);
	generate_width_test("%-*lc", ac, testNumber, count += 5, 6);
	generate_width_test("%-*lc", ac, testNumber, count += 5, 7);
	cout << ENDL;
	return (0);
}
