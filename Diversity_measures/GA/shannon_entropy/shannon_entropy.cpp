#include "shannon_entropy.h"

template<typename Container, typename Chromosome, typename Item>

double shannon_enthrophy( const Container& population ){
    std::unordered_map< Item, int > alleles = {};

    int count_of_genes = 0;

    for ( const Chromosome& chromosome : population )
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

    if ( count_of_genes == 0 )
	    throw std::runtime_error ( "shannon_entropy: populace neobsahuje žádné geny" );

    double result = 0.0;
    for ( auto& allel : alleles )
    {
        double propability = static_cast<double> ( allel.second ) / count_of_genes;
        result += propability * std::log2( propability );
    }

    return result * ( -1.0 );

}
template double shannon_enthrophy<std::vector<std::vector<bool>>, std::vector<bool>, bool>( const std::vector<std::vector<bool>>& );
template double shannon_enthrophy<std::vector<std::vector<int>>, std::vector<int>, int>( const std::vector<std::vector<int>>& );
template double shannon_enthrophy<std::vector<std::vector<double>>, std::vector<double>, double >( const std::vector<std::vector<double>>& );
