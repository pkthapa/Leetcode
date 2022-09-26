#include "main.hpp"

class OrderedStream {
    int index;
    vector<string> stream;
    
public:
    // Resize the 'stream' array to store 'n' data streams.
    OrderedStream(int n) {
        stream.resize(n);
        index = 0;
    }
    
    vector<string> insert(int idKey, const string& value) {
        vector<string> result;
        
        // Store data stream in that offset.
        stream[idKey - 1] = value;
        
        // Push into 'result' until next empty data stream is found
        // while travelling in sequencial order. That is, if any data stream
        // has arrived out of order.
        while (index < stream.size() && !stream[index].empty()) {
            result.push_back(stream[index++]);
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {
    OrderedStream* obj = new OrderedStream(5);

    assert(vector<string>{} == obj->insert(3, "ccccc"));
    assert(vector<string>{"aaaaa"} == obj->insert(1, "aaaaa"));

    auto t = obj->insert(2, "bbbbb");
    assert(2 == t.size());
    assert((t[0] == "bbbbb" && t[1] == "ccccc") || (t[0] == "ccccc" && t[1] == "bbbbb"));
    
    assert(vector<string>{} == obj->insert(5, "eeeee"));

    delete obj;
    
    return 0;
}