#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>


int main()
{
   std::string input_line;
   long count = 0;
   timespec start;
   clock_gettime(CLOCK_MONOTONIC, &start);

   std::cin.sync_with_stdio(false); //disable synchronous IO

   std::vector<std::string> spline;
   std::size_t numWords = 0;
   std::size_t numChars = 0;

   while(std::getline(std::cin, input_line)) {
      boost::algorithm::split(spline, input_line, boost::algorithm::is_any_of(" "));
      numWords += spline.size();
      for (std::vector<std::string>::const_iterator iter = spline.begin(); iter != spline.end(); ++iter)
         numChars += iter->size();
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
