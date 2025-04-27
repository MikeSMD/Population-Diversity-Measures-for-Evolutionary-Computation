#include "RouletteHelperSelection.h"

//explicitní instanciace
template class RouletteHelperSelection< std::vector< int > >;
template class RouletteHelperSelection< std::vector< bool > >;

template< typename Chromosome >
RouletteHelperSelection< Chromosome >::RouletteHelperSelection ( ) : GA_Selection< Chromosome >( )
{
}

template< typename Chromosome >
void RouletteHelperSelection< Chromosome >::random_roulette_selection( const std::vector< double >& roulette, const std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const
{

    Random_generator& random_generator = Random_generator::get_instance();

    std::size_t last_chosen_chromosome = population.size(); 
    
   for ( std::size_t i = 0; i < selection_count; ++i )
    {
        double random_number = random_generator.generate_double( 0.0, roulette.back() );
	std::size_t low_index = 0;
	std::size_t high_index = roulette.size() -  1;

	std::size_t current_index = 0;

        while( low_index < high_index )
        {
            current_index = ( low_index + high_index ) / 2;

            if ( random_number >= roulette[ current_index ] )
		    low_index = current_index + 1;
            else 
		    high_index = current_index;
        }

	if ( low_index == last_chosen_chromosome )
	{
		i-=1;
		continue;
	}

	last_chosen_chromosome = low_index;

	selected_indices.emplace_back( low_index );
    }
}
