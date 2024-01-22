#include <iostream>
#include <vector>

using namespace std;

string longestCommonSuffixPath(const vector<string>& paths) {
    if (paths.empty()) {
        return ""; // Empty input, no common suffix path
    }

    // Find the minimum length among all paths
    int minLength = paths[0].size();
    for (const string& path : paths) {
        minLength = min(minLength, static_cast<int>(path.size()));
    }

    // Iterate from the end of the paths to find the common suffix
    int commonSuffixLength = 0;
    for (int i = 1; i <= minLength; ++i) {
        char currentChar = paths[0][paths[0].size() - i];

        // Check if the current character is common among all paths
        bool isCommon = true;
        for (int j = 1; j < paths.size(); ++j) {
            if (paths[j][paths[j].size() - i] != currentChar) {
                isCommon = false;
                break;
            }
        }

        if (isCommon) {
            commonSuffixLength = i;
        } else {
            break; // Stop when a non-matching character is found
        }
    }

    // Extract the common suffix path
    string commonSuffixPath = paths[0].substr(paths[0].size() - commonSuffixLength, commonSuffixLength);

    // Remove special characters like ".."
    size_t pos = commonSuffixPath.find_last_not_of('/');
    if (pos != string::npos) {
        commonSuffixPath = commonSuffixPath.substr(0, pos + 1);
    }

    return commonSuffixPath;
}

int main() {
    // Example usage
    vector<string> paths = { "/a/b/c", "/a/b/../d", "/x/y/z" };

    string result = longestCommonSuffixPath(paths);

    cout << "Longest Common Suffix Path: " << result << endl;

    return 0;
}
