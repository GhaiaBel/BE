// Comportement.h
#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

class Bestiole; // Forward declaration
class Milieu;

class Comportement {
public:
    virtual ~Comportement() {} // Make the base class polymorphic
    virtual void action(Bestiole &b, Milieu &monMilieu) = 0;
    virtual Comportement* clone() const = 0; // Pure virtual clone function
};

#endif
