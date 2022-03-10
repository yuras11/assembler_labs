#include <iostream>

int main()
{
	__int32 number;
	std::cout << "Enter number:\n";
	std::cin >> number;

	int result;

	int array[32];
	for (int i = 0; i < 32; i++)
	{
		array[i] = 0;
	}

	__asm
	{
		mov EAX, number
		mov EBX, 128
		mov ECX, 32

start_count:
		SHR EAX, 1
		JC one_case
		JNC zero_case

loop_count :
		loop start_count

		JMP end_of_program

one_case:

		add array[EBX - 4], 1
		sub EBX, 4

		JMP loop_count

zero_case:

		add array[EBX - 4], 0
		sub EBX, 4

		JMP loop_count

end_of_program:
	}

	for (int i = 0; i < 32; i++)
	{
		std::cout << array[i];
	}
	std::cout << std::endl;

	return 0;
}
