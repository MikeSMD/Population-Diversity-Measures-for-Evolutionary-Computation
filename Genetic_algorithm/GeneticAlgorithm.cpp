#include "GeneticAlgorithm.h"
template class GeneticAlgorithm<std::vector<int>>;
template class GeneticAlgorithm<std::vector<bool>>;


template < typename Chromosome >
GeneticAlgorithm< Chromosome >::GeneticAlgorithm( int population_size ) : population_size( population_size )
{
    this->elitism = nullptr;
    this->offspring_selection = nullptr;
    this->chromosome_generator = nullptr;
    this->fitness_evaluator = nullptr;
    this->selection = nullptr;
    this->mutation = nullptr;
    this->crossover = nullptr;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_chromosome_generator ( Chromosome_generator< Chromosome >* chromosome_generator )
{
    this->chromosome_generator = chromosome_generator;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_fitness_evaluator ( Fitness_evaluator< Chromosome >* fitness_evaluator )
{
    this->fitness_evaluator = fitness_evaluator;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_mutation( GA_Mutation< Chromosome >* mutation )
{
    this->mutation = mutation;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_selection( GA_Selection< Chromosome >* selection )
{
    this->selection = selection;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_crossover( GA_Crossover< Chromosome >* crossover )
{
    if ( dynamic_cast< Sequential_constructive_crossover< Chromosome, int >* > ( crossover ) )
    {
    	if ( this->offspring_selection != nullptr )
	{
		std::cerr << "chyba, nelze nastavit SCX operator kdyz je nastavena offspring selekce" << std::endl; 
		return;
	}
    }
    this->crossover = crossover;
    
}


template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_elitism( GA_Elitism< Chromosome >* elitism )
{
    this->elitism = elitism;
}
	template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::set_offspring_selection( GA_offspring_selection< Chromosome >* offspring_selection )
{
	if ( this->crossover != nullptr )
	{
		if ( dynamic_cast< Sequential_constructive_crossover< Chromosome, int >* > ( crossover ) )
		{
			std::cerr << "chyba, nelze nastavit offspring selekci pri nastavenem SCX" << std::endl; 				
			return;
		}
	}
	this->offspring_selection = offspring_selection;
}

template< typename Chromosome >
void GeneticAlgorithm< Chromosome >::create_offsprings( const std::size_t count, std::vector< std::pair < Chromosome, double > >& parents_population, std::vector< std::pair < Chromosome, double > >& offspring_vector, std::vector< std::pair< double, double > >& parents_vector  )
{
    std::vector< std::size_t > selected_indices = {};
  
    this->selection->run_selection( parents_population, ( ( count % 2 ) ? count + 1 : count ), selected_indices );
    
    this->crossover->create_offsprings(parents_population, offspring_vector, parents_vector, selected_indices, count );
    if (  dynamic_cast< Sequential_constructive_crossover< Chromosome, int >* > ( crossover ) )
    {
 // pokud SCX - odstranění nejhorších k jedinců pro uvolneni mista na elitismus - odstraní se pouze místo pro ty elitistické jedince, jež se nezachovali v populaci
	if ( this->elitism != nullptr )
	{
	    std::vector< std::pair< Chromosome, double > >k = this->elitism->get_saved_chromosomes();
		
	    auto is_same = []( const Chromosome& first, Chromosome& second )
	    {
		   	for ( int i = 0; i < first.size(); ++i )
			{
				if( first[ i ] != second[ i ] )
					return false;
			}
			return true;
	    };
	
	    for ( const auto& chromosome : k )
	    {
		    for ( std::size_t i = 0; i < offspring_vector.size(); ++i )
		    {
			if ( is_same( chromosome.first, offspring_vector[ i ].first ) )
			{
				offspring_vector.erase( offspring_vector.begin() + i);
				break;
			}
		    }
		    
	    }
	std::sort(offspring_vector.begin(), offspring_vector.end(),
          [](const std::pair<Chromosome, double>& a, const std::pair<Chromosome, double>& b) {
              return a.second > b.second; 
          });
	std::size_t space = this->elitism->get_elitism_size() - (this->population_size - offspring_vector.size() );
	offspring_vector.erase(offspring_vector.end() - space, offspring_vector.end());
	}
    }
    this->mutation->mutate_population( offspring_vector );

   this->fitness_evaluator->evaluate_chromosomes( offspring_vector );
}

template< typename Chromosome >
bool GeneticAlgorithm< Chromosome >::run( DiversityLogger< Chromosome >* diversityLogger, int generations_count )
{

	if ( this->chromosome_generator == nullptr || this->fitness_evaluator == nullptr || this->selection == nullptr || this->crossover == nullptr || this->mutation == nullptr )
		throw std::runtime_error("run: nejsou nastaveny všechny strategie");

   DiversityLogger< Chromosome >* logger = diversityLogger;
    
    if ( generations_count <= 0 ) return false;

    std::vector< std::pair < Chromosome, double > > population = {};
    
    this->chromosome_generator->initialize_population( population, this->population_size );

    this->fitness_evaluator->evaluate_chromosomes( population );

    int generation_counter = 1;
    while( 1 )
    {
	
        std::cout << "generation - " << generation_counter << " population size - " << population.size() << std::endl;
        logger->logDiversities( population, generation_counter );

        if ( generations_count >= 0 )
        {
            if ( generation_counter++ >= generations_count ) break;
        }


        if ( this->elitism != nullptr )
            this->elitism->save_best_chromosomes( population );

	int selection_count =  this->population_size -  ( (this->elitism != nullptr ) ? this->elitism->get_elitism_size() : 0 );
	std::vector<std::pair<Chromosome, double>> old_population = std::move(population);
	population = {};

        std::vector< std::pair < double, double > > parents = {};
        std::vector< std::pair < Chromosome, double > > offsprings = {};
    
	this->create_offsprings( selection_count, old_population, offsprings, parents );

        if ( this->elitism != nullptr )
        {
            std::vector< std::pair <Chromosome, double > > elitism_chromsomes = this->elitism->get_saved_chromosomes();
            population.insert( population.begin(), elitism_chromsomes.begin(), elitism_chromsomes.end() );
        }

        if( this->offspring_selection == nullptr )
            	population.insert( population.end(), offsprings.begin(), offsprings.end() );
        else
        {
	   	this->offspring_selection->proceed_selection( population, offsprings, parents, this->population_size - population.size(), [&]( std::pair< Chromosome, double >& offspring, std::pair< double, double >& parents )
                    {
                        std::vector< std::pair < Chromosome, double > > offspring_vector = {};
                        std::vector< std::pair< double, double > > parents_vector = {};
			this->create_offsprings( 1, old_population, offspring_vector, parents_vector );
                        offspring = offspring_vector[ 0 ];
                        parents = parents_vector[ 0 ];
                    }
                    );
        }
        std::cout << "generated " << population.size() << std::endl;
    }

    logger->close();

     this->fitness_evaluator->evaluate_chromosomes( population );

     std::cout << "results - " << std::endl;
    for ( int i = 0; i < population.size(); ++i )
    {
        std::cout << population.at( i ).second << " - ";
        for ( int j = 0; j < population.at( i ).first.size(); ++j )
        {
            std::cout << population[ i ].first[ j ]<< " ";
       	}
        std::cout << std::endl;
    }

    return true;
}
template< typename Chromosome >
GeneticAlgorithm< Chromosome >::~GeneticAlgorithm()
{
	delete this->chromosome_generator;
	delete this->fitness_evaluator;
	delete this->elitism;
	delete this->selection;
	delete this->crossover;
	delete this->mutation;
	delete this->offspring_selection;
}
