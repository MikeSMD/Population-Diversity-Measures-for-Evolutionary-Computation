/**
 * @file Differential_evolution.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef DA_DIFERENTIAL_EVOLUTION_HEADER
#define DA_DIFERENTIAL_EVOLUTION_HEADER

#include <vector>
#include "Mutation_strategy/DE_Mutation.h"
#include "Crossover_strategy/DE_Crossover.h"
#include "Selection_strategy/DE_Selection.h"
#include "Initialization_strategy/DE_Initialization.h"
#include "DE_Fitness_evaluator.h"
#include "DE_Diversity_logger.h"

template< typename Individual >

/**
 * @class Differential_evolution
 * @brief Třída zajišťující běh diferenciální evoluce
 */
class Differential_evolution
{

    private:

	/**
	 * @brief objekt třídy DE_Mutation pro mutační strategii
	*/ 
        DE_Mutation< Individual >* mutation;

	/**
	 * @brief objekt třídy DE_Crossover pro strategii křížení
	*/
        DE_Crossover< Individual >* crossover;
        
	/**
	 * @brief objekt třídy DE_Selection pro strategii selekce
	*/
	DE_Selection< Individual >* selection;
        
	/**
	 * @brief objekt třídy DE_Inditialization pro mutační strategii
	*/
	DE_Initialization< Individual >* initialization;
        
	/**
	 * @brief objekt třídy DE_Fitness_evaluator pro evaluaci jedinců
	*/
	DE_Fitness_evaluator< Individual >* evaluator;

    public:

	/**
	 * @brief konstruktor třídy Differential_evolution
	*/	
        Differential_evolution( );

	/**
	 * @brief setter metoda pro nastavení mutační strategie
	 * @param[in] mutation - objekt třídy DE_Mutation
	*/
        void set_mutation_strategy( DE_Mutation< Individual >* mutation );
        
	/**
	 * @brief setter metoda pro nastavení strategie křížení
	 * @param[in] mutation - objekt třídy DE_Crossover
	*/
	void set_crossover_strategy( DE_Crossover< Individual >* crossover );
        
	/**
	 * @brief setter metoda pro nastavení strategie selekce
	 * @param[in] mutation - objekt třídy DE_Selection
	*/	
	void set_selection_strategy( DE_Selection< Individual >* selection );
        
	/**
	 * @brief setter metoda pro nastavení strategie inicializace
	 * @param[in] mutation - objekt třídy DE_Initialization
	*/
	void set_initialization_strategy( DE_Initialization< Individual >* initialization );
        
	/**
	 * @brief setter metoda pro nastavení evaluace jedinců
	 * @param[in] mutation - objekt třídy DE_Fitness_evaluator
	*/
	void set_evaluation_strategy( DE_Fitness_evaluator< Individual >* evaluator );


	/**
	 * @brief setter metoda pro běh DE
	 * @param[in] generation_count - počet generací běhu
	 * @param[in] logger - objekt třídy DE_Diversity_logger pro logování měr diverzit (není povinný )
	 * @throws dle použitých strategií či loggeru
	*/
        void run_evolution(unsigned int generation_count = 1, DE_Diversity_logger< Individual >* logger = nullptr);
        
};


#endif
