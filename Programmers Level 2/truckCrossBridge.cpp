#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<pair<int, int>> truck;
    int onBridge = 0, complete = 0;
    
    int i = 0;
    while (complete < truck_weights.size()) {
        for (int j = 0; j < truck.size(); j++) truck[j].second++;
        if (truck.size() != 0 && truck[0].second == bridge_length) {
            onBridge -= truck[0].first;
            truck.erase(truck.begin());
            complete++;
        }
        if (onBridge + truck_weights[i] <= weight) {
            onBridge += truck_weights[i];
            truck.push_back(make_pair(truck_weights[i], 0));
            i++;
        }
        answer++;
    }
    
    return answer;
}