#include <stdio.h>

int	global_var = 1234; /* initialized to 1234 */
int main(void)
{
	printf("global_var value in decimal is %d\n", global_var);
	printf("global_var value in hexadecimal is %x\n", global_var);

	char *memory_pointer; /* pointer to memory == address location */
	/* a "char *" is a pointer that points to a "char" type
	 * A "char" is 8-bit or 1 byte, but global_var is an "int"
	 * which is 4-bytes long.
	 * To print the 4 bytes of int value contained in global_var
	 * identifier location, we will increment memory_pointer
	 * by 1 (one byte) for 3 times to point to the four bytes
	 * of the int, and print one byte at a time as a 'char'
	 *
	 * memory_pointer +---------+---------+---------+---------+
	 *                | byte 0  | byte 1  | byte 2  | byte 3  |
	 *                +---------+---------+---------+---------+
	 */
	memory_pointer = &global_var; /* set memory pointer to address of
	                                 global_var identifier in memory */
	/*To "dereference" a pointer, use '*' before pointer
	 * "De-reference" means to get value from the address
	 * But memory address pointer could be incremented for huge number,
	 * say 4GB of main memory, so how does "dereference" work.
	 * It looks at the type of the pointer declared, here "char *"
	 * means "pointer to a char", since 'char' type is 1-byte
	 * the dereference will return value stored in 1 (one) byte.
	 */
	printf("memory_pointer first byte %c \n", *memory_pointer);
	/*
	 * increment memory_pointer by 1 (1 of char length)
	 * Since 'length of char' is 1, here 1 means 1 byte
	 */
	memory_pointer = memory_pointer + 1;
	printf("memory_pointer second byte %c \n", *memory_pointer);
	/*
	 * increment memory pointer by 1 (1 of char length) to
	 * point to the next location
	 */
	memory_pointer = memory_pointer + 1;
	printf("memory_pointer third byte %c \n", *memory_pointer);
	/*
	 * increment memory pointer by 1 (1 of char length) to
	 * point to the next location, the last location in global_var
	 * int value
	 */
	memory_pointer = memory_pointer + 1;
	printf("memory_pointer last byte %c \n", *memory_pointer);

	/* done with example - return from main */
	return 0; /* main returns an integer value to the system */
}
