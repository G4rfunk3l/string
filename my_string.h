#ifndef SRC_MY_STRING_H_
#define SRC_MY_STRING_H_
#define my_size_t unsigned long
#define my_NULL (void*)0
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void *my_memchr(const void *str, int c, my_size_t n);
int my_memcmp(const void *str1, const void *str2, my_size_t n);
void *my_memcpy(void *dest, const void *src, my_size_t n);
void *my_memmove(void *dest, const void *src, my_size_t n);
void *my_memset(void *str, int c, my_size_t n);
char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, my_size_t n);
char *my_strchr(const char *str, int c);
int my_strcmp(const char *str1, const char *str2);
int my_strncmp(const char *str1, const char *str2, my_size_t n);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, my_size_t n);
my_size_t my_strcspn(const char *str1, const char *str2);
char *my_strerror(int errnum);
my_size_t my_strlen(const char *str);
char *my_strpbrk(const char *str1, const char *str2);
char *my_strrchr(const char *str, int c);
my_size_t my_strspn(const char *str1, const char *str2);
my_size_t my_strrspn(const char *str1, const char *str2);
char *my_strstr(const char *haystack, const char *needle);
char *my_strtok(char *str, const char *delim);
void *my_to_upper(const char *str);
void *my_to_lower(const char *str);
void *my_insert(const char *str, const char *insertion, my_size_t index);
void *my_trim(const char *src, const char *trim_chars);

int my_sprintf(char *str, const char *format, ...);
long long int my_pow(long long int number, long long int power);
char *int_to_char(long long int number);
int char_to_int(char* str);
char *unsigned_to_char(long unsigned number);
char *float_to_char(long double number, int number_precision);

int flag_length_width_filling(char *temp, char *flag,
        char *length, char *precision, int *number_precision, int *flag_precision,  char **format);

int flags(char *flag, const char *lenght, int *flag_space, int *flag_plus,
        int *flag_minus, int *flag_h, int *flag_l);

int widths(char *str, int *str_index, int *align, int *written_chars_count);
int plus_or_space(char *str, int *str_index, int flag_plus, int *written_chars_count);
long int lenght_digit(va_list *list, int flag_h, int flag_l);
long unsigned int lenght_unsigned(va_list *list, int flag_h, int flag_l);
long double lenght_float(va_list *list, int flag_l, int *flag_float, int *flag_double);

int rounding(const char *float_part_arr, long int *int_part, int number_precision, int flag_float,
                int flag_double);

int float_filling(char *int_float_number, char *int_part_arr, char *float_part_arr, int number_precision);
int get_the_number_precision(const char *format, int *number_precision);

int sprintf_digit(char *str, va_list *list, int str_index, int number_precision, int flag_space,
        int flag_plus, int flag_minus, int flag_precision, int width, int flag_h, int flag_l);

int sprintf_float(char *str, va_list *list, int str_index, int *number_precision,
        int flag_space, int flag_plus, int flag_minus, int flag_precision, int width, int flag_l);

int sprintf_char(char *str, va_list *list, int str_index, int flag_minus, int width);

int sprintf_string(char *str, va_list *list, int str_index, int number_precision,
                int flag_minus, int flag_precision, int width);

int sprintf_unsigned(char *str, va_list *list, int str_index, int number_precision, int flag_minus,
        int width, int flag_h, int flag_l);

void my_clean(char *str, char *src, my_size_t size);

#if defined(__linux) || defined(__linux__)

