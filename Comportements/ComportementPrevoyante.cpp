#include "ComportementPrevoyante.h"
#include <vector>
#include <cstdlib>
#include "Bestiole.h"

#include "Milieu.h"

ComportementPrevoyante::ComportementPrevoyante()
{
	std::cout<<"New Comportement Prevoyante Constructed"<<endl;
}


void ComportementPrevoyante::action(Bestiole &b, Milieu &monMilieu)
{
    std::cout<<"Action Comportement Prevoyante"<<endl;

    std::vector<Bestiole*> voisins = monMilieu.getVoisins(b);

    if (!voisins.empty()) {
        double futurX = b.getX() + cos(b.getOrientation()) * b.getVitesse();
        double futurY = b.getY() - sin(b.getOrientation()) * b.getVitesse();

        for (auto voisin : voisins) {
            double voisinFuturX = voisin->getX() + cos(voisin->getOrientation()) * voisin->getVitesse();
            double voisinFuturY = voisin->getY() - sin(voisin->getOrientation()) * voisin->getVitesse();

            double distance = std::sqrt((voisinFuturX - futurX) * (voisinFuturX - futurX) +
                                            (voisinFuturY - futurY) * (voisinFuturY - futurY));


            if (distance < 50.0) {
                // Exemple: inverser l'orientation
                double newOrientation = atan2(voisinFuturY - futurY, voisinFuturX - futurX) + M_PI;
                b.setOrientation(newOrientation);
                return;  
            }
        }
    }

    b.setOrientation(b.getOrientation());  
    b.setVitesse(b.getOriginalVitesse());   

}

std::unique_ptr<Comportement> ComportementPrevoyante::clone() const {
    return std::make_unique<ComportementPrevoyante>(*this);
}

ComportementPrevoyante::~ComportementPrevoyante() {
    
}

