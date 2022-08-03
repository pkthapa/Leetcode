#include "main.hpp"

class MyCalendar {
public:
    set<pair<int, int>> events;

    MyCalendar() {}
    
    bool book(int start, int end) {

        if (!events.empty()) {
            for (auto p : events) {
                
                if (start < p.first && end > p.first) {
                    return false;
                }
                if (start >= p.first && start < p.second) {
                    return false;
                }
            }
        }
        events.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() {
    MyCalendar* obj = new MyCalendar();

    assert(true == obj->book(10, 20));
    assert(false == obj->book(15, 25));
    assert(true == obj->book(20, 30));
    assert(true == obj->book(5, 10));
    assert(false == obj->book(5, 11));

    delete obj;
    return 0;
}