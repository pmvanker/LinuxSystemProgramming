#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open file for writing using std::ofstream - output file stream
    // Constructor opens file in write mode, truncates if exists
    std::ofstream outfile("example.txt");
    if (!outfile) {
        std::cerr << "Error opening file for writing" << std::endl;
        return 1;
    }
    // Write to file using << operator - stream insertion
    outfile << "Hello, World!" << std::endl;
    // Close the file explicitly using close() - ensures data is flushed
    outfile.close();

    // Open file for reading using std::ifstream - input file stream
    std::ifstream infile("example.txt");
    if (!infile) {
        std::cerr << "Error opening file for reading" << std::endl;
        return 1;
    }
    std::string line;
    // Read a line from file using std::getline - reads until newline
    std::getline(infile, line);
    std::cout << "Read from file: " << line << std::endl;
    // Close the file
    infile.close();

    return 0;
}