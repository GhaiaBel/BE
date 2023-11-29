#ifndef _CompGreg_H_
#define _CompGreg_H_
#include <iostream>
#include <vector>
#include "Comportement.h"
using namespace std;


// Forward declarations
class Bestiole;
class Milieu;
class ComportementGregaire : public Comportement {
public:
    ComportementGregaire();
    virtual ~ComportementGregaire() override;
    virtual void action(Bestiole &b, Milieu &monMilieu) override;
    virtual ComportementGregaire* clone() const override; 
};

#endif