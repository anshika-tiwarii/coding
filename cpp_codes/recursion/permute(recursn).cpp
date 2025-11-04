#include <iostream>
#include <string>
#include <algorithm> // For std::swap

void permute(std::string str, int l, int r) {
    // Base case: If l and r are the same, a permutation is complete
    if (l == r) {
        std::cout << str << std::endl;
    } else {
        // Iterate through the remaining characters
        for (int i = l; i <= r; ++i) {
            // Swap the current character with the character at index 'l'
            std::swap(str[l], str[i]);

            // Recursively call for the rest of the string
            permute(str, l + 1, r);

            // Backtrack: Swap back to restore the original order for next iterations
            std::swap(str[l], str[i]);
        }
    }
}

int main() {
    std::string s = "ABC";
    int n = s.length();
    permute(s, 0, n - 1);
    return 0;
}


