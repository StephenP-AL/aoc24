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

    int rpos = 0; //Index for the right list
    unsigned long long int day2sum = 0; //store for the similarity value
    for (int val : vleft) {
        //Skip values that have no match
        if (val < vright[rpos]) {
            continue;
        }
        //Find matching records
        while (val > vright[rpos]) {
            rpos ++;
        }
        //Count the matching records
        int count = 0;
        while (val == vright[rpos]) {
            count ++;
            rpos ++;
        }
        //update this similarity value
        day2sum += val * count;
    }
    //print the result
    printf("%d\n",day2sum);

    return 0;
}
