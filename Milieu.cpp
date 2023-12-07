#include "Milieu.h"
#include "Bestiole.h"
#include <cstdlib>
#include <ctime>
#include <vector>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{
   
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {  
      it->action( *this );
      it->draw( *this );
      this->checkCollision(*it);
   }

   this->updateListBestioles();
      
} // for



int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;

   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}



std::vector<Bestiole*> Milieu::getVoisins( const Bestiole & b )
{
   std::vector<Bestiole*>  voisins;

   for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it)
      if ( !(b == *it) && b.jeTeVois(*it) )
         voisins.push_back(&(*it));

   return voisins;   
}


Bestiole* Milieu::VoisinPP( Bestiole & b )
{
   std::vector<Bestiole*>  voisins;
   voisins = this->getVoisins(b);

   double MinDist =b.Distance(voisins[0]);
   Bestiole* vpp = voisins[0];
   for (auto it = voisins.begin()+ 1; it != voisins.end(); ++it)
   {  
      // cout<<"Liste Voisins de "<<b.getIdentite()<<" : "<<(*it)->getIdentite()<<endl;
      double dist = b.Distance(*it);
      if ( dist < MinDist )
      {
         MinDist = dist;
         vpp = *it;
      } 
   }
      
   return vpp;
}


void Milieu::checkCollision( Bestiole & b)
{
   std::vector<Bestiole*> voisinage = getVoisins(b);
   
   for ( auto it = voisinage.begin() ; it != voisinage.end() ; 	++it )
   {
      if (b.Distance(*it) <= 8.0) {
         cout<<"Bestiole touched "<<endl;
         this->handleCollision(**it, b);
      }
   }

}

void Milieu::handleCollision( Bestiole & b1 , Bestiole & b2 )
{
   double randomProbabilityb1 = static_cast<double>(std::rand()) / RAND_MAX;
   double randomProbabilityb2 = static_cast<double>(std::rand()) / RAND_MAX;

   if (randomProbabilityb1 < b1.getDeathProba() && randomProbabilityb2 < b2.getDeathProba())
   {
      b1.setLifeSpan(0);
      b2.setLifeSpan(0);
   }
   else if (randomProbabilityb1 < b1.getDeathProba())
   {
      b1.setLifeSpan(0);
   }
   else if (randomProbabilityb2 < b2.getDeathProba())
   {
      b2.setLifeSpan(0);
   }
}

void Milieu::updateListBestioles()
{
   // cout<<"size of liste bestioles "<<listeBestioles.size()<<endl;
   listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(),
                                       [](const Bestiole& b) { return b.getLifeSpan() == 0; }),
                        listeBestioles.end());
}
