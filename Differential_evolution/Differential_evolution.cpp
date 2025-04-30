#include "Differential_evolution.h"
#include <stdexcept>

#include <iostream>

#include <vector>

template class Differential_evolution< std::vector< double > >;

template < typename Individual >
Differential_evolution< Individual >::Differential_evolution()
{
    //
}

template < typename Individual >
void Differential_evolution< Individual >::set_mutation_strategy( DE_Mutation< Individual >* mutation )
{
    this->mutation = mutation;
}

template < typename Individual >
void Differential_evolution< Individual >::set_crossover_strategy( DE_Crossover< Individual >* crossover )
{
    this->crossover = crossover;
}


template < typename Individual >
void Differential_evolution < Individual >::set_selection_strategy( DE_Selection< Individual >* selection )
{
    this->selection = selection;
}

template < typename Individual >
void Differential_evolution < Individual >::set_initialization_strategy( DE_Initialization< Individual >* initialization )
{
    this->initialization = initialization;
}
template < typename Individual >
void Differential_evolution < Individual >::set_evaluation_strategy( DE_Fitness_evaluator< Individual >* evaluator )
{
    this->evaluator = evaluator;
}

template < typename Individual >
void Differential_evolution < Individual >::run_evolution( unsigned int generation_count, DE_Diversity_logger< Individual > * logger )
{

    if ( this->selection == nullptr || this->crossover == nullptr || this->mutation == nullptr || this->initialization == nullptr || this->evaluator == nullptr )
    {
        throw std::runtime_error( "run_evolution: strategies not set" );
    }
    std::vector< std::pair< Individual, double > > population;

    std::vector< Individual > mutants;
    std::vector< std::pair < Individual, double > > trials;

    // inicializace populace
    this->initialization->initialize_population( population );

    this->evaluator->evaluate( population );

    int generation_counter = 1;
    while( generation_count -- )
    {

	    std::cout << "generation - " << generation_count << " population size " << population.size() << std::endl;
        mutants = {};
        trials = {};
	    std::cout << "logging "<< std::endl;
        
	    if ( logger != nullptr )
        	logger->log_Diversities( population, generation_counter ++ );
        
        // mutace jedincu
        this->mutation->get_mutants( population, mutants );
        
        // krizeni jedincu
        this->crossover->get_trials( population, mutants, trials );

        // vyhodnoceni jedincu po krizeni
        this->evaluator->evaluate( trials );

        // selekce jedincu do nove generace
        this->selection->update_population( population, trials );
    }


    std::cout << "results - " << std::endl;
    for ( int i = 0; i < population.size(); ++i )
    {
        std::cout << "individual " << i << " fitness " << population[ i ].second << " --- ( ";
        for ( int j = 0; j < population[ i ].first.size(); ++j )
        {
            std::cout << " " << population[ i ].first[ j ];
        }
        std::cout << " )" << std::endl;
    }

    return;
}
