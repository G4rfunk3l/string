#include "my_string.h"

void *my_memchr(const void *str, int c, my_size_t n) {
    void *p = my_NULL;
    unsigned char *s = (unsigned char*)str;

    while (n--) {
        if (*s == c) {
            p = s;
            break;
        }
        s++;
    }

  return p;
}


int my_memcmp(const void *str1, const void *str2, my_size_t n) {
    char res = 0;

    if (n == 0) {
        res = 0;
    }
    for (int i = 0; n--; i++) {
        if (((char*)str1)[i] != ((char*)str2)[i]) {
            res = ((char*)str1)[i] - ((char*)str2)[i];
            break;
        }
    }

    return res;
}


void *my_memcpy(void *dest, const void *src, my_size_t n) {
    char *tdest = (char*)dest;
    const char *tsrc = (const char*)src;

    for (my_size_t i = 0; i < n; i++) {
    tdest[i] = tsrc[i];
    }

    return dest;
}


void *my_memmove(void *dest, const void *src, my_size_t n) {
    char *tdest = (char*)dest;
    const char *tsrc = (const char*)src;
    my_size_t i = 0;

    if (dest <= src) {
        for (i = 0; i < n; i++) {
            tdest[i] = tsrc[i];
        }
    } else {
        for (i = n; i > 0; i--) {
           tdest[i-1] = tsrc[i-1];
        }
    }

    return dest;
}


void *my_memset(void *str, int c, my_size_t n) {
    void *p = str;

    for (int i = 0; n--; i++) {
        ((char*)str)[i] = (unsigned char)c;
    }

    return p;
}


char *my_strcat(char *dest, const char *src) {
    char *res = dest;

    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';

    return res;
}


char *my_strncat(char *dest, const char *src, my_size_t n) {
    char *res = dest;

    while (*dest) {
        dest++;
    }
    while (*src && n) {
        --n;
        *dest++ = *src++;
    }
    *dest = '\0';

    return res;
}


char *my_strchr(const char *str, int c) {
    char *p = my_NULL;

      if (c == 256) {
        int str_len = (int)my_strlen(str);
        p = (char*)str + str_len;
      } else {
        c = (unsigned char)c;
      }
      while (*str && !p) {
        if (*str == c) {
          p = (char*)str;
        }
        str++;
      }

      return p;
}


int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }

    return ((unsigned char)*str1 - (unsigned char)*str2);
}


int my_strncmp(const char *str1, const char *str2, my_size_t n) {
    int res = 0;

    while (n && *str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
        n--;
    }
    if (n == 0) {
        res = 0;
    } else {
        res = (unsigned char)*str1 - (unsigned char)*str2;
    }

    return res;
}


char *my_strcpy(char *dest, const char *src) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}


char *my_strncpy(char *dest, const char *src,  my_size_t n) {
    my_size_t i = 0;

    while (n > 0 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
        n--;
    }
    if (n > 0 && src[i] == '\0') {
        dest[i] = '\0';
        i++;
        my_size_t m = my_strlen(&dest[i]);
        while (m > 0) {
            dest[i] = ' ';
            i++;
            m--;
        }
    }

    return dest;
}


my_size_t my_strcspn(const char *str1, const char *str2) {
    int str_rejected_len = 0, str1_len, str2_len, first_occ = 1;
    str1_len = (int)my_strlen(str1);
    str2_len = (int)my_strlen(str2);

    for (int i = 0; i < str1_len && first_occ; i++) {
        for (int j = 0; j < str2_len && first_occ; j++) {
            if (str1[i] == str2[j]) {
                first_occ = 0;
            } else {
                str_rejected_len += 1;
            }
        }
    }
    if (!str2_len) {
        str_rejected_len = str1_len;
        str2_len = 1;
    }

    return str_rejected_len / str2_len;
}


