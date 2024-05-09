CC = g++
CFLAGS = -fopenmp -O3

SRCS := $(wildcard *.cpp)
EXECS := $(SRCS:.cpp=)

all: $(EXECS)

pdf: Sprawozdanie.pdf

Sprawozdanie.pdf: Sprawozdanie.md
	pandoc $< -o $@

%: %.cpp builddir
	$(CC) $(CFLAGS) $< -o build/$@

builddir:
	@mkdir -p build

clean:
	rm -rf build/
