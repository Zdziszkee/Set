#include <iostream>
#include "Set.hpp"
#include "tokenize.hpp"
#include <chrono>

int main(int argc, char **argv) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] <<
                " <mode> (common_words, unique_words, all_words) <first_file> <second_file>"
                << std::endl;
        return 1;
    }

    const std::string mode = argv[1];
    const std::string first_file = argv[2];
    const std::string second_file = argv[3];

    std::vector<std::string> first_file_contents = readAndTokenize(first_file);
    std::vector<std::string> second_file_contents = readAndTokenize(second_file);

    Set first_set(2);
    Set second_set(2);

    for (const auto &
         str: first_file_contents) {
        first_set.insert(str);
    }
    for (const auto &
         str: second_file_contents) {
        second_set.insert(str);
    }

    if (mode == "common_words") {
        // auto start = std::chrono::high_resolution_clock::now();
        const Set common_words = first_set.intersect(second_set);
        common_words.print();
        // auto end = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<double, std::milli> elapsed_ms = end - start;
        // std::cout << "Execution time: " << elapsed_ms.count() << " ms\n";
    } else if (mode == "unique_words") {
        //auto start = std::chrono::high_resolution_clock::now();
        const Set unique_in_first = first_set.difference(second_set);
        const Set unique_in_second = second_set.difference(first_set);
        std::cout << first_file << ":" << std::endl;
        unique_in_first.print();
        std::cout << second_file << ":" << std::endl;
        unique_in_second.print();
        // auto end = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<double, std::milli> elapsed_ms = end - start;
        // std::cout << "Execution time: " << elapsed_ms.count() << " ms\n";
    } else if (mode == "all_words") {
        //auto start = std::chrono::high_resolution_clock::now();
        const Set all_words = first_set.sum(second_set);
        all_words.print();
        // auto end = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<double, std::milli> elapsed_ms = end - start;
        // std::cout << "Execution time: " << elapsed_ms.count() << " ms\n";
    } else {
        std::cerr << "Mode must be one of common_words, unique_words and all_words." << std::endl;
        return 1;
    }
}