char *my_strerror(int errnum) {
    static char s[100];
    my_memset(s, 0, 100);
    char *p = my_NULL;

    if (Mac) {
        if (errnum >= MIN && errnum <= MAX) {
            p = STRERROR_ERRORS[errnum];
        } else {
            my_sprintf(s, "Unknown error: %d", errnum);
            p = s;
        }
    } else if (Linux) {
        if (errnum >= MIN && errnum <= MAX) {
            p = STRERROR_ERRORS[errnum];
        } else {
             my_sprintf(s, "Unknown error %d", errnum);
             p = s;
        }
    }

    return p;
}


my_size_t my_strlen(const char *str) {
    my_size_t str_len = 0;

    while (*str++) {
        str_len += 1;
    }

    return str_len;
}


char *my_strpbrk(const char *str1, const char *str2) {
    void *p = my_NULL;
    my_size_t str_pbrk = 0;
    my_size_t n = 0;

    for (my_size_t i = 0; i < my_strlen(str1); i++) {
        for (my_size_t j = 0; j < my_strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                str_pbrk = i + 1;
                break;
            }
        }
        if ((str_pbrk < n) || (n == 0)) {
            n = str_pbrk;
        }
    }

    if (n != 0) {
    p = (char*)str1 + n - 1;
    }

    return p;
}


char *my_strrchr(const char *str, int c) {
  char *p = my_NULL;

  c = (unsigned char)c;
  while (*str) {
    if (*str == c) {
      p = (char*)str;
    }
    str++;
  }
  if (c == '\0') {
    p = (char*)str;
  }

  return p;
}


my_size_t my_strspn(const char *str1, const char *str2) {
    my_size_t str_spn = 0;
    my_size_t n = 0;

    for (my_size_t i = 0; i < my_strlen(str1); i++) {
        for (my_size_t j = 0; j < my_strlen(str2); j++) {
            if (str1[i] == str2[j]) {
            str_spn++;
            }
        }
        if (n == str_spn) {
            break;
        } else {
            n++;
            str_spn = n;
        }
    }

    return n;
}


char *my_strstr(const char *haystack, const char *needle) {
  char *p = my_NULL;
  const char *needle_st = needle;

  if (my_strlen(needle) == 0) {
    p = (char*)haystack;
  }
  while (*haystack && *needle) {
    if (*haystack == *needle) {
      if (!p) {
        p = (char*)haystack;
      }
      needle++;
    } else {
      p = my_NULL;
      needle = needle_st;
    }
    haystack++;
  }
  if (*needle) {
    p = my_NULL;
  }

  return p;
}


char *my_strtok(char *str, const char *delim) {
    static char * ptr = my_NULL;
    int ptr_is_null = 1;

    if (str) {
        for (ptr = str; my_strchr(delim, *ptr); ) {
            ++ptr;
        }
    }
    if (ptr == my_NULL || *ptr == '\0') {
        ptr_is_null = 0;
        ptr = my_NULL;
    }

    str = ptr;

    while (ptr_is_null && *ptr && !my_strchr(delim, *ptr)) {
        ++ptr;
    }
    while (ptr_is_null && *ptr && my_strchr(delim, *ptr)) {
        *ptr++ = '\0';
    }

    return str;
}


void *my_trim(const char *src, const char *trim_chars) {
    static char edited_src[300];
    int src_len = my_strlen(src);
    int str_st = 0, str_end = src_len, sym_num = 0;

    my_memset(edited_src, 0, 300);

    if (my_strlen(trim_chars) == 0) {
         my_strcpy((char*)trim_chars, " \t\n\r\0\v");
    }

    for (; my_strchr(trim_chars, src[str_st]) && src[str_st];) {
        str_st++;
    }

    for (; my_strrchr(trim_chars, src[src_len]) && src_len >= str_st;) {
        str_end = src_len--;
    }

    sym_num = str_end - str_st;

    my_strncat(edited_src, &src[str_st], sym_num);
    my_strcat(edited_src, "\0");

    return edited_src;
}


