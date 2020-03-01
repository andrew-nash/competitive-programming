/*
  Convex hull implementation using Andrew's monotone chain algorithm
*/
struct point {
    int x, y;

    long long int operator*(point a){
      return x*a.x + y*a.y;
    }
    bool operator<(point a){
      return x<a.x || (x==a.x && y<a.y);
    }

    point operator+(point a){
      return {x+a.x, y+a.y};
    }

    point operator/(point a){
      return {x/a.x, y/a.y};
    }

    point operator-(point a){
      return {x-a.x, y-a.y};
    }
    bool operator==(point a){
      return x==a.x && y==a.y;
    }
};

// make print debugging a bit easier
ostream& operator<<(ostream& o, point a){
  return o << "(" << a.x << "," << a.y << ")" << endl;
}

bool ccw(point a, point b, point c){
    return (b.x-a.x)*(c.y-b.y) - (c.x-b.x)*(b.y-a.y) < 0;
}

vector<point> convexHull(vector<point> points) {
    sort(points.begin(), points.end());
    vector<point> hull;
    int hs = 0;
    int n = points.size();

    for (auto p: points){
      while (hs>1 && ccw(hull[hs-2], hull[hs-1], p)){
          hull.pop_back();
          hs--;
      }
      hull.push_back(p);
      hs++;
    }

    if (hs==n) return hull;

    for (int i = n-1; i>=0; i--){
        point p = points[i];
        while (hs>1 && ccw(hull[hs-2], hull[hs-1], p)){
            hull.pop_back();
            hs--;
        }
        hull.push_back(p);
        hs++;
    }

    hull.pop_back();
    return hull;
 }
