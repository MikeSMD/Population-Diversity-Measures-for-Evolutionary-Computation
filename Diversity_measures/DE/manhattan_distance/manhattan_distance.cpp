#include "manhattan_distance.h"
#include <vector>


template<typename Individual>

double manhattan_distance( const Individual& individualOne, const Individual& individualTwo ){
   double sum = 0;
   
   size_t size = individualOne.size();

   if ( individualTwo.size() != size )
	   throw std::runtime_error ("manhattan_distance: počet dimenzí jedinců není shodný");
   
   for ( std::size_t i = 0; i < size; ++i )
   {
        sum += std::abs( individualOne[ i ] - individualTwo[ i ] );
   }

   return sum;
}

template double manhattan_distance< std::vector< double > >( const std::vector< double >&, const std::vector< double >& );

