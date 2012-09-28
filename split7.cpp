// Contributed by Arash Partow (http://www.partow.net/)
// Requires StrTk (http://www.partow.net/programming/strtk/index.html)
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "strtk.hpp"


int main()
{
   std::string input_line;
   long count = 0;
   int sec, lps;
   time_t start = time(NULL);

   std::cin.sync_with_stdio(false); //disable synchronous IO

   const strtk::single_delimiter_predicate<std::string::value_type> delimiter(' ');
   std::size_t token_count;

   while(std::cin)
   {
      std::getline(std::cin, input_line);
      strtk::split(delimiter,
                   input_line,
                   strtk::counting_back_inserter<strtk::std_string::range_t>(token_count));
      count++;
   };

   count--; //subtract for final over-read
   sec = (int) time(NULL) - start;
   std::cerr << "C++   : Saw " << count << " lines in " << sec << " seconds." ;

   if (sec > 0)
   {
      lps = count / sec;
      std::cerr << "  Crunch speed: " << lps << std::endl;
   }
   else
      std::cerr << std::endl;

   return 0;
}
