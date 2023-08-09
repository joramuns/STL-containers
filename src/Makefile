CC = g++ -Wall -Werror -Wextra -std=c++17 -g # -fsanitize=address
CFLAGS = -c
OFLAGS = -o
COVFLAGS = -fprofile-arcs -ftest-coverage 
TESTF = -lgtest -lgtest_main -pthread
RUNFILE = test.out 

all: run

gcov_report:TESTF+=$(COVFLAGS)
gcov_report: run
	gcov -f *.gcda
	lcov -t "S21 Containers" -o test.info -c -d . --rc lcov_branch_coverage=0 --no-external
	genhtml -o report test.info  --rc lcov_branch_coverage=0 
	@rm -rf objects *.gcno *.gcda *.gcov *.info
	open report/index.html


run: test
	./$(RUNFILE)

test: objects
	$(CC) $(OFLAGS) $(RUNFILE) --coverage $(TESTF) objects/*.o

objects: test_array test_list test_map test_multiset test_queue test_set test_stack test_vector 
	$(CC) $(CFLAGS) tests/*.cc $(TESTF)
	mv *.o objects/

test_array:
	mkdir -p objects
	$(CC) $(CFLAGS) $(COVFLAGS) tests/$@/*.cc $(TESTF)

test_list:
	$(CC) $(CFLAGS) $(COVFLAGS) tests/$@/*.cc $(TESTF)

test_map:
	$(CC) $(CFLAGS) $(COVFLAGS) tests/$@/*.cc $(TESTF)

test_multiset:
	$(CC) $(CFLAGS) $(COVFLAGS) tests/$@/*.cc $(TESTF)

test_queue:
	$(CC) $(CFLAGS) $(COVFLAGS) tests/$@/*.cc $(TESTF)

test_set:
	$(CC) $(CFLAGS) $(COVFLAGS) tests/$@/*.cc $(TESTF)

test_stack:
	$(CC) $(CFLAGS) $(COVFLAGS) tests/$@/*.cc $(TESTF)

test_vector:
	$(CC) $(CFLAGS) $(COVFLAGS) tests/$@/*.cc $(TESTF)

leaks:
	leaks -atExit -- ./$(RUNFILE)

valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./$(RUNFILE)

style:
	#@cp ../materials/linters/.clang-format ./.clang-format
	@find -iname "*.cc" -o -iname "*.h" | xargs clang-format -i
	@find -iname "*.cc" -o -iname "*.h" | xargs clang-format -i
	@rm clang-format


clean:
	@rm -rf *.out *.o *.gcno *.gcov *.gcda objects report *.info

rebuild: clean all

.PHONY: objects
