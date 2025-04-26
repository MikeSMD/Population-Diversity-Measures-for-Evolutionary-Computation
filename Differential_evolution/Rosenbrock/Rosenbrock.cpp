#include "Rosenbrock.h"

double rosenbrock_fitness_function( std::vector< double > individual )
{

	double fitness = 0.0;
	for ( std::size_t i = 0; i < individual.size() - 1; ++i )
	{
		fitness += 100 * std::pow( ( individual[ i + 1 ] -  individual [ i ] * individual[ i ] ), 2 ) + std::pow(( individual [ i ] - 1 ),2);
	}
	return - fitness;

}
