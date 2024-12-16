#include "simpson_index_diversity.h"
#include <algorithm>
/** 
 * Sablona pro libovolny typ Iteratoru, ktery bude odkazovat na urcitou cast kontejneru chromozomu
*/
template<typename Container, typename Chromosome, typename Item>

double simpson_index_of_diversity( const Container& population ){
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
        result += allel.second * ( allel.second - 1 );
    }
    result = result / ( count_of_genes * ( count_of_genes - 1 ) );
    return 1 - result;
}
