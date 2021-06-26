#include <string>
using namespace std;

string solution(string new_id) {
    
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] = new_id[i] - 'A' + 'a';
    }
    
    for (int i = 0; i < new_id.size(); i++) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
           || (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')) continue;
        else { new_id.erase(i, 1); i--; }
    }
    
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.') {
            if (new_id[i+1] == '.') { new_id.erase(i, 1); i--; }
        }
    }

    while (new_id[0] == '.') new_id.erase(0, 1);
    while (new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1);
    
    if (new_id.size() == 0) new_id += 'a';
    
    if (new_id.size() > 15) new_id.erase(15);
    
    if (new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1);
    
    if (new_id.size() < 3) {
        for (int i = new_id.size(); i < 3; i++) new_id += new_id[i-1];
    }

    return new_id;
}