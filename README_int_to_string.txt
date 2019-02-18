>>> 
>>> # Manually computing remainder, quotient for int_to_string
... 
>>> # Example: convert 1234 to ASCII string
... 
>>> remainder = 1234 % 10
>>> quotient = 1234 // 10
>>> (quotient, remainder)
(123, 4)
>>> print(chr(remainder))

>>> print(chr(remainder+48))
4
>>> remainder = quotient % 10
>>> quotient = quotient // 10
>>> (quotient, remainder)
(12, 3)
>>> print(chr(remainder+48))
3
>>> remainder = quotient % 10
>>> quotient = quotient // 10
>>> (quotient, remainder)
(1, 2)
>>> print(chr(remainder+48))
2
>>> remainder = quotient % 10
>>> quotient = quotient // 10
>>> (quotient, remainder)
(0, 1)
>>> print(chr(remainder+48))
1
>>> # stop now as quotient == 0 (zero)
... 
>>> 
>>> # do the same steps but add remainder ASCII value to a list
... 
>>> ascii_char_lst = []
>>> remainder = 1234 % 10
>>> quotient = 1234 // 10
>>> (quotient, remainder)
(123, 4)
>>> ascii_char_lst.append(chr(remainder+48))
>>> 
>>> ascii_char_lst
['4']
>>> remainder = quotient % 10
>>> quotient = quotient // 10
>>> (quotient, remainder)
(12, 3)
>>> ascii_char_lst.append(chr(remainder+48))
>>> ascii_char_lst
['4', '3']
>>> remainder = quotient % 10
>>> quotient = quotient // 10
>>> ascii_char_lst.append(chr(remainder+48))
>>> ascii_char_lst
['4', '3', '2']
>>> remainder = quotient % 10
>>> quotient = quotient // 10
>>> ascii_char_lst.append(chr(remainder+48))
>>> ascii_char_lst
['4', '3', '2', '1']
>>> (quotient, remainder)
(0, 1)
>>> # stop here as quotient is 0 (zero), now print the list using join
... 
>>> "".join(ascii_char_lst)
'4321'
>>> # need to reverse the list to get the correct ascii representation
... 
>>> "".join(reversed(ascii_char_lst))
'1234'
>>> # yay! done
... 
>>> # Trick is to put the steps in a loop
... 
>>> # Hint: Initialize quotient with the original value to code the loop
... 
>>> 
