// Contributed by Henrique Bucher (http://www.vitorian.com/)
// Requires SSE4.2
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <unistd.h>

int main()
{
   long count = 0;
   timespec start;
   clock_gettime(CLOCK_MONOTONIC, &start);

   std::cin.sync_with_stdio(false); //disable synchronous IO

   std::size_t numWords = 0;
   std::size_t numChars = 0;

   unsigned bufsize = 1024*1024;
   char* buf = (char*)aligned_alloc( 16, bufsize );

   while ( true ) {
       int nb = ::fread( buf, 1, bufsize, stdin );
       if ( nb<=0 ) break;
       for ( int j=0; j<nb; ++j ) {
           if ( buf[j] == '\n' ) {
               numWords++;
               count++;
           }
           else if ( buf[j] == ' ' ) {
               numWords++;
           }
           else {
               numChars++;
           }
       }
   }

   timespec end;
   clock_gettime(CLOCK_MONOTONIC, &end);
   const double sec = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
   std::cerr << "C++   : Saw " << count << " lines (" << numWords << " words/" << numChars << " chars) in " << std::fixed << std::setprecision(1) << sec << " seconds." ;

   if (sec > 0)
   {
      const double lps = count / sec;
      std::cerr << "  Crunch speed: " << std::fixed << std::setprecision(1) << lps << std::endl;
   }
   else
      std::cerr << std::endl;

   return 0;
}
