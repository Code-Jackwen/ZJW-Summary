#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;



vector<string> topKFrequent(vector<string>& strs, int k) {
    vector<string> ret;						//c++小根堆
    unordered_map<string, int> dict;		//um不能排序
    for (auto &i : strs) ++dict[i];
    typedef pair<string, int> psi;			//字符串，频率
    auto cmp = [](psi &o1, psi &o2) {		//注意：o1.first > o2.first 是从z到a
        return o1.second == o2.second ? o1.first > o2.first : o1.second < o2.second;
    };										//用大根堆对队列里的pair进行排序
    priority_queue<psi, vector<psi>, decltype(cmp)> pq(cmp);
    for (auto &i : dict) pq.emplace(i);
    while (k--) ret.push_back(pq.top().first), pq.pop();
    return ret;
}


int main(int argc, char const *argv[]){ 
  	// ["i", "love", "leetcode", "i", "love", "coding"]
  	vector<string> v;
//  	char *s[] = { "i", "love", "leetcode", "i", "love", "coding"};
//  	int len = s.length();
//  	for(int i =0; i < len; ++i){
//  		v.push_back(s[i]);
//	}
//	
//	for(int i =v.begin(); i < v.end(); ++i){
//  		cout<<v.pop_back()<<endl;
//	}

	v.push_back("i");
	v.push_back("i");

	v.push_back("love");
	v.push_back("love");
	v.push_back("leetcode"),v.push_back("coding");
	
	vector<string> ret = topKFrequent(v,2);
	
	for(auto i =v.begin(); i < v.end(); ++i){
//		string a = v.
  		cout<<v.pop_back()<<endl;
	}
	
}