void *my_insert(const char *str, const char *insertion, my_size_t index) {
     my_size_t insertion_len = my_strlen(insertion);
     my_size_t str_len = my_strlen(str);
     static char res[2000];
     my_memset(res, '\0', 2000);
     char *pstr = (char*)str;

     if (index <= str_len) {
         my_memmove(res, pstr, index);
         my_memmove(&res[index + insertion_len], &pstr[index], str_len - index);
         my_memmove(&res[index], insertion, insertion_len);
         res[insertion_len + str_len] = '\0';
    }

    return res;
}


void *my_to_upper(const char *str) {
    int i = 0, str_len = (int)my_strlen(str);
    static char res[2000];
    my_memset(res, '\0', 2000);
    char *pstr = (char*)str;

    for (; i < str_len; i++) {
        if (pstr[i] >= 'a' && pstr[i] <= 'z') {
            res[i] = pstr[i] ^ ' ';
            continue;
        }
        res[i] = pstr[i];
    }
    res[i] = '\0';

    return res;
}


void *my_to_lower(const char *str) {
    int i = 0, str_len = (int)my_strlen(str);
    static char res[2000];
    my_memset(res, '\0', 2000);
    char *pstr = (char*)str;

    for (; i < str_len; i++) {
        if (pstr[i] >= 'A' && pstr[i] <= 'Z') {
            res[i] = pstr[i] ^ ' ';
            continue;
        }
        res[i] = pstr[i];
    }
    res[i] = '\0';

    return res;
}


int my_sprintf(char *str, const char *format, ...) {
    int str_index = 0, flag_space = 0, flag_plus = 0, flag_minus = 0, number_precision = 6;
    int flag_precision = 0, flag_h = 0, flag_l = 0, width;
    char flag[100] = {0}, temp[100] = {0}, precision[100] = {0}, length[100] = {0};
    va_list list;
    va_start(list, format);

    while (*format) {
        if (*format++ == '%') {
            flag_length_width_filling(temp, flag, length, precision, &number_precision, &flag_precision,
                    (char**)&format);
            flags(flag, length, &flag_space, &flag_plus, &flag_minus, &flag_h, &flag_l);
            width = char_to_int(temp);
            switch (*format++) {
                case '%':
                    str[str_index++] = '%';
                    break;
                case 'D':
                case 'd':
                case 'i':
                    str_index += sprintf_digit(str, &list, str_index, number_precision, flag_space,
                            flag_plus, flag_minus, flag_precision, width, flag_h, flag_l);
                    break;
                case 'u':
                    str_index += sprintf_unsigned(str, &list, str_index, number_precision, flag_minus, width,
                            flag_h, flag_l);
                    break;
                case 'f':
                    str_index += sprintf_float(str, &list, str_index, &number_precision, flag_space,
                            flag_plus, flag_minus, flag_precision, width, flag_l);
                    break;
                case 'c':
                    str_index += sprintf_char(str, &list, str_index, flag_minus, width);
                    break;
                case 's':
                    str_index += sprintf_string(str, &list, str_index, number_precision, flag_minus,
                            flag_precision, width);
                    break;
                default:
                    str[str_index++] = *(format-1);
            }
        } else {
            str[str_index++] = *(format-1);
        }
    }
    str[str_index] = '\0';
    va_end(list);
    return my_strlen(str);
}


