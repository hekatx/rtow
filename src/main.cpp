#include "ppm_image.hpp"
#include <iostream>

#define WIDTH 256
#define HEIGHT 256

color ran(int x, int y) {
  auto r = double(x) / (WIDTH - 1);
  auto g = double(y) / (HEIGHT - 1);
  auto b = 0.25;

  int ir = static_cast<int>(255.999 * r);
  int ig = static_cast<int>(255.999 * g);
  int ib = static_cast<int>(255.999 * b);
  return color(ir, ig, ib);
}

int main() {

  PPMImage img(WIDTH, HEIGHT);

  img.write_ppm_file("example.ppm", ran);

  return 0;
};
