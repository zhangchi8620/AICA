CC = g++

OBJECTS = aica_asy_image.o 
EXEC = aica

$(EXEC): $(OBJECTS)
	$(CC) -g -o $@ $^

aica_asy_image.o: aica_asy_image.cpp pgm.o
	$(CC) -g -c $<

pgm.o:pgm.cpp pgm.h
	$(CC) -g -c $<

clean:
	rm -rf $(EXEC) *.o *~
