
CXX      := clang++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror -O2
INCLUDE  := -I../../thermoModel/specie/customModel/
BIN := thermoTest

all: $(BIN)

% : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

run: 
	./$(BIN)

clean:
	rm $(BIN) *.dat
