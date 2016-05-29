// http://stackoverflow.com/a/9379203/106471
#include <iostream>                                                              
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class StringRef
{
private:
    const char* m_itBeg;
    int m_iSize;
    
public:
    int size() const { return m_iSize; }
    const char* begin() { return m_itBeg; }
    const char* end() const { return m_itBeg + m_iSize; }
    
    StringRef(const char* &beg, const char* &nd)
    : m_itBeg(beg)
    , m_iSize(nd - beg)
    {}
};

void split(vector<StringRef> &ret, const string& s)
{
    for(auto ps = &s[0], pd = ps, pe = ps + s.size(); ps < pe; ps = pd + 1)
    {
        ret.emplace_back(StringRef(ps, pd = find(ps, pe, ' ')));
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

    vector<StringRef> words;
    while(getline(cin, input_line)) 
    {
        words.clear();
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
