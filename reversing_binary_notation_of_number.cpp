#include <iostream>
#include <bitset>

int main()
{
	__int32 number, reversed_number(0);
	std::cout << "Enter number:\n";
	std::cin >> number;

	__asm
	{
		mov EAX, number
		mov EBX, reversed_number
		mov ECX, 32

start_count:
		SHR EAX, 1
		JC one_case
		JNC zero_case
      
loop_count:
		loop start_count
        
      JMP end_of_program

one_case:
		SHL EBX, 1
		add EBX, 1
		JMP loop_count

zero_case:
		SHL EBX, 1
		add EBX, 0
		JMP loop_count

end_of_program:
		mov reversed_number, EBX
	}

	std::cout << "Your number:\n";
	std::bitset<32> n1(number);
	std::cout << n1 << std::endl;

	std::cout << "Reversed number:\n";
	std::bitset<32> n(reversed_number);
	std::cout << n << std::endl;

	return 0;
}
