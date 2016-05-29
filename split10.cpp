// http://stackoverflow.com/a/9379203/106471
#include <iostream>                                                              
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void split(vector<string> &ret, const string& s, char delimiter=' ')
{
    ret.clear();
    for(auto itStart = s.begin(), itDelim = itStart, itEnd = s.end(); itStart < itEnd; itStart = itDelim + 1)
    {
        itDelim = find(itStart, itEnd, delimiter);
        ret.emplace_back(string(itStart, itDelim));
    }
}



int main() {
    string input_line;
    long count = 0;
    timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);

    cin.sync_with_stdio(false); //disable synchronous IO
    size_t numWords = 0;
    size_t numChars = 0;

    vector<string> words;
    while(getline(cin, input_line)) 
    {
        split(words, input_line);
        numWords += words.size();
        for(const auto &s:words)
            numChars += s.size();
        count++;
    };

    timespec end;
    clock_gettime(CLOCK_MONOTONIC, &end);
    const double sec = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
    cerr << "C++   : Saw " << count << " lines (" << numWords << " words/" << numChars << " chars) in " << fixed << setprecision(1) << sec << " seconds." ;
    if (sec > 0) {
        const double lps = count / sec;
        cerr << "  Crunch speed: " << fixed << setprecision(1) << lps << endl;
    } else
        cerr << endl;
    return 0;
}
