CC=g++ -Wall -Werror -Wextra -std=c++17
ASAN=-fsanitize=address
GCOV=--coverage
TARGET=test.out
SRCDIR=tests
OBJDIR=bin
SOURCES=$(shell find $(SRCDIR) -type f -name '*.cc')
OBJECTS = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$($(notdir SOURCES):.cc=.o))
LIB=-lgtest -pthread

all: test

test: $(TARGET)
	./$(TARGET) --gtest_brief=1

asan:CC+=$(ASAN)
asan: clean test clean

gcov_report:CC+=$(GCOV)
gcov_report: clean test
	lcov -t "S21 Containers" -o coverage.info -c -d . --rc lcov_branch_coverage=0 --no-external
	genhtml -o report coverage.info --rc lcov_branc_coverage=0
	open ./report/index.html

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJDIR)/*.o $(OBJDIR)/*/*.o $(LIB)

$(OBJDIR)/%.o : $(SRCDIR)/%.cc | $(OBJDIR)
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(LIB)

$(OBJDIR):
	mkdir -p $@

clean:
	@rm -rf $(TARGET) $(OBJDIR)
	@rm -rf *.out *.gcno *.gcov *.gcda objects report *.info
