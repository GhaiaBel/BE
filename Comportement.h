// Comportement.h
#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_
#include <memory>

class Bestiole; 
class Milieu;

class Comportement {
public:
    virtual ~Comportement() = default; 
    virtual void action(Bestiole &b, Milieu &monMilieu) = 0;
    virtual std::unique_ptr<Comportement> clone() const = 0;
};

#endif
