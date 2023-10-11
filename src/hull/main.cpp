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
	return (u.real()*v.imag()-u.imag()*v.real());

}

struct Compare {
	Point p0; // Leftmost point of the poly
	bool operator ()(const Point &p1, const Point &p2) {
		// TODO
		// return true;

		double d = det(p1-p0, p2-p0);
        if(d!=0) return d>0;
        return std::abs(p1-p0) < std::abs(p2-p0);
	}
};

// bool inline salientAngle(Point &a, Point &b, Point &c) {
//because there is a problem report: 
// qualifiers dropped in binding reference of type "Point &" to initializer of type "const Point"
bool inline salientAngle(const Point &a, const Point &b, const Point &c) {
	// TODO
	return det(b-a, c-a) > 0;
}

////////////////////////////////////////////////////////////////////////////////

Polygon convex_hull(std::vector<Point> &points) {
	Compare order;
	// TODO
	// order.p0 = Point(0, 0);
	order.p0 = *std::min_element(points.begin(), points.end(), 
								[](const Point&a, const Point&b) {
									return (a.real() < b.real()) || (a.real() == b.real() && a.imag() < b.imag());
								});
	std::sort(points.begin(), points.end(), order);
	Polygon hull;
	// TODO
	// use salientAngle(a, b, c) here
    for (const auto &point : points) {
        while (hull.size() > 1 && !salientAngle(hull[hull.size() - 2], hull.back(), point)) {
            hull.pop_back();
        }
        hull.push_back(point);
    }
	
	return hull;
}

////////////////////////////////////////////////////////////////////////////////

std::vector<Point> load_xyz(const std::string &filename) {
	std::vector<Point> points;
	std::ifstream in(filename);
	// TODO
	//读取的时候要把z也加进去吗？
	if (!in.is_open()) {
        throw std::runtime_error("failed to open file " + filename+"please check again");
    }
    // double x,y,z;
    // while (in >> x >> y>> z) {
    //     points.emplace_back(Point(x, y));
    // }
	double x,y;
    while (in >> x >> y) {
        points.emplace_back(Point(x, y));
    }
	return points;
}

void save_obj(const std::string &filename, Polygon &poly) {
	std::ofstream out(filename);
	if (!out.is_open()) {
		throw std::runtime_error("failed to open file " + filename);
	}
	out << std::fixed;
	for (const auto &v : poly) {
		out << "v " << v.real() << ' ' << v.imag() << " 0\n";
	}
	for (size_t i = 0; i < poly.size(); ++i) {
		out << "l " << i+1 << ' ' << 1+(i+1)%poly.size() << "\n";
	}
	out << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char * argv[]) {
	if (argc <= 3) {//I met problem but not sure whether it's caused by the argc
		std::cerr << "Usage: " << argv[0] << " points.xyz output.obj" << std::endl;
	}
	std::vector<Point> points = load_xyz(argv[1]);
	Polygon hull = convex_hull(points);
	save_obj(argv[2], hull);
	return 0;
}
