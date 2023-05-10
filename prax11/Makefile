CXXFLAGS := -std=c++20 -Werror -Wall\
	-Wpedantic -Wconversion

.FORCE:

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

prax11: main.cpp .FORCE
	g++ $(CXXFLAGS) -o prax11 main.cpp
	./prax11

clean:
	rm -f *.o prax11