#   define Linux 1
#   define Mac 0
#   define MIN 0
#   define MAX 133
#   define STRERROR_ERRORS (char[200][90]) {                    \
    {"Success"},                                                \
    {"Operation not permitted"},                                \
    {"No such file or directory"},                              \
    {"No such process"},                                        \
    {"Interrupted system call"},                                \
    {"Input/output error"},                                     \
    {"No such device or address"},                              \
    {"Argument list too long"},                                 \
    {"Exec format error"},                                      \
    {"Bad file descriptor"},                                    \
    {"No child processes"},                                     \
    {"Resource temporarily unavailable"},                       \
    {"Cannot allocate memory"},                                 \
    {"Permission denied"},                                      \
    {"Bad address"},                                            \
    {"Block device required"},                                  \
    {"Device or resource busy"},                                \
    {"File exists"},                                            \
    {"Invalid cross-device link"},                              \
    {"No such device"},                                         \
    {"Not a directory"},                                        \
    {"Is a directory"},                                         \
    {"Invalid argument"},                                       \
    {"Too many open files in system"},                          \
    {"Too many open files"},                                    \
    {"Inappropriate ioctl for device"},                         \
    {"Text file busy"},                                         \
    {"File too large"},                                         \
    {"No space left on device"},                                \
    {"Illegal seek"},                                           \
    {"Read-only file system"},                                  \
    {"Too many links"},                                         \
    {"Broken pipe"},                                            \
    {"Numerical argument out of domain"},                       \
    {"Numerical result out of range"},                          \
    {"Resource deadlock avoided"},                              \
    {"File name too long"},                                     \
    {"No locks available"},                                     \
    {"Function not implemented"},                               \
    {"Directory not empty"},                                    \
    {"Too many levels of symbolic links"},                      \
    {"Unknown error 41"},                                       \
    {"No message of desired type"},                             \
    {"Identifier removed"},                                     \
    {"Channel number out of range"},                            \
    {"Level 2 not synchronized"},                               \
    {"Level 3 halted"},                                         \
    {"Level 3 reset"},                                          \
    {"Link number out of range"},                               \
    {"Protocol driver not attached"},                           \
    {"No CSI structure available"},                             \
    {"Level 2 halted"},                                         \
    {"Invalid exchange"},                                       \
    {"Invalid request descriptor"},                             \
    {"Exchange full"},                                          \
    {"No anode"},                                               \
    {"Invalid request code"},                                   \
    {"Invalid slot"},                                           \
    {"Unknown error 58"},                                       \
    {"Bad font file format"},                                   \
    {"Device not a stream"},                                    \
    {"No data available"},                                      \
    {"Timer expired"},                                          \
    {"Out of streams resources"},                               \
    {"Machine is not on the network"},                          \
    {"Package not installed"},                                  \
    {"Object is remote"},                                       \
    {"Link has been severed"},                                  \
    {"Advertise error"},                                        \
    {"Srmount error"},                                          \
    {"Communication error on send"},                            \
    {"Protocol error"},                                         \
    {"Multihop attempted"},                                     \
    {"RFS specific error"},                                     \
    {"Bad message"},                                            \
    {"Value too large for defined data type"},                  \
    {"Name not unique on network"},                             \
    {"File descriptor in bad state"},                           \
    {"Remote address changed"},                                 \
    {"Can not access a needed shared library"},                 \
    {"Accessing a corrupted shared library"},                   \
    {".lib section in a.out corrupted"},                        \
    {"Attempting to link in too many shared libraries"},        \
    {"Cannot exec a shared library directly"},                  \
    {"Invalid or incomplete multibyte or wide character"},      \
    {"Interrupted system call should be restarted"},            \
    {"Streams pipe error"},                                     \
    {"Too many users"},                                         \
    {"Socket operation on non-socket"},                         \
    {"Destination address required"},                           \
    {"Message too long"},                                       \
    {"Protocol wrong type for socket"},                         \
    {"Protocol not available"},                                 \
    {"Protocol not supported"},                                 \
    {"Socket type not supported"},                              \
    {"Operation not supported"},                                \
    {"Protocol family not supported"},                          \
    {"Address family not supported by protocol"},               \
    {"Address already in use"},                                 \
    {"Cannot assign requested address"},                        \
    {"Network is down"},                                        \
    {"Network is unreachable"},                                 \
    {"Network dropped connection on reset"},                    \
    {"Software caused connection abort"},                       \
    {"Connection reset by peer"},                               \
    {"No buffer space available"},                              \
    {"Transport endpoint is already connected"},                \
    {"Transport endpoint is not connected"},                    \
    {"Cannot send after transport endpoint shutdown"},          \
    {"Too many references: cannot splice"},                     \
    {"Connection timed out"},                                   \
    {"Connection refused"},                                     \
    {"Host is down"},                                           \
    {"No route to host"},                                       \
    {"Operation already in progress"},                          \
    {"Operation now in progress"},                              \
    {"Stale file handle"},                                      \
    {"Structure needs cleaning"},                               \
    {"Not a XENIX named type file"},                            \
    {"No XENIX semaphores available"},                          \
    {"Is a named type file"},                                   \
    {"Remote I/O error"},                                       \
    {"Disk quota exceeded"},                                    \
    {"No medium found"},                                        \
    {"Wrong medium type"},                                      \
    {"Operation canceled"},                                     \
    {"Required key not available"},                             \
    {"Key has expired"},                                        \
    {"Key has been revoked"},                                   \
    {"Key was rejected by service"},                            \
    {"Owner died"},                                             \
    {"State not recoverable"},                                  \
    {"Operation not possible due to RF-kill"},                  \
    {"Memory page has hardware error"},                         \
}                                                               \

#elif defined(__APPLE__)

