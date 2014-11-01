all: problem1 problem2 problem3 problem4

problem1: problem1.cpp
	clang++ -O3 -std=c++11 -stdlib=libc++ -o problem1 problem1.cpp

problem2: problem2.cpp
	clang++ -O3 -std=c++11 -stdlib=libc++ -o problem2 problem2.cpp

problem3: problem3.cpp
	clang++ -O3 -std=c++11 -stdlib=libc++ -o problem3 problem3.cpp

problem4: problem4.cpp
	clang++ -O3 -std=c++11 -stdlib=libc++ -o problem4 problem4.cpp

clean:
	rm -f *.o problem1 problem2 problem3 problem4