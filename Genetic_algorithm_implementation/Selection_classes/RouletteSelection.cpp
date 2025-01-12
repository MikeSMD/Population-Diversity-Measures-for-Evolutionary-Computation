#include "RouletteSelection.h"
template < typename Chromosome >
RouletteSelection< Chromosome >::RouletteSelection ( double selection_percentage ) : RouletteHelperSelection< Chromosome >( selection_percentage )
{ }

template < typename Chromosome >
void RouletteSelection< Chromosome >::run_selection( std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes )
{
    int sum_fitness = 0;
    std::vector< double > roulette = {};
    for ( int chromosome_index = 0; chromosome_index < population.size(); ++chromosome_index )
    {
        sum_fitness += population[ chromosome_index ].second;
        roulette.emplace_back( sum_fitness );
    }
    //
    this->random_roulette_selection( roulette, population, selected_chromosomes );
}
