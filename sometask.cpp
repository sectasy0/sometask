#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

int digsum(int n);
bool isprime(int n);
bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b);

std::map<int, int> primeNumbers{};

int main() {
    std::ifstream infile("liczby.txt");

    int numberIndex = 1;

    for ( std::string line; std::getline(infile, line); ) {

        int fNumber = std::stoi(line.substr(0, line.find("	")).c_str());
        int sNumber = std::stoi(line.substr(line.find("	"), line.length()).c_str());

        if (isprime(fNumber)) {
            primeNumbers.insert(std::pair<int, int>(numberIndex, fNumber));
        }
        if (isprime(sNumber)) {
            primeNumbers.insert(std::pair<int, int>(numberIndex, sNumber));
        }
        numberIndex++;
    }


    auto maxm = max_element(primeNumbers.begin(), primeNumbers.end(), compare);
    auto minm = min_element(primeNumbers.begin(), primeNumbers.end(), compare);

    std::cout << "Najwieksza liczba pierwsza to " << maxm->second << ", wystepuje w lini " << maxm->first << std::endl;
    std::cout << "Najmniejsza liczba pierwsza to " << minm->second << ", wystepuje w lini " << minm->first;
}


int digsum(int n) {
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}


bool isprime(int n) {
    int i;
    if (n == 1) {
        return false;
    }
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
            break;
        }
    }
    if (n == i) {
        return true;
    }
}

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}