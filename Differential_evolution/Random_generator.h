/**
 * @file Random_generator.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef GENERATOR
#define GENERATOR
#include <random>

#include <stdlib.h>
#include <time.h>
/**
 * @class Random_generator
 * @brief  třída pro pseudonáhodnou generaci čísel
 */
class Random_generator
{

private:

	/**
	 * @brief generátor
	*/	
    std::mt19937 generator;

	/**
	 * @brief privátní konstruktor třídy Random_generator
	*/
    Random_generator();


public:

	/**
	 * @brief získání instance třídy Random_generator
	*/
    static Random_generator& get_instance();
 
   /**
	 * @brief funkce pro generaci celočíselné hodnoty
	 * @param[in] minimum - omezení generované hodnoty zdola
	 * @param[in] maximum - omezení generované hodnoty shora
	*/
    int generate_int( int minimum, int maximum );

    /**
	 * @brief funkce pro generaci hodnoty s pohyblivou řadovou čárkou
	 * @param[in] minimum - omezení generované hodnoty zdola
	 * @param[in] maximum - omezení generované hodnoty shora
	*/

    double generate_double ( double minimum, double maximum );
	/**
	 * @brief funkce pro změnu seedu
	 * @param[in] seed - hodnota seedu
	*/

    void change_seed( unsigned long new_seed = 0 );
	/**
	 * @brief zázkaz kopírovacího konsturktoru
	*/

    Random_generator(const Random_generator&) = delete;

	/**
	 * @brief zákaz přiřazení 
	*/
    
    Random_generator& operator=(const Random_generator&) = delete;
};
#endif
