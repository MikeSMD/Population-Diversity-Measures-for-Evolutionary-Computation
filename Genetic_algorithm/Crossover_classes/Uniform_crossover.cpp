#include"Uniform_crossover.h"

template class Uniform_crossover< std::vector< int > >;
template class Uniform_crossover< std::vector< bool > >;

template < typename Chromosome >
Uniform_crossover< Chromosome >::Uniform_crossover( double crossover_propability ) : GA_Crossover<Chromosome>( crossover_propability )
{
	//
}

template < typename Chromosome >

Chromosome Uniform_crossover< Chromosome >::perform_crossover( const Chromosome& parentOne, const Chromosome& parentTwo, std::vector< bool > mask ) const
{
	Chromosome child = Chromosome( mask.size() );
	for ( size_t gene = 0; gene < mask.size(); ++gene )
	{
		child[ gene ] = ( mask[ gene ] ) ? parentOne[ gene ] : parentTwo[ gene ];
	}
	return child;
}
template < typename Chromosome >

std::vector< Chromosome > Uniform_crossover< Chromosome >::cross_chromosomes( const Chromosome& parentOne, const Chromosome& parentTwo, const bool generate_two )
{
	Random_generator& random_generator = Random_generator::get_instance();
	std::size_t genes = parentOne.size();

	std::vector< bool > mask = {};
	for ( size_t gene = 0; gene < genes; ++gene )
	{
		mask.emplace_back( random_generator.generate_int( 0, 1 ) == 1 );
	}
	

	std::vector< Chromosome > offsprings = {};
	offsprings.emplace_back( perform_crossover( parentOne, parentTwo, mask ) );
	
	if ( generate_two )
		offsprings.emplace_back( perform_crossover( parentTwo, parentOne, mask ) );
	
	return offsprings;
}
