#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //sort, stable_sort

using namespace std;

int main() {
    vector<string> tokens = {
        "Jlhvvd", "wfwnphmxoa", "qcuucx", "qsvqskq", "cqwfypww", "dyphntfz",
        "hkbwx", "xmwohi", "qvzegb", "ubogo", "sbdfmnyeim", "tuqppyipb", 
        "llwzeug", "hrsaebveez", "aszqnvruhr", "xqpqd", "ipwbapd", "mlghuuwvec",
        "xpefyglstj", "dkvhhgecd", "kry"
    };
    
    vector<string> sorted = tokens;
    vector<string> stable_sorted = tokens;
    
    auto comp = [](const string& a, const string& b){
        return a.size() < b.size();
        };
    
    sort(sorted.begin(), sorted.end(), comp);
    stable_sort(stable_sorted.begin(), stable_sorted.end(), comp);
    
    cout << "sorted: " << endl;
    for(string& s : sorted){
        cout << s << " ";
    }
    cout << endl;
    
    cout << "stable sorted: " << endl;
    for(string& s : stable_sorted){
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}

/*
sorted: 
kry xqpqd ubogo hkbwx qvzegb Jlhvvd xmwohi qcuucx qsvqskq llwzeug ipwbapd dyphntfz cqwfypww tuqppyipb dkvhhgecd sbdfmnyeim xpefyglstj mlghuuwvec aszqnvruhr hrsaebveez wfwnphmxoa 
stable sorted: 
kry hkbwx ubogo xqpqd Jlhvvd qcuucx xmwohi qvzegb qsvqskq llwzeug ipwbapd cqwfypww dyphntfz tuqppyipb dkvhhgecd wfwnphmxoa sbdfmnyeim hrsaebveez aszqnvruhr mlghuuwvec xpefyglstj 
*/
