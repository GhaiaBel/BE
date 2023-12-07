#ifndef COMPORTEMENTPEUREUSE_H
#define COMPORTEMENTPEUREUSE_H
#include <iostream>
#include <vector>
#include "Comportement.h"
using namespace std;


class Bestiole;
class Milieu;
class ComportementPeureuse : public Comportement {
private: 
    static int counter; 
public:
    ComportementPeureuse();
    virtual ~ComportementPeureuse() override;
    virtual void action(Bestiole &b, Milieu &monMilieu) override;
    // virtual ComportementPeureuse* clone() const override; 
    virtual std::unique_ptr<Comportement> clone() const override;
};

#endif