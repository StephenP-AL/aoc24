#include <iostream>
#include <fstream>

int main () {
    std::fstream infile;
    infile.open("data.txt");
    if(!infile) {
        printf("Failed to open data file\n");
        return 1;
    }
    //Variables for handling file data

    std::string line;
    while (!infile.eof()) {
        getline(infile,line);
        printf("%s-%d\n",line.c_str(),line.length());
    }

    printf("hello world\n");
    return 0;
}
