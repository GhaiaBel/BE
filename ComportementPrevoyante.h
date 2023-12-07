#ifndef _CompPrev_H_
#define _CompPrev_H_
#include <iostream>
#include <vector>
#include "Comportement.h"
using namespace std;


class Bestiole;
class Milieu;
class ComportementPrevoyante : public Comportement {
public:
    ComportementPrevoyante();
    virtual ~ComportementPrevoyante() override;
    virtual void action(Bestiole &b, Milieu &monMilieu) override;
    virtual std::unique_ptr<Comportement> clone() const override; 
};

#endif