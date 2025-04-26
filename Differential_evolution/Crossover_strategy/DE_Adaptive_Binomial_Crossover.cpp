#include "DE_Adaptive_Binomial_Crossover.h"
template class DE_Adaptive_Binomial_Crossover< std::vector< double > >;
template< typename Vector >
DE_Adaptive_Binomial_Crossover< Vector >::DE_Adaptive_Binomial_Crossover( ) : DE_Crossover< Vector >( )
{
    this->even_call = false;
    this->crossover_rate = 0.0;
}

template< typename Vector >
void DE_Adaptive_Binomial_Crossover< Vector >::get_trials( const std::vector< std::pair < Vector, double > >& population, const std::vector< Vector >& mutants, std::vector< std::pair< Vector, double > >& trials )
{
	Random_generator& rd = Random_generator::get_instance();
    if ( ! this->even_call )
    {
        this->crossover_rate = rd.generate_double( 0.8, 1.0 );
    }
    else
    {
        this->crossover_rate = rd.generate_double( 0.0, 0.2 );
    }

    this->even_call = ! this->even_call;

    DE_Crossover< Vector >::get_trials( population, mutants, trials );
}
template< typename Vector >

void DE_Adaptive_Binomial_Crossover< Vector >::reset_calls()
{
    this->even_call = false;
}

template< typename Vector >
Vector DE_Adaptive_Binomial_Crossover< Vector >::get_trial( const Vector& parent, const Vector& mutant ) const
{
	Random_generator& rd = Random_generator::get_instance();

    Vector trial = Vector( parent.size() );

    for ( size_t dimension = 0; dimension < parent.size(); ++dimension )
    {
        double generated_number = rd.generate_double( 0.0, 1.0 );
        
        if ( generated_number < this->crossover_rate )
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
