#include "manhattan_distance.h"
/** 
 * Sablona pro libovolny typ Iteratoru, ktery bude odkazovat na urcitou cast kontejneru chromozomu
*/
template<typename Chromosome>

double manhattan_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo ){
   double sum = 0;
   
   size_t size = chromosomeOne.size();
   
   for ( unsigned int i = 0; i < size; ++i )
   {
        sum += std::abs( chromosomeOne[ i ] - chromosomeTwo[ i ] );
   }

   return sum;
}
