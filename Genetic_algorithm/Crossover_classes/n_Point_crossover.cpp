#include"n_Point_crossover.h"

template class n_Point_crossover<std::vector<int>>;
template class n_Point_crossover<std::vector<bool>>;

template < typename Chromosome >

n_Point_crossover< Chromosome >::n_Point_crossover( double crossover_propability, int crossover_points ) : GA_Crossover<Chromosome>( crossover_propability ), crossover_points( crossover_points )
{
	//
}

template < typename Chromosome >
Chromosome n_Point_crossover< Chromosome >::perform_crossover( const Chromosome& parentOne, const Chromosome& parentTwo, std::unordered_set< int > mask ) const
{
	std::size_t genes = parentOne.size();
    	Chromosome child = Chromosome( genes );
	
	bool first_parent = true; //
	for ( std::size_t gene = 0; gene < genes; ++gene )
	{
		if ( first_parent )
		{
			child[ gene ] = parentOne[ gene ];
		}
		else 
			child[ gene ] = parentTwo[ gene ];

		if ( mask.find( gene ) != mask.end() )
			first_parent = !first_parent;
	}

	return child;
}


template < typename Chromosome >
std::vector< Chromosome > n_Point_crossover< Chromosome >::cross_chromosomes( const Chromosome& parentOne, const Chromosome& parentTwo, const bool generate_two )
{
	Random_generator& random_generator = Random_generator::get_instance();

	int genes = parentOne.size();
	if ( this->crossover_points > parentOne.size() )
		this->crossover_points = genes - 1;

	if ( this->crossover_points <= 0 )
		this->crossover_points = 1;

	std::unordered_set< int > points = {};
	while( points.size() < this->crossover_points )
	{
		int number = random_generator.generate_int( 0, genes - 2 );
		points.insert( number );
	}
	std::vector< Chromosome > offsprings = {};
	
	offsprings.emplace_back( perform_crossover( parentOne, parentTwo, points ) );
	
	if ( generate_two )
		offsprings.emplace_back( perform_crossover( parentTwo, parentOne, points ) );

	return offsprings;
}
