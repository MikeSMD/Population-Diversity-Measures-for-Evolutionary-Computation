#ifndef GENETICALGORITHM_HEADER
#define GENETICALGORITHM_HEADER

#include <vector>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <algorithm>

#include "Selection_classes/GA_Selection.h"
#include "Crossover_classes/GA_Crossover.h"
#include "Mutation_classes/GA_Mutation.h"

template < typename Chromosome >
class GeneticAlgorithm
{
    private:

        // population
        std::vector< std::pair< Chromosome, double > > population;
        int population_size;

        bool initialize_population ();
        std::function<Chromosome () > chromosome_generator;

        bool evaluate_chromosomes (); 
        std::function< double (Chromosome&) > fitness_evlauator;

        //elitismus
        std::vector< Chromosome > elitism_chromosomes;
        bool elitism_enabled;
        int elitism_count;

        void apply_elitism();
        void save_elitism();

        // selection
        GA_Selection< Chromosome >* selection;

        // crossover
        GA_Crossover< Chromosome >* crossover;
        bool apply_crossover();

        // mutation
        GA_Mutation< Chromosome >* mutation;
        double mutation_propability;
        bool apply_mutation();

        std::function< bool ( std::vector< Chromosome, double >& population ) > end_criterium;
        

    public:
       GeneticAlgorithm ( int population_size, double mutation_propability );
       
       void set_chromosome_generator ( std::function<Chromosome()> chromosome_generator );
       void set_fitness_evaluator ( std::function< double ( Chromosome& ) > chromosome_evaluator );
       void set_gene_mutation ( std::function< void ( Chromosome&, int ) > gene_mutation );
       void set_end_cirterium ( std::function< bool ( std::vector< Chromosome >& population ) > end_criterium );
       void set_elitism( int elitism_count );
        void disable_elitism();

       bool run( int generations_count = -1 );
};

#endif
