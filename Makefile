CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

SRCDIR = D:/projects/MP/src
TESTDIR = D:/projects/MP/test
GTESTDIR = D:/projects/MP/googletest

INCFLAGS = -I$(SRCDIR) -I$(GTESTDIR)/include
LIBFLAGS = -L$(GTESTDIR)/lib -lgtest -lgtest_main -pthread

TEST_EXECUTABLE = testa_velha

all: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TESTDIR)/$(TEST_EXECUTABLE).cpp $(SRCDIR)/velha.c $(SRCDIR)/velha.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -o $@ $< $(SRCDIR)/velha.c $(LIBFLAGS)

clean:
	rm -f $(TEST_EXECUTABLE)

run: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

coverage: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)
	gcov $(TEST_EXECUTABLE).cpp

cppcheck:
	cppcheck --enable=warning $(SRCDIR)/*.c $(TESTDIR)/*.cpp

valgrind: $(TEST_EXECUTABLE)
	valgrind --leak-check=full ./$(TEST_EXECUTABLE)
