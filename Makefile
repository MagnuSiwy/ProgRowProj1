CC = g++
CFLAGS = -fopenmp -O3

SRCS := $(wildcard *.cpp)
EXECS := $(SRCS:.cpp=)

all: $(EXECS)

%: %.cpp builddir
	$(CC) $(CFLAGS) $< -o build/$@

builddir:
	mkdir build

clean:
	rm -rf build/
