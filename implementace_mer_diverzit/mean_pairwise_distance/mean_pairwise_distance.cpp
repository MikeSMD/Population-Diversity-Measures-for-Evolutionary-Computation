#include <functional>
#include "mean_pairwise_distance.h"

template<typename Container, typename Chromosome, typename ReturnType>

double mean_pairwise_distance(const Container& population, std::function< ReturnType( const Chromosome&, const Chromosome& ) > distance_method){
    ReturnType sum = 0;
    int count = ( population.size() * (population.size() - 1) ) / 2;

    for( size_t i = 0; i < population.size(); ++i )
    {
        for ( size_t j = i + 1; j < population.size(); ++j )
        {
            sum += distance_method( population[ i ], population[ j ] );
        }
    }

    return static_cast<double>(sum) / count;
}
