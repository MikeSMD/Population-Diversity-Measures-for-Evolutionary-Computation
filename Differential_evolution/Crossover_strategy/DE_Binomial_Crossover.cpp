#include "DE_Binomial_Crossover.h"
#include <iostream>
template class DE_Binomial_Crossover< std::vector< double > >;

template< typename Vector >
DE_Binomial_Crossover< Vector >::DE_Binomial_Crossover( double crossover_rate ) : DE_Crossover< Vector >()
{
    this->crossover_rate = crossover_rate;
}
template< typename Vector >
Vector DE_Binomial_Crossover< Vector >::get_trial( const Vector& parent, const Vector& mutant ) const
{
	Random_generator& rd = Random_generator::get_instance();
        int generated_index = rd.generate_int( 0, parent.size() - 1 );

    Vector trial = Vector( parent.size() );

    for ( size_t dimension = 0; dimension < parent.size(); ++dimension )
    {
        double generated_number = rd.generate_double( 0.0, 1.0 );
        
        if ( generated_number < this->crossover_rate || dimension == generated_index )
        {
            trial[ dimension ] = mutant [ dimension ];
        }
        else
        {
            trial[ dimension ] = parent [ dimension ];
        }
    }

    return trial;
}
