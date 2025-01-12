#include "GeneticAlgorithm.h"

template < typename Chromosome >
GeneticAlgorithm< Chromosome >::GeneticAlgorithm( int population_size, double mutation_propability ) : population_size( population_size ),mutation_propability( mutation_propability )
{
    std::srand(time(NULL));
    this->elitism_count = 0;
    this->elitism_enabled = false;
}

template < typename Chromosome >
bool GeneticAlgorithm < Chromosome >::initialize_population()
{
    if ( this->chromosome_generator == nullptr ) return false;

    for ( int chromosome_index = 0; chromosome_index < this->population_size; ++chromosome_index )
    {
        this->population.emplace_back ( std::make_pair ( this->chromosome_generator(), 0 ) );
    }
    
    return true;
}

template < typename Chromosome >
void GeneticAlgorithm < Chromosome >::save_elitism()
{
    if ( this->elitism_count > 0 )
    {
         std::sort( this->population.begin(), this->population.end(), []( const std::pair< Chromosome, double >& first, const std::pair< Chromosome, double >& second )
                {
                    return first.second > second.second;
                }
             );
         for ( int i = 0; i < this->elitism_count; ++i )
         {
            this->elitism_chromosomes.emplace_back(population[ i ]);
         }
    }
}

template < typename Chromosome >
bool GeneticAlgorithm< Chromosome >::evaluate_chromosomes()
{
    if ( this->fitness_evaluator == nullptr ) return false;
    for ( int chromosome_index = 0; chromosome_index < this->population_size; ++chromosome_index )
    {
        if ( this->population [ chromosome_index ].second != 0 ) continue;

        this->population [ chromosome_index ].second = this->fitness_evaluator( this->population[ chromosome_index ].first );
    }
}

template < typename Chromosome >
void GeneticAlgorithm< Chromosome >::apply_elitism()
{
    for ( int i = 0; i < this->elitism_chromosomes.size(); ++i )
    {
        this->population.emplace_back( this->elitism_chromosomes.at( i ) );
    }

    this->elitism_chromosomes = {};
}


template< typename Chromosome >
bool GeneticAlgorithm< Chromosome >::apply_crossover( )
{
    if ( this->crossover == nullptr )
    {
        return false;
    }

    for ( int i = 0; i < this->population_size - this->elitism_size; ++i )
    {
        this->population.emplace_back( std::pair < Chromosome&, double > ( this->crossover->run_crossover( this->selected_chromosomes ), 0.0 ) );
    }

    return true;
}

template< typename Chromosome >
bool GeneticAlgorithm< Chromosome >::apply_mutation( )
{
    if ( this->mutation == nullptr )
    {
        return false;
    }

      for ( int i = this->elitism_size; i < this->population_size; ++i )
        {
            for ( int gene = 0; gene < this->population.at( i ).size(); gene++ )
            {
                if ( ( ( rand() % 1000 ) / 1000.0 ) < this->mutation_propability )
                {
                  this->mutation->run_mutation( this->population.at( i ).first, gene );
                  this->population.at( i ).second = 0.0;
                }
          }
      }

    return true;
}
template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_chromosome_generator ( std::function<Chromosome()> chromosome_generator )
{
    this->chromosome_generator = chromosome_generator;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_fitness_evaluator ( std::function< double ( Chromosome& ) > chromosome_evaluator )
{
    this->chromosome_evaluator = chromosome_evaluator;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_gene_mutation ( std::function< void ( Chromosome&, int ) > gene_mutation )
{
    this->gene_mutation = gene_mutation;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_end_cirterium ( std::function< bool ( std::vector< Chromosome >& population ) > end_criterium )
{
    this->end_criterium = end_criterium;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_elitism( int elitism_count )
{
    this->elitism_enabled = true;
    this->elitism_count = elitism_count;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::disable_elitism( )
{
    this->elitism_enabled = false;
}
template< typename Chromosome >
bool GeneticAlgorithm< Chromosome >::run( int generations_count )
{
    // kontrola správného zadání alespoň jednoho ukončrvacího kritéria
    
    if ( generations_count <= 0 && ! this->end_criterium ) return false;

    // inicializace
    bool initialized = this->initialize_population();

    if ( ! initialized ) return false;

    int generation_counter = 1;

    while( 1 )
    {
        //evaluace dle fitness
        
        bool evaluated = this->evaluate_chromozomes();
        
        if ( ! evaluated )
            return false;

        // kontrola ukončovacího kritéria ( dle počtu generací či předané funkce )
        
        if ( generations_count >= 0 )
        {
            if ( generation_counter++ >= generations_count ) break;
        }
        else 
            if ( this->end_criterium( population ) ) break;

        // uložení elitismu předchozí generace 

        if ( this->elitism_enabled )
        {
            this->save_elitism();
        }

        // výběr potenciálních rodičů další generace

        this->selection->run_selection( this->population ,this->selected_chromosomes );


        // vytvoření nové generace populace

        this->population = {};

        // aplikace elitismu z minulé generace
        
        if ( elitism_enabled )
        {
            this->apply_elitism();
        }

        // křížení
        
        bool crossed = this->apply_crossover();

        if ( ! crossed )
            return false;

        // mutace dle pravděpodobnosti
        
        bool mutated = this->apply_mutation();
        
        if ( ! mutated ) 
            return false;
      
    }

    return true;
}
