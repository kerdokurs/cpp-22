CXXFLAGS := -std=c++20 -Werror -Wall\
	-Wpedantic -Wconversion

.FORCE:

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

prax9: main.cpp raamat.o .FORCE
	g++ $(CXXFLAGS) -o prax9 main.cpp raamat.o
	./prax9

clean:
	rm -f *.o prax9
