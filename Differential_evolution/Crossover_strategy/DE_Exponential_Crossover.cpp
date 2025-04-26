#include "DE_Exponential_Crossover.h"

template class DE_Exponential_Crossover< std::vector< double > >;

template< typename Vector >
DE_Exponential_Crossover< Vector >::DE_Exponential_Crossover( ) : DE_Crossover< Vector >()
{
}

template< typename Vector >
Vector DE_Exponential_Crossover< Vector >::get_trial( const Vector& parent, const Vector& mutant ) const
{
    Random_generator& rd = Random_generator::get_instance();
    std::size_t starting_dimension = rd.generate_int(0, parent.size() - 1);
    int crossover_count = rd.generate_int(1, parent.size() - 1);


    Vector trial = Vector( parent.size() );

     std::size_t actual_dimension = starting_dimension;
    int count = 0;
    do
    {
        if ( count++ < crossover_count )
        {
            trial[ actual_dimension ] = mutant[ actual_dimension ];
        }
        else
            trial [ actual_dimension ] = parent [ actual_dimension ];

        actual_dimension += 1;
        if ( actual_dimension >= parent.size() ) actual_dimension = 0;
    }
    while( actual_dimension != starting_dimension ); // predelat..

    return trial;
}
