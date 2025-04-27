#include "Chromosome_generator.h"

// explicitní instanciace
template class Chromosome_generator< std::vector< int > >;
template class Chromosome_generator< std::vector< bool > >;


template< typename Chromosome >

Chromosome_generator< Chromosome >::Chromosome_generator( std::function< Chromosome() > chromosome_generator ) : chromosome_generator( chromosome_generator )
{
    //
}

template< typename Chromosome >

void Chromosome_generator< Chromosome >::initialize_population( std::vector< std::pair< Chromosome, double > >& population, const std::size_t population_size ) const
{
    if ( ! this->chromosome_generator )
	    return;

    population = {};
    for ( std::size_t chromosome_index = 0; chromosome_index < population_size; ++chromosome_index )
    {
       population.emplace_back ( std::make_pair ( this->chromosome_generator(), 0 ) );
    }

    return;
}
