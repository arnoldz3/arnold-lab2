#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma bss_seg("BSS")
char bssString[12];
char bssBytes[15];

void printString(char* str) {
	printf("%s", str);
}

int main()
{

	// #1 - Copy 12 bytes from the bss (unininitialized) section to the stack.
	// Take twelve uninitialized bytes from the user and copy them
	// to the stack.
	char stackString[12] = "StackString";
	printf("Please enter 11 bytes. (Null character is considered.)\n");
	scanf("%s", bssString);
	memcpy(stackString, bssString, 12);


	// #2 - Copy 13 bytes from the heap (dynamic memory) section to the DATA section.
	// Take thirteen newly allocated bytes and store them as something in the data section.
	char *heapBuffer = (char*) malloc(13);
	printf("Please enter 12 bytes. (Null character is considered.)\n");
	scanf("%s", heapBuffer);
	char dataString[13];
	memcpy(dataString, heapBuffer, 13);

	// #3 - Copy 14 bytes from the stack to the heap.
    // Take 14 bytes from a function and save them to a newly allocated variable.
	char stackString2[14] = "StackString14";
	char *heapBuffer2 = (char*)malloc(14);
	memcpy(stackString2, heapBuffer2, 13);
	

	// #4 - Copy 15 bytes from the data section to the bss.
	char fifteenBytes [] = "123456789ABCDE";
	sprintf(bssBytes, "%s", fifteenBytes);

	// #5 - Copy 4 bytes from the text section to the data section.
	int n = sizeof(&printString);
	printf("%d, %x", n, &printString);

	free(heapBuffer);
	free(heapBuffer2);
	return 0;
}