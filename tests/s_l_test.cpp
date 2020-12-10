extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 108
#define TEST(...) if (ac == 1 || testNumber == ++current) print(__VA_ARGS__);

int iTest = 1;
bool showTest = false;
int main(int ac, char ** av)
{
	int testNumber;
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "[s_l]" << RESET_ALL;
	
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

	TEST("%ls", L"");
	TEST("%ls", L"Something normal");
	TEST("%ls %ls", L"Something", L"normal");
	TEST("%ls", L"$$$$");
	TEST("%ls", L"¢¢¢¢");
	TEST("%ls", L"हहहह");
	TEST("%ls", L"𐍈𐍈𐍈𐍈");
	TEST("%ls", L"$¢ह𐍈");

	for (int i = 0; i <= 20; i += 5)
	{
		TEST("%*ls", i, L"$$$");
		TEST("%*ls", i, L"¢¢¢¢");
		TEST("%*ls", i, L"हहहह");
		TEST("%*ls", i, L"𐍈𐍈𐍈𐍈");
		TEST("%*ls", i, L"$¢ह𐍈");

		TEST("%.*ls", i, L"$$$");
		TEST("%.*ls", i, L"¢¢¢¢");
		TEST("%.*ls", i, L"हहहह");
		TEST("%.*ls", i, L"𐍈𐍈𐍈𐍈");
		TEST("%.*ls", i, L"$¢ह𐍈");

		TEST("%*.*ls", i * 2, i, L"$$$");
		TEST("%*.*ls", i * 2, i, L"¢¢¢¢");
		TEST("%*.*ls", i * 2, i, L"हहहह");
		TEST("%*.*ls", i * 2, i, L"𐍈𐍈𐍈𐍈");
		TEST("%*.*ls", i * 2, i, L"$¢ह𐍈");

		TEST("%-*.*ls", i * 2, i, L"$$$");
		TEST("%-*.*ls", i * 2, i, L"¢¢¢¢");
		TEST("%-*.*ls", i * 2, i, L"हहहह");
		TEST("%-*.*ls", i * 2, i, L"𐍈𐍈𐍈𐍈");
		TEST("%-*.*ls", i * 2, i, L"$¢ह𐍈");
	}
	cout << ENDL;
	return (0);
}
