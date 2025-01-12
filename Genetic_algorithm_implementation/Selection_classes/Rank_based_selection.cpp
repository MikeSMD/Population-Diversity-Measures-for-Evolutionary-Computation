#include "Rank_based_selection.h"
template < typename Chromosome >
Rank_based_selection< Chromosome >::Rank_based_selection ( double selection_percentage ) : RouletteHelperSelection< Chromosome > ( selection_percentage ){ }

template < typename Chromosome >
void Rank_based_selection< Chromosome >::run_selection( std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes )
{
     std::sort( population.begin(), population.end(), []( const std::pair< Chromosome, double >& first, const std::pair< Chromosome, double >& second )
                {
                    return first.second < second.second;
                }
             );
        
    std::vector< double > roulette = {};
    int sum = 0;
    for ( int i = 0; i < population.size(); ++i )
    {
        sum += ( i + 1 );
        roulette.emplace_back( sum );
    }
    this->random_roulette_selection( roulette, population, selected_chromosomes );
}
