#include "ComportementPeureuse.h"
#include <vector>
#include <cstdlib>
#include "Bestiole.h"
#include "Milieu.h"


int  ComportementPeureuse::counter = 0;

ComportementPeureuse::ComportementPeureuse()
{
	// std::cout<<"New Comportement Peureuse Constructed"<<endl;
}


void ComportementPeureuse::action(Bestiole &b, Milieu &monMilieu)
{
    // std::cout<<"Action Comportement Peureuse"<<endl;
    ++counter;
    int nbVoisins = monMilieu.nbVoisins(b);
    double beforeVitesse = b.getOriginalVitesse();
    if ((nbVoisins >= 2) &&  (counter % 10 == 0))
    {   
        double oppositeOrientation = b.getOrientation() + M_PI;
        b.setVitesse(beforeVitesse* beforeVitesse); 
        b.setOrientation(oppositeOrientation);
    } else if (counter % 10 == 0) {
        b.setVitesse(beforeVitesse);
        
    }
}
    

std::unique_ptr<Comportement> ComportementPeureuse::clone() const {
    return std::make_unique<ComportementPeureuse>(*this);
}

ComportementPeureuse::~ComportementPeureuse() {
    // Destructor implementation
}

