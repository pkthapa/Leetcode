#include "main.hpp"

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;

        // Format: <Length><#><actual-string>
        for (auto str : strs) {
            s += std::to_string(str.size()) + "#" + str;
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> output;

        int start = 0;
        int offset = s.find("#");

        while (offset != string::npos) {
            int len = std::stoi(s.substr(start, offset));
            ++offset; // Skip '#'.
            output.emplace_back(s.substr(offset, len));
            start = offset + len;
            offset = s.find("#", start);
        }
        return output;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {
    Codec codec;
    {
        vector<string> strs {"Hello", "World"};
        auto encodedStr = codec.encode(strs);
        assert(strs == codec.decode(encodedStr));
    }
    {
        vector<string> strs {""};
        auto encodedStr = codec.encode(strs);
        assert(strs == codec.decode(encodedStr));
    }
    {
        vector<string> strs {"12", "4#", "hello22#"};
        auto encodedStr = codec.encode(strs);
        assert(strs == codec.decode(encodedStr));
    }
    return 0;
}