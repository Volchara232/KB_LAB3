#include "RayTracer.h"
#include <cmath>
#include <limits>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

RayTracer::RayTracer(int w, int h) : width(w), height(h) {}

Vector3 RayTracer::traceRay(const Ray& ray, int depth) {
    if (depth > 5) return Vector3(0, 0, 0);

    double closestT = std::numeric_limits<double>::max();
    bool hitSphere = false;
    Vector3 hitPoint, hitNormal;
    Vector3 hitColor;

    for (const auto& sphere : scene.getSpheres()) {
        double t = sphere.intersect(ray);
        if (t > 0.001 && t < closestT) {
            closestT = t;
            hitSphere = true;
            hitPoint = ray.pointAt(t);
            hitNormal = sphere.getNormal(hitPoint);
            hitColor = sphere.getColor(hitPoint);
        }
    }

    double tPlane = scene.getPlane().intersect(ray);
    if (tPlane > 0.001 && tPlane < closestT) {
        closestT = tPlane;
        hitSphere = false;
        hitPoint = ray.pointAt(tPlane);
        hitNormal = scene.getPlane().getNormal(hitPoint);
        hitColor = scene.getPlane().getColor(hitPoint);

        int tx = static_cast<int>(std::abs(std::floor(hitPoint.getX())));
        int tz = static_cast<int>(std::abs(std::floor(hitPoint.getZ())));
        if ((tx + tz) % 2 == 0) {
            hitColor = hitColor * 0.7;
        }
    }

    if (closestT < std::numeric_limits<double>::max()) {
        Vector3 ambient = scene.getAmbientColor();
        Vector3 shadowRayOrigin = hitPoint + hitNormal * 0.001;
        Ray shadowRay(shadowRayOrigin, (-1.0) * scene.getLightDir());

        bool inShadow = false;


        for (const auto& sphere : scene.getSpheres()) {
            if (sphere.intersect(shadowRay) > 0.001) {
                inShadow = true;
                break;
            }
        }


        if (!inShadow) {
            double tPlaneShadow = scene.getPlane().intersect(shadowRay);
            if (tPlaneShadow > 0.001 && tPlaneShadow < std::numeric_limits<double>::max()) {
                inShadow = true;
            }
        }

        Vector3 diffuse(0, 0, 0);
        if (!inShadow) {
            Vector3 lightDirection = (-1.0) * scene.getLightDir();
            double diff = std::max(0.0, hitNormal.dot(lightDirection));
            diffuse = scene.getLightColor() * diff;
        }

        return hitColor.multiply(ambient + diffuse);
    }


    double t = 0.5 * (ray.getDirection().getY() + 1.0);
    return Vector3(1, 1, 1) * (1.0 - t) + Vector3(0.5, 0.7, 1.0) * t;
}

std::vector<Vector3> RayTracer::render() {
    std::vector<Vector3> pixels(width * height);
    Vector3 cameraPos(0, 0, 0);
    double aspectRatio = static_cast<double>(width) / height;
    double fov = 60.0 * M_PI / 180.0;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double px = (2.0 * (x + 0.5) / width - 1.0) * aspectRatio * std::tan(fov / 2.0);
            double py = (1.0 - 2.0 * (y + 0.5) / height) * std::tan(fov / 2.0);

            Vector3 rayDir(px, py, -1);
            Ray ray(cameraPos, rayDir.normalize());

            Vector3 color = traceRay(ray);


            double r = std::max(0.0, std::min(1.0, color.getX()));
            double g = std::max(0.0, std::min(1.0, color.getY()));
            double b = std::max(0.0, std::min(1.0, color.getZ()));

            r = std::sqrt(r);
            g = std::sqrt(g);
            b = std::sqrt(b);

            pixels[y * width + x] = Vector3(r, g, b);
        }
    }

    return pixels;
}