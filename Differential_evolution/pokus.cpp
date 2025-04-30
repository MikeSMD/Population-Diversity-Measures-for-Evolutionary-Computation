#include "Differential_evolution.h"

#include "Mutation_strategy/DE_Mutation.h"
#include "Mutation_strategy/DE_rand_1.h"
#include "Mutation_strategy/DE_rand_2.h"
#include "Mutation_strategy/DE_rand_to_best_1.h"
#include "Mutation_strategy/DE_curr_to_best_2.h"

#include "Crossover_strategy/DE_Crossover.h"
#include "Crossover_strategy/DE_Binomial_Crossover.h"
#include "Crossover_strategy/DE_Adaptive_Binomial_Crossover.h"
#include "Crossover_strategy/DE_Exponential_Crossover.h"

#include "Selection_strategy/DE_Selection.h"
#include "Selection_strategy/DE_Greedy_selection.h"

#include "Initialization_strategy/DE_Initialization.h"
#include "Initialization_strategy/DE_LHS_Initialization.h"
#include "Initialization_strategy/DE_Uniform_Initialization.h"

#include "DE_Fitness_evaluator.h"

#include <math.h>
#include "Rosenbrock/Rosenbrock.h"
#include "Ackley/Ackley.h"
int main( void )
{
	int dimensions = 15;
	int runs = 30;

	for ( int i = 0; i < runs; ++i )
	{
	std::vector< std::pair< double, double > > ranges;

	for ( int r = 0; r < dimensions; ++r )
	{
		ranges.push_back( std::make_pair( -5, 10 ) );  			// rozsahy pro Rosenbrock
		// ranges.push_back( std::make_pair( -32.768, 32.768 ) );	// rozsahy pro Ackley
	}

	std::vector< std::pair< double, double > > ranges2 = std::vector< std::pair< double, double > >( ranges ) ;
	std::vector< std::pair< double, double > > ranges3 = std::vector< std::pair< double, double > >( ranges ) ;

	// výběr typu inicializace
	DE_Uniform_initialization< std::vector< double> >* initialization = new DE_Uniform_initialization< std::vector< double > >(dimensions, 100, ranges );
	//   DE_LHS_initialization< std::vector< double> >* initialization = new DE_LHS_initialization< std::vector< double > >( 15, 100, ranges );

	// výběr typu mutace
	// DE_Mutation< std::vector< double > >* mutation = new DE_rand_to_best_1< std::vector< double > >( 0.5, ranges2 );               
	DE_Mutation< std::vector< double > >* mutation = new DE_Rand_1< std::vector< double > >( 0.5, ranges2 );    
	//DE_Mutation< std::vector< double > >* mutation = new DE_rand_2< std::vector< double > >( 0.5, ranges2 );
	// DE_Mutation< std::vector< double > >* mutation = new DE_Best_1< std::vector< double > >( 0.5, ranges2 );   
	// DE_Mutation< std::vector< double > >* mutation = new DE_curr_to_best_2< std::vector< double > >( 0.5, ranges2 );                 


	// výběr typu křížení
	DE_Crossover< std::vector< double > >* crossover = new DE_Binomial_Crossover< std::vector< double > > ( 0.9 );  
	// DE_Crossover< std::vector< double > >* crossover = new DE_Exponential_Crossover< std::vector< double > > ( );
	// DE_Crossover< std::vector< double > >* crossover = new DE_Adaptive_Binomial_Crossover< std::vector< double > >  ( );    

	DE_Selection< std::vector< double > >* selection = new DE_Greedy_Selection< std::vector< double > > ();

	/* // pro testování Ackleyho funkce
	   auto ackley = [&]( std::vector< double > individual )
	   {
	   return ackley_fitness_function(20, 0.2, 2 * M_PI, individual );
	   };
	   */ 

	DE_Fitness_evaluator< std::vector< double > >* evaluator = new DE_Fitness_evaluator < std::vector< double > > ( rosenbrock_fitness_function ); // pro testování Rosenbrock Funkce
																		       // DE_Fitness_evaluator< std::vector< double > >* evaluator = new DE_Fitness_evaluator < std::vector< double > > ( ackley ); // pro testování Ackleyho funkce

	Differential_evolution< std::vector< double > >* DE = new Differential_evolution< std::vector< double > >();

	DE->set_initialization_strategy( initialization );
	DE->set_mutation_strategy( mutation );
	DE->set_crossover_strategy( crossover );
	DE->set_selection_strategy( selection );
	DE->set_evaluation_strategy( evaluator );

	DE_Diversity_logger< std::vector< double > >* q = new DE_Diversity_logger< std::vector< double > >( "logs.txt", 4, true, ranges3 );

	DE->run_evolution( 2000, q);
	}

    return -1;
}
