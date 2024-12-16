#include "jaccard_index.h"

template<typename Chromosome, typename Item>

double jaccard_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo ){
    std::set<Item> chromosomeOneAlleles = {};
    std::set<Item> chromosomeTwoAlleles = {};

    for ( size_t i = 0; i < chromosomeOne.size(); ++i )
    {
        chromosomeOneAlleles.insert( chromosomeOne[ i ] );
    }

    for ( size_t i = 0; i < chromosomeTwo.size(); ++i )
    {
        chromosomeTwoAlleles.insert( chromosomeTwo[ i ] );
    }

    std::set<Item> intersection;
    std::set_intersection( chromosomeOneAlleles.begin(), chromosomeOneAlleles.end(), chromosomeTwoAlleles.begin(), chromosomeTwoAlleles.end(), intersection.begin() );

    size_t intersection_count = intersection.size();

    std::set<Item> union_sets;
    std::set_union( chromosomeOneAlleles.begin(), chromosomeOneAlleles.begin(), chromosomeTwoAlleles.begin(), chromosomeTwoAlleles.end(), union_sets.end() );

    size_t union_count = union_sets.size();

    return static_cast<double>( intersection_count ) / union_count;
}
