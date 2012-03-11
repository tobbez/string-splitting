#include <iostream>                                                              
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
#include <string.h>

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
    int sec, lps;
    time_t start = time(NULL);

    cin.sync_with_stdio(false); //disable synchronous IO

    while(cin) {
        getline(cin, input_line);
        spline.clear(); //empty the vector for the next line to parse

        splitc1(spline, input_line);  

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
