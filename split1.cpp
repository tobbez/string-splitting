// http://stackoverflow.com/q/9378500/106471
#include <iostream>                                                              
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
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
    timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);

    cin.sync_with_stdio(false); //disable synchronous IO
    size_t numWords = 0;
    size_t numChars = 0;

    while(getline(cin, input_line)) {
        spline.clear(); //empty the vector for the next line to parse

        split1(spline, input_line);  
        numWords += spline.size();
        for (vector<string>::const_iterator iter = spline.begin(); iter != spline.end(); ++iter)
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
