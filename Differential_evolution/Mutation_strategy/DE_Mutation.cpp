
#include "DE_Mutation.h"


template class DE_Mutation< std::vector< double > >;

template< typename Vector >
DE_Mutation< Vector >::DE_Mutation( double mutation_factor, std::vector< std::pair< double, double > > ranges ) : mutation_factor( mutation_factor ), ranges( std::move( ranges ) )
{
	//
}

template< typename Vector >
void DE_Mutation< Vector >::get_mutants( const std::vector< std::pair < Vector, double > >& population, std::vector< Vector >& mutants )
{
    this->best_vector = nullptr;
    mutants = {};
    for ( std::size_t i = 0; i < population.size(); ++i )
    {
       mutants.emplace_back( this->Mutate_individual( population, i ) );
    }

    for ( std::size_t i = 0; i < mutants.size(); ++i )
    {
    	for ( std::size_t j = 0; j < mutants[ i ].size(); ++j )
	{
		if ( mutants [ i ][ j ] < this->ranges[ j ].first )
			mutants [ i ][ j ] = this->ranges[ j ].first;

		else if (mutants [ i ][ j ] > this->ranges[ j ].second )
			mutants [ i ][ j ] = this->ranges[ j ].second;
	}
    }

    return;
}


template< typename Vector >
std::vector<std::size_t > DE_Mutation< Vector >::getRandomIndexes( int count, std::size_t population_size, std::size_t index ) const
{

	if ( count > population_size - 1 )
		throw std::runtime_error("getRandomIndexes: velikost populace je menší než požadovaný počet indexů");

	Random_generator& rd = Random_generator::get_instance();
    std::unordered_set< int > indexes = {};

    while( indexes.size() < count )
    {
	    std::size_t generated = rd.generate_int( 0 , population_size - 1 );
	    if ( generated != index )
        	indexes.insert( generated );
    }
    
    return std::vector<std::size_t > ( indexes.begin(), indexes.end() );
}
template < typename Vector >
const Vector* DE_Mutation< Vector >::getBestVector( const std::vector< std::pair < Vector, double > >& population)
{
	if ( this->best_vector != nullptr )
		return this->best_vector ;

	if ( population.size() == 0 )
		throw std::runtime_error("getBestVector: populace je prázdná");

    int best_index = 0;

    if ( population.empty() )
	    return nullptr;
    for ( int i = 1; i < population.size(); ++i )
    {
        if ( population.at( best_index ).second < population.at( i ).second )
        {
            best_index = i;
        }
    }
    this->best_vector = &population.at( best_index ).first;
    return this->best_vector ;
}
