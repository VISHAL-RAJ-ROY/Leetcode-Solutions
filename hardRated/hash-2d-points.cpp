// ways to hash 2d points 

// 1
namespace std
{
    template <>
    struct hash<pair<int, int>>
    {
        size_t operator()(const pair<int, int> &p) const __attribute__((no_sanitize("shift")))
        {
            return hash<long>()(((long) p.first << 32) | ((long) p.second));
        }
    };
}

// 2
unordered_map<int, unordered_set<int>> m;
m[x].insert(y); // add a point
if( m[x].erase(y) ) // simultaneously check and erase a point

