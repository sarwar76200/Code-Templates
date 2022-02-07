#include <bits/stdc++.h>

using namespace std;

namespace geometry {
    template<typename type>
    struct Point {
        type x, y;

        Point(type x, type y) {
            Point::x = x;
            Point::y = y;
        }

        Point() { x = 0, y = 0; }
    };

    template<typename T>
    double slope(Point<T> a, Point<T> b) {
        return 1.0 * (b.y - a.y) / (b.x - a.x);
    }

    template<typename T>
    double dist(Point<T> a, Point<T> b) {
        return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    }

    template<typename T>
    bool collinear(Point<T> a, Point<T> b, Point<T> c) {
        return (b.y - a.y) * (c.x - b.x) == (b.x - a.x) * (c.y - b.y);
    }

    template<typename T>
    T tri_area_doubled(Point<T> a, Point<T> b, Point<T> c) {
        return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    }

    template<typename T>
    T rect_area(Point<T> bottom_left, Point<T> top_right) {
        return (top_right.y - bottom_left.y) * (top_right.x - bottom_left.x);
    }

    template<typename type>
    struct Rectangle {
        // Bottom Left, Top Right
        Point<type> bl, tr;

        Rectangle(Point<type> bl, Point<type> tr) {
            Rectangle::bl = bl;
            Rectangle::tr = tr;
        }

        type area() const {
            return (tr.y - bl.y) * (tr.x - bl.x);
        }
    };

    template<typename T>
    pair<T, T> intersection(vector<Rectangle<T>> rects) {
        // returns <x_intersection_length, y_intersection_length>
        T mn_tr_x = numeric_limits<T>::max(), mx_bl_x = numeric_limits<T>::min();
        for (Rectangle i : rects) {
            mn_tr_x = min(mn_tr_x, i.tr.x);
            mx_bl_x = max(mx_bl_x, i.bl.x);
        }
        T x = max(static_cast<T>(0), mn_tr_x - mx_bl_x);

        T mn_tr_y = numeric_limits<T>::max(), mx_bl_y = numeric_limits<T>::min();
        for (Rectangle i : rects) {
            mn_tr_y = min(mn_tr_y, i.tr.y);
            mx_bl_y = max(mx_bl_y, i.bl.y);
        }
        T y = max(static_cast<T>(0), mn_tr_y - mx_bl_y);

        return make_pair(x, y);
    }

    template<typename T>
    T intersect_area(vector<Rectangle<T>> rects) {
        pair<T, T> sides = intersection(std::move(rects));
        return sides.first * sides.second;
    }

    template<typename T>
    istream& operator>>(istream& in, Rectangle<T>& r) {
        in >> r.bl.x >> r.bl.y >> r.tr.x >> r.tr.y;
        return in;
    }

    template<typename T>
    istream& operator>>(istream& in, Point<T>& p) {
        in >> p.x >> p.y;
        return in;
    }

    template<typename T>
    ostream& operator<<(ostream& out, Point<T>& p) {
        out << "(" << p.x << "," << p.y << ")";
        return out;
    }
}
using namespace geometry;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Point x = {1, 2};
    cout << x << '\n';

    return 0;
}