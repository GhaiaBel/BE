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
    std::vector<Bestiole> voisins = monMilieu.getVoisins(b);

    if (!voisins.empty())
    {
		// Calculate the average orientation of the neighboring bestioles
		double averageOrientation = 0.0;
		for (const Bestiole &voisin : voisins)
		{
			averageOrientation += voisin.getOrientation();
		}
		averageOrientation /= voisins.size();

		// Adjust the current bestiole's orientation towards the 		normalized average
		b.setOrientation(averageOrientation);
    }
    
}

ComportementGregaire* ComportementGregaire::clone() const {
	cout << "Comportement Cloned" << endl;
    return new ComportementGregaire(*this);
}

ComportementGregaire::~ComportementGregaire() {
    // Destructor implementation
}

