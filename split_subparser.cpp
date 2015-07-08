// Contributed by Scott Yeager (dsyeager@thehouseofyeager.com)
// Requires subparser and subbuffer (https://github.com/VerizonDigital/json_parser)
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <iterator>

#include "subbuffer.h"
#include "subparser.h"


int main()
{
   std::string input_line;
   std::vector<subbuffer> spline;
   long count = 0;
   timespec start;
   clock_gettime(CLOCK_MONOTONIC, &start);

   std::cin.sync_with_stdio(false); //disable synchronous IO

   std::size_t numWords = 0;
   std::size_t numChars = 0;

   spline.reserve(100);

   while(std::getline(std::cin, input_line))
   {
      spline.clear();
      subparser flds(input_line, ' ', subparser::SKIP_EMPTY);
      numWords += flds.split(spline);

      for (std::vector<subbuffer>::const_iterator iter = spline.begin(); iter != spline.end(); ++iter)
         numChars += (*iter).length();

      count++;
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
