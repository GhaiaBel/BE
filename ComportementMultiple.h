#ifndef _CompMult_H_
#define _CompMult_H_
#include <iostream>
#include <vector>
#include "Comportement.h"
using namespace std;


class Bestiole;
class Milieu;
class ComportementMultiple : public Comportement {
private:
    std::vector<std::unique_ptr<Comportement>> comportements;
    int currentComportementIndex;
    static int counter; 
public:
    ComportementMultiple();
    virtual ~ComportementMultiple() override;
    virtual void action(Bestiole &b, Milieu &monMilieu) override;
    virtual std::unique_ptr<Comportement> clone() const override; 
};

#endif