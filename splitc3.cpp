#include <iostream>                                                              
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

void splitc3(vector<string> &tokens, char *str,
        const char *delimiters) {
    char *saveptr;
    char *token;

    for(token = strtok_r(str, delimiters, &saveptr);
        token != NULL;
        token = strtok_r(NULL, delimiters, &saveptr)) {
        tokens.push_back(string(token));
    }
}

int main() {
    const int MAX_LINE = 1024;
    char input_line[MAX_LINE], *result;
    vector<string> spline;
    long count = 0;
    int sec, lps;
    time_t start = time(NULL);

    while((result = fgets(input_line, MAX_LINE, stdin)) != NULL) {
        spline.clear(); //empty the vector for the next line to parse

        if (result[strlen(result)-1] == '\n') {
            result[strlen(result)-1] = '\0';
        }

        splitc3(spline, result, " ");
  
        count++;
    };

    sec = (int) time(NULL) - start;
    cerr << "C++   : Saw " << count << " lines in " << sec << " seconds." ;
    if (sec > 0) {
        lps = count / sec;
        cerr << "  Crunch speed: " << lps << endl;
    } else
        cerr << endl;
    return 0;
}
