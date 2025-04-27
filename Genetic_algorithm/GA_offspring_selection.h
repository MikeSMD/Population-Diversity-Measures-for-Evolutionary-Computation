/**
 * @file GA_offspring_selection.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_OFFSPRING_SELECTION_HEADER
#define GA_OFFSPRING_SELECTION_HEADER
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <vector>
#include "Random_generator.h"
#include <set>

template < typename Chromosome >



/**
 * @class GA_offspring_selection
 * @brief Třída pro offspring selekci
 */
class GA_offspring_selection
{
    private:
	/**
	 * @brief proměnná pro určení nejvyššího povoleného selekčního tlaku
	*/  
	double maxActualSelectionPressure;
	/**
	 * @brief proměnná pro určení porovnávacího faktoru
	*/
        double comparsionFactor;

	  /**
	 * @brief proměnná pro určení nutné míry úspěšnosti
	*/ 
	double successRatio;
  	/**
	 * @brief proměnná pro určení minimální nutné míry úspěšnosti
	*/  
	double minSuccesRatio; 
      /**
	 * @brief proměnná pro určení krok snižování nutné míry úspěšnosti.
	 */  
	double decreasing_constant; 

        /**
	 * @brief proměnná pro určení minimálního porovnávacího faktoru
	*/
	double minComparsionFactor;
     
       
        /**
	 * @brief proměnná pro určení krok snižování porovnávacího faktoru
	 */  
	double decreasing_constant_cf;
	/**
	 * @brief metoda pro zjištění porovnávacího faktoru offspringu vúči jeho rodičům
	 * @param[in] offspring_performance fitness offspringu
	 * @param[in] parents_performance fitness rodičů offspringa
	 *
 	 * @return - porovnávací faktor mezi offspringem a rodiči
	*/
        double get_offspring_factor( double offspring_performance, std::pair< double, double >& parents_performance ) const;

    public:

	/**
	 * @brief konstruktor třídy GA_offspring_selection
	*/
        GA_offspring_selection( double maxActualSelectionPressure, double comparsionFactor, double successRatio, double minSuccesRatio, double decreasing_constant, double minComparsionFactor, double decreasing_constant_cf );

	/**
	 * @brief metoda pro snížení selekčního tlaku
	*/
        void decrease_selection_pressure();

	/**
	 * @brief metoda pro provedení offspring selekce
	 * @param[out] accepted_offsprings výstupní proměnná pro přijaté potomky, zachová své původní data
	 * @param[in] offsprings kolekce offspringů pro rozhodnutí pro jejich přijetí do populace
	 * @param[in] parents_performance seznam fitness rodičů k jednotlivým offspringům
	 * @param[in] population_size velikost populace kterou je nutné naplnit.
	 * @param[in] generate_offspring funkce pro generaci dodatečných jedinců
	*/
        void proceed_selection( std::vector< std::pair < Chromosome, double > >& accepted_offsprings, std::vector<  std::pair < Chromosome, double > >& offsprings, std::vector< std::pair< double, double > >& parents_performance, const int population_size, std::function< void( std::pair< Chromosome, double >& offspring, std::pair< double, double >& parents ) > generate_offspring );
	/**
	 * @brief destruktor třídy GA_offspring_selection
	*/	
	~GA_offspring_selection() = default;

};

#endif
