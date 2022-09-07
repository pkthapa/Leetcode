#include "main.hpp"

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {
        m.clear();
    }

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        vector<pair<int, string>>& v = m[key];

        int low = 0;
        int high = v.size() - 1;
        string result;

        // We can use binary search as per the constraint:
        // All the timestamps timestamp of set are strictly increasing.
        while (low <= high) {
            int mid = (low + high) / 2;

            if (v[mid].first <= timestamp) {
                low = mid + 1;
                result = v[mid].second;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    {
        TimeMap* obj = new TimeMap();
        obj->set("foo", "bar", 1);
        assert("bar" == obj->get("foo", 1));
        assert("bar" == obj->get("foo", 3));
        obj->set("foo", "bar2", 4);
        assert("bar2" == obj->get("foo", 4));
        assert("bar2" == obj->get("foo", 5));

        delete obj;
    }
    return 0;
}