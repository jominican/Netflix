# Detecting OS
UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC=g++-4.8
    GTEST_LL=-I /usr/local/opt/gtest/include/ -lgtest_main -lpthread
else
    ifeq ($(UNAME_S),Darwin)
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/opt/gtest/lib/ -lgtest_main -lgtest -lpthread
    else
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/lib/ -lgtest_main -lgtest -lpthread
    endif
endif

CC=g++-4.8
LIBS=lib
BIN=bin
SRC=src
TEST=test
CFLAGS= -std=c++11 -ggdb -Wall
GTEST_CPPFLAGS = -Wall -g -I$(LIB) -I$(SRC) -Wextra -pthread -std=gnu++0x


all: hw4


$(BIN)/Movie.o: Movie.cpp Movie.h $(LIBS)/Map* $(LIBS)/Set*
	$(CC) -c -o $(BIN)/Movie.o Movie.cpp $(CFLAGS)
 
$(BIN)/User.o: User.cpp User.h $(LIBS)/Map* $(LIBS)/Set* $(LIBS)/Queue* $/Movie*
	$(CC) -c -o $(BIN)/User.o User.cpp $(CFLAGS)
	
$(BIN)/hw5.o: hw5.cpp $(BIN)/Movie.o $(BIN)/User.o 
	$(CC) -c -o $(BIN)/hw5.o hw5.cpp $(CFLAGS)

$(BIN)/hw4.o: hw4.cpp $(BIN)/Movie.o $(BIN)/User.o $(LIBS)/sha1/sha1.o
	$(CC) -c -o $(BIN)/hw4.o hw4.cpp $(CFLAGS)


# Rules for compiling and running all test cases in 'test folder'

$(BIN)/%.test.o: $(TEST)/%.cpp $(LIBS)/* $(BIN)/.dirstamp
	$(CC) $(GTEST_CPPFLAGS) $(GTEST_LL) -c $< -o $@

$(BIN)/MergeSortTest: $(TEST)/merge_sort_test.cpp 
	$(CC) $(GTEST_CPPFLAGS) $^ $(GTEST_LL) -o $@

$(BIN)/SetTest: $(TEST)/set_test.cpp 
	$(CC) $(GTEST_CPPFLAGS) $^ $(GTEST_LL) -o $@

hw5: $(BIN)/hw5.o $(BIN)/Movie.o $(BIN)/User.o
	$(CC) -g -o hw5 $(BIN)/hw5.o $(BIN)/Movie.o $(BIN)/User.o $(CFLAGS)


hw4: $(BIN)/hw4.o $(BIN)/Movie.o $(BIN)/User.o $(LIBS)/sha1/sha1.o
	$(CC) -g -o hw4 $(BIN)/hw4.o $(BIN)/Movie.o $(BIN)/User.o $(LIBS)/sha1/sha1.o $(CFLAGS)



.PHONY: clean
.PHONY: mergetests
.PHONY: settests

mergetests: $(BIN)/MergeSortTest
	-@$(BIN)/MergeSortTest
	-@echo "--- All Tested!---"
settests: $(BIN)/SetTest
	-@$(BIN)/SetTest
	-@echo "--- All Tested!---"

clean:
	rm -f $(BIN)/*.o hw4 *~
