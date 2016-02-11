//taken from https://stackoverflow.com/questions/9378500/why-is-splitting-a-string-slower-in-c-than-python
//and modified by Zachary Parchman


#include <iostream>                                                              
#include <iomanip>
#include <string>
#include <vector>

#include <boost/date_time/posix_time/conversion.hpp>

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
    vector<StringRef> ret ;
    ret.reserve(32); //32 is a nice general number. If this was optimized for the benchmark it would be 3

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
                ret.emplace_back(pTokenBegin, &*it - pTokenBegin);
                break;
            case inToken:
                pTokenBegin = &*it;
            }
        }
        state = newState;
    }
    if( state == inToken )
    {
        ret.emplace_back(pTokenBegin, &*str.end() - pTokenBegin);
    }
    return ret;
}

int main() {
    string input_line;
    long count = 0;
    int lps;

    cin.sync_with_stdio(false); //disable synchronous IO

    timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);


    int words=0, chars=0;
    while(cin) {
        getline(cin, input_line);

        std::vector<StringRef> r = split3( input_line );
        words += r.size();

        for( const auto & ref : r){
          chars += ref.size();
        }
        count++;
    };

    count--; //subtract for final over-read

   timespec end;
   clock_gettime(CLOCK_MONOTONIC, &end);
   const double sec = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;

    cerr << "C++   : Saw " << count << " lines ("<<words<<" words/" << chars<<" chars) in " << fixed <<setprecision(1)<< sec << " seconds." ;
    if (sec > 0) {
        lps = count / sec;
        cerr << "  Crunch speed: " << setprecision(1)<< lps << endl;
    } else
        cerr << endl;
    return 0;
}

//compiled with: g++ -Wall -O3 -o split3 split_3.cpp -std=c++11 -flto -march=native
