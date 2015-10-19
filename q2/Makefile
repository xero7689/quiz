CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99
PERF_FLAGS = stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,cs,branch-misses,dTLB-load-misses,dTLB-store-misses,iTLB-loads,iTLB-load-misses
SOURCE_common = main.c
EXEC = iterative iterative_bin  recursive

GENARTE_STR := perl genRndStr.pl
STRING_LENGTH = 100 1000 10000 100000
CHAR := A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\
    	a b c d e f g h i j k l m n o p q r s t u v w x y z

all: $(EXEC)

iterative: iterative.c timer.c
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -DTIMER="\"timer.h"\" -o $@ $(SOURCE_common) $^

iterative_bin: iterative_bin.c timer.c
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -DTIMER="\"timer.h"\" -o $@ $(SOURCE_common) $^

recursive: recursive.c timer.c
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -DTIMER="\"timer.h"\" -o $@ $(SOURCE_common) $^

run: $(EXEC)
	$(foreach exec, $^, $(foreach len, $(STRING_LENGTH), $(foreach char, $(CHAR), ./$(exec) `$(GENARTE_STR) $(len)` $(char);)))

perf_iterative: iterative
	perf $(PERF_FLAGS) ./$<

perf_iterative_bin: iterative_bin
	perf $(PERF_FLAGS) ./$<

perf_recursive: recursive
	perf $(PERF_FLAGS) ./$<

clean_txt:
	$(RM) *.txt

clean:
	$(RM) $(EXEC) *.o perf.* *.txt