#   define Linux 0
#   define Mac 1
#   define MIN 0
#   define MAX 106
#   define STRERROR_ERRORS (char[200][90]) {                \
    {"Undefined error: 0"},                                 \
    {"Operation not permitted"},                            \
    {"No such file or directory"},                          \
    {"No such process"},                                    \
    {"Interrupted system call"},                            \
    {"Input/output error"},                                 \
    {"Device not configured"},                              \
    {"Argument list too long"},                             \
    {"Exec format error"},                                  \
    {"Bad file descriptor"},                                \
    {"No child processes"},                                 \
    {"Resource deadlock avoided"},                          \
    {"Cannot allocate memory"},                             \
    {"Permission denied"},                                  \
    {"Bad address"},                                        \
    {"Block device required"},                              \
    {"Resource busy"},                                      \
    {"File exists"},                                        \
    {"Cross-device link"},                                  \
    {"Operation not supported by device"},                  \
    {"Not a directory"},                                    \
    {"Is a directory"},                                     \
    {"Invalid argument"},                                   \
    {"Too many open files in system"},                      \
    {"Too many open files"},                                \
    {"Inappropriate ioctl for device"},                     \
    {"Text file busy"},                                     \
    {"File too large"},                                     \
    {"No space left on device"},                            \
    {"Illegal seek"},                                       \
    {"Read-only file system"},                              \
    {"Too many links"},                                     \
    {"Broken pipe"},                                        \
    {"Numerical argument out of domain"},                   \
    {"Result too large"},                                   \
    {"Resource temporarily unavailable"},                   \
    {"Operation now in progress"},                          \
    {"Operation already in progress"},                      \
    {"Socket operation on non-socket"},                     \
    {"Destination address required"},                       \
    {"Message too long"},                                   \
    {"Protocol wrong type for socket"},                     \
    {"Protocol not available"},                             \
    {"Protocol not supported"},                             \
    {"Socket type not supported"},                          \
    {"Operation not supported"},                            \
    {"Protocol family not supported"},                      \
    {"Address family not supported by protocol family"},    \
    {"Address already in use"},                             \
    {"Can't assign requested address"},                     \
    {"Network is down"},                                    \
    {"Network is unreachable"},                             \
    {"Network dropped connection on reset"},                \
    {"Software caused connection abort"},                   \
    {"Connection reset by peer"},                           \
    {"No buffer space available"},                          \
    {"Socket is already connected"},                        \
    {"Socket is not connected"},                            \
    {"Can't send after socket shutdown"},                   \
    {"Too many references: can't splice"},                  \
    {"Operation timed out"},                                \
    {"Connection refused"},                                 \
    {"Too many levels of symbolic links"},                  \
    {"File name too long"},                                 \
    {"Host is down"},                                       \
    {"No route to host"},                                   \
    {"Directory not empty"},                                \
    {"Too many processes"},                                 \
    {"Too many users"},                                     \
    {"Disc quota exceeded"},                                \
    {"Stale NFS file handle"},                              \
    {"Too many levels of remote in path"},                  \
    {"RPC struct is bad"},                                  \
    {"RPC version wrong"},                                  \
    {"RPC prog. not avail"},                                \
    {"Program version wrong"},                              \
    {"Bad procedure for program"},                          \
    {"No locks available"},                                 \
    {"Function not implemented"},                           \
    {"Inappropriate file type or format"},                  \
    {"Authentication error"},                               \
    {"Need authenticator"},                                 \
    {"Device power is off"},                                \
    {"Device error"},                                       \
    {"Value too large to be stored in data type"},          \
    {"Bad executable (or shared library)"},                 \
    {"Bad CPU type in executable"},                         \
    {"Shared library version mismatch"},                    \
    {"Malformed Mach-o file"},                              \
    {"Operation canceled"},                                 \
    {"Identifier removed"},                                 \
    {"No message of desired type"},                         \
    {"Illegal byte sequence"},                              \
    {"Attribute not found"},                                \
    {"Bad message"},                                        \
    {"EMULTIHOP (Reserved)"},                               \
    {"No message available on STREAM"},                     \
    {"ENOLINK (Reserved)"},                                 \
    {"No STREAM resources"},                                \
    {"Not a STREAM"},                                       \
    {"Protocol error"},                                     \
    {"STREAM ioctl timeout"},                               \
    {"Operation not supported on socket"},                  \
    {"Policy not found"},                                   \
    {"State not recoverable"},                              \
    {"Previous owner died"},                                \
    {"Interface output queue is full"},                     \
}                                                           \

#else

#   error Cannot determine OS type

#endif

#endif  // SRC_MY_STRING_H_
