#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    vector<int> countX(10, 0), countY(10, 0);
    for (int i = 0; i < X.length(); i++) countX[X[i] - '0']++;
    for (int i = 0; i < Y.length(); i++) countY[Y[i] - '0']++;
    string answer = "";
    int loop;
    for (int i = 9; i >= 0; i--) {
        if (countX[i] > 0 && countY[i] > 0) {
            loop = countX[i] < countY[i] ? countX[i] : countY[i];
            for (int j = 0; j < loop; j++) answer += to_string(i);
        }
    }
    if (answer.empty()) answer = "-1";
    else if (answer[0] == '0') answer = "0";
    return answer;
}