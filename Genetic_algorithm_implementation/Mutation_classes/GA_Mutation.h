#ifndef GA_MUTATION_HEADER
#define GA_MUTATION_HEADER

#include <functional>

template< typename Chromosome >
class GA_Mutation 
{
    private:
        std::function< void( Chromosome&, int ) > mutation;

    public:
        GA_Mutation( std::function< void ( Chromosome&, int ) > mutation );
        void run_mutation( Chromosome& chromosome, int gene_index );
};


#endif

