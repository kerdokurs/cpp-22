CXXFLAGS := -std=c++20 -Werror -Wall\
	-Wpedantic -Wconversion

.FORCE:

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

prax6: main.cpp osalejad_tulemused.o .FORCE
	g++ $(CXXFLAGS) -o prax6 main.cpp osalejad_tulemused.o
	./prax6

clean:
	rm -f *.o prax6
