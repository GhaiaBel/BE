#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include "ComportementGregaire.h"
#include "ComportementPeureuse.h"
#include "ComportementKamikaze.h"
#include "ComportementPrevoyante.h"
#include "ComportementMultiple.h"
#include <iostream>
#include <memory> 
using namespace std;



class Milieu;

class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;


private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

   std::unique_ptr<Comportement> c;  
   double originalVitesse; // New  variable to store the original speed

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   Bestiole& operator=(const Bestiole &b);
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   int getIdentite();

   double getOrientation() const;

   void setOrientation(double o);

   double getVitesse() const;

   void setVitesse(double v);

   double getOriginalVitesse() const;
   
   // T  getColor();
   
   double Distance(const Bestiole * b ) const;

   int getX() const;
   int getY() const;

};

#endif

