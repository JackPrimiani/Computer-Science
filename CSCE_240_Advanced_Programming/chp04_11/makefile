CC = g++  # use g++ compiler

# Make a compiler variable for C++ 11 standard flag named FLAGS
FLAGS = -std=c++11
# Append the "all warnings" flag to variable
FLAGS += -Wall

# Create LINK variable to compile, assemble, link, and name
LINK = $(CC) $(FLAGS) -o

# Create variable COMPILE to compile, assemble, but not link
COMPILE = $(CC) $(FLAGS) -c

app1: order.cc
	$(LINK) $@ $^

app2 : separate.o
	$(LINK) $@ $^

separate.o : separate.cc separate.h
	$(COMPILE) $<  # notice the new placeholder 

app3 : pass_by_ref.o
	$(LINK) $@ $^

pass_by_ref.o : pass_by_ref.cc pass_by_ref.h
	$(COMPILE) $<

app4 : overload.o
	$(LINK) $@ $^

overload.o : overload.cc overload.h
	$(COMPILE) $<

app5 : default.o
	$(LINK) $@ $^

default.o : default.cc default.h
	$(COMPILE) $<

all : app1 app2 app3 app4 app5

clean:
	rm app? *.o 
