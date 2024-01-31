##
## EPITECH PROJECT, 2024
## B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS = -lncurses

SRCDIR = src
OBJDIR = obj
BINDIR = .

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXECUTABLE = $(BINDIR)/MyGKrellm

all: build $(EXECUTABLE)

build:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all build clean fclean re
