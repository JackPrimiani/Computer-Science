CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test: test_vector2d test_point2d
	./test_vector2d && ./test_point2d

test_vector2d: test_vector2d.o vector2d.o
	$(LINK) $@ $^

test_point2d: test_point2d.o point2d.o vector2d.o
	$(LINK) $@ $^

vector2d.o: vector2d.cc vector2d.h
	$(COMPILE) $<

point2d.o: point2d.cc point2d.h vector2d.h
	$(COMPILE) $<

test_vector2d.o: test_vector2d.cc test_vector2d.h vector2d.h
	$(COMPILE) $<

test_point2d.o: test_point2d.cc test_point2d.h point2d.h vector2d.h
	$(COMPILE) $<

clean:
	rm -f *2d *.o