int sprintf_float(char *str, va_list *list, int str_index, int *number_precision, int flag_space,
                  int flag_plus, int flag_minus, int flag_precision, int width, int flag_l) {
    char int_float_number[100] = {0};
    int written_chars_count = 0;
    int flag_float = 0, flag_double = 0, flag_unnegatory = 0;
    long double f_digit = lenght_float(list, flag_l, &flag_float, &flag_double);

    if (f_digit < 0) {
        f_digit *= -1;
        my_strcat(int_float_number, "-");
    }

    long int int_part = (long int)f_digit;
    long double float_part = (f_digit - (long double)int_part);
    if (!flag_precision) {
        *number_precision = 6;
    }
    char *float_part_arr = float_to_char(float_part, *number_precision);

    rounding(float_part_arr, &int_part, *number_precision, flag_float, flag_double);

    char *int_part_arr = int_to_char(int_part);
    float_filling(int_float_number, int_part_arr, float_part_arr, *number_precision);

    int align = width - (int)my_strlen(int_float_number);
    if (int_float_number[0] != '-' && (flag_space || flag_plus)) {
        align--;
        flag_unnegatory = 1;
    }
    if (!flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }
     if (flag_unnegatory && (flag_space || flag_plus)) {
        plus_or_space(str, &str_index, flag_plus, &written_chars_count);
     }

    for (int i = 0; int_float_number[i]; i++) {
        str[str_index++] = int_float_number[i];
        written_chars_count++;
    }
    if (flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }
    str[str_index] = '\0';

    return written_chars_count;
}


int sprintf_unsigned(char *str, va_list *list, int str_index, int number_precision, int flag_minus,
                     int width, int flag_h, int flag_l) {
    long unsigned int unsigned_digit = lenght_unsigned(list, flag_h, flag_l);
    char *p = unsigned_to_char(unsigned_digit);
    int written_chars_count = 0;

    if (number_precision > (int)my_strlen(p)) {
        char temp[100];
        my_memset(temp, '0', number_precision);
        my_strcpy(&temp[number_precision - my_strlen(p)], p);
        my_strcpy(p, temp);
    }
    int align = width - my_strlen(p);

    if (!flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }
    while (*p) {
        str[str_index++] = *p++;
        written_chars_count++;
    }
    if (flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }

    str[str_index] = '\0';

    return written_chars_count;
}


int sprintf_string(char *str, va_list *list, int str_index, int number_precision,
                   int flag_minus, int flag_precision, int width) {
    char *string_ini = va_arg(*list, char*);
    char string[100];
    my_strcpy(string, string_ini);
    int written_chars_count = 0;

    if (flag_precision && number_precision < (int)my_strlen(string)) {
        my_memset(&string[number_precision], '\0', 1);
    }
    int align = width - (int)my_strlen(string);

    if (!flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }
     for (int i = 0; string[i]; i++) {
        str[str_index++] = string[i];
        written_chars_count++;
    }
    if (flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }

    str[str_index] = '\0';

    return written_chars_count;
}


int sprintf_char(char *str, va_list *list, int str_index, int flag_minus, int width) {
    char ch = va_arg(*list, int);
    int written_chars_count = 1;
    int align = width - 1;

    if (!flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }
    str[str_index++] = ch;
    if (flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }

    str[str_index] = '\0';

    return written_chars_count;
}


int sprintf_digit(char *str, va_list *list, int str_index, int number_precision, int flag_space,
                  int flag_plus, int flag_minus, int flag_precision, int width, int flag_h, int flag_l) {
    long int digit = lenght_digit(list, flag_h, flag_l);
    char *p = int_to_char(digit);
    int written_chars_count = 0;

    if (number_precision > (int)my_strlen(p)) {
        char temp[100];
        my_memset(&temp[0], '0', number_precision);
        my_strcpy(&temp[number_precision - (int)my_strlen(p)], p);
        my_strcpy(p, temp);
    }
    int align = width - (int)my_strlen(p);

    if (digit >= 0 && (flag_space || flag_plus)) {
        align--;
    }
    if (flag_precision && digit == 0 && number_precision == 0) {
        p[0] = '\0';
        align++;
    }
    if (!flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }
    if (digit >= 0 && (flag_space || flag_plus)) {
        plus_or_space(str, &str_index, flag_plus, &written_chars_count);
    }
    while (*p) {
        str[str_index++] = *p++;
        written_chars_count++;
    }
    if (flag_minus) {
        widths(str, &str_index, &align, &written_chars_count);
    }
    str[str_index] = '\0';

    return written_chars_count;
}


