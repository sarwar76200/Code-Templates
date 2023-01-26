struct pt {
    double x, y;
};

int orientation(pt a, pt b, pt c) { // a current point, b looking at , c target
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}

bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = true) {
    if (a.size() == 1)
        return;
    /*
        pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) { // sorts in anticlockwise order
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
        });
        sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
            int o = orientation(p0, a, b);
            if (o == 0)
                return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                    < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
            return o < 0;
        });*/

    sort(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    }); // normally sorted

    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int) a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for (int i = 0; i < (int) up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

double sign(pt p1, pt p2, pt p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle(pt p, pt v1, pt v2, pt v3) {
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(p, v1, v2);
    d2 = sign(p, v2, v3);
    d3 = sign(p, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    if (v1.x == v2.x && v1.y == v2.y && v2.x == v3.x && v2.y == v3.y) {
        if (v1.x == p.x && v1.y == p.y)return true;
        else return false;
    }

    if (sign(v1, v2, v3) == 0) { // collinear with three points
        if (min(v1.x, min(v2.x, v3.x)) <= p.x && max(v1.x, max(v2.x, v3.x)) >= p.x
            && min(v1.y, min(v2.y, v3.y)) <= p.y && max(v1.y, max(v2.y, v3.y)) >= p.y)return true;
        else return false;
    }
    return !(has_neg && has_pos);
}

bool inside_the_polygon(vector<pt>& a, pt x) {

    if (a.size() == 0)return false;
    if (a.size() == 1)return PointInTriangle(x, a[0], a[0], a[0]);
    if (a.size() == 2)return PointInTriangle(x, a[0], a[0], a[1]);

    int l = 1, r = a.size() - 1;

    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (orientation(a[0], a[mid], x) > 0) {
            r = mid;
        }
        else if (orientation(a[0], a[mid], x) == 0) {
            return PointInTriangle(x, a[0], a[mid], a[0]);
        }
        else {
            l = mid;
        }
    }
    return PointInTriangle(x, a[0], a[l], a[r]);
}