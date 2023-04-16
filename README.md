# string.h
My own realization of standart library (C language) "string.h" for Mac and Linux.
For build static library do make all, for tests do make test.
Usage like in my_test.c.
## Realized functions
### memchr
Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str.
### memcmp
Compares the first n bytes of str1 and str2.
### memcpy
Copies n characters from src to dest.
### memmove
Another function to copy n characters from src to dest.
### memset
Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.
### strcat
Appends the string pointed to, by src to the end of the string pointed to by dest.
### strncat
Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long.
### strchr
Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
### strcmp
Compares the string pointed to, by str1 to the string pointed to by str2.
### strncmp
Compares at most the first n bytes of str1 and str2.
### strcpy
Copies the string pointed to, by src to dest.
### strncpy
Copies up to n characters from the string pointed to, by src to dest.
### strcspn
Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
### strerror
Searches an internal array for the error number errnum and returns a pointer to an error message string. You need to declare macros containing arrays of error messages for mac and linux operating systems. Error descriptions are available in the original library. Checking the current OS is carried out using directives.
### strlen
Computes the length of the string str up to but not including the terminating null character.
### strpbrk
Finds the first character in the string str1 that matches any character specified in str2.
### strrchr
Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str.
### strspn
Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
### strstr
Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack.
### strtok
Breaks string str into a series of tokens separated by delim.
### to_upper
Returns a copy of string (str) converted to uppercase. In case of any error, return NULL
### to_lower
Returns a copy of string (str) converted to lowercase. In case of any error, return NULL
### insert
Returns a new string in which a specified string (str) is inserted at a specified index position (start_index) in the given string (src). In case of any error, return NULL
### trim
Returns a new string in which all leading and trailing occurrences of a set of specified characters (trim_chars) from the given string (src) are removed. In case of any error, return NULL
### sprintf
Sends formatted output to a string pointed to, by str.
#### Specifiers:
c, d, i, f, s, u, %
#### Flags:
-, +, (space)
#### Width description:
(number)
#### Precision description:
.(number)
#### Length description:
h, l


