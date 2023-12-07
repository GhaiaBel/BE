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

   // **** Nouveaux attributs **** // : 
   std::unique_ptr<Comportement> c; // Nouvel attribut représentant le comportement d'une Bestiole.
   double originalVitesse; // Nouvel attribut pour stocker la vitesse originale et l'utiliser dans la classe ComportementPeureuse.
   int lifespan;

   double DeathProba;


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
   int getX() const;
   int getY() const;

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   // Méthode qui retourne l'identité de la Bestiole : 
   int getIdentite();

   // Méthode qui retourne l'orientation de la Bestiole :
   double getOrientation() const;

   // Méthode qui permet de définir l'orientation de la Bestiole :
   void setOrientation(double o);

   // Méthode qui retourne la vitesse de la Bestiole :
   double getVitesse() const;

   // Méthode qui permet de définir la vitesse de la Bestiole :
   void setVitesse(double v);

   // Méthode qui retourne la vitesse originale de la Bestiole :
   double getOriginalVitesse() const;
   
   // T  getColor();
   
   // Méthode qui retourne la distance entre la Bestiole actuelle et une autre Bestiole spécifiée b : 
   double Distance(const Bestiole * b ) const;

   bool jeTeTouche( const Bestiole & b ) const;


   int getLifeSpan() const;

   void setLifeSpan(int l) ;

   double getDeathProba() const;



};

#endif

