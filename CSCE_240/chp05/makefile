CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # compile, assemble, link
COMPILE = $(CC) $(FLAGS) -c  # compile, assemble, do not link

01app : 01arrays.o
	$(LINK) $@ $^
01arrays.o : 01arrays.cc
	$(COMPILE) $^

02app : 02dyna_arrays.o
	$(LINK) $@ $^
02dyna_arrays.o : 02dyna_arrays.cc
	$(COMPILE) $^

03app : 03multi_arrays.o
	$(LINK) $@ $^
03multi_arrays.o : 03multi_arrays.cc
	$(COMPILE) $^

04app : 04undef_ind.o
	$(LINK) $@ $^
04undef_ind.o : 04undef_ind.cc
	$(COMPILE) $^

05app : 05str_proc.o
	$(LINK) $@ $^
05str_proc.o : 05str_proc.cc
	$(COMPILE) $^

06app : 06func.o
	$(LINK) $@ $^
06func.o : 06func.cc 06func.h
	$(COMPILE) $<

all : 01app 02app 03app 04app 05app
	@echo All apps made

clean:
	rm ??app *.o
