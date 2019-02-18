#!/usr/bin/env python3
#
# Uses python3
#

# Warning: Python integer division '//' does weird things for negative
#   values. So will the code work for negative numbers?
# Needs fixing
#
def int_to_string(ival):
	'''
	This function uses integer division and remainder (modulo) to
	convert integer value to its ASCII printable char sequence
	'''
	if ival == 0:
		return '0'	# handle degenerate case
	ival_str = []   # list to hold the ASCII digit chars
	# For non-zero values, extract digits using div and mod
	quot = ival     # let quot be the original value
	while quot != 0:
		remdr = quot % 10	# first, calculate the remainder
		quot = quot // 10	# then, recompute quotient
		# 48 is the ASCII char value for digit 0
		ival_str.append(chr(remdr+48)) # add 48 to get ASCII digit char

	# exited the while loop. ival_str has all the digit chars
	# join the list of ASCII chars and return the reversed string
	# Why not use insert to list instead of append in the loop?
	return "".join(reversed(ival_str))

if __name__ == "__main__":
	# test int_to_string with different integers 0, 100, 1234, 24680864
	for i in [0, 100, 1234, 24680864]:
		ret = int_to_string(i)
		print("Integer {0} in string is {1}\n".format(i, ret))
