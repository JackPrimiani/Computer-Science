CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test : comp_geo.o test.cc
	$(LINK) $@ $^

comp_geo.o : comp_geo.cc comp_geo.h
	$(COMPILE) $< 

clean:
	@rm test comp_geo.o
