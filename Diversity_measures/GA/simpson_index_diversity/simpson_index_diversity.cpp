#include "simpson_index_diversity.h"
#include <algorithm>
/** 
 * Sablona pro libovolny typ Iteratoru, ktery bude odkazovat na urcitou cast kontejneru chromozomu
*/
template<typename Container, typename Chromosome, typename Item>

double simpson_index_of_diversity( const Container& population ){
    std::unordered_map< Item, int > alleles = {};

    int count_of_genes = 0;

    for ( const Chromosome& chromosome : population )
    {
        for ( const Item gene : chromosome )
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
	    throw std::runtime_error ( "simpson_index_of_diversity: populace neobsahuje žádné geny" );
    double result = 0.0;
    for ( auto& allel : alleles )
    {
        result += allel.second * ( allel.second - 1 );
    }
    result = result / ( count_of_genes * ( count_of_genes - 1 ) );
    return 1 - result;
}
template double simpson_index_of_diversity< std::vector< std::vector< bool > >, std::vector< bool >, bool >( const std::vector< std::vector < bool > >& );

template double simpson_index_of_diversity< std::vector< std::vector< int > >, std::vector< int >, int >( const std::vector< std::vector < int > >& );
