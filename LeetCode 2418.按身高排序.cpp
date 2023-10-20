// 对于std::map来说，默认情况下，它会根据键（即int类型的身高）来进行升序排序。
// 因此，在这个代码中，身高是用作键，而string类型的名字是与之相关联的值。
#include "predefs.h"
#include <map>
#include <vector>
// greater参数用于使得要将std::map的排序改为降序（按照身高降序排列），默认是升序
// 可以使用std::greater作为std::map的模板参数来指定比较函数。这将使std::map按照降序排序。
class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        map<int, string, greater<int>> Height2Name;
        
        for (int i = 0; i < names.size(); i++) {
            Height2Name[heights[i]] = names[i];
        }
        
        vector<string> sortedNames;
        for (const auto &entry : Height2Name) {
            sortedNames.push_back(entry.second);
        }
        
        return sortedNames;
    }
};

int main2418() {
    Solution sol;
    vector<string> names = {"Mary", "John", "Emma"};
    vector<int> heights = {180, 165, 170};
    vector<string> sortedNames = sol.sortPeople(names, heights);
    
    for (const auto &name : sortedNames) {
        cout << name << " ";
    }
    
    return 0;
}
