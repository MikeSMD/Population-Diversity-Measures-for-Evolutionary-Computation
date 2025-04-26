/**
 * @file DE_Diversity_logger.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef GA_DIVERSITY_LOGGER_HEADER
#define GA_DIVERSITY_LOGGER_HEADER


#include "../Diversity_measures/DE/mahalanobis_distance/mahalanobis_distance.h"
#include "../Diversity_measures/DE/dimension_wise_diversity/dimension_wise_diversity.h"
#include "../Diversity_measures/DE/euclidean_distance/euclidean_distance.h"
#include "../Diversity_measures/DE/clustering/kmeans.h"
#include "../Diversity_measures/DE/MPD/mean_pairwise_distance.h"
#include "../Diversity_measures/DE/manhattan_distance/manhattan_distance.h"
#include "../Diversity_measures/DE/shannon_entropy/shannon_entropy.h"

#include <fstream>
#include <vector>

template < typename Individual >
 /* 
 * @class DE_Diversity_logger
 * @brief Třída zajišťující logování měr diverzit
 *
 */
class DE_Diversity_logger
{

private:
	/**
	 * @brief proměnná uchovávající název logovacího souboru
	*/
	std::ofstream log_file;

	/**
	 * @brief interval výpočtu a zápisu metrik
	*/
	int interval;

	/**
	 * @brief povolený rozsah dimenzí
	*/
	std::vector< std::pair < double, double > > bounds;
public:
  	/**
	 * @brief konstruktor třídy DE_Diversity_logger
	 * @param[in] filename - název souboru
	 * @param[in] interval - interval výpočtu metrik
	 * @param[in] reset - zda přepsat nebo rozšířit logovací soubor
	 * @param[in] bounds - rozsahy dimenzí
	*/
    	DE_Diversity_logger( std::string filename, int interval, bool reset, std::vector< std::pair < double, double > > bounds );

	/**
	 * @brief funkce pro logování diverzit
	 * @param[in] population - populace
	 * @param[in] generation - číslo generace
	 *
	 * @throws dle funkcí výpočtu měr diverzit
	 */
    void log_Diversities( const std::vector< std::pair< Individual, double > >& population, int generation );
    void close();
};

#endif
