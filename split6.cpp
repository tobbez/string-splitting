// http://stackoverflow.com/a/9379203/106471
#include <iostream>                                                              
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

vector<StringRef> split3( string const& str, char delimiter = ' ' )
{
    vector<StringRef>   result;

    enum State { inSpace, inToken };

    State state = inSpace;
    char const*     pTokenBegin = 0;    // Init to satisfy compiler.
    for( auto it = str.begin(); it != str.end(); ++it )
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
    return result;
}

int main() {
    string input_line;
    vector<string> spline;
    long count = 0;
    int sec, lps;
    time_t start = time(NULL);

    cin.sync_with_stdio(false); //disable synchronous IO

    while(cin) {
        getline(cin, input_line);

        vector<StringRef> const v = split3( input_line );
        count++;
    };

    count--; //subtract for final over-read
    sec = (int) time(NULL) - start;
    cerr << "C++   : Saw " << count << " lines in " << sec << " seconds." ;
    if (sec > 0) {
        lps = count / sec;
        cerr << "  Crunch speed: " << lps << endl;
    } else
        cerr << endl;
    return 0;
}
