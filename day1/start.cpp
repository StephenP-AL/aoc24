#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main () {
    std::fstream infile;
    infile.open("data.txt");
    if(!infile) {
        printf("Failed to open data file\n");
        return 1;
    }
    //Variables for handling file data
    std::vector<int> vleft,vright;

    std::string line;
    while (!infile.eof()) {
        getline(infile,line);
        // Ignore lines without data
        if (line.length() < 13) {
            continue;
        }
        //Get the values and store in vectors
        int left = std::stoi(line.substr(0,5));
        int right = std::stoi(line.substr(8,5));
        vleft.push_back(left);
        vright.push_back(right);
    }
    //Sort the vectors
    std::sort(vleft.begin(),vleft.end());
    std::sort(vright.begin(),vright.end());

    //Calculate the difference
    unsigned int sum = 0;
    for (int i = 0; i < vleft.size(); i++) {
        int diff = vleft[i] - vright[i];
        if (0 > diff) {
            diff *= -1;
        }
        sum += diff;
    }
    //print the result
    printf("%d\n",sum);

    return 0;
}
