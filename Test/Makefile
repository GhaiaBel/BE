main : main.cpp Aquarium.o Bestiole.o ComportementGregaire.o ComportementPeureuse.o Milieu.o 
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o ComportementGregaire.o ComportementPeureuse.o Milieu.o  -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11 -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp 
	g++ -Wall -std=c++11 -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11 -c Milieu.cpp -I .

ComportementGregaire.o: ComportementGregaire.h ComportementGregaire.cpp 
	g++ -Wall -std=c++11 -c ComportementGregaire.cpp -I .

ComportementPeureuse.o: ComportementPeureuse.h ComportementPeureuse.cpp 
	g++ -Wall -std=c++11 -c ComportementPeureuse.cpp -I .

Comportement.o: Comportement.h
	g++ -Wall -std=c++11 -c -o Comportement.o -I .

clean:
	rm -rf *.o main
