# Must execute make in its parent directory

CC 	= g++

OBJ	= rgbhlr.o rgbstats.o staging.o

## # Debug, linker, and compiling flags

DEBUG_FLAGS		= -Wall -W
CPP_LINK_FLAGS 	= -std=c++11 -o
CPP_COMP_FLAGS 	= -std=c++11 $(DEBUG_FLAGS) -c

## # File path variables
SRC_PATH		= src/
INCL_PATH       = incl/
INCL_PATH_FLAG	= -I incl

## # Header file variables with include paths
HEADER_RGB_HLR	= $(INCL_PATH)rgbhlr.h
HEADERS_RSTAT	= $(INCL_PATH)rgbhlr.h $(INCL_PATH)rgbstats.h

.PHONY: ca

## Executable
cdws : $(OBJ)

	$(CC) $(CPP_LINK_FLAGS) cdws $(OBJ)

# Below are depended-upon objects with relative file paths considered

rgbhlr.o : $(SRC_PATH)rgbhlr.cpp $(HEADER_RGB_HLR)

	$(CC) $(INCL_PATH_FLAG) $(CPP_COMP_FLAGS) $(SRC_PATH)rgbhlr.cpp


rgbstats.o : $(SRC_PATH)rgbstats.cpp $(HEADERS_RSTAT)

	$(CC) $(INCL_PATH_FLAG) $(CPP_COMP_FLAGS) $(SRC_PATH)rgbstats.cpp


staging.o : staging.cpp $(HEADERS_RSTAT)

	$(CC) $(INCL_PATH_FLAG) $(CPP_COMP_FLAGS) staging.cpp

# Remove executable and object files command
ca:
	rm cdws $(OBJ)
