

# ________________________________________________________________________________
# VARIABLES
# ________________________________________________________________________________
CXX = gcc

TLPI_DIR = ./lib
THREAD_FLAGS = -pthread

CXXFLAGS = -I$(TLPI_DIR) 
CXXFLAGS += -I./ 

SOURCES = $(wildcard $(TLPI_DIR)/*.c)
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))

# optimization (-O0 none)
OPTZ = -O0

# ________________________________________________________________________________
# TLPI
# ________________________________________________________________________________
%.o: $(TLPI_DIR)/%.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# ________________________________________________________________________________
# CONCURRENCY
# ________________________________________________________________________________
#include "lib/tlpi_hdr.h"
# concurrency.elf: concurrency.c $(OBJS)
	# $(CXX) $(CXXFLAGS) $(OBJS) concurrency.c -o concurrency.elf $(THREAD_FLAGS) 

concurrency.elf: clean concurrency.c 
	$(CXX) $(OPTZ) concurrency.c -o concurrency.elf $(THREAD_FLAGS)
	./concurrency.elf

concurrency.s: clean concurrency.c 
	$(CXX) -S concurrency.c

# ________________________________________________________________________________
# CLEAN
# ________________________________________________________________________________
clean:
	@rm -rf *.o
	@rm -rf *.out
	@rm -rf *.elf
