// http://stackoverflow.com/q/9378500/106471
#include <iostream>                                                              
#include <string>
#include <sstream>
#include <time.h>
#include <vector>

using namespace std;

void split1(vector<string> &tokens, const string &str,
        const string &delimiters = " ") {
    // Skip delimiters at beginning
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);

    // Find first non-delimiter
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        // Found a token, add it to the vector
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next non-delimiter
        pos = str.find_first_of(delimiters, lastPos);
    }
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
        spline.clear(); //empty the vector for the next line to parse

        split1(spline, input_line);  

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
