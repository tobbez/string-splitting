// Contributed by Arash Partow (http://www.partow.net/)
// Requires StrTk (http://www.partow.net/programming/strtk/index.html)
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <iterator>

#include "strtk.hpp"


int main()
{
   std::string input_line;
   typedef std::pair<const char *, const char *> StrLimits;
   std::vector<StrLimits> spline;
   long count = 0;
   timespec start;
   clock_gettime(CLOCK_MONOTONIC, &start);

   std::cin.sync_with_stdio(false); //disable synchronous IO

   const strtk::single_delimiter_predicate<std::string::value_type> delimiter(' ');
   std::size_t numWords = 0;
   std::size_t numChars = 0;

   spline.reserve(100);

   while(std::getline(std::cin, input_line))
   {
      spline.clear();

      numWords += strtk::split(delimiter,
                               input_line,
                               std::back_inserter(spline));

      for (std::vector<StrLimits>::const_iterator iter = spline.begin(); iter != spline.end(); ++iter)
         numChars += iter->second - iter->first;

      count++;
   };

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
