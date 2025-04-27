#include "unpresented_genes.h"
template<typename Chromosome, typename Item >

double unpresented_genes( std::size_t count_of_genes, const std::vector< Chromosome >& population ){
	std::set< Item > unique_genes = {};
    if ( count_of_genes == 0 )
	    throw std::runtime_error ( "unpresented_genes: maximální počet genů musí být alespoň 1" );	
	for ( int candidate = 0; candidate < population.size(); ++candidate )
	{
		for ( Item gene : population[ candidate ] )
		{
			unique_genes.insert( gene );
		}
	}
	
	return static_cast< double >( unique_genes.size() ) / count_of_genes;
}
template double unpresented_genes<std::vector<bool>, bool>(std::size_t , const std::vector< std::vector<bool> >&);

template double unpresented_genes<std::vector<int>, int>(std::size_t, const std::vector< std::vector< int > >&);

