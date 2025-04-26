#include "DE_LHS_Initialization.h"

#include <iostream>

template class DE_LHS_initialization< std::vector< double > >;

template< typename Vector >
DE_LHS_initialization< Vector >::DE_LHS_initialization(std::size_t dimension_count,std::size_t population_size, std::vector< std::pair < double, double > >& dimension_ranges ) : DE_Initialization< Vector >( dimension_count, population_size, dimension_ranges )
{
	//
}

template< typename Vector >
void DE_LHS_initialization< Vector >::initialize_population( std::vector< std::pair < Vector, double > >& population )
{
    this->generated_strat_indexes = {};
    this->generated_strat_indexes.resize( this->dimension_count );
    for ( int i = 0; i < this->dimension_count; ++i )
	    this->generated_strat_indexes[ i ] = std::unordered_set< std::size_t >();


    DE_Initialization< Vector >::initialize_population( population );
}

template< typename Vector >
Vector DE_LHS_initialization< Vector >::generate_individual( )
{
	Random_generator& rd = Random_generator::get_instance();
    Vector generated( this->dimension_count );
    for ( std::size_t dimension = 0; dimension < this->dimension_count; ++dimension )
    {

        std::size_t strat_index;
        do
        {
            strat_index = rd.generate_int( 0, this->population_size - 1 );
        } while( this->generated_strat_indexes[ dimension ].count( strat_index ) );

        this->generated_strat_indexes.at( dimension ).insert( strat_index );

        double strat_size = ( ( this->dimension_ranges[ dimension ].second - this->dimension_ranges[ dimension ].first ) / static_cast< double >( this->population_size ) );
        double strat_begin = strat_size * strat_index + this->dimension_ranges.at( dimension ).first;

        generated[ dimension ] = rd.generate_double( strat_begin, strat_begin + strat_size );
    }

    return generated;
}
