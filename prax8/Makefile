CXXFLAGS := -std=c++20# -Werror -Wall\
	-Wpedantic -Wconversion

.FORCE:

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

prax8: main.cpp .FORCE
	g++ $(CXXFLAGS) -o prax8 main.cpp
	./prax8

clean:
	rm -f *.o prax8
