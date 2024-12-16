#include "edit_distance.h"

template<typename Chromosome>

unsigned int edit_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo ){

    size_t lengthOfChromosomeOne = chromosomeOne.size();
    size_t lengthOfChromosomeTwo = chromosomeTwo.size();

    std::vector<std::vector<unsigned int>> D(lengthOfChromosomeOne + 1, std::vector<unsigned int>(lengthOfChromosomeTwo + 1)); 

    for( size_t i = 0; i <= lengthOfChromosomeTwo; ++i )
    {
        D[ 0 ][ i ] = i;
    } 

    for( size_t i = 0; i <= lengthOfChromosomeOne; ++i )
    {
        D[ i ][ 0 ] = i;
    }

    for( size_t i = 1; i <= lengthOfChromosomeOne; ++i )
    {
        for( size_t j = 1; j <= lengthOfChromosomeTwo; ++j )
        {
            int rcost;            
            if( chromosomeOne[ i - 1 ] == chromosomeTwo[ j - 1 ] ) rcost = 0;
            else rcost = 1;

            unsigned int minimal_value = std::min( std::min ( D[ i - 1 ][ j ] + 1, D[ i ][ j - 1 ] + 1 ), D[ i - 1 ][ j - 1 ] + rcost );

            D[ i ][ j ] = minimal_value;
        }
    }

    unsigned int result = D[ lengthOfChromosomeOne ][ lengthOfChromosomeTwo ];
 

    return result;
}
