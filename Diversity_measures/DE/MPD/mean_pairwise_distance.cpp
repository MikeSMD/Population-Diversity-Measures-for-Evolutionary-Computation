#include "mean_pairwise_distance.h"

template<typename Container, typename Individual >

double mean_pairwise_distance(const Container& population, std::function< double( const Individual&, const Individual& ) > distance_method){

	if ( population.size() <= 1 )
		throw std::runtime_error ( "mean_pairwise_distance: populace je příliš malá" );
    double sum = 0;
    int count = ( population.size() * (population.size() - 1) ) / 2;
    
    for( std::size_t i = 0; i < population.size(); ++i )
    {
        for ( std::size_t j = i + 1; j < population.size(); ++j )
        {
            sum += distance_method( population[ i ], population[ j ] );
        }
    }

    return sum / count;
}

template double mean_pairwise_distance< std::vector < std::vector< double > >, std::vector< double > >( const std::vector< std::vector < double > >&, std::function< double( const std::vector< double >&, const std::vector< double >& ) > );

template double mean_pairwise_distance< std::vector < std::vector< bool > >, std::vector< bool > >( const std::vector< std::vector < bool > >&, std::function< double( const std::vector< bool >&, const std::vector< bool >& ) > );
