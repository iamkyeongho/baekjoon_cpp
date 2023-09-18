#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution1(vector<int>crain_weight, vector<int>box_weight)
{
	sort(crain_weight.begin(), crain_weight.end(), greater<>());
	sort(box_weight.begin(), box_weight.end(), greater<>());

	if (crain_weight.front() < box_weight.front())
	{
		return -1;
	}

	int result = 0;
	while (!box_weight.empty())
	{
		int boxIndex = 0;
		for (int i = 0; i < crain_weight.size();)
		{
			if (boxIndex == box_weight.size())
			{
				break;
			}
			else if (crain_weight[i] >= box_weight[boxIndex])
			{
				box_weight.erase(box_weight.begin() + boxIndex);
				i++;
			}
			else
			{
				boxIndex++;
			}
		}
		result++;
	}
	return result;
}

int solution2(vector<int>crain_weight, vector<int>box_weight)
{
	sort(crain_weight.begin(), crain_weight.end(), greater<>());
	sort(box_weight.begin(), box_weight.end(), greater<>());

	if (crain_weight.front() < box_weight.front())
	{
		return -1;
	}

	int result = 0;
	while (!box_weight.empty())
	{
		result++;
		for (int i = 0; i < crain_weight.size(); i++)
		{
			for (int j = 0; j < box_weight.size(); j++)
			{
				if (crain_weight[i] >= box_weight[j])
				{
					box_weight.erase(box_weight.begin() + j);
					break;
				}
			}
		}
	}
	return result;
}

int main(void)
{
	clock_t start, end;

	int crain_num, box_num;

	cin >> crain_num;
	vector<int> crain_weight;
	for (int i = 0; i < crain_num; i++)
	{
		int weight;
		cin >> weight;
		crain_weight.push_back(weight);
	}

	cin >> box_num;
	vector<int> box_weight;
	for (int i = 0; i < box_num; i++)
	{
		int weight;
		cin >> weight;
		box_weight.push_back(weight);
	}

	start = clock();
	int result = solution1(crain_weight, box_weight);
	cout << result << endl;
	end = clock();
	cout << "소요시간(ms) = " << (end - start) << endl;

	start = clock();
	result = solution2(crain_weight, box_weight);
	cout << result << endl;
	end = clock();
	cout << "소요시간(ms) = " << (end - start) << endl;
	return 0;
}