#include "Ackley.h"

double ackley_fitness_function( const double a, const double b, double const c, std::vector< double > individual )
{

	double midres1 = 0.0;
	double midres2 = midres1;
	for ( std::size_t i = 0; i < individual.size(); ++i )
	{
		midres1 += individual[ i ] * individual[ i ];
		midres2 += std::cos ( individual [ i ] * c );
	}

	midres1 *= 1.0 / ( individual.size() );
	midres2 *= 1.0 / ( individual.size() );
	return( (-a)*std::exp(-b * std::sqrt( midres1 ) ) - std::exp( midres2 ) + a + std::exp( 1 ) ) * (-1);
}