int flag_length_width_filling(char *temp, char *flag, char *length, char *precision, int *number_precision,
                              int *flag_precision, char **format) {
    int i_local = 0;
    *number_precision = 0;
    *flag_precision = 0;
    char *format_local = *format;

    while (*format_local == ' ' || *format_local == '+' || *format_local == '-') {
        flag[i_local++] = *format_local;
        format_local++;
    }
    flag[i_local] = '\0';
    i_local = 0;

    while (*format_local >= '0' && *format_local <= '9') {
        temp[i_local++] = *format_local;
        format_local++;
    }
    temp[i_local] = '\0';
    i_local = 0;

    if (*format_local == '.') {
        *flag_precision = 1;
        format_local++;
        while (*format_local >= '0' && *format_local <= '9') {
            precision[i_local++] = *format_local;
            format_local++;
            }
    }
    precision[i_local] = '\0';
    i_local = 0;
    *number_precision = char_to_int(precision);

    while (*format_local == 'h' || *format_local == 'l') {
        length[i_local++] = *format_local;
        format_local++;
    }
    length[i_local] = '\0';

    *format = format_local;

    return 0;
}


int flags(char *flag, const char *lenght, int *flag_space, int *flag_plus, int *flag_minus,
        int *flag_h, int *flag_l) {
    *flag_space = 0;
    *flag_plus = 0;
    *flag_minus = 0;
    *flag_h = 0;
    *flag_l = 0;

    while (*flag) {
    if (*flag == ' ') {
        *flag_space = 1;
    }
    if (*flag == '+') {
        *flag_plus = 1;
    }
    if (*flag == '-') {
        *flag_minus = 1;
    }
    flag++;
    }

    if (*lenght == 'h') {
        *flag_h = 1;
    } else if (*lenght == 'l') {
        *flag_l = 1;
    }

    return 0;
}


int widths(char *str, int *str_index, int *align, int *written_chars_count) {
    int align_local = *align;
    int str_local = *str_index;
    int count_local = *written_chars_count;

    while (align_local > 0) {
        str[str_local++] = ' ';
        align_local--;
        count_local++;
    }

    *align = align_local;
    *str_index = str_local;
    *written_chars_count = count_local;

    return 0;
}


int plus_or_space(char *str, int *str_index, int flag_plus, int *written_chars_count) {
    int str_local = *str_index;
    int count_local = *written_chars_count;

    if (flag_plus) {
        str[str_local] = '+';
    } else {
        str[str_local] = ' ';
    }

    str_local++;
    count_local++;
    *str_index = str_local;
    *written_chars_count = count_local;

    return 0;
}


long int lenght_digit(va_list *list, int flag_h, int flag_l) {
    long int digit;

    if (flag_l) {
        digit = va_arg(*list, long int);
    } else if (flag_h) {
        digit =  (short int) va_arg(*list, int);
    } else {
        digit = va_arg(*list, int);
    }

    return digit;
}


long unsigned int lenght_unsigned(va_list *list, int flag_h, int flag_l) {
    long unsigned int digit;

    if (flag_l) {
        digit = va_arg(*list, long unsigned int);
    } else if (flag_h) {
       digit =  (short unsigned) va_arg(*list, unsigned int);
    } else {
        digit = va_arg(*list, unsigned int);
    }

    return digit;
}


long double lenght_float(va_list *list, int flag_l, int *flag_float, int *flag_double) {
    long double f_digit;
    *flag_float = 0;
    *flag_double = 0;

    if (flag_l) {
        f_digit = va_arg(*list, double);
        *flag_double = 1;
    } else {
        f_digit = va_arg(*list, double);
        *flag_float = 1;
    }

    return f_digit;
}


