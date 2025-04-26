/**
 * @file DE_Greedy_Selection.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */
#ifndef DE_GREEDY_SELECTION_HEADER
#define DE_GREEDY_SELECTION_HEADER

#include <vector>
#include <unordered_set>
#include "DE_Selection.h"



template< typename Vector >
/**
 * @class DE_Greedy_Selection
 * @brief abstraktní třída pro aplikaci mutační strategie
 */
class DE_Greedy_Selection : public DE_Selection< Vector >
{
    public:
       	/**
	 * @brief konstruktor třídy DE_Greedy_Selection
	*/	
	    DE_Greedy_Selection();

        virtual bool change_individual( const std::pair< Vector, double >& target, const std::pair< Vector, double >& trial ) const;
        
};
#endif
