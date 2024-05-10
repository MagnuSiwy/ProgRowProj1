CC = g++
CFLAGS = -fopenmp -O3 -g

ICC = icpx
ICFLAGS = $(CFLAGS) -g -debug inline-debug-info

SRCS := $(wildcard *.cpp)
EXECS := $(SRCS:.cpp=)

all: $(EXECS)

pdf: Sprawozdanie.pdf

Sprawozdanie.pdf: Sprawozdanie.md
	pandoc --listing $< -o $@

%: %.cpp builddir vtunedir
	$(ICC) $(ICFLAGS) $< -o build/$@
	vtune -collect hotspots -result-dir=vtune/hs_$@ build/$@
	vtune -collect performance-snapshot --result-dir=vtune/ps_$@ build/$@ 
	vtune -collect threading --result-dir=vtune/th_$@ build/$@ 
	vtune -collect uarch-exploration --result-dir=vtune/ue_$@ build/$@ 

builddir:
	@mkdir -p build

vtunedir:
	@mkdir -p vtune

clean:
	rm -rf build/
	rm -rf vtune/
