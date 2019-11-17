CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=mymath.o
FLAGS= -Wall -g

all: libmymath.so libmymath.a mains maind	
mains: $(OBJECTS_MAIN) libmymath.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmymath.a
maind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmymath.so
mymath.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmymath.so $(OBJECTS_LIB)
libmymath.a: $(OBJECTS_LIB)
	$(AR) -rcs libmymath.a $(OBJECTS_LIB)	
mymath.o: mymath.c mymath.h
	$(CC) $(FLAGS) -c mylib.c
main.o: main.c mymath.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maind
