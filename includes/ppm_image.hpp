#pragma once
#include "math.hpp"
#include <cstdint>
#include <fstream>
#include <functional>
#include <vector>

using drawing_func = std::function<color(const int x, const int y)>;

class PPMImage {
public:
  int m_width = 0;
  int m_height = 0;

  PPMImage(const int w, const int h);
  int write_ppm_file(const std::string filename, drawing_func draw) const;

private:
  std::vector<std::uint8_t> data = {};
};
