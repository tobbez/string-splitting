#include <iostream>                                                              
#include <iomanip>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
#include <string.h>
#include <cstdlib>

using namespace std;

void splitc1(vector<string> &tokens, const string &str,
        const string &delimiters = " ") {
    char *saveptr;
    char *cpy, *token;

    cpy = (char*)malloc(str.size() + 1);
    strcpy(cpy, str.c_str());

    for(token = strtok_r(cpy, delimiters.c_str(), &saveptr);
        token != NULL;
        token = strtok_r(NULL, delimiters.c_str(), &saveptr)) {
        tokens.push_back(string(token));
    }

    free(cpy);
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

        splitc1(spline, input_line);  
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
