CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test : draw_card
	python3 test_draw_card.py

draw_card : draw_card.cc
	$(LINK) $@ $^ 

clean:
	@rm draw_card
