#include "RouletteHelperSelection.h"


template< typename Chromosome >
RouletteHelperSelection< Chromosome >::RouletteHelperSelection ( double selection_percentage ) : GA_Selection< Chromosome >( selection_percentage )
{
}


template< typename Chromosome >
void RouletteHelperSelection< Chromosome >::random_roulette_selection( const std::vector< double >& roulette, const std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes )
{
    selected_chromosomes = {};
   int selection_count = population.size() * this->selection_percentage;
    for ( int i = 0; i < selection_count; ++i )
    {
        double random_number = ( static_cast<double> ( rand() ) / RAND_MAX ) * roulette[ roulette.size() - 1 ];
        int low_index = 0;
        int high_index = roulette.size() -  1;
        int current_index = -1;
        while( low_index <= high_index )
        {
            current_index = ( low_index + high_index ) / 2;

            if ( random_number > roulette[ current_index ] ) low_index = current_index + 1;
            else high_index = current_index - 1;
        }

       selected_chromosomes.emplace_back( population[ current_index ] );
    }
}
