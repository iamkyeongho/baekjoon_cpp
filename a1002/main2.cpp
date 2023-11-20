#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2, r1, r2;

    // 좌표와 거리 입력
    cout << "조규현의 좌표 (x1, y1): ";
    cin >> x1 >> y1;
    cout << "백승환의 좌표 (x2, y2): ";
    cin >> x2 >> y2;
    cout << "조규현이 계산한 거리 (r1): ";
    cin >> r1;
    cout << "백승환이 계산한 거리 (r2): ";
    cin >> r2;

    // 류재명이 있을 수 있는 좌표의 수 계산
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    int result = 0;

    if (distance == 0 && r1 == r2) {
        // 조규현과 백승환의 위치와 계산한 거리가 같을 때
        if (r1 == 0) {
            // 류재명이 이미 있는 경우
            result = 1;
        }
        else {
            // 원의 중심이 겹치는 경우 (무한히 많은 좌표)
            result = -1;
        }
    }
    else if (distance <= abs(r1 - r2) && r1 != r2) {
        // 원이 내접하거나 한 원이 다른 원 안에 있는 경우 (해가 없음)
        result = 0;
    }
    else if (distance == r1 + r2 || distance == abs(r1 - r2)) {
        // 원이 외접하거나 내접하는 경우 (해가 하나)
        result = 1;
    }
    else if (distance < r1 + r2 && distance > abs(r1 - r2)) {
        // 원이 겹치는 경우 (해가 두 개)
        result = 2;
    }
    else {
        // 그 외의 경우 (해가 없음)
        result = 0;
    }

    // 결과 출력
    if (result == -1) {
        cout << "무한히 많은 좌표" << endl;
    }
    else {
        cout << "류재명이 있을 수 있는 좌표의 수: " << result << endl;
    }

    return 0;
}
