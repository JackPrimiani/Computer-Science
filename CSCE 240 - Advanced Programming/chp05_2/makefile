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

05app : 05func.o
	$(LINK) $@ $^
05func.o : 05func.cc
	$(COMPILE) $^

06app : 06str_proc.o
	$(LINK) $@ $^
06str_proc.o : 06str_proc.cc
	$(COMPILE) $^

all : 01app 02app 03app 04app 05app
	@echo All apps made

clean:
	rm 01arrays.o 01app 02dyna_arrays.o 02app 03multi_arrays.o \
      03app 04undef_ind.o 04app 05func.o 05app 06str_proc.o 06app
