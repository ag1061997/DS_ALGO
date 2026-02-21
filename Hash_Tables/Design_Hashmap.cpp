#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
    private:
        static const int kSize = 10000;
        vector<list<pair<int,int> > > mp;
    public:
        MyHashMap() : mp(kSize) {
        }
        
        void put(int key, int value) {
            auto& pairs = mp[key%kSize];
            for(auto& [k,v] : pairs) {
                if(k==key) {
                    v=value;
                    return;
                }
            }
            pairs.push_back(make_pair(key,value));
        }
        
        int get(int key) {
            const auto& pairs = mp[key%kSize];
            for(const auto& [k,v] : pairs) {
                cout<<k<<" "<<v<<endl;
                if(k==key) {
                    return v;
                }
            }
            return -1;
        }
        
        void remove(int key) {
            auto& pairs = mp[key%kSize];
            for(auto it=pairs.begin();it!=pairs.end();it++) {
                if(it->first==key) {
                    pairs.erase(it);
                    return;
                }
            }
        }
};

int main() {
    MyHashMap map;
    map.put(1,100);
    cout<<map.get(1)<<endl;
    cout<<map.get(2)<<endl;
    map.remove(1);
    cout<<map.get(1)<<endl;
    return 0;
}