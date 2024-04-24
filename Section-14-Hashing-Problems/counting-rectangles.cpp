#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Point class
class Point{
    public:
        int x, y;

        // Point(){

        // }

        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
};

class Compare{
    public:
        bool operator()(const Point P1, const Point P2) const{
            if(P1.x == P2.x){
                return P1.y < P2.y;
            }
            return P1.x < P2.x;
        }
};

//Count rectrangles function
int count_rectangles(vector<Point> points){

    //1. Insert all points in the set
    set<Point,Compare> s;

    for(Point x: points){
        s.insert(x);
    }

    int ans = 0;
    //2. Logic Brute Force Two Points + LookUp for other Two
    for(auto it=s.begin();it!=prev(s.end());it++){
        for(auto jt=next(it);jt!=s.end();jt++){
            Point P1 = *it;
            Point P2 = *jt;

            //small check that we want to make
            if(P1.x == P2.x or P1.y == P2.y){
                continue;
            }

            //P3, P4
            Point P3(P1.x, P2.y); //assign this carefully
            Point P4(P2.x, P1.y);

            //Lookup
            if(s.find(P3)!=s.end() and s.find(P4)!=s.end()){
                ans += 1;
            }
        }
    }
    return ans/2;
}

int main(){
    int N;
    cin>>N;

    int x,y;

    vector<Point> points;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        Point p(x,y);
        points.push_back(p);
    }

    cout<<count_rectangles(points)<<endl;
    return 0;
}