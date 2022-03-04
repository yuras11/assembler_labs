#include <iostream>


int main()
{
	__int32 number, result, for_zero_case(0);
	int number_of_expression, result_in_cplusplus;

	std::cout << "Enter your number:\n";
	std::cin >> number;
	
	std::cout << "Enter number of expression(1, 2 or 3):\n";
	std::cin >> number_of_expression;

	while (number_of_expression != 1 && number_of_expression != 2 && number_of_expression != 3)
	{
		std::cout << "You\'ve entered a number that is not in the definition area, try again:\n";
		std::cin >> number_of_expression;
	}
	
	__asm
	{
		mov EAX, number_of_expression

		CMP EAX, 1
		JE expression_1

		CMP EAX, 2
		JE expression_2

		CMP EAX, 3
		JE expression_3

zero_case :
		mov EAX, number_of_expression
		mov for_zero_case, EAX
		JMP end_of_program

expression_1 :
		mov EAX, number

		CMP EAX, 0
		JE zero_case
		mov ECX, 4

start_count :
		mul number
		loop start_count

		mov EBX, EAX

		mov EAX, number
		mul number
		sub EAX, 4
		mov ECX, 2
		mul ECX

		add EBX, EAX
		add EBX, number

		mov EAX, number
		mov ECX, 2

start_count_2:
		mul number
		loop start_count_2

		mov ECX, EAX
		mov EAX, EBX
		CDQ
		idiv ECX

		mov result, EAX

		JMP end_of_program

expression_2 :

		mov EAX, number

		CMP EAX, 0
		JE zero_case

		mov EBX, 2
		mul EBX
		sub EAX, 1

		mov EBX, EAX
		
		mov EAX, number
		mov ECX, 2
		mul ECX
		sub EAX, 1

		mul EBX

		mov EBX, number
		add EBX, 3

		mul EBX

		mov EBX, EAX
		mov EAX, number
		mov ECX, 2
		mul ECX

		mov ECX, EBX
		mov EBX, EAX
		mov EAX, ECX

		CDQ
		idiv EBX

		mov result, EAX

		JMP end_of_program

expression_3:
	
		mov EAX, number
		mov EBX, 4
		mul EBX
		sub EAX, 1

		mov EBX, EAX

		mov EAX, number
		mov ECX, 4
		mul ECX
		sub EAX, 1

		mul EBX 

		mov ECX, 4
		CDQ
		idiv ECX 

		mov result, EAX

end_of_program:
	}
	
	if (for_zero_case != 0)
	{
		throw std::runtime_error("Can\'t divide by 0");
	}
	if (number_of_expression == 1)
	{
		result_in_cplusplus = (pow(number, 5) + 2 * (pow(number, 2) - 4) + number) / (pow(number, 3));
	}
	else if (number_of_expression == 2)
	{
		result_in_cplusplus = pow((2 * number - 1), 2) * (number + 3) / (2 * number);
	}
	else
	{
		result_in_cplusplus = pow((4 * number - 1), 2) / 4;
	}

	std::cout << "Your result: " << std::endl;
	std::cout << result << std::endl;
	std::cout << "Result in C++:\n";
	std::cout << result_in_cplusplus << std::endl;
	if (result != result_in_cplusplus)
	{
		std::cout << "Results does not coincide!\n";
	}
	else
	{
		std::cout << "Results coincide!\n";
	}
	return 0;
}
