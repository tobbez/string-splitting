// Contributed by Arash Partow (http://www.partow.net/)
// Requires StrTk (http://www.partow.net/programming/strtk/index.html)
#include <iostream>
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
   int sec, lps;
   time_t start = time(NULL);

   std::cin.sync_with_stdio(false); //disable synchronous IO

   const strtk::single_delimiter_predicate<std::string::value_type> delimiter(' ');
   std::size_t numWords = 0;
   std::size_t numChars = 0;

   spline.reserve(100);

   while(std::cin)
   {
      spline.clear();

      std::getline(std::cin, input_line);

      numWords += strtk::split(delimiter,
                               input_line,
                               std::back_inserter(spline));

      for (std::vector<StrLimits>::const_iterator iter = spline.begin(); iter != spline.end(); ++iter)
         numChars += iter->second - iter->first;

      count++;
   };

   count--; //subtract for final over-read
   sec = (int) time(NULL) - start;
   std::cerr << "C++   : Saw " << count << " lines (" << numWords << " words/" << numChars << " chars) in " << sec << " seconds." ;

   if (sec > 0)
   {
      lps = count / sec;
      std::cerr << "  Crunch speed: " << lps << std::endl;
   }
   else
      std::cerr << std::endl;

   return 0;
}
