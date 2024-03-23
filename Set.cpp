#include <iostream>
#include "Set.hpp"

#include <set>

#include "tokenize.hpp"


int main() {
    std::vector<std::string> input1 = readAndTokenize("C:\\Users\\Zdziszkee\\CLionProjects\\Set\\lorem.txt");
    std::vector<std::string> input2 = readAndTokenize("C:\\Users\\Zdziszkee\\CLionProjects\\Set\\lorem2.txt");

    Set first_set(2);
    Set second_set(2);

    for (const auto&
         str: input1) {
        first_set.insert(str);
    }
    for (const auto&
         str: input2) {
        second_set.insert(str);
    }

    std::set<std::string> set;
    Set intersection = first_set.intersect(second_set);
    Set sum = first_set.sum(second_set);
    Set difference = first_set.difference(second_set);

    first_set.print();
    std::cout << "xdf<";
}
