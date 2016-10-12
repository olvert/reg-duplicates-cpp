/* Includes */
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <chrono>

/* Headers */
void solve(std::string filePath);

/* Code */
int main(int argc, char* argv[]) {

    /* Start clocking */
    auto start = std::chrono::high_resolution_clock::now();

    char* filePath = argv[1];
    solve(filePath);

    /* Result */
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms\n";

    return 0;
}

void solve(std::string filePath) {

    std::ifstream file(filePath);
    std::unordered_set<std::string> set;

    std::string line;
    while (std::getline(file, line))
    {
        //std::cout << line << std::endl;
        if(!set.insert(line).second) {
            std::cout << "Dublett" << std::endl;
            break;
        }
    }
}

#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */
unsigned hash_str(const char* s)
{
    unsigned h = FIRSTH;
    while (*s) {
        h = (h * A) ^ (s[0] * B);
        s++;
    }
    return h; // or return h % C;
}