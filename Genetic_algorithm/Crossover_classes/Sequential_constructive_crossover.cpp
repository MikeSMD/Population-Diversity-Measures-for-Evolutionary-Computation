#include"Sequential_constructive_crossover.h"


#include <algorithm>
template class Sequential_constructive_crossover< std::vector< int >, int >;
template class Sequential_constructive_crossover< std::vector< bool >, bool >;

template < typename Chromosome, typename Gene >
Sequential_constructive_crossover< Chromosome , Gene >::Sequential_constructive_crossover( double crossover_propability, const std::vector< std::vector< int > >& flowMatrix, const std::vector< std::vector< int > >& distanceMatrix, std::function< double( Chromosome& ) > fitness ) : GA_Crossover< Chromosome > ( crossover_propability ), flowMatrix ( flowMatrix ), distanceMatrix( distanceMatrix ), fitness( fitness )
{
	//
}










template < typename Chromosome, typename Gene >
Gene Sequential_constructive_crossover< Chromosome, Gene > :: findNext( Gene current, Chromosome parent, std::unordered_set< Gene > used_genes )
{
	
	auto iterator = std::find( parent.begin(), parent.end(), current );
	std::size_t curIndex = std::distance( parent.begin(), iterator );
	for ( std::size_t searchId = 1; searchId < parent.size(); ++searchId )
	{
		std::size_t index = ( curIndex + searchId ) % parent.size();
		if ( ! used_genes.count( parent[ index ] ) )
			return parent[ index ];
	}
	throw std::runtime_error("nenalezena následující lokace");
	
}

template < typename Chromosome, typename Gene >
double Sequential_constructive_crossover< Chromosome, Gene > :: Calculate( const Chromosome& offspring, Gene adding_facility , std::size_t adding_location ) const
{
	double value = 0.0;
	for ( std::size_t fac = 0; fac < adding_location; ++fac )
	{
		value += this->flowMatrix[ offspring[ fac ] ][ adding_facility ] * this->distanceMatrix[ fac ][ adding_location ];
		value += this->flowMatrix[ adding_facility ][ offspring[ fac ] ] * this->distanceMatrix[ adding_location ][ fac ];
	}

	return value;
}

template < typename Chromosome, typename Gene >

std::vector< Chromosome > Sequential_constructive_crossover< Chromosome, Gene >::cross_chromosomes( const Chromosome& parentOne, const Chromosome& parentTwo, const bool generate_two )
{
	Random_generator& random_generator = Random_generator::get_instance();
	std::size_t genes = parentOne.size();

	std::unordered_set< Gene > added_genes = std::unordered_set< Gene >();
	Chromosome offspring = Chromosome( genes );

	if ( random_generator.generate_int( 0, 1 ) )
		offspring[ 0 ] = parentOne[ 0 ];
	else
		offspring[ 0 ] = parentTwo [ 0 ];

	for ( std::size_t i = 1; i < genes; ++i )
	{
		added_genes.insert( offspring[ i - 1 ] );
		Gene first = findNext( offspring[ i - 1 ], parentOne, added_genes );
		Gene second = findNext( offspring[ i - 1 ], parentTwo, added_genes );
		double valueFirst = this->Calculate( offspring, first, i );
		double valueSecond = this->Calculate( offspring, second, i );

		if ( valueFirst < valueSecond )
		{
			offspring[ i ] = first;
		}
		else 
			offspring[ i ] = second;

	}

	return { offspring };
}
#include <map>
template < typename Chromosome, typename Gene >
// předpoklad - v offspring vektoru je populace aktuálních rodičů
void Sequential_constructive_crossover< Chromosome, Gene >::create_offsprings(const std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& offsprings, std::vector< std::pair< double, double > >& fitness_parents, const std::vector< std::size_t >& selected_indices, const int offspring_count )
{

	    if ( std::is_same<Gene, bool>::value )
	    {
	    	throw std::runtime_error("nelze spustit SCX s bool");
	    }
	    offsprings = std::vector< std::pair< Chromosome, double > >( population.begin(), population.end() );

	for ( int i = 0; i < selected_indices.size(); i+=2 )
	{
		Random_generator& random_generator = Random_generator::get_instance();

		if ( random_generator.generate_double( 0.0, 1.0 ) <= this->crossover_propability )
		{
			Chromosome returned_offspring = this->cross_chromosomes( offsprings[ selected_indices[ i ] ].first, offsprings[ selected_indices[ i + 1 ] ].first, false )[ 0 ];
			
		        double value = this->fitness( returned_offspring );

			if ( value > offsprings [ selected_indices[ i ] ].second )
			{
				offsprings[ selected_indices[ i ] ] = std::make_pair ( returned_offspring, value );
			}
		}
	}	
}
