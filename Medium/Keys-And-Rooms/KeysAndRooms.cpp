#include "main.hpp"

bool canVisitAllRooms(vector<vector<int>> rooms){
    bool res{true};
    size_t roomsCnt = rooms.size();
    bool* visited = new bool[roomsCnt]{false};
    
    stack<int> stk;
    
    visited[0] = true; // Make room 0 visited for sure.
    for (auto key : rooms[0]){
        stk.push(key); // Push all the keys in room 0.
    }

    while(!stk.empty()){
        auto key = stk.top();
        stk.pop();

        if (!visited[key]){
            visited[key] = true;

            for (auto subKey : rooms[key]){
                stk.push(subKey);
            }
        }
    }

    for (int i = 0; i < roomsCnt; ++i){
        if (!visited[i]){
            res = false;
        }
    }

    delete[] visited;
    return res;
}

int main(int argc, char* argv[])
{
    {
        vector<vector<int>> rooms{{1}, {2}, {3}, {}};
        assert(1 == canVisitAllRooms(rooms));
    }
    {
        vector<vector<int>> rooms{{1, 3}, {3, 0, 1}, {2}, {0}};
        assert(0 == canVisitAllRooms(rooms));
    }
    {
        vector<vector<int>> rooms{{}, {2}, {3}, {}};
        assert(0 == canVisitAllRooms(rooms));
    }
    return 0;
}