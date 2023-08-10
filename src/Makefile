CC=g++ -Wall -Werror -Wextra -std=c++17
TARGET=test.out
SRCDIR=tests
OBJDIR=bin
SOURCES=$(shell find $(SRCDIR) -type f -name '*.cc')
OBJECTS = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$($(notdir SOURCES):.cc=.o))
LIB=-lgtest -pthread

all: test

test: $(TARGET)
	./$(TARGET) --gtest_brief=1

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJDIR)/*.o $(OBJDIR)/*/*.o $(LIB)

$(OBJDIR)/%.o : $(SRCDIR)/%.cc | $(OBJDIR)
	@mkdir -p $(@D)
	$(CC) -o $@ -c $(CFLAGS) $< $(LIB)

$(OBJDIR):
	mkdir -p $@

clean:
	@rm -rf $(TARGET) $(OBJDIR)
	@rm -rf *.out *.gcno *.gcov *.gcda objects report *.info
