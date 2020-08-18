#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    map<int, char> m = {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};
    unordered_map<int, char> um = {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};

    return 0;
}
