# **42.printf**


Run:
----
- make *(this makes the library of functions used to run printf)*
- write your own main file and compile it together with the library

-------------------------------------------------------------------

42 The Network Assignment:
-----------
Recode the [printf()](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm) function from libc, with the prototype beeing:
    int ft_printf(const char *, ...);

Requirements:
-------------
- The buffer management of the original printf() is not necessary.
- The command ar must be used to create the library.
- Use of the libtool command is forbidden.
The function has to handle the following conversions:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent s

-------------------------------------------------------------------

Code format: 
------------
The code must be written in accordance to the 42 set of norms.  
These include for example a maximum of 25 lines per function and at most 80 columns per line, comments included. 
