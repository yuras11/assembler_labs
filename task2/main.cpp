#include <iostream>

int main()
{
	
	__int32 number;
	__int32 first_digit, last_digit, middle_part_of_number;
	__int32 bit_depth(0), multiplier(1);
	
	std::cout << "Enter number:\n";
	std::cin >> number;

	__int32 reversed_number = number;
	__asm
	{
		mov EAX, number
		CMP EAX, 10
		JB end_of_program

;// searh for the last digit in number:
		
        mov EAX, number
		mov EBX, 10
		CDQ
		div EBX
		mov last_digit, EDX

;// searh for a number of digits in the  number:
		
		mov EAX, number
		mov ECX, 0
		CDQ

start_count_1:
		CMP EAX, 00
		JE end_count_1

		div EBX
		CDQ
		add ECX, 1
		JMP start_count_1
end_count_1:
		mov bit_depth, ECX

;// search for the first digit in the number:
		
		mov EAX, number
		mov ECX, bit_depth
		mov EBX, 10
start_count_2:
		div EBX
		mov first_digit, EDX
		CDQ
		loop start_count_2
		
;// reversing number
		mov EAX, multiplier
		mov EBX, 10
		mov ECX, bit_depth
		sub ECX, 1
start_count_3:
		mul EBX
		loop start_count_3
		mov multiplier, EAX
		
		mov EAX, number
		mov EBX, multiplier
		div EBX
		mov middle_part_of_number, EDX
		CDQ
		mov EAX, middle_part_of_number
		mov EBX, 10
		div EBX 
		mov middle_part_of_number, EAX

		mov EAX, last_digit
		mov EBX, 10
		mov ECX, bit_depth
		sub ECX, 1
      
start_count_4:
		mul EBX
		loop start_count_4

		mov last_digit, EAX

		mov EAX, middle_part_of_number
		mov EBX, 10
		mul EBX

		mov middle_part_of_number, EAX

		mov EAX, last_digit
		mov EBX, middle_part_of_number
		add EAX, EBX
		add EAX, first_digit

		mov reversed_number, EAX

end_of_program:
	}

	std::cout << "Your number with the first and last digits reversed:\n";
	std::cout << reversed_number << std::endl;

	return 0;
}
