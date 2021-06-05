TARGET=Aplicacion

CC=gcc
DEBUG=-g
OPT=-O0
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS=    ventana.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
	
ventana.o: ventana.c
	$(CC) -c $(CCFLAGS) ventana.c $(GTKLIB) -o ventana.o

clean:
	rm -f *.o $(TARGET)
