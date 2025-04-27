#include "hamming_distance.h"
template<typename Chromosome>

unsigned int hamming_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo ){
    int sum = 0;

	if ( chromosomeOne.size() != chromosomeTwo.size() )
		throw std::runtime_error ( "hamming_distance: chromozomy mají jiné počty genů" );
	std::size_t length = chromosomeOne.size();

    for ( std::size_t i = 0; i < length; ++i ) 
    {
       sum += (chromosomeOne[ i ] != chromosomeTwo[ i ])? 1:0;
    }

   return sum;
}
template unsigned int hamming_distance<std::vector<bool>>(const std::vector<bool>&, const std::vector<bool>&);


template unsigned int hamming_distance<std::vector<int>>(const std::vector<int>&, const std::vector<int>&);

