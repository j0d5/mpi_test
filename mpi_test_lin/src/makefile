########################################
##                                    ##
## Makefile for mpiTest               ##
##                                    ##
########################################

# Versionsnummer
VERSION = 0.01
# Compiler
# CC = $(shell which mpic++)
CC = mpicc

# Compilerflags
CFLAGS = -Wall -std=c99 -g -DVERSION=\"$(VERSION)\"

# Linkerflags
LDFLAGS  = 
PROGNAME = ../mpiTest
SRC  = main.c
OBJS = main.o

all: hello $(OBJS) finish
	@$(CC) $(CFLAGS) -o $(PROGNAME) $(OBJS) $(LDFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $<

# Phony targets, will always be executed
.PHONY: clean hello finish
clean:
	@echo
	@echo "    cleaning dirs..."
	@echo
	@rm -f $(PROGNAME) $(OBJS)
	@echo
	@echo "    ...finished."
	@echo

hello:
	@echo
	@echo "    building" $(PROGNAME) $(VERSION) "..."
	@echo

finish:
	@echo
	@echo "    ...finished."
	@echo
