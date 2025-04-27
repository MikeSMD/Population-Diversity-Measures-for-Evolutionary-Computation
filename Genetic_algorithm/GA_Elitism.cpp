#include "GA_Elitism.h"

template < typename Chromosome >
GA_Elitism< Chromosome >::GA_Elitism( std::size_t elitism_count )
{
    this->elitism_count = elitism_count;
}
template < typename Chromosome >

void GA_Elitism< Chromosome >::save_best_chromosomes( std::vector< std::pair< Chromosome, double > >& population )
{
    this->elitism_chromosomes = {};
 if ( this->elitism_count > 0 && this->elitism_count <= population.size())
    {
         std::sort( population.begin(), population.end(), []( const std::pair< Chromosome, double >& first, const std::pair< Chromosome, double >& second )
                {
                    return first.second > second.second;
                }
             );
         for ( size_t i = 0; i < this->elitism_count; ++i )
         {
            this->elitism_chromosomes.emplace_back( population[ i ] );
         }
    }
 else {
 throw std::runtime_error ("save_best_chromosomes: počet hledaných jedinců je příliš velký nebo menší než 1");
 }
}

template < typename Chromosome >


std::vector< std::pair< Chromosome, double > > GA_Elitism< Chromosome >::get_saved_chromosomes() const 
{
    return this->elitism_chromosomes;
}
template < typename Chromosome >


size_t GA_Elitism< Chromosome >::get_elitism_size() const 
{
    return this->elitism_count;
}
template class GA_Elitism< std::vector< bool > >;

template class GA_Elitism< std::vector< int > >;
