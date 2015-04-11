// Contributed by Anders Bakken
#include <string>
#include <vector>
#include <sys/time.h>
#include <cstdint>

static inline uint64_t currentTimeMs()
{
    timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * static_cast<uint64_t>(1000)) + (time.tv_usec / static_cast<uint64_t>(1000));
}

int main()
{
    const uint64_t start = currentTimeMs();
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
            case ' ':
                data.push_back(std::string(last, ch));
                last = ch + 1;
                break;
            case '\n':
                data.push_back(std::string(last, ch));
                last = ch + 1;
                data.clear();
                ++lines;
            default:
                break;
            }
            ++ch;
        }
        if (last == buf + sizeof(buf)) {
            pos = 0;
        } else {
            pos = buf + sizeof(buf) - last - 1;
            memmove(buf, last, pos);
        }
    }
    const double elapsed = static_cast<double>(currentTimeMs() - start) / 1000.0;
    printf("C++   : Saw %d lines in %.2f sec\n", lines, elapsed);
    if (elapsed)
        printf("  Crunch speed: %.2f\n", lines / elapsed);

    return 0;
}
