CC ?= gcc
CFLAGS_common ?= -pg -O0 -Wall -std=gnu99
PERF_FLAGS = stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,cs,branch-misses,dTLB-load-misses,dTLB-store-misses,iTLB-loads,iTLB-load-misses
SOURCE_common = main.c
EXEC = iterative recursive

all: $(EXEC)

iterative: iterative.c bst.c timer.c
	$(CC) $(CFLAGS_common) \
	    -DIMPL="\"$@.h\""  \
	    -DTIMER="\"timer.h\"" \
	    -DBST="\"bst.h\"" \
	    -o $@ $(SOURCE_common) $^

recursive: recursive.c bst.c timer.c
	$(CC) $(CFLAGS_common) \
	    -DIMPL="\"$@.h\""  \
	    -DTIMER="\"timer.h\""\
	    -DBST="\"bst.h\"" \
	    -o $@ $(SOURCE_common) $^

run: $(EXEC)
	./iterative
	@echo "=================="
	./recursive

perf_iterative: iterative
	perf $(PERF_FLAGS) ./$<

perf_recursive: recursive
	perf $(PERF_FLAGS) ./$<

clean:
	$(RM) $(EXEC) *.o perf.* gmon.out
