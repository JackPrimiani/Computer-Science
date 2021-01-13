CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # produce debugging information

LINK = $(CC) $(FLAGS) -o
COMPILE = $(CC) $(FLAGS) -c

search: search.cc queue.o stack.o
	$(LINK) $@ $^

test_stack: test_stack.o stack.o
	$(LINK) $@ $^
test_queue: test_queue.o queue.o
	$(LINK) $@ $^

test_stack.o : test_stack.cc stack.h
	$(COMPILE) $<
test_queue.o : test_queue.cc queue.h
	$(COMPILE) $<

stack.o : stack.cc stack.h
	$(COMPILE) $<
queue.o : queue.cc queue.h
	$(COMPILE) $<

clean:
	@rm *.o test_stack test_queue search
