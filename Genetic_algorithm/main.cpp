#include "GeneticAlgorithm.h"
#include "Crossover_classes/n_Point_crossover.h"
#include "Crossover_classes/Uniform_crossover.h"
#include "Selection_classes/Tournament_selection.h"
#include "Selection_classes/RouletteSelection.h"
#include "Selection_classes/Rank_based_selection.h"
#include "GA_Elitism.h"
#include "Fitness_evaluators/Fitness_evaluator.h"
#include "Chromosome_generator.h"
#include "GA_offspring_selection.h"
#include <vector>
#include "SAT_problem/SAT_problem.h"
#include "Graph_coloring_problem/Graph_coloring.h"
#include "instances_SAT.h"
#include "instances_GCP.h"
#include "instances_QAP.h"
#include "QAP/QAP.h"

#include "Mutation_classes/GA_Mutation_per_chromosome.h"
#include <functional>
#include <iostream>

void SAT_problem();
void GCP_problem();

typedef enum
{
	Tournament, Roulette, Ranked_based
} Selection;

typedef enum
{
	n_Point, Uniform, SCX
} Crossover;


struct Params_OS
{
	double maxActualSelectionPressure;
	double comparsionFactor;
	double successRatio; 
	double minSuccesRatio; 
	
	double decreasing_constant;
	double minComparsionFactor;
	double decreasing_constant_cf;

	  Params_OS(double maxActualSelectionPressure, double comparsionFactor, double successRatio, double minSuccesRatio,double decreasing_constant,double minComparsionFactor,double decreasing_constant_cf) : maxActualSelectionPressure(maxActualSelectionPressure), comparsionFactor(comparsionFactor),successRatio(successRatio),minSuccesRatio(minSuccesRatio),decreasing_constant(decreasing_constant),minComparsionFactor(minComparsionFactor),decreasing_constant_cf(decreasing_constant_cf)
	{
		//
	}

	  
} ;

std::ostream& operator<<(std::ostream& os, const Params_OS& params)
{
	os << "   maxActualSelectionPressure: " << params.maxActualSelectionPressure << std::endl;
	os << "   comparsionFactor: " << params.comparsionFactor << std::endl;
	os << "   successRatio: " << params.successRatio << std::endl;
	os << "   minSuccesRatio: " << params.minSuccesRatio << std::endl;
	os << "   decreasing_constant: " << params.decreasing_constant << std::endl;
	os << "   minComparsionFactor: " << params.minComparsionFactor << std::endl;
	os << "   decreasing_constant_cf: " << params.decreasing_constant_cf << std::endl;
	return os;
}

template < typename Chromosome >
struct Params
{
	size_t population_size;
	Selection selection;
	int tournament_parameter = 0;
	Crossover crossover;
	double crossover_rate;
	int crossover_points = 0;
	std::function< void( Chromosome&, int ) > mutation;
	unsigned int elitism_count = 0;
	bool mutation_per_gene;
	double mutation_propability;
	bool offspring_selection;
	Params_OS params_os;
	std::function< double( Chromosome& ) > fitness_evaluator;
	std::function< Chromosome() > chromosome_generator;
	std::function< void( Chromosome& ) > mutation_per_c;
	
	unsigned int generations;
	unsigned int runs;

	 Params(size_t population_size, Selection selection, int tournament_parameter, Crossover crossover, double crossover_rate, int crossover_points, std::function<void(Chromosome&, int)> mutation, unsigned int elitism_count, bool mutation_per_gene, double mutation_propability, bool offspring_selecltion, Params_OS params_os, std::function<double(Chromosome&)> fitness_evaluator, std::function<Chromosome()> chromosome_generator,	std::function< void( Chromosome& ) > mutation_per_c, unsigned int generations, unsigned int runs)
        : population_size(population_size), selection(selection), tournament_parameter(tournament_parameter),crossover(crossover), crossover_rate(crossover_rate), crossover_points(crossover_points),mutation(mutation), elitism_count(elitism_count), mutation_per_gene( mutation_per_gene ), mutation_propability(mutation_propability),offspring_selection(offspring_selecltion), params_os(params_os), fitness_evaluator(fitness_evaluator),chromosome_generator(chromosome_generator),mutation_per_c( mutation_per_c ), generations(generations),runs(runs)
	{
		//
	}
};

