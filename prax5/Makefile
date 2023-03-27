CXXFLAGS := -std=c++20 -Werror -Wall\
	-Wpedantic -Wconversion

.FORCE:

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

prax5: main.cpp PahupidiArv.o .FORCE
	g++ $(CXXFLAGS) -o prax5 main.cpp PahupidiArv.o
	./prax5

clean:
	rm -f *.o prax5
