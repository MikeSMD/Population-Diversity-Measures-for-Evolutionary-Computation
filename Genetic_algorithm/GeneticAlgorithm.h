/**
 * @file GeneticAlgorithm.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 26.03.2025
 */

#ifndef GENETICALGORITHM_HEADER
#define GENETICALGORITHM_HEADER

#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>

#include "Selection_classes/GA_Selection.h"
#include "Crossover_classes/GA_Crossover.h"
#include "Mutation_classes/GA_Mutation.h"
#include "Chromosome_generator.h"
#include "GA_Elitism.h"
#include "Fitness_evaluators/Fitness_evaluator.h"
#include "Crossover_classes/Sequential_constructive_crossover.h"

#include "GA_offspring_selection.h"


#include "DiversityLogger.h"

template < typename Chromosome >
/**
 * @class GeneticAlgorithm
 * @brief Třída pro provedení běhů Genetického algoritmu s nastavenými parametry
 */
class GeneticAlgorithm
{
    private:
	/**
	 * @brief Velikost populace
	*/ 
	std::size_t population_size;

	/**
	 * @brief generátor chromozomu
	*/ 
        Chromosome_generator< Chromosome >* chromosome_generator;

	/**
	 * @brief fitness evaluátor
	*/ 
        Fitness_evaluator< Chromosome >* fitness_evaluator;

	/**
	 * @brief Elitismus
	*/ 
        GA_Elitism< Chromosome >* elitism;

	/**
	 * @brief selekční proměnná pro aplikaci selekce
	*/ 
        GA_Selection< Chromosome >* selection;

	/**
	 * @brief proměnná pro aplikaci křížení
	*/ 
        GA_Crossover< Chromosome >* crossover;

	/**
	 * @brief selekční proměnná pro aplikaci mutace
	*/ 
        GA_Mutation< Chromosome >* mutation;

   	/**
	 * @brief selekční proměnná pro aplikaci offspring selekce
	*/  
        GA_offspring_selection< Chromosome >* offspring_selection;

    public:
	/**
	 * @brief konsturktor třídy GeneticAlgorithm
	*/ 
       GeneticAlgorithm ( int population_size );
       
       	/**
	 * @brief setter funkce pro nastavení generátoru chromozomu
	 * @param[in] chromosome_generator instance třídy Chromosome_generator
	*/ 
       void set_chromosome_generator ( Chromosome_generator< Chromosome >* chromosome_generator );

       /**
	 * @brief setter funkce pro nastavení fitness evaluátoru
	 * @param[in] fitness_evaluator instance třídy Fitness_evaluator
	*/ 
       void set_fitness_evaluator (  Fitness_evaluator< Chromosome >* fitness_evaluator );

       /**
	 * @brief setter funkce pro nastavení selekce 
	 * @param[in] selection instance třídy GA_Selection či jejího potomka
	*/ 
       void set_selection ( GA_Selection< Chromosome >* selection );

       /**
	 * @brief setter funkce pro nastavení křížení
	 * @param[in] crossover instance třídy GA_Crossover či jejího potomka
	*/ 
       void set_crossover ( GA_Crossover< Chromosome >* crossover );

	/**
	 * @brief setter funkce pro nastavení mutace 
	 * @param[in] mutation instance třídy GA_Mutation či jejího potomka
	*/ 
       void set_mutation ( GA_Mutation< Chromosome >* mutation );

	/**
	 * @brief setter funkce pro nastavení elitismu
	 * @param[in] elitism instance třídy GA_Elitism
	*/
       void set_elitism( GA_Elitism< Chromosome >* elitism );

       /**
	 * @brief setter funkce pro nastavení selekce offspringů
	 * @param[in] elitism instance třídy GA_offspring_selection
	*/
       void set_offspring_selection( GA_offspring_selection< Chromosome >* offspring_selection );
	/**
	 * @brief funkce pro vytvoření potomků
	 * @param[in] count kolik potomků se má vytvořit.
	 * @param[in] parents_population populace rodičů, ze kterých se potomci vytvářejí
	 * @param[out] offspring_vector kolekce vytvořených offspringů
	 * @param[out] parents_vector kolekce fitness rodičů, dle vytvořených potomků
	*/
       void create_offsprings( const std::size_t count, std::vector< std::pair < Chromosome, double > >& parents_population, std::vector< std::pair < Chromosome, double > >& offspring_vector, std::vector< std::pair< double, double > >& parents_vector );

	/**
	 * @brief funkce pro provedení běhu Genetického algoritmu
	 * @param[in] diversityLogger instance pro měření diverzit a zapisování jejich výsledků
	 * @param[in] generations_count nepovinný parametr pro určení maximálníhon počtu generací
	 * @throws runtime_error - pokud nejsou nastaveny všechny strategie
	*/
       bool run( DiversityLogger< Chromosome >* diversityLogger, int generations_count = -1 );

       /**
	* @brief destruktor tridy GeneticAlgorithm
	*/


       ~GeneticAlgorithm();

};

#endif
