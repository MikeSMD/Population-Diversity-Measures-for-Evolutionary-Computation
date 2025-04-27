#include "GA_offspring_selection.h"

template < typename Chromosome >
GA_offspring_selection< Chromosome >::GA_offspring_selection( double maxActualSelectionPressure, double comparsionFactor, double successRatio, double minSuccesRatio, double decreasing_constant, double minComparsionFactor, double decreasing_constant_cf ) : maxActualSelectionPressure( maxActualSelectionPressure ), comparsionFactor( comparsionFactor ), successRatio( successRatio ), minSuccesRatio( minSuccesRatio ), decreasing_constant ( decreasing_constant ), minComparsionFactor( minComparsionFactor ), decreasing_constant_cf( decreasing_constant_cf )
{
    //
}

template < typename Chromosome >
double GA_offspring_selection< Chromosome >::get_offspring_factor( double offspring_performance, std::pair< double, double >& parents_performance ) const
{
	double min = parents_performance.first;	
	double max = parents_performance.second;
	if( min > max )
	{
		min = max;
		max = parents_performance.first;
	}

	if ( min == max )
		return ( offspring_performance > max ) ? 1 : 0;

	return ( offspring_performance - min ) / ( max - min );
}

template < typename Chromosome >

void GA_offspring_selection< Chromosome >::decrease_selection_pressure()
{
    if ( this->successRatio > this->minSuccesRatio )
    {
        this->successRatio = std::max( this->successRatio - this->decreasing_constant, this->minSuccesRatio );
    }
    else if ( this->comparsionFactor > this->minComparsionFactor )
    {
        this->comparsionFactor = std::max( this->comparsionFactor - this->decreasing_constant_cf, this->minComparsionFactor );
    }
}

template < typename Chromosome >
void GA_offspring_selection< Chromosome >::proceed_selection( std::vector< std::pair < Chromosome, double > >& accepted_offsprings, std::vector<  std::pair < Chromosome, double > >& offsprings, std::vector< std::pair< double, double > >& parents_performance, const int population_size, std::function< void( std::pair< Chromosome, double >& offspring, std::pair< double, double >& parents ) > generate_offspring )
{

    Random_generator& random_generator = Random_generator::get_instance();

    int required_accepted_offsprings = this->successRatio * population_size;

    std::set< int > accepted_ids = {};

    for ( int offspring_id = 0; offspring_id < offsprings.size(); ++offspring_id )
    {
        double offspring_factor = this->get_offspring_factor( offsprings[ offspring_id ].second, parents_performance[ offspring_id ] );
        if ( offspring_factor >= this->comparsionFactor )
        {
            accepted_offsprings.emplace_back( offsprings[ offspring_id ] );
            accepted_ids.insert( offspring_id );
        }
    }

    int attempts = this->maxActualSelectionPressure * 100 * population_size;

    while ( accepted_ids.size() < required_accepted_offsprings )
    {
        attempts -= 1;
        if( attempts < 0 ) break;

        std::pair< Chromosome, double > generated;
        std::pair <double, double> parents_fitness; 
        generate_offspring( generated, parents_fitness );

        double offspring_factor = this->get_offspring_factor( generated.second, parents_fitness );
         
        offsprings.emplace_back( generated );

        if ( offspring_factor >= this->comparsionFactor )
        {
            accepted_offsprings.emplace_back( offsprings[ offsprings.size() - 1 ] );
            accepted_ids.insert( offsprings.size() - 1 );
        }
    }

    int rest = population_size - accepted_ids.size();
    // již z výchozí práce hlavní třídy GeneticAlgorithm bude vždy zaručen dostatečný počet zbylých offspringů. Z toho důvodu tento problém není řešen.
    while( rest-- > 0 )
    {
        int generated_index = 0;
        do
        {
            generated_index = random_generator.generate_int( 0, offsprings.size() - 1 );
        }
        while( accepted_ids.find( generated_index ) != accepted_ids.end() );

        accepted_ids.insert( generated_index );
        accepted_offsprings.emplace_back( offsprings [ generated_index ] );
    }

    double actualSelectionPressure = offsprings.size() / static_cast< double > ( population_size );

    if ( actualSelectionPressure > this->maxActualSelectionPressure )
    {
        this->decrease_selection_pressure();
    }

    return;
}
template class GA_offspring_selection< std::vector< bool > >;

template class GA_offspring_selection< std::vector< int > >;

