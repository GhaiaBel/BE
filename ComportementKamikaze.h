#ifndef COMPORTEMENTKAMIKAZE_H
#define COMPORTEMENTKAMIKAZE_H
#include <iostream>
#include <vector>
#include "Comportement.h"
#include <memory>
using namespace std;


class Bestiole;
class Milieu;
class ComportementKamikaze : public Comportement {
private: 
    static int counter; 
public:
    ComportementKamikaze();
    virtual ~ComportementKamikaze() override;
    virtual void action(Bestiole &b, Milieu &monMilieu) override;
    // virtual ComportementKamikaze* clone() const override; 
    virtual std::unique_ptr<Comportement> clone() const override;
};

#endif