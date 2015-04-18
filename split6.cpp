// http://stackoverflow.com/a/9379203/106471
#include <iostream>                                                              
#include <iomanip>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>

using namespace std;

class StringRef
{
private:
    char const*     begin_;
    int             size_;

public:
    int size() const { return size_; }
    char const* begin() const { return begin_; }
    char const* end() const { return begin_ + size_; }

    StringRef( char const* const begin, int const size )
        : begin_( begin )
        , size_( size )
    {}
};

void split3( string const& str, vector<StringRef> &result, char delimiter = ' ' )
{
    enum State { inSpace, inToken };

    State state = inSpace;
    char const*     pTokenBegin = 0;    // Init to satisfy compiler.
    for( string::const_iterator it = str.begin(); it != str.end(); ++it )
    {
        State const newState = (*it == delimiter? inSpace : inToken);
        if( newState != state )
        {
            switch( newState )
            {
            case inSpace:
                result.push_back( StringRef( pTokenBegin, &*it - pTokenBegin ) );
                break;
            case inToken:
                pTokenBegin = &*it;
            }
        }
        state = newState;
    }
    if( state == inToken )
    {
        result.push_back( StringRef( pTokenBegin, &*str.end() - pTokenBegin ) );
    }
}

int main() {
    string input_line;
    vector<StringRef> spline;
    long count = 0;
    timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);

    cin.sync_with_stdio(false); //disable synchronous IO
    size_t numWords = 0;
    size_t numChars = 0;

    while(getline(cin, input_line)) {
        spline.clear();
        split3( input_line, spline );
        numWords += spline.size();
        for (vector<StringRef>::const_iterator iter = spline.begin(); iter != spline.end(); ++iter)
            numChars += iter->size();
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
