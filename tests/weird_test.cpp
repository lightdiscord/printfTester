extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 16
#define TEST(...) if (ac == 1 || testNumber == ++current) print(__VA_ARGS__);

int iTest = 1;
bool showTest = false;
int main(int ac, char ** av)
{
	int testNumber;
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "[weird]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl;

	int current = 0;

	TEST("test: %k");
	TEST("test: %20k");
	TEST("test: %-20k");
	TEST("test: %0-20k");
	TEST("test: %020k");

	TEST("test: %.*k%c", 20, 't');
	TEST("test: %*.k%c", 20, 't');
	TEST("test: %*.*k%c", 20, 30, 't');

	TEST("test: %1234")
	TEST("test: %.1234")
	TEST("test: %1234.1234")
	TEST("test: %0-+1234.1234")
	TEST("test: %")
	TEST("test: %.*", 20);
	TEST("test: %*.", 20);
	TEST("test: %*.*", 20, 30);
	return (0);
}
