#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <numeric>
#include <charconv>


template<typename T>
T convert(std::string line){
    T val;
    std::from_chars(line.c_str(), line.c_str() +  line.size(), val);
    return val;
}

template<typename T>
std::vector<T> read_file(const std::string& path){
    std::ifstream input(path.c_str());
    std::vector<T> vals;
    for(std::string line; getline(input, line);){
        vals.emplace_back(convert<T>(line));
    }

    return vals;
}

int main(int argc, char* argv[])
{
    std::string infile(argv[1]);
    auto vals = read_file<int>(infile);

    /*auto final = std::accumulate(vals.begin(), vals.end(), 0, [](int num1, int num){
                    return num/3 - 2;
                });*/

    int final = 0;
    for(int v : vals){
        final += (v/3) - 2;
    }

    std::cout << final << std::endl;
    return 0;
}
