#include "jaccard_index.h"
#include <vector>
template<typename Chromosome, typename Item>

double jaccard_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo ){

    std::set<Item> chromosomeOneAlleles = {};
    std::set<Item> chromosomeTwoAlleles = {};

    for ( size_t i = 0; i < chromosomeOne.size(); ++i )
    {
        chromosomeOneAlleles.insert( chromosomeOne[ i ] );
    }

    for ( size_t i = 0; i < chromosomeTwo.size(); ++i )
    {
        chromosomeTwoAlleles.insert( chromosomeTwo[ i ] );
    }

    unsigned int intersection_count = 0;
    unsigned int union_count;
    std::set<Item> union_set = {};

    for ( const auto& allele : chromosomeOneAlleles )
    {
    	if ( chromosomeTwoAlleles.count( allele ) )
	{
		intersection_count += 1;
	}
	union_set.insert( allele );
    }

    
    for ( const auto& allele : chromosomeTwoAlleles )
    {
    	union_set.insert( allele );
    }

    union_count = union_set.size() ;


    return static_cast<double>( intersection_count ) / union_count;
}


template double jaccard_distance<std::vector<bool>, bool >( const std::vector<bool>&, const std::vector<bool>&  );
template double jaccard_distance<std::vector<int>, int >( const std::vector<int>&, const std::vector<int>&  );
