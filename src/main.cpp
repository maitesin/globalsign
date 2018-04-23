#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

#include "treap.hpp"

 int main(int argc, char * argv[]) {
     if (argc != 2) {
         std::cerr << "Bad number of parameters" << std::endl;
         std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
         return EXIT_FAILURE;
     }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    // The only place where I used C++ strings is to be able to read them out of the file.
    // This could have been done in other ways to read char * out of the file, however, I
    // do not think this was the intent of the limitation for the usage of C++ strings.
    std::string only_string;

    globalsign::Treap treap;

    while (file >> only_string) {
        std::transform(only_string.begin(), only_string.end(), only_string.begin(), ::tolower);
        char const * str = only_string.c_str();
        std::cout << "Word: " << str << std::endl;
        if (!treap.Has(str)) {
            std::cout << "New word!" << std::endl;
            treap.Add(str);
        } else {
            std::cout << "Increase!" << std::endl;
            treap.IncreasePriority(str, 1);
        }
    }
    file.close();

    std::cout << "Total size of the Treap: " << treap.Size() << std::endl;

    return 0;
 }