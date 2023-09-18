#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int testCount = 0;
	cin >> testCount;

	vector<int> ax1 = vector<int>();
	vector<int> ay1 = vector<int>();
	vector<int> ar1 = vector<int>();
	vector<int> ax2 = vector<int>();
	vector<int> ay2 = vector<int>();
	vector<int> ar2 = vector<int>();

	for (int i = 0; i < testCount; i++)
	{
		int x1, y1, r1, x2, y2, r2;
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
		r1 = sqrt((ax1[0] - ax2[0]) ^ 2 + (ay1[0] - ay2[0]) ^ 2);

	}
	return 0;
}