#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> values{};
    values.push_back(1);
    values.push_back(2);
    //values.emplace_back(1);
    //values.emplace_back(2);
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    return 0;
}
