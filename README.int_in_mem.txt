int_to_mem.c: Test C program for how integers get stored in memory

Build Instructions for int_to_mem.c
===================================
1. Compile int_in_mem.c using clang to produce output int_in_mem executable

	$ clang int_in_mem.c -g -o int_in_mem

Example output: (ignore compiler warning for now)

int_in_mem.c:22:17: warning: incompatible pointer types assigning to 'char *'
      from 'int *' [-Wincompatible-pointer-types]
        memory_pointer = &global_var; /* set memory pointer to address of
                       ^ ~~~~~~~~~~~
1 warning generated.

2. Run int_in_mem in current directory under lldb debugger

	$ lldb ./int_in_mem

Example output: (Note: *** x86_64, a little-endian architecture)

	Current executable set to './int_in_mem' (x86_64).

3. Set breakpoint at entry to function main()

	(lldb) break set -b main

Example output:

	Breakpoint 1: where = int_in_mem`main + 23 at int_in_mem.c:6, address = 0x0000000000400547

4. Run the int_to_mem executable under lldb from start

	(lldb) run

Example output: Program execution stops when it reaches main() function

	Process 12734 launched: './int_in_mem' (x86_64)
	Process 12734 stopped

5. Read (dump) memory from address-of global_var variable, count 4 bytes

	(lldb) memory read -c 4 &global_var

Example output: 1st column is actual address of global_var, followed
   by the four byte values, last column of .... is ASCII representation
   of the byte values if they have printable ASCII chars, else '.'
   Since these are 4 non-printable ASCII chars, we see 4 '.' (dots)
   All values are printed in hexadecimal format.

	0x00601034: d2 04 00 00                                      ....

NOTE:
 The value of decimal 1234 in 4-bytes (32-bit) quantity is: 0x000004d2
 but the bytes are dumped in reverse order because it is little-endian
 x86_64 architecture (right-most is least, left-most is most significant)

6. Read (dump) memory from address-of (&) global_var, read it as a
   decimal integer (-f d), which is 4 bytes, and print count of 1 value

	(lldb) memory read -c 1 -f d &global_var

Example output: 1st column is address, 2nd column 32-bit integer value
   (four bytes) in that location in decimal format.

	0x00601034: 1234

7. Read (dump or examine) memory from address-of (&) global_var,
   read count of 1 (one) hexadecimal integer (x) value, which is
   value contained in 4-bytes, print in hexadecimal format.

	(lldb) memory read -c 1 -f x &global_var

Example output: 1st column is address, 2nd column 32-bit value in
  hexadecimal format of 1234.

	0x00601034: 0x000004d2

8. Continue execution until program termination
	(lldb) cont

Example output: Note the squiqqly characters printed for non-printable
   ASCII chars in output.

	Process 12734 resuming
	global_var value in decimal is 1234
	global_var value in hexadecimal is 4d2
	memory_pointer first byte � 
	memory_pointer second byte  
	memory_pointer third byte  
	memory_pointer last byte  
	Process 12734 exited with status = 0 (0x00000000) 
	(lldb) 

