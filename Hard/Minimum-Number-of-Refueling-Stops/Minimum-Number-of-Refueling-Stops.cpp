#include "main.hpp"

/*
 * Explanation:
 * Initially you have a range(startFuel), before you run out of fuel, you can stop by any station within your range.
 * The greedy idea is to put all the stations within your range into a candidate list (pq), then you always
 * pick the station with the most fuel supply one at a time to extend your range until your range reaches the target.
 * Once your range is extended, you can add more stations to your candidate list.
 * If you have exhausted the stations in your list(pq) and still can't reach the target, return -1.
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int range = startFuel;
        int stationId = 0;
        priority_queue<int> pq;

        while (range < target) {
            while (stationId < stations.size() && stations[stationId][0] <= range) {
                pq.push(stations[stationId++][1]); // Consider all stations within the 'range'.
            }

            if (pq.empty()) {
                return -1;
            }
            range += pq.top();
            pq.pop();
            ++stops;
        }
        return stops;
    }
};

int main() {
    Solution sln;
    {
        int target = 1;
        int startFuel = 1;
        vector<vector<int>> stations {{}};
        assert(0 == sln.minRefuelStops(target, startFuel, stations));
    }
    {
        int target = 100;
        int startFuel = 1;
        vector<vector<int>> stations {{10, 100}};
        assert(-1 == sln.minRefuelStops(target, startFuel, stations));
    }
    {
        int target = 100;
        int startFuel = 10;
        vector<vector<int>> stations {{10, 60},
                                      {20, 30},
                                      {30, 30},
                                      {60, 40}};
        assert(2 == sln.minRefuelStops(target, startFuel, stations));
    }
    return 0;
}