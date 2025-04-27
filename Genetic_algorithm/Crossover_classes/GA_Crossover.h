/**
 * @file GA_Crossover.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_CROSSOVER_HEADER
#define GA_CROSSOVER_HEADER

#include <vector>
#include <utility>

template <typename Chromosome>


/**
 * @class GA_Crossover
 * @brief Třída zajišťující křížení jedinců
 */
class GA_Crossover
{
    protected: 
	/**
	 * @brief Pravděpodobnost křížení
	 *
	 * proměnná uchovávající pravděpodobnost křížení chromozomů pravděpodobnost křížení chromozomů
	*/
        double crossover_propability;
    
    public:
	/**
	 * @brief Konstruktor třídy GA_Crossover
	*/
	GA_Crossover( double crossover_propability );
	/**
	 * @brief metoda pro zkřížení dvou rodičů za účelem získání konkrétních potomků
	 * @param[in] parentOne první z rodičů
	 * @param[in] parentTwo druhý z rodičů
	 * @param[in] generate_two hodnota zda zkřížit rodiče za účelem vytvoření páru jedinců či jedináčka, tato hodnota je ignorována u typů křížení, jež nepodporují generaci dvou chromozomů
 	 * @return - jeden či dva zkřížené chromozomy
	 */
        virtual std::vector< Chromosome > cross_chromosomes( const Chromosome& parentOne, const Chromosome& parentTwo, const bool generate_two ) = 0;
        

	// lze to upravit dle indexů bylo by lepší pro SCX ale nevim mno

	/**
	 * @brief metoda pro zkřížení a vytvoření nových jedinců dle vybraných chromozomů
	 * @param[in, out] offsprings Výstupní paramter pro uchování zkřížených offspringů, na počátku v případě použití třídy SCX by měl mít obsahovat chromozomy z aktuální generace rodičů
	 * @param[in] selected_chromosomes vybrání rodiče pro reprodukci
	 * @param[out] fitness_parents Výstupní parametr pro uložení fitness hodnoty jednotlivých rodičů
	 * @param[in] offspring_count počet offspringů, kteří se mají vytvořit
 	 * @warning - výstupní proměnné budou přepsány
	 * 	    - pokud je použita třída Sequential_construction_crossover, je třeba parametr offsprigs naplnit generaci rodiču, zároveň se nepočítá aktivace offspring selekce po užití této třídy jelikož by to narušilo vlastní princip implementovaný SCX křížením. 
	 */
	virtual void create_offsprings(const std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& offsprings, std::vector< std::pair< double, double > >& fitness_parents, const std::vector< std::size_t >& selected_indices, const int offspring_count = 1 );

	/**
	 * @brief destruktor třídy GA_Crossover
	*/
	virtual ~GA_Crossover() = default;
};
#endif
