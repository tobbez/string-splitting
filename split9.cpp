#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>


int main()
{
   std::string input_line;
   long count = 0;
   int sec, lps;
   time_t start = time(NULL);

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
