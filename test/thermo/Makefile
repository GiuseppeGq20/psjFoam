
CXX      := g++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror -O2
INCLUDE  := -I../../thermoModel/specie/customModel/
BIN := thermoTest.out thermoArrays.out

all: $(BIN)

%.out : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

foamtest: thermoTestFoam.cpp
	$(CXX) -std=c++14 -pthread -DOPENFOAM=2206 -DWM_DP -DWM_LABEL_SIZE=32 -Wall \
		-Wextra -Wold-style-cast -Wnon-virtual-dtor -Wno-unused-parameter \
		-Wno-invalid-offsetof -Wno-attributes -Wno-unknown-pragmas -O3 -floop-optimize \
		-falign-loops -falign-labels -falign-functions -falign-jumps \
		-DNoRepository -ftemplate-depth-100  -DFULLDEBUG -g -O0 \
		-iquote. -IlnInclude \
		$(INCLUDE) \
		-I/usr/lib/openfoam/openfoam2206/src/OpenFOAM/lnInclude \
		-I/usr/lib/openfoam/openfoam2206/src/OSspecific/POSIX/lnInclude   -fPIC $< -o $@

#run: 
#	./$(BIN)

clean:
	rm -r $(BIN) *.dat *.H *.dSYM
