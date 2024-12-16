#include "euclidean_distance.h"
#include <cmath>
/** 
 * Sablona pro libovolny typ Iteratoru, ktery bude odkazovat na urcitou cast kontejneru chromozomu
*/
template<typename Chromosome>

double euclidean_distance(const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo){
   double sum = 0;

   const size_t size = chromosomeOne.size();
   
   for ( unsigned int i = 0; i < size; ++i )
   {
        sum += std::pow( ( chromosomeOne[ i ] - chromosomeTwo[ i ] ), 2 );
   }

   return std::pow( sum, 0.5 );
}
