all: problems

problems: problems.cpp
	clang++ -std=c++11 -stdlib=libc++ -o problems problems.cpp

clean:
	rm -f *.o problems