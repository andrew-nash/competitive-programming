/*
LeetCode 587. Erect the Fence

Requires convex hull implementation.
*/

class Solution {
public:
    struct point {
      int x, y;

      long long int operator*(point a){
        return x*a.x + y*a.y;
      }
      bool operator<(point a){
        return x<a.x || (x==a.x && y<a.y);
      }
      bool operator==(point a){
        return x==a.x && y==a.y;
      }
    };

    long double ccw(point a, point b, point c){
        return (b.x-a.x)*(c.y-b.y) - (c.x-b.x)*(b.y-a.y) < 0;
    }


    vector<point> convexHull(vector<point> points) {
        sort(begin(points), end(points));
        vector<point> hull;
        int hs = 0;
        int n = points.size();

        for (int i = 0; i < n; ++i) {
                while (hs > 1 && ccw(hull[hs-2], hull[hs-1], points[i])){
                    hull.pop_back();
                    hs--;
                }
                hull.push_back(points[i]);
                hs++;
            }

        if (hull.size() == n) return hull;

        for (int i = n-2; i >= 0; i--) {
              while (hull.size() > 1 && ccw(hull[hs-2], hull[hs-1], points[i])){
                    hull.pop_back();
                    hs--;
              }
              hull.push_back(points[i]);
              hs++;
            }


            hull.pop_back();
            return hull;
     }


      vector<vector<int>> outerTrees(vector<vector<int>>& points) {
          if (points.size()<=3) return points;
          vector<point> ps;
          for (auto v: points){
              ps.push_back({v[0], v[1]});
          }

          auto ans = convexHull(ps);
          vector<vector<int>> a2;
          for (auto p: ans){
              a2.push_back({p.x, p.y});
          }

          return a2;

        }
};
