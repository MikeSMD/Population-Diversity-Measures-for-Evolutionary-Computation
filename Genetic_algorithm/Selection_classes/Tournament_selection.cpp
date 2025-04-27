#include "Tournament_selection.h"

//explicitní instanciace
template class Tournament_selection<std::vector<int>>;
template class Tournament_selection<std::vector<bool>>;
template < typename Chromosome >
Tournament_selection< Chromosome >::Tournament_selection ( std::size_t tournament_size ) : GA_Selection< Chromosome >( ), tournament_size( tournament_size ) 
{ 
}
template < typename Chromosome >
void Tournament_selection< Chromosome >::run_selection(std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const
{
    
    std::size_t last_chosen_chromosome = -1;
    std::size_t counter = 0;
    while( counter < selection_count )
    {
	std::size_t chosen_chromosome = this->tournament_chooser( population );
	
	if ( last_chosen_chromosome == chosen_chromosome )
		continue;

	last_chosen_chromosome = chosen_chromosome;
	counter += 1;
	selected_indices.emplace_back( chosen_chromosome );
    }
}
template < typename Chromosome >
int Tournament_selection< Chromosome >::tournament_chooser(const std::vector< std::pair< Chromosome, double > >& population ) const
{
    Random_generator& random_generator = Random_generator::get_instance();
    std::unordered_set< int > choosen_indexes;
    
    double best_fitness = -std::numeric_limits<double>::infinity();
    int best_index = -1;

    while( choosen_indexes.size() < this->tournament_size )
    {
        int index = random_generator.generate_int( 0, population.size() - 1 );

        if ( choosen_indexes.find( index ) != choosen_indexes.end() ) 
		continue;

        if ( best_fitness < population[ index ].second )
        {
            best_fitness = population[ index ].second;
            best_index = index;
        }
        choosen_indexes.insert( index );
    }
    return best_index;
}
