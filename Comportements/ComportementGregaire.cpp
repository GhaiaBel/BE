#include "ComportementGregaire.h"
#include <vector>
#include <cstdlib>
#include "Bestiole.h"

#include "Milieu.h"

ComportementGregaire::ComportementGregaire()
{
	std::cout<<"New Comportement Constructed"<<endl;
}


void ComportementGregaire::action(Bestiole &b, Milieu &monMilieu)
{
	std::cout<<"Action Comportement Gregaire"<<endl;

    std::vector<Bestiole*> voisins = monMilieu.getVoisins(b);

    if (!voisins.empty())
    {
		double averageOrientation = 0.0;
		for (std::vector<Bestiole*>::iterator it = voisins.begin(); it != voisins.end(); ++it)
			averageOrientation += (*it)->getOrientation();

		averageOrientation /= voisins.size();
		b.setOrientation(averageOrientation);
    }
    
}

std::unique_ptr<Comportement> ComportementGregaire::clone() const {
    return std::make_unique<ComportementGregaire>(*this);
}

ComportementGregaire::~ComportementGregaire() {
    
}

