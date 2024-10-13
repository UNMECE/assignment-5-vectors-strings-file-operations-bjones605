#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "pixel.h"

void average_colors(const std::vector<Pixel> &pixels);

void flip_vertically(std::vector<Pixel> &pixels);

int main(int argc, char* argv[]) {
    std::string input_file = argv[1];
    std::ifstream infile(input_file);
    std::vector<Pixel> pixels;
    std::string line;

    while (std::getline(infile, line)) {
        Pixel pixel;
        size_t pos = 0;

        pixel.x = std::stoi(line, &pos);
        line = line.substr(pos + 1);
        
        pixel.y = std::stoi(line, &pos);
        line = line.substr(pos + 1);
        
        pixel.r = std::stof(line, &pos);
        line = line.substr(pos + 1);
        
        pixel.g = std::stof(line, &pos);
        line = line.substr(pos + 1);
        
        pixel.b = std::stof(line);
        pixels.push_back(pixel);
    }

    average_colors(pixels);

    flip_vertically(pixels);

    std::ofstream outfile("flipped.dat");
    for (const auto &pixel : pixels) {
        outfile << pixel.x << "," << pixel.y << "," << pixel.r << "," << pixel.g << "," << pixel.b << "\n";
    }

    return 0;
}

void average_colors(const std::vector<Pixel> &pixels) {
    float sum_r = 0.0f;
    float sum_g = 0.0f;
    float sum_b = 0.0f;
    int count = pixels.size();

    for (size_t i = 0; i < pixels.size(); ++i) {
        const Pixel &pixel = pixels[i];
        sum_r += pixel.r;
        sum_g += pixel.g;
        sum_b += pixel.b;
    }
    float avg_r = sum_r / count;
    float avg_g = sum_g / count;
    float avg_b = sum_b / count;

    std::cout << "Average R: " << avg_r << "\n";
    std::cout << "Average G: " << avg_g << "\n";
    std::cout << "Average B: " << avg_b << "\n";
}

void flip_vertically(std::vector<Pixel> &pixels) {
    int max_y = 600;
    for (size_t i = 0; i < pixels.size(); ++i) {
        Pixel &pixel = pixels[i];
        pixel.y = max_y - pixel.y;
    }
}