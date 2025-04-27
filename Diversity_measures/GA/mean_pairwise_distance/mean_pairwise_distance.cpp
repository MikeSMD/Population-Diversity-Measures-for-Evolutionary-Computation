#include "mean_pairwise_distance.h"

template<typename Container, typename Chromosome>

double mean_pairwise_distance(const Container& population, std::function< double( const Chromosome&, const Chromosome& ) > distance_method){
    double sum = 0;

	if ( population.size() <= 1 )
		throw std::runtime_error ( "mean_pairwise_distance: populace je příliš malá" );
    
    int count = ( population.size() * (population.size() - 1) ) / 2;
    
    for( size_t i = 0; i < population.size(); ++i )
    {
        for ( size_t j = i + 1; j < population.size(); ++j )
        {
            sum += distance_method( population[ i ], population[ j ] );
        }
    }

    return sum / count;
}

template double mean_pairwise_distance< std::vector < std::vector< int > >, std::vector< int > >( const std::vector< std::vector < int > >&, std::function< double( const std::vector< int >&, const std::vector< int >& ) > );

template double mean_pairwise_distance< std::vector < std::vector< bool > >, std::vector< bool > >( const std::vector< std::vector < bool > >&, std::function< double( const std::vector< bool >&, const std::vector< bool >& ) > );