template < typename Chromosome >
std::ostream& operator<<(std::ostream& os, const Params<Chromosome>& params)
{
	os << "Population size: " << params.population_size << std::endl;
	os << "Selection: " << (params.selection == Tournament ? "Tournament" : (params.selection == Roulette ? "Roulette" : "Ranked_based")) << std::endl;
	os << "Tournament parameter: " << params.tournament_parameter << std::endl;
	os << "Crossover: " << (params.crossover == n_Point ? "n_Point" : "Uniform") << std::endl;
	os << "Crossover rate: " << params.crossover_rate << std::endl;
	os << "Crossover points: " << params.crossover_points << std::endl;
	os << "Elitism count: " << params.elitism_count << std::endl;
	os << "Mutation probability: " << params.mutation_propability << std::endl;
	os << "Offspring selection: " << (params.offspring_selection ? "Yes" : "No") << std::endl;
	os << "Generations: " << params.generations << std::endl;
	os << "Runs: " << params.runs << std::endl;
	os << "Params_OS: " << params.params_os;
	return os;
}
void QAP_problem();

	template < typename Chromosome, typename Gene >
void run_GA( Params< Chromosome > parameters, std::string outfile, int interval, std::size_t genes = 0 );
int main ( void )
{
// QAP_problem();
 GCP_problem();
//     SAT_problem();
        return -1;
}
template < typename Chromosome, typename Gene >
void run_GA( Params< Chromosome > parameters, std::string outfile, int interval, std::size_t genes )
{
	Random_generator& rd = Random_generator::get_instance();
	GeneticAlgorithm< Chromosome >* GA = new GeneticAlgorithm< Chromosome >( parameters.population_size );
	GA_Selection< Chromosome >* selection = nullptr;
	if ( parameters.selection == Tournament )
    		selection = new Tournament_selection< Chromosome >( parameters.tournament_parameter );

	if ( parameters.selection == Roulette )
    		selection = new RouletteSelection< Chromosome >( );

	if ( parameters.selection == Ranked_based )
    		selection = new Rank_based_selection< Chromosome >( );

 	GA_Crossover< Chromosome >* crossover = nullptr;
	if ( parameters.crossover == n_Point )
        	crossover= new n_Point_crossover< Chromosome >( parameters.crossover_rate, parameters.crossover_points );

	if ( parameters.crossover == Uniform )
        	crossover= new Uniform_crossover< Chromosome >( parameters.crossover_rate );
	if ( parameters.crossover == SCX )
        	crossover= new Sequential_constructive_crossover< Chromosome, Gene>( parameters.crossover_rate, flow_tai30a, distance_tai30a, parameters.fitness_evaluator );

	GA_Elitism< Chromosome >* elitism = nullptr;
	if ( parameters.elitism_count > 0 )
    		elitism = new GA_Elitism< Chromosome >( parameters.elitism_count );
	
	GA_Mutation< Chromosome >* mutation = nullptr;
	if ( parameters.mutation_per_gene )
	{
     	mutation = new GA_Mutation< Chromosome > ( parameters.mutation , parameters.mutation_propability );
	}
	else 
	{
	mutation = new GA_Mutation_per_chromosome< Chromosome > ( parameters.mutation_per_c, parameters.mutation_propability);
	}

	GA_offspring_selection< Chromosome >* offspring_selection = nullptr;
    	if( parameters.offspring_selection )
    		offspring_selection = new GA_offspring_selection< Chromosome >( parameters.params_os.maxActualSelectionPressure, parameters.params_os.comparsionFactor, parameters.params_os.successRatio, parameters.params_os.minSuccesRatio, parameters.params_os.decreasing_constant, parameters.params_os.minComparsionFactor, parameters.params_os.decreasing_constant_cf );

    Fitness_evaluator< Chromosome >* fe = new Fitness_evaluator< Chromosome >( parameters.fitness_evaluator );
            
    Chromosome_generator< Chromosome >* chg = new Chromosome_generator< Chromosome >( parameters.chromosome_generator );



    GA->set_chromosome_generator ( chg );
    GA->set_fitness_evaluator (fe);
    GA->set_selection ( selection );
    GA->set_crossover ( crossover );
    GA->set_mutation ( mutation );
    GA->set_elitism ( elitism );
  if ( offspring_selection != nullptr )  GA->set_offspring_selection ( offspring_selection );

    
    for ( int i = 0; i < parameters.runs; ++i )
    {
        DiversityLogger< Chromosome >* loggers = new DiversityLogger< Chromosome >( outfile, i == 0, interval,genes);
	loggers->setKendallsTau( false );
	loggers->setUnpresentedGenes( false );
	loggers->setJaccardDistance( false );
	loggers->setEditDistance( false );
	loggers->setHammingDistance( false );
	
	loggers->setShannonEnthropy( false );
	loggers->setSimpsonIndex( false );
        
	GA->run(loggers, parameters.generations );
	rd.change_seed();
	delete loggers;
	
    }

    delete GA;

}

