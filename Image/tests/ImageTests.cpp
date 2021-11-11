#include "Image.h"
#include <gtest/gtest.h>
#include <fmt/format.h>
TEST(RGBA,ctor)
{
  RGBA a;
  ASSERT_EQ(a.r, 0);
  ASSERT_EQ(a.g, 0);
  ASSERT_EQ(a.b, 0);
  ASSERT_EQ(a.a, 255);
  
}
  
TEST(RGBA,userctor)
{
  RGBA a(255,128,64,55);
  ASSERT_EQ(a.r,255);
  ASSERT_EQ(a.g,128);
  ASSERT_EQ(a.b,64);
  ASSERT_EQ(a.a,55);

}

TEST(IMAGE,ctor)
{
  Image img;
  ASSERT_EQ(img.width(),0);
  ASSERT_EQ(img.height(),0);
}

TEST(IMAGE,userCtor)
{
  Image img(250,150);
  ASSERT_EQ(img.width(),250);
  ASSERT_EQ(img.height(),150);
  for(size_t y=0; y<img.height(); ++y)
  {
    for(size_t x=0; x<img.width(); ++x)
    {
      auto pixel=img.getPixel(x,y);
      ASSERT_EQ(pixel.r,0);
      ASSERT_EQ(pixel.g,0);
      ASSERT_EQ(pixel.b,0);
      ASSERT_EQ(pixel.a,255);
      
    }
  }
}

TEST(IMAGE,userCtorColour)
{
  Image img(250,150,255,0,0,255);
  ASSERT_EQ(img.width(),250);
  ASSERT_EQ(img.height(),150);
  for(size_t y=0; y<img.height(); ++y)
  {
    for(size_t x=0; x<img.width(); ++x)
    {
      auto pixel=img.getPixel(x,y);
      ASSERT_EQ(pixel.r,255);
      ASSERT_EQ(pixel.g,0);
      ASSERT_EQ(pixel.b,0);
      ASSERT_EQ(pixel.a,255);
      
    }
  }


}


TEST(IMAGE,writeTofile)
{
  Image img(1024,720,255,0,0,255);
  ASSERT_TRUE(img.save("test.exr"));
}

TEST(IMAGE,setPixel)
{
  Image img(100,100,255,255,255,255);
  for(int i=0; i<img.width(); ++i)
  {
    img.setPixel(i,30,{255,0,0,255});
    img.setPixel(i,31,{255,0,0,255});
    img.setPixel(i,32,{255,0,0,255});
    img.setPixel(i,33,{255,0,0,255});
    img.save(fmt::format("band.{}.exr",i));

  }
}























