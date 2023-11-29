#include "ComportementKamikaze.h"
#include <vector>
#include <cstdlib>
#include "Bestiole.h"
#include "Milieu.h"


ComportementKamikaze::ComportementKamikaze()
{
	std::cout<<"New Comportement Constructed"<<endl;
}


void ComportementKamikaze::action(Bestiole &b, Milieu &monMilieu)
{
    int nbVoisins = monMilieu.nbVoisins(b);
    
    if (nbVoisins != 0)
    {
        Bestiole vpp = monMilieu.VoisinPP(b);
        double targetOrientation = std::atan2(nearestBestiole->getY() - b.getY(), nearestBestiole->getX() - b.getX());
        b.setOrientation(targetOrientation);
    }    
}
    

ComportementKamikaze* ComportementKamikaze::clone() const {
    return new ComportementKamikaze(*this);
}

ComportementKamikaze::~ComportementKamikaze() {
    // Destructor implementation
}

