#include "Tournament_selection.h"

template < typename Chromosome >
Tournament_selection< Chromosome >::Tournament_selection ( double selection_percentage,int tournament_size ) : GA_Selection< Chromosome >( selection_percentage ), tournament_size( tournament_size ) { }

template < typename Chromosome >
void Tournament_selection< Chromosome >::run_selection( std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes )
{
    std::unordered_set < int > selected = {};

    int selection_count = population.size() * this->selection_percentage;

    while( selected.size() < selection_count )
    {
        int chosen_chromosome = this->tournament_chooser( population );
        if ( selected.find( chosen_chromosome ) == selected.end() )
        {
            selected.insert( chosen_chromosome );
        }
    }

    selected_chromosomes = {};
    for ( int index : selected )
    {
        selected_chromosomes.emplace_back( this->population[ index ] );
    }
}

template < typename Chromosome >
int Tournament_selection< Chromosome >::tournament_chooser(const std::vector< std::pair< Chromosome, double > >& population )
{
    std::unordered_set< int > choosen_indexes;

    double best_fitness = 0.0;
    int best_index = -1;

    while( choosen_indexes.size() < this->tournament_size )
    {
        int index = std::rand() % population.size();

        if ( choosen_indexes.find( index ) != choosen_indexes.end() ) continue;

        if ( best_fitness < population[ index ].second )
        {
            best_fitness = population[ index ].second;
            best_index = index;
        }
        choosen_indexes.insert( index );
    }
    return best_index;
}
