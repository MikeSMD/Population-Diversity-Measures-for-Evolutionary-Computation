#include "hamming_distance.h"

template<typename Chromosome>

unsigned int hamming_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo ){
    int sum = 0;

    size_t min_length = std::min( chromosomeOne.size(), chromosomeTwo.size() );

    for ( size_t i = 0; i < min_length; ++i ) 
    {
       sum += (chromosomeOne[ i ] != chromosomeTwo[ i ])? 1:0;
    }

   return sum;
}
