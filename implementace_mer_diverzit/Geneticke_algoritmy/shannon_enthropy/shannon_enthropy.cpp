#include "shannon_enthropy.h"

template<typename Container, typename Chromosome, typename Item>

double shannon_enthrophy( const Container& population ){
    std::unordered_map< Item, int > alleles = {};

    int count_of_genes = 0;

    for ( Chromosome& chromosome : population )
    {
        for ( Item gene : chromosome )
        {
            if( alleles.find( gene ) == alleles.end() ) 
            {
                alleles[ gene ] = 1;
            }
            else
                alleles[ gene ] += 1;

            count_of_genes += 1;
        }
    }

    double result = 0.0;
    for ( std::pair< Item, int >& allel : alleles )
    {
        double propability = static_cast<double> ( allel.second ) / count_of_genes;
        result += propability * std::log2( propability );
    }

    return result * ( -1.0 );

}
