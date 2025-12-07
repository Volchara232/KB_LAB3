#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "RayTracer.h"

int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void savePPM(const std::string& filename, const std::vector<Vector3>& pixels,
    int width, int height) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка создания файла: " << filename << std::endl;
        return;
    }

    file << "P3\n" << width << " " << height << "\n255\n";
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Vector3& color = pixels[y * width + x];

            int r = static_cast<int>(color.getX() * 255);
            int g = static_cast<int>(color.getY() * 255);
            int b = static_cast<int>(color.getZ() * 255);

            r = clamp(r, 0, 255);
            g = clamp(g, 0, 255);
            b = clamp(b, 0, 255);

            file << r << " " << g << " " << b << " ";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Изображение сохранено в: " << filename << std::endl;
}

int main() {
    const int WIDTH = 640;
    const int HEIGHT = 480;
    setlocale(LC_ALL, "Russian");

    std::cout << "Запуск трассировщика лучей..." << std::endl;

    RayTracer tracer(WIDTH, HEIGHT);
    std::cout << "Рендеринг " << WIDTH << "x" << HEIGHT << "..." << std::endl;
    std::vector<Vector3> pixels = tracer.render();

    savePPM("output.ppm", pixels, WIDTH, HEIGHT);
    std::cout << "Рендеринг завершен! \n" << std::endl;
    std::cout << "Откройте output.ppm в любом просмотрщике изображений" << std::endl;

    return 0;
}