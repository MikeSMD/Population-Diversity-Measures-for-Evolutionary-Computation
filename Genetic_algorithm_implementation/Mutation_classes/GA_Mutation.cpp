#include "GA_Mutation.h"

template< typename Chromosome >
GA_Mutation< Chromosome >::GA_Mutation( std::function< void ( Chromosome&, int ) > mutation ) : mutation( mutation )
{
}

template< typename Chromosome >
void GA_Mutation< Chromosome >::run_mutation( Chromosome& chromosome, int gene_index )
{
    this->mutation( chromosome, gene_index );
}
