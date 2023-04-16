CC=gcc 
ifeq ($(shell uname), Linux)
	CHKFLAGS=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHKFLAGS=-lcheck
endif

all: my_string.a

clean:
	@rm -rf *.o *.gcda *.gcno *.html *.css *.out *.a test gcov_report

my_string.o: my_string.c
	gcc -o my_string.o $^ -c

my_string.a: my_string.o
	ar crs $@ $^

test:
	$(CC) my_string.c -c -o my_string_test.o
	$(CC) my_test.c -c -o test_test.o
	$(CC) test_test.o my_string_test.o -o $@ $(CHKFLAGS)
	./$@

gcov_report:
	$(CC) --coverage my_string.c -c -o my_string_coverage.o
	$(CC) my_test.c -c -o test_coverage.o
	$(CC) my_string_coverage.o test_coverage.o -o $@ $(CHKFLAGS) -lgcov
	./$@
	gcovr --html --html-details -o report.html
