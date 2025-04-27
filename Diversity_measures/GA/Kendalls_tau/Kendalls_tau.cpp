#include "Kendalls_tau.h"
template double kendalls_tau<std::vector<bool> >(const std::vector<bool>&, const std::vector<bool>&);
template double kendalls_tau<std::vector<int> >(const std::vector<int>&, const std::vector<int>&);
template<typename Chromosome>

double kendalls_tau( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo ){
	if ( chromosomeOne.size() != chromosomeTwo.size() )
	{
		throw std::runtime_error ("kendalls_tau: počet genů chromozomů je odlišný");
	}
	std::size_t genes_count = chromosomeOne.size();
	unsigned int rozdilne = 0;

	for ( std::size_t gene = 0; gene < genes_count; ++gene )
	{
		for ( std::size_t geneTwo = gene + 1 ; geneTwo < genes_count; ++geneTwo )
		{
			if ( chromosomeOne[ gene ] == chromosomeOne[ geneTwo ] || chromosomeTwo [ gene ] == chromosomeTwo[ geneTwo ] )
				continue;
			
			bool prvni = chromosomeOne[ geneTwo ] > chromosomeOne[ gene ];
			bool druhy = chromosomeTwo[ geneTwo ] > chromosomeTwo[ gene ];

			if ( prvni != druhy ) 
			{
				rozdilne ++ ;
			}
		}
	}
	if ( genes_count == 0 )
		return 0;
	return ( static_cast< double > ( rozdilne ) ) / ( static_cast< double > ( genes_count ) * 0.5 * ( genes_count - 1 )  ) ;
}


