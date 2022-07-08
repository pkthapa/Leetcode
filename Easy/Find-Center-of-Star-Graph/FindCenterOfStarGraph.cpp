#include "main.hpp"

int findCenter(vector<vector<int>>& edges) {
    int res{0};
    auto a = edges[0][0];
    auto b = edges[0][1];
    
    auto x = edges[1][0];
    auto y = edges[1][1];
    
    if (a == x || b == x){
        res = x;
    }
    else if (a == y || b == y){
        res = y;
    }
    return res;
}

int main(int argc, char* argv[])
{
    {
        vector<vector<int>> rooms{{1, 2}, {2, 3}, {4, 2}};
        assert(2 == findCenter(rooms));
    }
    {
        vector<vector<int>> rooms{{1, 2}, {5, 1}, {1, 2}, {1, 4}};
        assert(1 == findCenter(rooms));
    }
    return 0;
}