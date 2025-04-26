#include "DE_Uniform_Initialization.h"
template class DE_Uniform_initialization< std::vector< double > >;

template< typename Vector >
DE_Uniform_initialization< Vector >::DE_Uniform_initialization( std::size_t dimension_count, std::size_t population_size, std::vector< std::pair < double, double > >& dimension_ranges ) : DE_Initialization< Vector >( dimension_count, population_size, dimension_ranges )
{
	//
}
template< typename Vector >
Vector DE_Uniform_initialization< Vector >::generate_individual( )
{
     Random_generator& rd = Random_generator::get_instance();
    Vector generated( this->dimension_count );
    for ( std::size_t dimension = 0; dimension < this->dimension_count; ++dimension )
    {
        generated[ dimension ] = rd.generate_double( this->dimension_ranges[ dimension ].first, this->dimension_ranges[ dimension ].second  );
    }

    return generated;
}
