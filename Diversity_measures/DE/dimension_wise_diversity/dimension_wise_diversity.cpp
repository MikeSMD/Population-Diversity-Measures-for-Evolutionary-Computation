#include "dimension_wise_diversity.h"

template<typename Container, typename Chromosome>

double dimension_wise_diversity( const Container& population, const std::size_t dimension ){
    
	if ( population.size() == 0 )
	{
		throw std::runtime_error( "dimension_wise_diversity: populace je prázdná" );
	}

	std::vector< double > values = {};
    
    for ( const Chromosome& chromosome : population )
    {
        values.emplace_back( chromosome[ dimension ] );
    }

    std::sort( values.begin(), values.end() );

    double median = 0.0;

    if ( values.size() % 2 == 0 )
    {
        median = ( values[ values.size() / 2  - 1 ] + values[ values.size() / 2 ] ) / 2;
    }
    else
    {
        median = values[ ( values.size() - 1 ) / 2 ];
    }

    double result = 0.0;
    for ( const Chromosome& chromosome : population )
    {
        result += std::abs( median - chromosome[ dimension ] );
    }

    return result / population.size();
}

template double dimension_wise_diversity< std::vector< std::vector< double > >, std::vector< double > >( const std::vector < std::vector< double > >&, const std::size_t );

template<typename Container, typename Chromosome>
double all_dimensions_wise_diversity(const Container& population){
    
    if ( population.size() == 0 )
		throw std::runtime_error( "all_dimensions_wise_diversity: populace je prázdná" );

    size_t chromosome_size = population[ 0 ].size();

    if ( chromosome_size == 0 )
	    throw std::runtime_error ( "all_dimensions_wise_diversity: počet dimenzí je nulový" ) ;

    double result = 0.0;


    for ( size_t i = 0; i < chromosome_size; ++i )
    {
        result += dimension_wise_diversity< Container, Chromosome>( population, i );
    }

    return result / chromosome_size;
}
template double all_dimensions_wise_diversity< std::vector< std::vector< double > >, std::vector< double > >( const std::vector < std::vector< double > >& );

