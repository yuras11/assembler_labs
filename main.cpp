#include <iostream>

int main()
{
	unsigned int numbers[10];
	int number_with_ones_on_suitable_positions(268410752);
	int cutted_bytes[10];
	numbers[0] = 268500992;
	numbers[1] = 536903680;
	numbers[2] = 1073742336;
	numbers[3] = 2147483776;

	for (int i = 4; i < 10; i++)
	{
		numbers[i] = 0;
	}
	
	__asm
	{
		mov ecx, 10
		mov esi, 0
		xor ebx, ebx
		add ebx, number_with_ones_on_suitable_positions
start_cutting:		
		cdq
		xor eax, eax
		add eax, numbers[esi]
		and eax, ebx
		add edx, eax
		shr edx, 15
		shl eax, 19
		shr eax, 26
		shl edx, 6
		add edx, eax
		mov cutted_bytes[esi], edx
		add esi, 4
loop start_cutting
		
		mov ecx, 8
sorting_1:
		mov esi, 0
		push ecx
	sorting_2:
		xor eax, eax
		xor ebx, ebx
		add eax, cutted_bytes[esi]
		add ebx, cutted_bytes[esi+4]
		cmp eax, ebx
		jg sort_array
loop_sorting_2:
		add esi, 4
	loop sorting_2
		pop ecx
loop sorting_1

		jmp end_

sort_array:
		xor eax, eax
		xor ebx, ebx
		add eax, numbers[esi]
		add ebx, numbers[esi+4]
		mov numbers[esi], ebx
		mov numbers[esi+4], eax
		jmp loop_sorting_2

end_:
	}

	for (int i = 0; i <	10; i++)
	{
		std::cout << numbers[i] << std::endl;
	}

	return 0;
}
