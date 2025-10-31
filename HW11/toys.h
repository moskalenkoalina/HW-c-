#ifndef TOYS_H
#define TOYS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

struct Toy {
    std::string name;
    double price;
    int min_age;
    int max_age;
};

bool isToySuitableForAge(const Toy& toy, int age);
std::vector<Toy> readToysFromTextFile(const std::string& filename);
std::vector<std::pair<Toy, Toy>> findToyPairs(const std::vector<Toy>& toys, int age, double max_total_price);
void writeResultsToBinaryAndConsole(const std::vector<std::pair<Toy, Toy>>& results, 
                                   const std::string& filename, double max_price);
void createSampleFile(const std::string& filename);

#endif