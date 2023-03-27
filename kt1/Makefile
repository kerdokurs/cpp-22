CXXFLAGS := -std=c++20 -Werror -Wall\
	-Wpedantic -Wconversion

.PHONY: run clean

run: kt1
	./kt1

kt1: videod.o asfalt.o
	g++ $(CXXFLAGS) -o kt1 main.cpp $^

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f *.o kt1
