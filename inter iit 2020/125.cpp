#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream fin;
    fin.open("data.csv");
    vector<double> arr[100];
    string s;
    getline(fin,s);
    int n = 0;
    while(getline(fin,s)){
        s += ',';
        int curr = 0, pos = s.find(',');
        double x1 = stod(s.substr(curr, pos - curr));
        curr = ++pos;pos = s.find(',',pos);
        double x2 = stod(s.substr(curr, pos - curr));
        curr = ++pos;pos = s.find(',',pos);
        double x3 = stod(s.substr(curr, pos - curr));
        curr = ++pos;pos = s.find(',',pos);
        double y = stod(s.substr(curr, pos - curr));

        arr[n++] = {x1,x2,x3,y};
        vector<double> l = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
        sort(arr, arr + n);

        vector<pair<double,double>> a1;
        for(int i = 0; i < n; i++){
            if(arr[i][0] == 0.5 && arr[i][1] == 0.5)
                a1.push_back({arr[i][2],arr[i][3]});
        }
        //f3 poly
        double err = 1e9, c3,d3;
        for(int c = -500; c <= 500; c++){
            for(int d = -5; d <= 5; d++){
                double curr = 0;
                for(int i = 0;i<a1.size();i++){
                    for(int j = i+1;j<a1.size();j++){
                        curr += abs(c*(pow(a1[i].first,d) - pow(a1[j].first,d) - (a1[i].second - a[j].second));
                        
                    }
                }
            }
        }






    } 



}