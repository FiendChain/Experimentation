CC=g++
CFLAGS=-std=c++17
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
DFLAGS=
SDIR=Sources
ODIR=ObjectFiles

main: objects
	$(CC) $(ODIR)/*.o -o main $(CFLAGS) $(LFLAGS) $(DFLAGS)

objects:
	cd ./$(ODIR) && \
	$(CC) ../$(SDIR)/*.cpp -c $(CFLAGS) $(LFLAGS) $(DFLAGS) && \
	$(CC) ../$(SDIR)/GravitySim/*.cpp -c $(CFLAGS) $(LFLAGS) $(DFLAGS) && \
	$(CC) ../$(SDIR)/Body/*.cpp -c $(CFLAGS) $(LFLAGS) $(DFLAGS) && \
	cd ../

clean:
	rm -f $(ODIR)/*.o *.o main core