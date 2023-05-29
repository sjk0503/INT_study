#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int aMax = park.size() - 1;
    int bMax = park[0].length() - 1;
    int a = 0, b = 0;

    bool stopPoint = false;
    for (int i = 0; i <= aMax; i++) {
        for (int j = 0; j <= bMax; j++) {
            if (park[i][j] == 'S') {
                a = i;
                b = j;
                stopPoint = true;
                break;
            }
        }
        if (stopPoint) break;
    }

    int move;
    bool alloc;
    for (int i = 0; i < routes.size(); i++) {
        alloc = true;
        move = routes[i][2] - '0';
        if (routes[i][0] == 'E') { // 오른
            for (int j = 1; j <= move; j++) {
                if (b + j > bMax || park[a][b + j] == 'X') {
                    alloc = false;
                    break;
                }
            }
            if (alloc) b += move;
        } else if (routes[i][0] == 'S') { // 아래
            for (int j = 1; j <= move; j++) {
                if (a + j > aMax || park[a + j][b] == 'X') {
                    alloc = false;
                    break;
                }
            }
            if (alloc) a += move;
        } else if (routes[i][0] == 'W') { // 왼
            for (int j = 1; j <= move; j++) {
                if (b - j < 0 || park[a][b - j] == 'X') {
                    alloc = false;
                    break;
                }
            }
            if (alloc) b -= move;
        } else if (routes[i][0] == 'N') { // 위
            for (int j = 1; j <= move; j++) {
                if (a - j < 0 || park[a - j][b] == 'X') {
                    alloc = false;
                    break;
                }
            }
            if (alloc) a -= move;
        }
    }

    vector<int> answer;
    answer.push_back(a);
    answer.push_back(b);

    return answer;
}