#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include <boost/tokenizer.hpp>


int main()
{
   std::string input_line;
   long count = 0;
   int sec, lps;
   time_t start = time(NULL);

   std::cin.sync_with_stdio(false); //disable synchronous IO

   typedef boost::tokenizer<boost::char_separator<char> > Tokenizer;
   boost::char_separator<char> sep(" ");

   while(std::cin)
   {
      std::getline(std::cin, input_line);
      Tokenizer fields(input_line, sep);
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
