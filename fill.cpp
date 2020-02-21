/* fill.cpp
   CSC 116 - Fall 2019
   
   Write your implementation below.

   Muhammad Adil Zafar Khan - 11/15/2019
   V00924050
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include "image.hpp"


int main(int argc, const char** argv){

    std::vector< std::string > args {};
    for(int i = 1; i < argc; i++){
        args.push_back(argv[i]);
    }

    if (args.size() != 7){
        std::cout << "Usage: ./fill <input image> <output image> <x> <y> <r> <g> <b>" << std::endl;
        return 1;
    }

    std::string input_filename {args.at(0)}, output_filename {args.at(1)};
    unsigned int start_x = std::stoi(args.at(2));
    unsigned int start_y = std::stoi(args.at(3));

    unsigned char r = std::stoi(args.at(4));
    unsigned char g = std::stoi(args.at(5));
    unsigned char b = std::stoi(args.at(6));

    int r2 = std::stoi(args.at(4));
    int g2 = std::stoi(args.at(5));
    int b2 = std::stoi(args.at(6));

    if ((r2 < 0 || r2 > 255) || (g2 < 0 || g2 > 255) || (b2 < 0 || b2 > 255)){
        std::cout << "Error: Invalid RGB fill colour" << std::endl;
        return 0;
    }
    
    try{

        Image pic {input_filename};

        unsigned int h = pic.get_height();
        unsigned int w = pic.get_width();

        if ((start_x >= w || start_x < 0 ) || (start_y >= h || start_y < 0 )){
            std::cout << "Error: Invalid starting pixel" << std::endl;
            return 0;
        }

        std::list<std::pair<unsigned int, unsigned int>> point {};
        point.push_back(std::make_pair(start_x,start_y));

        Image::Pixel colour {pic.at(start_x,start_y).r,pic.at(start_x,start_y).g, pic.at(start_x,start_y).b};
        

        pic.at(start_x,start_y).r = r;
        pic.at(start_x,start_y).b = b;
        pic.at(start_x,start_y).g = g;

        std::vector<int> neighbour {1,-1};

        auto iter = point.begin();

        while (point.size() != 0){
            iter = point.begin();
            auto coor = *iter;
            point.pop_front();

            for (auto each : neighbour){
                if ((coor.first + each) < w && (coor.first + each) >= 0){
                    if(pic.at(coor.first + each , coor.second) == colour ){
                        point.push_back(std::make_pair(coor.first + each , coor.second));
                        pic.at(coor.first + each ,coor.second).r = r;
                        pic.at(coor.first + each ,coor.second).b = b;
                        pic.at(coor.first + each ,coor.second).g = g;

                    }

                }
                    
            }

            for (auto each : neighbour){
                if ( (coor.second + each) < h && (coor.second + each) >= 0){
                    
                    if(pic.at(coor.first ,coor.second + each) == colour){
                        point.push_back(std::make_pair(coor.first , coor.second + each));
                        pic.at(coor.first ,coor.second + each).r = r;
                        pic.at(coor.first ,coor.second + each).b = b;
                        pic.at(coor.first ,coor.second + each).g = g;

                    }       

                }
            
            }
        }
        try{
            pic.save(output_filename);
        }
        catch(std::runtime_error){
            std::cout<< "Error: Unable to write output image" << std::endl;
            return 0;
        }
        

    }
    catch(std::runtime_error){
        std::cout<< "Error: Unable to open input image" << std::endl;
        return 0;
    }
    



    return 0;
}