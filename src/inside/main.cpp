////////////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <complex>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
////////////////////////////////////////////////////////////////////////////////

typedef std::complex<double> Point;
typedef std::vector<Point> Polygon;

double inline det(const Point &u, const Point &v) {
	// TODO
	// return 0;
	return u.real() * v.imag() - u.imag() * v.real();

}

// Return true iff [a,b] intersects [c,d], and store the intersection in ans
bool intersect_segment(const Point &a, const Point &b, const Point &c, const Point &d, Point &ans) {
	// TODO
	// return true;
	double d1 = det(c-a, b-a);
    double d2 = det(d-a, b-a);
	double d3 = det(a-c, d-c);
	double d4 = det(b-c, d-c);
    if (d1 * d2 < 0 && d3 * d4 < 0) {
		double t = d3 / (d3 - d4);
		// double t = d3 / d4;
		ans = c + (d - c) * t;
		return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////

bool is_inside(const Polygon &poly, const Point &query) {
	// 1. Compute bounding box and set coordinate of a point outside the polygon
	// TODO
	Point outside(1e6, query.imag());
	// 2. Cast a ray from the query point to the 'outside' point, count number of intersections
	// TODO
	// return true;
	int count = 0;
    
    for (size_t i = 0; i < poly.size(); ++i) {
        Point a = poly[i];
        Point b = poly[(i + 1) % poly.size()];
        Point intersection;
        if (intersect_segment(query, outside, a, b, intersection)) {
            // if (std::abs(intersection.imag() - query.imag()) < 1e-9) {
            //     return true; // Point is on an edge
            // }
            // if (intersection.real() > query.real()) {
            //     count++;
            // }
            count++;

        }
    }
    return count % 2 == 1; // Inside if the count of intersections is odd

}

////////////////////////////////////////////////////////////////////////////////

std::vector<Point> load_xyz(const std::string &filename) {
	std::vector<Point> points;
	std::ifstream in(filename);
	// TODO
	// double x, y, z;
    // while (in >> x >> y >> z) {
    //     points.emplace_back(x, y);
    // }
    double x, y;
    while (in >> x >> y) {
        points.emplace_back(x, y);
    }
	return points;
}

Polygon load_obj(const std::string &filename) {
	std::ifstream in(filename);
	// TODO
	if (!in) {
        std::cerr << "Failed to open OBJ file: " << filename << std::endl;
        return Polygon(); // in case there are errors
    }

    Polygon poly; // 存储多边形的点
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string keyword;
        iss >> keyword;

        if (keyword == "v") {
            double x, y;
            iss >> x >> y;
            poly.emplace_back(x, y);
            // double x, y, z;
            // iss >> x >> y >> z;
            // poly.emplace_back(x, y); // 仅添加 x 和 y 坐标部分
        }
        // else if (keyword == "f") {
        //     std::vector<int> vertexIndices;
        //     int index;
        //     while (iss >> index) {
        //         // Process the vertex index. Subtract 1 because OBJ indices are 1-based.
        //         vertexIndices.push_back(index - 1);
        //     }
            
        //     if (vertexIndices.size() >= 3) {
        //         // Create polygon faces from vertex indices.
        //         for (size_t i = 1; i < vertexIndices.size() - 1; ++i) {
        //             poly.push_back(poly[vertexIndices[0]]);
        //             poly.push_back(poly[vertexIndices[i]]);
        //             poly.push_back(poly[vertexIndices[i + 1]]);
        //         }
        //     }
        // }
        // more operation about 'f'?
    }

    return poly;
}

void save_xyz(const std::string &filename, const std::vector<Point> &points) {
	// TODO
	std::ofstream out(filename);
	if (!out.is_open()) {
    	std::cerr << "Cannot open file for writing: " << filename << std::endl;
        return;
    }

    for (const Point &p : points) {
        out << p.real() << " " << p.imag() << " 0" << std::endl; // 设置第三维度为0
    }
    // for (const Point &p : points) {
        // out<<p.real()<<' '<< p.imag()<<" 0\n";
    // }

}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char * argv[]) {
	if (argc <= 2) {
		std::cerr << "Usage: " << argv[0] << " points.xyz polygon.obj result.xyz" << std::endl;
		// std::cerr << "Usage: " << argv[0] << " points.xyz poly.obj result.xyz" << std::endl;
	}

	std::vector<Point> points = load_xyz(argv[1]);
	Polygon poly = load_obj(argv[2]);
	std::vector<Point> result;
	
	for (size_t i = 0; i < points.size(); ++i) {
		if (is_inside(poly, points[i])) {
			result.push_back(points[i]);
		}
	}
	std::cout << "The value of 'point' is: "<< result.size() << std::endl;

	save_xyz(argv[3], result);
	return 0;
}
