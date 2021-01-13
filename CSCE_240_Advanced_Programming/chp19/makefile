CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # produce debugging information

LINK = $(CC) $(FLAGS) -o
COMPILE = $(CC) $(FLAGS) -c

days_in_month: days_in_month.o
	$(LINK) $@ $^

days_in_month.o: days_in_month.cc 
	$(COMPILE) $<

clean:
	@rm -f *.o days_in_month
