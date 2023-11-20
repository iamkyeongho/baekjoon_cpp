#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int testCount = 0;
	cin >> testCount;

	vector<float> ax1 = vector<float>();
	vector<float> ay1 = vector<float>();
	vector<float> ar1 = vector<float>();
	vector<float> ax2 = vector<float>();
	vector<float> ay2 = vector<float>();
	vector<float> ar2 = vector<float>();

	for (int i = 0; i < testCount; i++)
	{
		float x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		ax1.push_back(x1);
		ay1.push_back(y1);
		ar1.push_back(r1);
		ax2.push_back(x2);
		ay2.push_back(y2);
		ar2.push_back(r2);
	}

	for (int i = 0; i < testCount; i++)
	{
		int result = 0;
		float distance_p1_p2 = sqrt(pow(ax1[i] - ax2[i], 2) + pow(ay1[i] - ay2[i],2));
		if (distance_p1_p2 == 0 && ar1[i] == ar2[i]) // �������� ���ȯ�� ���� ��ġ, �Ÿ��� ������
		{
			if (ar1[i] == 0)	// �� ��ġ�� ���� ��ġ. ���� �ƴ� ��.
			{
				result = 1;
			}
			else				// ���� �߽��� ��ġ�� ������ ��. ������ ����.
			{
				result = -1;
			}
		}
		else if (distance_p1_p2 <= abs(ar1[i] - ar2[i]) && ar1[i] != ar2[i])
		{
			result = 0;		// �� ���� �ٸ� �� �ȿ� ���� (������ ����)
		}

		else if (ar1[i] + ar2[i] > distance_p1_p2)
		{
			result = 2;
		}
		else if (ar1[i] + ar2[i] == distance_p1_p2)
		{
			result = 1;
		}
		else if (abs(ar1[i] - ar2[i]) == distance_p1_p2)
		{
			result = 1;
		}
		else if (ar1[i] + ar2[i] < distance_p1_p2)
		{
			result = 0;
		}
		else if (abs(ar1[i] - ar2[i]) > distance_p1_p2)
		{
			result = 0;
		}
		else if (distance_p1_p2 == 0)
		{
			result = -1;
		}
		cout << result << endl;
	}
	return 0;
}