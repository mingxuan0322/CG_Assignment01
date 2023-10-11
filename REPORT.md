# Project Reports

##1: Convex Hull

In this project, we implemented a program to compute the convex hull of a point cloud in a 2D space. The convex hull is the smallest convex polygon that encloses all the given points. We used the Graham Scan algorithm to achieve this.
- We represented points in 2D space using complex numbers (a complex number with real and imaginary parts).
- The `det` function calculated the determinant of two complex vectors, which is essential for identifying the orientation of points.
- We implemented the `Compare` structure to determine the order in which points should be considered when finding the convex hull. This structure helps identify the leftmost point of the polygon.
- The `salientAngle` function determined whether an angle formed by three points was salient, which is a key concept in the Graham Scan algorithm.
- We computed the convex hull by sorting the points based on their angles from the leftmost point. Then, we iterated through the sorted points, creating the convex hull incrementally by checking the angles between points.

### Comments on Results

- The implementation successfully computes the convex hull of a 2D point cloud.
- The Graham Scan algorithm efficiently identifies the convex hull in O(n log n) time complexity, where n is the number of input points.
- The program provides accurate results for a wide range of point clouds, handling both simple and complex cases effectively.

### result :
![Recording](https://drive.google.com/file/d/1RARr1cYwF3sY9E5M3Bt5dUCVuEWAsA5g/view?usp=drive_link)


##2:Polygon

In this project, we implemented a program to determine the intersection of a point cloud with a given polygon. The program reads points from an XYZ file and a polygon from an OBJ file and computes the intersection.

- We used complex numbers to represent 2D points and implemented functions for calculating the determinant and checking for intersection between line segments.
- The `is_inside` function employed a ray-casting algorithm to determine whether a point is inside the polygon.
- We provided functions to load points from an XYZ file and a polygon from an OBJ file and save the results to an XYZ file.

### Comments on Results

- The program successfully determines which points from the point cloud are inside the given polygon.
- The ray-casting algorithm effectively handles the intersection test, providing accurate results.
- The program can process large datasets efficiently and is a valuable tool for spatial analysis and data extraction.


### result :
![Recording](https://drive.google.com/file/d/1Pi5fGS3nv6VYtbEYLFZPjxXWe0R_ZvKr/view?usp=sharing)
## Summary


In summary, both projects have been implemented successfully and offer practical solutions for handling 2D spatial data. The first project focuses on computing the convex hull, while the second project deals with spatial intersections between point clouds and polygons. These implementations can be applied in various fields, including computer graphics, geographic information systems, and computational geometry.
