// Contributed by Anders Bakken
#include <string>
#include <vector>
#include <string.h>
#include <sys/time.h>
#include <cstdint>

#define MULTIDELIMITER
int main()
{
    const time_t start = time(0);
    char buf[16384];
    size_t pos = 0;
    std::vector<std::string> data;
    int lines = 0;
    int read;
    while ((read = fread(buf + pos, 1, sizeof(buf) - pos - 1, stdin)) > 0) {
        buf[read + pos] = '\0';
        const char *ch = buf;
        const char *last = ch;
        const int count = read + pos;
        for (int i=0; i<count; ++i) {
            switch (*ch) {
            case '\f':
            case '\t':
            case '\v':
            case ' ':
                if (last) {
                    data.push_back(std::string(last, ch));
                    last = 0;
                }
                break;
            case '\n':
                if (last) {
                    data.push_back(std::string(last, ch));
                    last = 0;
                }
                data.clear();
                ++lines;
                break;
            default:
                if (!last)
                    last = ch;
                break;
            }
            ++ch;
        }
        if (!last || last == buf + sizeof(buf)) {
            pos = 0;
        } else {
            pos = buf + sizeof(buf) - last - 1;
            memmove(buf, last, pos);
        }
    }
    const time_t elapsed = time(0) - start;
    printf("C++   : Saw %d lines in %zu seconds.  Crunch speed: %zu\n",
           lines, elapsed, elapsed ? lines / elapsed : 0);

    return 0;
}
