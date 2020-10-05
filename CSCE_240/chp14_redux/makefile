CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # produce debugging information

LINK = $(CC) $(FLAGS) -o
COMPILE = $(CC) $(FLAGS) -c

test_ppt: test_ppt.cc ppt.o stack.o queue.o
	$(LINK) $@ $^

ppt.o: ppt.cc ppt.h  
	$(COMPILE) $<

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

stack.o : stack.cc stack.h ppt.h
	$(COMPILE) $<
queue.o : queue.cc queue.h ppt.h
	$(COMPILE) $<

clean:
	@rm -f *.o test_stack test_queue test_ppt search
