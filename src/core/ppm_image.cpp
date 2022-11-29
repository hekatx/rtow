#include "ppm_image.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>

#define LOG(x, y) std::cout << x << ", " << y << std::endl;

PPMImage::PPMImage(const int w, const int h) : m_width(w), m_height(h){};

int PPMImage::write_ppm_file(const std::string filename,
                             drawing_func draw) const {
  std::ofstream out(filename, std::ios_base::out | std::ios_base::binary);

  if (out.fail()) {
    std::cout << "Failed to write " << filename << std::endl;
    return -1;
  }

  // Set header
  out << "P3" << std::endl;
  out << m_width << " " << m_height << std::endl;
  out << "255" << std::endl;

  for (int j = m_height - 1; j >= 0; j--) {
    for (int i = 0; i < m_width; i++) {
      // LOG(j, i);
      color c = draw(i, j);

      out << c[0] << ' ' << c[1] << ' ' << c[2] << '\n';
    }
  }

  out.close();
  return 0;
};
