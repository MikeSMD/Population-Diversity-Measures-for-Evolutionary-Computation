#include "QAP.h"
std::vector< int > QAP_generate_chromosome( int genes_count )
{
	Random_generator& random_generator = Random_generator::get_instance();

	std::vector< int > chromosome = {};
	std::unordered_set< int > used = {};

	while ( chromosome.size() != genes_count )
	{
		int generated = random_generator.generate_int(0, genes_count - 1);
		if ( ! used.count( generated ) )
		{
			used.insert( generated );
			chromosome.emplace_back( generated );
		}
	}
	
	return chromosome;
}
void mutation_exchange_three( std::vector< int >& chromosome )
{ 
	std::unordered_set < std::size_t > indexes = {};

	std::vector< std::size_t > indexes_vec = {};
	Random_generator& random_generator = Random_generator::get_instance();
	while( indexes.size() < 3 )
	{
		std::size_t r = random_generator.generate_int( 0, chromosome.size() - 1 );
		auto returned = indexes.insert( r );
		if ( returned.second ) indexes_vec.emplace_back( r );
	}



	std::swap(chromosome[ indexes_vec[ 0 ] ], chromosome[ indexes_vec [ 1 ] ] );
    	std::swap(chromosome[ indexes_vec[ 1 ] ], chromosome[ indexes_vec [ 2 ] ] );
}

double QAP_fitness_evaluator( const std::vector< std::vector< int > >& flow, const std::vector< std::vector< int > >& distance, std::vector< int >& chromosome )
{
 	unsigned long sum = 0;
	for ( std::size_t i = 0; i < flow.size(); ++i) {
            for ( std::size_t j = 0; j < flow.size(); ++j) {
                sum += flow[chromosome[i]][chromosome[j]] * distance[i][j];
            }
        }
        return 1 / ( 1 + static_cast<double>( sum ) );
}
