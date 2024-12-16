#include "dimension_wise_diversity.h"

template<typename Container, typename Chromosome, typename Item>

double dimension_wise_diversity( const Container& population, const unsigned int dimension ){
    std::vector< double > values = {};
    
    for ( Chromosome& chromosome : population )
    {
        values.emplace_back( chromosome[ dimension ] );
    }

    std::sort( values.begin(), values.end() );

    double median = 0.0;

    if ( values.size() % 2 == 0 )
    {
        median = ( values.at( values.size() / 2  - 1 ) + values.at( values.size() / 2 ) ) / 2;
    }
    else
    {
        median = values.at( ( values.size() - 1 ) / 2 );
    }

    double result = 0.0;
    for ( Chromosome& chromosome : population )
    {
        result += std::abs( median - chromosome[ dimension ] );
    }

    return result / population.size();

}

template<typename Container, typename Chromosome, typename Item>
double all_dimensions_wise_diversity(const Chromosome& population){
    
    if ( population.size() == 0 ) return 0.0;

    size_t chromosome_size = population[ 0 ].size();

    double result = 0.0;

    for ( size_t i = 0; i < chromosome_size; ++i )
    {
        result += dimension_wise_diversity( population, i );
    }

    return result / chromosome_size;
}

