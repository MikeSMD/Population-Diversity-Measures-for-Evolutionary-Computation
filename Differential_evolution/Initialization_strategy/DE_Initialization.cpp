#include "DE_Initialization.h"

template class DE_Initialization< std::vector< double > >;

template< typename Vector >
DE_Initialization< Vector >::DE_Initialization( std::size_t dimension_count, std::size_t population_size, std::vector< std::pair < double, double > > dimension_ranges ) : dimension_count ( dimension_count ), population_size( population_size ), dimension_ranges( dimension_ranges )
{
   	if ( dimension_count != dimension_ranges.size() ) 
		throw std::runtime_error ( "DE_Initialization: počet dimenzí a nastavené rozsahy dimenzí se neshodují")  
}

template< typename Vector >
void DE_Initialization< Vector >::initialize_population( std::vector< std::pair < Vector, double > >& population )
{
    population.resize( this->population_size );
    for ( std::size_t individual = 0; individual < population.size(); ++individual )
    {
        population[ individual ] = std::pair< Vector, double >( this->generate_individual(), 0.0 );
    }
}

