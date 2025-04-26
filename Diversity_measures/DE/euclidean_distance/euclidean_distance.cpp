#include "euclidean_distance.h"


template<typename Individual>

double euclidean_distance(const Individual& individualOne, const Individual& individualTwo){


   if ( individualOne.size() != individualTwo.size() )
   {
  	throw std::runtime_error ( "euclidean distance: jedinci nemají stejný počet dimenzí" );
   }

   double sum = 0.0;

   const size_t size = individualOne.size();
   for ( unsigned int i = 0; i < size; ++i )
   {
        sum += std::pow( ( individualOne[ i ] - individualTwo[ i ] ), 2 );
   }

   return std::sqrt( sum );
}

template double euclidean_distance< std::vector< double > >( const std::vector< double >&, const std::vector< double >& );
