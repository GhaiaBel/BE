#include "ComportementPeureuse.h"
#include <vector>
#include <cstdlib>
#include "Bestiole.h"
#include "Milieu.h"


int  ComportementPeureuse::counter = 0;

ComportementPeureuse::ComportementPeureuse()
{
	std::cout<<"New Comportement Constructed"<<endl;
}


void ComportementPeureuse::action(Bestiole &b, Milieu &monMilieu)
{
    ++counter;
    int nbVoisins = monMilieu.nbVoisins(b);
    double beforeVitesse = b.getOriginalVitesse();
    if ((nbVoisins >= 2) &&  (counter % 5 == 0))
    {   
        double oppositeOrientation = b.getOrientation() + M_PI;
        b.setVitesse(beforeVitesse* 4.0); 
        b.setOrientation(oppositeOrientation);
    } else if (counter % 5 == 0) {
        b.setVitesse(beforeVitesse);
        
    }
}
    

ComportementPeureuse* ComportementPeureuse::clone() const {
    return new ComportementPeureuse(*this);
}

ComportementPeureuse::~ComportementPeureuse() {
    // Destructor implementation
}

