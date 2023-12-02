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
    std::cout<<"Action Comportement Kamikaze"<<endl;

    int nbVoisins = monMilieu.nbVoisins(b);

    if (nbVoisins != 0)
    {
        Bestiole* vpp = monMilieu.VoisinPP(b);
        cout<<" VPP de "<<b.getIdentite()<<" : "<<vpp->getIdentite()<<endl;
        double targetOrientation = std::atan2(vpp->getY() - b.getY(), vpp->getX() - b.getX());
        b.setOrientation(-targetOrientation); 
    }    
}
    
std::unique_ptr<Comportement> ComportementKamikaze::clone() const {
    return std::make_unique<ComportementKamikaze>(*this);
}

ComportementKamikaze::~ComportementKamikaze() {
    cout << "Destructor of ComportementKamikaze" << endl;
}

