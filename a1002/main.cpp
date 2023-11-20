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
		if (distance_p1_p2 == 0 && ar1[i] == ar2[i]) // 조규현과 백승환이 같은 위치, 거리가 같을때
		{
			if (ar1[i] == 0)	// 세 위치가 같은 위치. 원이 아님 점.
			{
				result = 1;
			}
			else				// 원의 중심이 겹치는 동일한 원. 무수히 많음.
			{
				result = -1;
			}
		}
		else if (distance_p1_p2 <= abs(ar1[i] - ar2[i]) && ar1[i] != ar2[i])
		{
			result = 0;		// 한 원이 다른 원 안에 있음 (만나지 않음)
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