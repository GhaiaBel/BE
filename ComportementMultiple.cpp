#include "ComportementMultiple.h"
#include <vector>
#include <cstdlib>
#include "Bestiole.h"
#include <cstdlib> 

#include "Milieu.h"


int ComportementMultiple::counter = 0;

ComportementMultiple::ComportementMultiple():currentComportementIndex(0)
{
	// std::cout<<"New Comportement Multiple Constructed"<<endl;

    comportements.push_back(std::make_unique<ComportementGregaire>());
    comportements.push_back(std::make_unique<ComportementPeureuse>());
    comportements.push_back(std::make_unique<ComportementKamikaze>());
    comportements.push_back(std::make_unique<ComportementPrevoyante>());   
}


void ComportementMultiple::action(Bestiole &b, Milieu &monMilieu)
{
    if (counter % 5 == 0)
    {
        // std::cout<<"Comportement Multiple : "<<endl;
        currentComportementIndex = rand() % comportements.size();
        comportements[currentComportementIndex]->action(b, monMilieu);
    }
    ++counter;
}

std::unique_ptr<Comportement> ComportementMultiple::clone() const {
    auto copie = std::make_unique<ComportementMultiple>();  

    for (const auto &c : comportements) {
        if (c) {
            copie->comportements.push_back(c->clone());
        }
    }
    return copie;
}

ComportementMultiple::~ComportementMultiple() {
    
}

