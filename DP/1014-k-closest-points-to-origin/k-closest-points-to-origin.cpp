class Solution {
public:

    class Coordinate{
        public:
            int x ;
            int y ;
            int dist ;

        Coordinate(int dist,int x,int y)
        {
            this -> x = x;
            this -> y = y;
            this -> dist = dist;
        }
        
    };

    class Compare{

        public:

        bool operator()(const Coordinate& a,const Coordinate& b)
        {
            return a.dist < b.dist;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<Coordinate, vector<Coordinate>, Compare > pq;
        
        for(int i = 0 ; i < points.size() ; i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int dist = (x*x + y*y) ; //sqrt lagane se galat answer aa raha tha 

            Coordinate point(dist,x,y);

            pq.push(point);

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> ans ;

        while(!pq.empty())
        {
            int x = pq.top().x;
            int y = pq.top().y;

            ans.push_back({x,y});

            pq.pop();
        }

        return ans ;

    }
}; 