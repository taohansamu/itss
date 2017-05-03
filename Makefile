# change application name here (executable output name)
#perl -pi -e 's/^  */\t/' Makefile 
# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall
	
PTHREAD=-pthread
	
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
	
GTKLIB=`pkg-config --cflags --libs gtk+-3.0`
	
# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic
	
OBJS= tang1 tang2 tang3 tang4 tang5
#  gcc `pkg-config --cflags gtk+-3.0` -o tang2 tang2.c `pkg-config --libs gtk+-3.0`
all: $(OBJS)
tang1: tang1.c
	$(LD) -o tang1 tang1.c $(LDFLAGS)
tang2: tang2.c
	$(LD) -o tang2 tang2.c $(LDFLAGS)
tang3: tang3.c
	$(LD) -o tang3 tang3.c $(LDFLAGS)
tang4: tang4.c
	$(LD) -o tang4 tang4.c $(LDFLAGS)
tang5: tang5.c
	$(LD) -o tang5 tang5.c $(LDFLAGS)	
tang1.o: tang1.c
	$(CC) -c $(CCFLAGS) tang1.c $(GTKLIB) -o tang1.o
tang2.o: tang2.c
	$(CC) -c $(CCFLAGS) tang2.c $(GTKLIB) -o tang2.o
tang3.o: tang3.c
	$(CC) -c $(CCFLAGS) tang3.c $(GTKLIB) -o tang2.o
tang4.o: tang4.c
	$(CC) -c $(CCFLAGS) tang4.c $(GTKLIB) -o tang2.o
tang5.o: tang5.c
	$(CC) -c $(CCFLAGS) tang5.c $(GTKLIB) -o tang2.o
clean:
	rm edit $(OBJS)