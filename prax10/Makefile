CXXFLAGS := -std=c++20 -Werror -Wall\
	-Wpedantic -Wconversion

.FORCE:

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

prax10: main.cpp .FORCE
	g++ $(CXXFLAGS) -o prax10 main.cpp
	./prax10

clean:
	rm -f *.o prax10
