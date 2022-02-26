#include <iostream>

int main()
{
	__int16 a3, a2, a1;
	__int16 b3, b2, b1;
        __int16 c3(0), c2(0), c1(0);
	std::cout << "Enter numbers \"a\":\n";
	std::cin >> a3 >> a2 >> a1;
	std::cout << "Enter numbers \"b\":\n";
	std::cin >> b3 >> b2 >> b1;
	
	__asm
	{
		mov AX, a1
		add AX, b1
		mov c1, AX

		mov AX, a2
		adc AX, b2
		mov c2, AX

		mov AX, a3
		adc AX, b3
		mov c3, AX
	}

	std::cout << "Numbers you\'ve entered in decimal number system:\n";
	std::cout << "a3 = " << a3 << '\t' << "a2 = " << a2 << '\t' << "a1 = " << a1 << std::endl;
	std::cout << "b3 = " << b3 << '\t' << "b2 = " << b2 << '\t' << "b1 = " << b1 << std::endl;
	std::cout << "c3 = " << c3 << '\t' << "c2 = " << c2 << '\t' << "c1 = " << c1 << std::endl;

	std::cout << "Numbers you\'ve entered in hexadecimal number system:\n";
	std::cout.unsetf(std::ios::dec);
	std::cout.setf(std::ios::hex);

	std::cout << "a3 = " << a3 << '\t' << "a2 = " << a2 << '\t' << "a1 = " << a1 << std::endl;
	std::cout << "b3 = " << b3 << '\t' << "b2 = " << b2 << '\t' << "b1 = " << b1 << std::endl;
	std::cout << "c3 = " << c3 << '\t' << "c2 = " << c2 << '\t' << "c1 = " << c1 << std::endl;

	std::cout << "The sum of numbers in decimal number system:\n";
	std::cout << ((uint64_t)c3 << 32 | (uint64_t)c2 << 16 | c1);

	return 0;
}
