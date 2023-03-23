#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> freq;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        freq[tmp]++;
    }
    for(auto val: freq)
        cout << val.first << " " << val.second << endl;
    return EXIT_SUCCESS;
}