#Work directories
SRCDIR 		:= src
OBJDIR 		:= obj
LIBDIR 		:= lib
INCLUDEDIR 	:= include
TESTSDIR	:= tests
BUILDDIR	:= build

#Set compiler options
CC 			:= clang -std=c17
CFLAGS		:= -Wall -Weverything --extra-warnings
DFLAGS		:= -glldb -fdebug-macro 
SANITOPTS	:= -fsanitize=address,return,undefined
OFLAGS		?=
CPPFLAGS	?= 
INCDIRS		?= 

# Filetype specifics
SRCEXT		:= c
HEADEREXT	:= h
OBJEXT		:= o
TARGETNAME	:= cutypes

#Dependencies and files
DEPS		:= $(wildcard $(INCLUDEDIR)/*.$(HEADEREXT))
SRCS		:= $(wildcard $(SRCDIR)/*.$(SRCEXT))
TESTS		:= $(wildcard $(TESTSDIR)/*.$(SRCEXT))
OBJS		?= 

.phony: clean all debug test

all: debug test

clean:
	rm -rf ./*.o 	$(OBJDIR)/*.o
	rm -rf ./*.out 	$(BUILDDIR)/*.out $(LIBDIR)/*.*

debug: $(SRCS)
	$(CC) -c $? $(CFLAGS) $(DFLAGS) -O1
	@mv *.$(OBJEXT) $(OBJDIR)

test: $(TESTS) 
	$(CC) -c $? $(CFLAGS) $(DFLAGS) -O1
	@mv *.$(OBJEXT) $(OBJDIR)
	$(CC) -o $(TARGETNAME)_test.out $(OBJDIR)/*.$(OBJEXT) 
	@mv *.out $(BUILDDIR)
	
