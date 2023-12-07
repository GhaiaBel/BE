#include "Comportement.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <cstdlib>
#include <cmath>



const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 50.;

int               Bestiole::next = 0;


Bestiole::Bestiole( void )
{
   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut "<< endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
   originalVitesse = vitesse;
   couleur = new T[ 3 ];
   lifespan=10;
   DeathProba=0.5;


   if (identite ==1) {
      couleur[ 0 ] = 230;
      couleur[ 1 ] = 0;
      couleur[ 2 ] = 0;
      c = std::make_unique<ComportementMultiple>();
   }
    else 
      if (identite == 10) {
      couleur[ 0 ] = 0;
      couleur[ 1 ] = 230;
      couleur[ 2 ] = 0;
      c = std::unique_ptr<ComportementKamikaze>(new ComportementKamikaze());
   }
    else 
      if (identite == 20) {
      couleur[ 0 ] = 0;
      couleur[ 1 ] = 0;
      couleur[ 2 ] = 230;
      c = std::unique_ptr<ComportementPeureuse>(new ComportementPeureuse());
   }
   else 
      if (identite == 40) {
      couleur[ 0 ] = 230;
      couleur[ 1 ] = 0;
      couleur[ 2 ] = 230;
      c = std::unique_ptr<ComportementGregaire>(new ComportementGregaire());
   }

   else 
      if (identite == 6) {
      couleur[ 0 ] = 230;
      couleur[ 1 ] = 230;
      couleur[ 2 ] = 0;
      c = std::unique_ptr<ComportementPrevoyante>(new ComportementPrevoyante());
   }

   else{
      couleur[ 0 ] = 0;
      couleur[ 1 ] = 0;
      couleur[ 2 ] = 0;
      c = std::unique_ptr<Comportement>();
      
}
}


Bestiole::Bestiole(const Bestiole &b) {
   
   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   lifespan=b.lifespan;
   DeathProba=b.DeathProba;

   if (b.c) {
        c = b.c->clone();
    } else {
        c = nullptr; 
    }
   

   vitesse = b.vitesse;
   originalVitesse = b.originalVitesse;
   couleur = new T[3];
   memcpy(couleur, b.couleur, 3 * sizeof(T));
}

Bestiole& Bestiole::operator=(const Bestiole &b) {

   cout << "operateur = " << endl;

   if (this != &b) {
      x = b.x;
      y = b.y;
      cumulX = cumulY = 0.;
      orientation = b.orientation;
      lifespan = b.lifespan;
      DeathProba=b.DeathProba;

      if (b.c) {
        c = b.c->clone();
    } else {
        c = nullptr;
    }
      
      vitesse = b.vitesse;
      originalVitesse = b.originalVitesse;

      delete[] couleur;
      couleur = new T[3];
      memcpy(couleur, b.couleur, 3 * sizeof(T));
   }

   return *this;
}

Bestiole::~Bestiole( void )
{
   delete[] couleur;

   // cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{
   
   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation += ((rand() % 100) / 100.0 - 0.5) * M_PI;
      //orientation = std::fmod(orientation, 2 * M_PI);
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation += ((rand() % 100) / 100.0 - 0.5) * M_PI;
      // orientation = std::fmod(orientation, 2 * M_PI);
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}


void Bestiole::action( Milieu & monMilieu )
{
   if (couleur[ 0 ] == 230 || couleur[ 1 ] == 230 || couleur[ 2 ] == 230)
   {
      // cout<<" Action de Bestiole "<<endl;
      c->action(*this, monMilieu);
   }
   bouge(monMilieu.getWidth(), monMilieu.getHeight());

}

void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{
   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{
   double         dist;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

double Bestiole::Distance(const Bestiole * b ) const
{
   double         dist;
   dist = std::sqrt( (x-b->x)*(x-b->x) + (y-b->y)*(y-b->y) );
   return dist;

}

int Bestiole::getIdentite()
{
   return identite;
}

double Bestiole::getOrientation() const
{
   return orientation;
}

void Bestiole::setOrientation(double o)
{
   this->orientation = o;
}

double Bestiole::getVitesse() const
{
   return vitesse;
}

void Bestiole::setVitesse(double v)
{
   this->vitesse =v;
}

double Bestiole::getOriginalVitesse() const
{  
   return originalVitesse;
}

// T  Bestiole::getColor(){
//    return this->couleur[1];
// }

int Bestiole::getX() const{
   return x;
}
int Bestiole::getY() const{
   return y;
}

int Bestiole::getLifeSpan() const{
   return lifespan;
}
void Bestiole::setLifeSpan(int l) {
   this->lifespan=l;
}

bool Bestiole::jeTeTouche( const Bestiole & b ) const
{
   if (this->Distance(&b) <= 10) {
      cout<<" JeTeTouche "<<endl;
      return true;
   }
   else {
      return false;
   }
}

double Bestiole::getDeathProba() const{
   return DeathProba;
}