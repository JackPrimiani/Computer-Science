CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test_shape: test_shape.cc circle.o rectangle.o vector2d.o point2d.o
	$(LINK) $@ $^

circle.o: circle.cc circle.h point2d.h shape.h vector2d.h
	$(COMPILE) $<

rectangle.o: rectangle.cc point2d.h rectangle.h shape.h vector2d.h
	$(COMPILE) $<

vector2d.o: vector2d.cc vector2d.h
	$(COMPILE) $<

point2d.o: point2d.cc point2d.h vector2d.h
	$(COMPILE) $<

clean:
	rm -f *.o test_shape
