#include "RouletteSelection.h"
// explicitní instanciace

template class RouletteSelection< std::vector< int > >;
template class RouletteSelection< std::vector< bool > >;

template < typename Chromosome >
RouletteSelection< Chromosome >::RouletteSelection ( ) : RouletteHelperSelection< Chromosome >( )
{ }

template < typename Chromosome >
void RouletteSelection< Chromosome >::run_selection(std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const
	{
    double sum_fitness = 0;
    std::vector< double > roulette = {};
    for ( std::size_t chromosome_index = 0; chromosome_index < population.size(); ++chromosome_index )
    {
        sum_fitness += population[ chromosome_index ].second;
        roulette.emplace_back( sum_fitness );
    }
   
    this->random_roulette_selection( roulette, population, selection_count, selected_indices );
}