int rounding(const char *float_part_arr, long int *int_part, int number_precision, int flag_float,
        int flag_double) {
    if (number_precision == 0) {
        int zero_digits = 0;

        if (flag_float) {
            for (int i = 1; i < 7; i++) {
                if (float_part_arr[i] > '0') {
                    zero_digits = 1;
                }
            }
        }

        if (flag_double) {
            for (int i = 1; i < 17; i++) {
                if (float_part_arr[i] > '0') {
                    zero_digits = 1;
                }
            }
        }

        if ( ((*int_part%10)%2 == 0 && float_part_arr[0] == '5' && zero_digits) ||
             ((*int_part%10)%2 == 1 && float_part_arr[0] >= '5')) {
            *int_part += 1;
        }
    }

    return 0;
}


int float_filling(char *int_float_number, char *int_part_arr, char *float_part_arr,
        int number_precision) {
    my_strcat(int_float_number, int_part_arr);

    if (number_precision) {
        my_strcat(int_float_number, ".");
    }

    my_strncat(int_float_number, float_part_arr, number_precision);

    return 0;
}


char *float_to_char(long double number, int number_precision) {
    static char str3[100];
    int i = 0;

    long double number_cpy = number;

    for (; i < 16; i++) {
        number *= 10;
        char float_digit = (long long int)number%10;
        str3[i] = (char)float_digit + '0';
    }

    i = number_precision;

    long int over_last_digit = ((unsigned long long int)(number_cpy* my_pow(10, number_precision+1)))%10;

    if (over_last_digit >= 5) {
        if (i) {
            i--;
        }
        if (str3[i] >= '0' && str3[i] < '9') {
            str3[i] += 1;
        } else if (str3[i] == '9') {
            while (str3[i] == '9') {
                str3[i--] = '0';
            }
            str3[i] += 1;
        }
    }

    my_strcat(str3, "\0");

    return str3;
}


char *unsigned_to_char(long unsigned number) {
    static char str2[50];
    my_memset(str2, 0, 50);
    long unsigned temp_number = number, i = 0;

    if (number == 0) {
        str2[i++] = '0';
    }

    for (; temp_number; i++) {
        char part_number = (char)(temp_number%10) + '0';
        str2[i] = part_number;
        temp_number /= 10;
    }

    for (long unsigned int temp, j = 0; j < (i + (i%2))/2; j++) {
        temp = str2[j];
        str2[j] = str2[i-1-j];
        str2[i-1-j] = temp;
    }

    str2[i] = '\0';

    return str2;
}


char *int_to_char(long long int number) {
    static char str1[50];
    my_memset(str1, 0, 50);
    long long int temp_number = number, i = 0;

    if (number < 0) {
        temp_number *= -1;
    } else if (number == 0) {
        str1[i++] = '0';
    }

    for (; temp_number; i++) {
        char part_number = (char)(temp_number%10) + '0';
        str1[i] = part_number;
        temp_number /= 10;
    }

    if (number < 0) {
        str1[i++] = '-';
    }

    for (long long int temp, j = 0; j < (i + (i%2))/2; j++) {
        temp = str1[j];
        str1[j] = str1[i-1-j];
        str1[i-1-j] = temp;
    }

    str1[i] = '\0';

    return str1;
}


int char_to_int(char* str) {
    int res = 0;
    int str_len = (int)my_strlen(str);
    int temp = str_len;

    for (int i = 0; i < temp; i++) {
         res += ((int)str[i] - '0') * my_pow(10, str_len - 1);
         str_len--;
    }

    return res;
}


long long int my_pow(long long int number, long long int power) {
    long long int temp_number = number;

    if (power != 0) {
        while (--power) {
        number *= temp_number;
        }
    } else {
        number = 1;
    }

    return number;
}


void my_clean(char *str, char *src, my_size_t size) {
    my_memset(str, '\0', size);
    my_memset(src, '\0', size);
}
