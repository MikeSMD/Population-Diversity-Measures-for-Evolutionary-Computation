#include "Rank_based_selection.h"

#include <iostream>

//explicitní instanciace
template class Rank_based_selection< std::vector< int > >;
template class Rank_based_selection< std::vector< bool > >;

template < typename Chromosome >
Rank_based_selection< Chromosome >::Rank_based_selection ( ) : RouletteHelperSelection< Chromosome > ( ){ }

template < typename Chromosome >
void Rank_based_selection< Chromosome >::run_selection(std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const
{
     std::sort( population.begin(), population.end(), []( const std::pair< Chromosome, double >& first, const std::pair< Chromosome, double >& second )
                {
                    return first.second < second.second;
                }
             );
        
    std::vector< double > roulette = {};
    double sum = 0;
    for ( int i = 0; i < population.size(); ++i )
    {
        sum += ( i + 1.0 );
        roulette.emplace_back( sum );
    }
    this->random_roulette_selection( roulette, population,selection_count, selected_indices );
}
