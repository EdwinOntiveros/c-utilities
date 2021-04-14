#Work directories
SRCDIR 		:= src
OBJDIR 		:= obj
LIBDIR 		:= lib
INCLUDEDIR 	:= include
TESTSDIR	:= tests
BUILDDIR	:= build

#Set compiler options
CC 			:= clang
CFLAGS		:= -std=c17 -Wall -Weverything --extra-warnings
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

.phony: clean debug_all release_all

all: debug_all release_all 

clean:
	rm -rf ./*.o 	$(OBJDIR)/*.o
	rm -rf ./*.out 	$(BUILDDIR)/*.out $(LIBDIR)/*.*

debug_all: clean debug_main
release_all: clean release_main

debug_main: $(SRCS)
	$(CC) -c $? $(CFLAGS) $(DFLAGS) -O1
	@mv ./*.$(OBJEXT) $(OBJDIR)

release_main: $(SRCS)
	$(CC) -c $? $(CFLAGS) $(SANITOPTS) -DNDEBUG -O3
	@mv ./*.$(OBJEXT) $(OBJDIR)

