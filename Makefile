

main : main.cpp Aquarium.o Bestiole.o ComportementGregaire.o ComportementPeureuse.o ComportementKamikaze.o ComportementPrevoyante.o ComportementMultiple.o Milieu.o  
	g++ -Wall -std=c++14 -g -o main main.cpp Aquarium.o Bestiole.o ComportementGregaire.o ComportementPeureuse.o ComportementKamikaze.o ComportementPrevoyante.o ComportementMultiple.o Milieu.o  -I . -I /opt/X11/include -L /opt/X11/lib -lX11 -lpthread


Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++14 -g -c Aquarium.cpp -I . -I /opt/X11/include 

Bestiole.o : Bestiole.h Bestiole.cpp 
	g++ -Wall -std=c++14 -g -c Bestiole.cpp -I . -I /opt/X11/include 

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++14 -g -c Milieu.cpp -I . -I /opt/X11/include 

ComportementGregaire.o: ComportementGregaire.h ComportementGregaire.cpp 
	g++ -Wall -std=c++14 -g -c ComportementGregaire.cpp -I . -I /opt/X11/include 

ComportementPeureuse.o: ComportementPeureuse.h ComportementPeureuse.cpp 
	g++ -Wall -std=c++14 -g -c ComportementPeureuse.cpp -I . -I /opt/X11/include 

ComportementKamikaze.o: ComportementKamikaze.h ComportementKamikaze.cpp 
	g++ -Wall -std=c++14 -g -c ComportementKamikaze.cpp -I . -I /opt/X11/include 

ComportementPrevoyante.o: ComportementPrevoyante.h ComportementPrevoyante.cpp 
	g++ -Wall -std=c++14 -g -c ComportementPrevoyante.cpp -I . -I /opt/X11/include 

ComportementMultiple.o: ComportementMultiple.h ComportementMultiple.cpp 
	g++ -Wall -std=c++14 -g -c ComportementMultiple.cpp -I . -I /opt/X11/include 


Comportement.o: Comportement.h
	g++ -Wall -std=c++14 -g -c -o Comportement.o -I . -I /opt/X11/include 

clean:
	rm -rf *.o main
