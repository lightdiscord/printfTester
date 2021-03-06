extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 68

int iTest = 1;
bool showTest = false;
int main(int ac, char ** av)
{
	int testNumber;
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "[d]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl;
	if (ac == 1 || testNumber == 1) print(" %d ", 0);
	if (ac == 1 || testNumber == 2) print(" %.d ", 0);
	if (ac == 1 || testNumber == 3) print(" %-.2d ", 0);
	if (ac == 1 || testNumber == 4) print(" %-2.2d ", 0);
	if (ac == 1 || testNumber == 5) print(" %-3.2d ", 0);
	if (ac == 1 || testNumber == 6) print(" %-3.2d %10.42d ", 0, 0);
	if (ac == 1 || testNumber == 7) print(" %-3.2d %10.42d ", 1, -1);
	if (ac == 1 || testNumber == 8) print(" %-3.2d %10.42d ", 10, -10);
	if (ac == 1 || testNumber == 9) print(" *%-*.*d* *%*.*d* ", 4, 5, 10, 10, 21, -10);
	if (ac == 1 || testNumber == 10) print(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
	if (ac == 1 || testNumber == 11) print(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
	if (ac == 1 || testNumber == 12) print(" 0*%0-*.*d*0 0*%0*.*d*0 ", 6, 2, 102, 10, 21, -101);
	if (ac == 1 || testNumber == 13) print(" 0*%0-*.*d*0 0*%0*.*d*0 ", 2, 6, 102, 21, 10, -101);
	if (ac == 1 || testNumber == 14) print(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011);
	if (ac == 1 || testNumber == 15) print(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011);
	if (ac == 1 || testNumber == 16) print(" --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1);
	if (ac == 1 || testNumber == 17) print(" --0*%0*.0d*0 0*%0*.10d*0-- ", -21, INT_MAX, 21, INT_MIN);
	if (ac == 1 || testNumber == 18) print(" --0*%0*.0d*0 0*%0*.10d*0-- ", -21, LONG_MAX, 21, LONG_MIN);
	if (ac == 1 || testNumber == 19) print(" --0*%-0*.20d*0 0*%-0*.10d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);
	if (ac == 1 || testNumber == 20) print(" --0*%-0*.2d*0 0*%-0*.2d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);
	if (ac == 1 || testNumber == 21) print(" --0*%-0*.3d*0 0*%-0*.3d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);
	if (ac == 1 || testNumber == 22) print(" --0*%-0*.4d*0 0*%-0*.4d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);
	if (ac == 1 || testNumber == 23) print("%9.2d", UINT_MAX);
	if (ac == 1 || testNumber == 24) print("%9.10d", UINT_MAX);
	if (ac == 1 || testNumber == 25) print("%10.0d", UINT_MAX);
	if (ac == 1 || testNumber == 26) print("%10.1d", UINT_MAX);
	if (ac == 1 || testNumber == 27) print("%10.2d", UINT_MAX);
	if (ac == 1 || testNumber == 28) print("%10.10d", UINT_MAX);
	if (ac == 1 || testNumber == 29) print("%11.0d", UINT_MAX);
	if (ac == 1 || testNumber == 30) print("%11.1d", UINT_MAX);
	if (ac == 1 || testNumber == 31) print("%11.2d", UINT_MAX);
	if (ac == 1 || testNumber == 32) print("%11.10d", UINT_MAX);
	if (ac == 1 || testNumber == 33) print("%-9.0d", UINT_MAX);
	if (ac == 1 || testNumber == 34) print("%-9.1d", UINT_MAX);
	if (ac == 1 || testNumber == 35) print("%-9.2d", UINT_MAX);
	if (ac == 1 || testNumber == 36) print("%-9.10d", UINT_MAX);
	if (ac == 1 || testNumber == 37) print("%-10.0d", UINT_MAX);
	if (ac == 1 || testNumber == 38) print("%-10.1d", UINT_MAX);
	if (ac == 1 || testNumber == 39) print("%-10.2d", UINT_MAX);
	if (ac == 1 || testNumber == 40) print("%-10.10d", UINT_MAX);
	if (ac == 1 || testNumber == 41) print("%-11.0d", UINT_MAX);
	if (ac == 1 || testNumber == 42) print("%-11.1d", UINT_MAX);
	if (ac == 1 || testNumber == 43) print("%-11.2d", UINT_MAX);
	if (ac == 1 || testNumber == 44) print("%-11.10d", UINT_MAX);
	if (ac == 1 || testNumber == 45) print("%09.0d", UINT_MAX);
	if (ac == 1 || testNumber == 46) print("%09.1d", UINT_MAX);
	if (ac == 1 || testNumber == 47) print("%09.2d", UINT_MAX);
	if (ac == 1 || testNumber == 48) print("%09.10d", UINT_MAX);
	if (ac == 1 || testNumber == 49) print("%010.0d", UINT_MAX);
	if (ac == 1 || testNumber == 50) print("%010.1d", UINT_MAX);
	if (ac == 1 || testNumber == 51) print("%010.2d", UINT_MAX);
	if (ac == 1 || testNumber == 52) print("%010.10d", UINT_MAX);
	if (ac == 1 || testNumber == 53) print("%011.0d", UINT_MAX);
	if (ac == 1 || testNumber == 54) print("%011.1d", UINT_MAX);
	if (ac == 1 || testNumber == 55) print("%011.2d", UINT_MAX);
	if (ac == 1 || testNumber == 56) print("%011.10d", UINT_MAX);
	if (ac == 1 || testNumber == 57) print("%09.0d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 58) print("%09.1d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 59) print("%09.2d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 60) print("%09.10d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 61) print("%010.0d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 62) print("%010.1d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 63) print("%010.2d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 64) print("%010.10d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 65) print("%011.0d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 66) print("%011.1d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 67) print("%011.2d", UINT_MAX + 1);
	if (ac == 1 || testNumber == 68) print("%011.10d", UINT_MAX + 1);
	cout << ENDL;
	return (0);
}