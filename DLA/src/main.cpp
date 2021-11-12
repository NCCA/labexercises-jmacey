#include <iostream>
#include <cstdlib>
#include "Walker.h"
#include <fmt/format.h>
#include <cxxopts.hpp>

int main(int argc, char **argv)
{
  cxxopts::Options options("DLA","Simple DLA Simulation");
  options.add_options()
  ("w,width","image width",cxxopts::value<int>()->default_value("200"))
  ("h,height","image height",cxxopts::value<int>()->default_value("200")) 
  ("i,iteration","how long to loop sim",cxxopts::value<int>()->default_value("1000")) 
  ("s,seeds","how many seeds",cxxopts::value<int>()->default_value("1")) 

  ;

  int width;
  int height;
  int seeds;
  int iterations;
  try 
  {
    auto results = options.parse(argc,argv);
    width = results["width"].as<int>();
    height = results["height"].as<int>();
    seeds = results["seeds"].as<int>();
    iterations = results["iteration"].as<int>();

  }
  catch(cxxopts::option_not_exists_exception)
  {
    std::cerr<< options.help() << '\n';
    exit(EXIT_FAILURE);
  } 



  std::cout<<"DLA\n";
  Walker w(width,height);
  for(int i=0; i<seeds; ++i)
    w.randomImageSeed();


  int simCount=0;
  int imageIndex=0;
  for(int i=0; i<iterations; ++i)
  {
    if(w.walk() == true)
    {
      if(!(simCount++ %100))
        w.saveImage(fmt::format("sim{:04d}.exr",imageIndex++));
    }
    w.resetStart();
  }


  w.saveImage("test.exr");
  return EXIT_SUCCESS;
}