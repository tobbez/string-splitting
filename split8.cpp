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
   std::size_t numWords = 0;
   std::size_t numChars = 0;

   while(std::getline(std::cin, input_line)) {
      Tokenizer fields(input_line, sep);
      numWords += std::distance(fields.begin(), fields.end());
      for (Tokenizer::const_iterator iter = fields.begin(); iter != fields.end(); ++iter)
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
