all: problems

problems: problems.cpp
	clang++ -O3 -std=c++11 -stdlib=libc++ -o problems problems.cpp

clean:
	rm -f *.o problems