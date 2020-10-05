CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g

LINK = $(CC) $(FLAGS) -o

COMPILE = $(CC) $(FLAGS) -c

intro : intro.cc
	$(LINK) $@ $^

nullptr : nullptr.cc
	$(LINK) $@ $^

dyna_arrays : dyna_arrays.cc
	$(LINK) $@ $^

multi_arrays : multi_arrays.cc
	$(LINK) $@ $^

clean:
	@rm intro nullptr multi_arrays dyna_arrays 
