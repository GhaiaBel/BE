#ifndef COMPORTEMENTKAMIKAZE_H
#define COMPORTEMENTKAMIKAZE_H
#include <iostream>
#include <vector>
#include "Comportement.h"
using namespace std;


// Forward declarations
class Bestiole;
class Milieu;
class ComportementKamikaze : public Comportement {
public:
    ComportementKamikaze();
    virtual ~ComportementKamikaze() override;
    virtual void action(Bestiole &b, Milieu &monMilieu) override;
    virtual ComportementKamikaze* clone() const override; 
};

#endif