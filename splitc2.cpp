#include <iostream>                                                              
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

void splitc2(vector<string> &tokens, const char *str,
        const char *delimiters) {
    char *saveptr;
    char *cpy, *token;

    cpy = (char*)malloc(strlen(str) + 1);
    strcpy(cpy, str);

    for(token = strtok_r(cpy, delimiters, &saveptr);
        token != NULL;
        token = strtok_r(NULL, delimiters, &saveptr)) {
        tokens.push_back(string(token));
    }

    free(cpy);
}

int main() {
    const int MAX_LINE = 1024;
    char input_line[MAX_LINE], *result;
    vector<string> spline;
    long count = 0;
    timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);
    size_t numWords = 0;
    size_t numChars = 0;

    while((result = fgets(input_line, MAX_LINE, stdin)) != NULL) {
        spline.clear(); //empty the vector for the next line to parse

        if (result[strlen(result)-1] == '\n') {
            result[strlen(result)-1] = '\0';
        }

        splitc2(spline, result, " ");
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
