/**
 * @file DE_Fitness_evaluator.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */


#ifndef DE_FITNESS_EVALUATOR_HEADER
#define DE_FITNESS_EVALUATOR_HEADER

#include <functional>
#include <vector>

template< typename Individual >

/**
 * @class DE_Fitness_evaluator
 * @brief Třída zajišťující evaluaci jedinců
 * */
class DE_Fitness_evaluator
{
    private:
	/**
	 * @brief fitness_evaluator pro evaluaci jedince
	*/
        const std::function< double( const Individual& ) > fitness_evaluator;
    
    public:
	/**
	 * @brief konstruktor třídy DE_Fitness_evaluator
	 * @param[in] fitness_evaluator - funkce pro evaluaci jedinců
	*/
        DE_Fitness_evaluator( const std::function< double ( const Individual& ) >& fitness_evaluator );
	/**
	 * @brief funkce pro evaluaci jedinců
	 * @param[in] individuals - vektor jedinců pro evaluaci
	 * @throws dle předané funcke na evaluaci jedince v konstruktoru
	*/
       

	void evaluate( std::vector< std::pair < Individual, double > >& individuals ) const;
};


#endif