void SAT_problem( )
{
	auto fe = [&](std::vector< bool >& r)
            {
			return fitness_evaluator( SAT_v150c645_1, r );
            };

	auto chg =  [&]() 
            {
		return generate_chromosome( 150 );
            };
       Params_OS os = Params_OS( 5.0, 1.0, 1.0, 0.01, 0.02, 0.01, 0.02 );
	Params< std::vector< bool > > parameter =  Params< std::vector< bool > >(100, Tournament, 2, Uniform,.9,15, mutation_gene, 1, true, 0.01, true, os, fe, chg,nullptr, 500, 50 );

	std::string dir = "./tests/SATer/150v/";
	run_GA< std::vector< bool >, bool >( parameter, "logs.txt", 2);
}

	
void GCP_problem()
{
   auto fe = [] (std::vector< int >& r)
	{
       	 return GCP_fitness_evaluator( miles1500, r );
	};/* */
	auto chg = []()
            {
                return GCP_generate_chromosome( 128, 107 ); // genes_count, max_colors_count
            };
	
	auto mutation = [](std::vector< int >& chromosome, int gene_index)
            {
                GCP_mutation_gene( chromosome, gene_index, 107 );
            };
       Params_OS os = Params_OS( 25.0, 1.0, 1.0, 0.001, 0.01, 0.001, 0.01 );
	Params< std::vector< int > > parameter =  Params< std::vector< int > >(100 , Tournament, 2, Uniform, 0.9, 2, mutation, 1, true, 0.1, false, os, fe, chg,nullptr, 500, 50 );
	run_GA< std::vector< int >, int >( parameter, "logs.txt", 2, 107 );

}
void QAP_problem()
{

   auto fe = [] (std::vector< int >& r)
	{
       		return QAP_fitness_evaluator( flow_tai30a, distance_tai30a, r );
	};/* */
	auto chg = []()
            {
                return QAP_generate_chromosome( 30 ); // genes_count, max_colors_count
            };
	
	auto mutation = [](std::vector< int >& chromosome)
            {
                mutation_exchange_three( chromosome );
            };
       Params_OS os = Params_OS( 25.0, 1.0, 1.0, 0.001, 0.01, 0.001, 0.01 );
       Params< std::vector< int > > parameter =  Params< std::vector< int > >(100 , Tournament, 2, SCX, 0.9, 0, nullptr, 1 ,false, 0.3, false, os, fe, chg, mutation, 1000, 50 );
	run_GA< std::vector< int >, int >( parameter, "logs.txt", 2 );

}
