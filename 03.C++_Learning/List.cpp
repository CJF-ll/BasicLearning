#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int n;
  
    cin >> n;
   
    cin.ignore();

    
    map<int, vector<int>> sequences;

    for (int i = 0; i < n; ++i) {
        string cmd;
     
        getline(cin, cmd);
        istringstream iss(cmd);

        string op;
        
        iss >> op;

        if (op == "new") {
            int id;
          
            iss >> id;
           
            sequences[id] = vector<int>();
        } else if (op == "add") {
            int id, num;
          
            iss >> id >> num;
           
            sequences[id].push_back(num);
        } else if (op == "merge") {
            int id1, id2;
          
            iss >> id1 >> id2;
            if (id1 != id2) {
             
                for (size_t j = 0; j < sequences[id2].size(); ++j) {
                    sequences[id1].push_back(sequences[id2][j]);
                }
               
                sequences[id2].clear();
            }
        } else if (op == "unique") {
            int id;
            
            iss >> id;
            
            set<int> s(sequences[id].begin(), sequences[id].end());
            sequences[id].assign(s.begin(), s.end());
        } else if (op == "out") {
            int id;
          
            iss >> id;
            
            for (size_t j = 0; j < sequences[id].size(); ++j) {
                if (j > 0) {
                    cout << " ";
                }
                cout << sequences[id][j];
            }
            cout << endl;
        }
    }

    return 0;
}


