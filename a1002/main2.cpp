#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2, r1, r2;

    // ��ǥ�� �Ÿ� �Է�
    cout << "�������� ��ǥ (x1, y1): ";
    cin >> x1 >> y1;
    cout << "���ȯ�� ��ǥ (x2, y2): ";
    cin >> x2 >> y2;
    cout << "�������� ����� �Ÿ� (r1): ";
    cin >> r1;
    cout << "���ȯ�� ����� �Ÿ� (r2): ";
    cin >> r2;

    // ������� ���� �� �ִ� ��ǥ�� �� ���
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    int result = 0;

    if (distance == 0 && r1 == r2) {
        // �������� ���ȯ�� ��ġ�� ����� �Ÿ��� ���� ��
        if (r1 == 0) {
            // ������� �̹� �ִ� ���
            result = 1;
        }
        else {
            // ���� �߽��� ��ġ�� ��� (������ ���� ��ǥ)
            result = -1;
        }
    }
    else if (distance <= abs(r1 - r2) && r1 != r2) {
        // ���� �����ϰų� �� ���� �ٸ� �� �ȿ� �ִ� ��� (�ذ� ����)
        result = 0;
    }
    else if (distance == r1 + r2 || distance == abs(r1 - r2)) {
        // ���� �����ϰų� �����ϴ� ��� (�ذ� �ϳ�)
        result = 1;
    }
    else if (distance < r1 + r2 && distance > abs(r1 - r2)) {
        // ���� ��ġ�� ��� (�ذ� �� ��)
        result = 2;
    }
    else {
        // �� ���� ��� (�ذ� ����)
        result = 0;
    }

    // ��� ���
    if (result == -1) {
        cout << "������ ���� ��ǥ" << endl;
    }
    else {
        cout << "������� ���� �� �ִ� ��ǥ�� ��: " << result << endl;
    }

    return 0;
}
