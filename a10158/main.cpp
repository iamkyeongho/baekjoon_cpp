#include <iostream>
#include <time.h>

using namespace std;

void solution1(int w, int h, int p, int q, long t)
{	
	long x = (p + t) % (2 * w);	// p위치에서 t시간만큼 이동한 거리를 2w(왕복거리)으로 나눈 나머지가 마지막 x위치.
	long y = (q + t) % (2 * h); // q위치에서 t시간만큼 이동한 거리를 2h(왕복거리)으로 나눈 나머지가 마지막 y위치.

	x = w - abs(w - x); // 마지막 위치가 0에서부터인지, w에서부터인지 계산.
	y = h - abs(h - y); // 마지막 위치가 0에서부터인지, h에서부터인지 계산.

	cout << x << " " << y << endl;
}

void solution2(int w, int h, int p, int q, long t)
{
	int xdir = (t / w) % 2 == 0 ? 1 : -1;  // 짝수면 + (0에서부터), 홀수면 - (w에서부터)
	int ydir = (t / h) % 2 == 0 ? 1 : -1;  // 짝수면 + (0에서부터), 홀수면 - (w에서부터)

	long x = (xdir > 0) ? t % w : w - t % w;  // 0위치에서부터 t시간동안 w구간을 반복한 후의 x위치->여기서 계산시작.
	long y = (ydir > 0) ? t % h : h - t % h;  // 0위치에서부터 t시간동안 h구간을 반복한 후의 y위치->여기서 계산시작.

	// 마지막 위치에서 p만큼 x방향으로의 이동
	for (int i = 0; i < p; i++)
	{
		xdir = (x == w) ? -1 : (x == 0) ? 1 : xdir;  // w또는0이면 방향전환함.
		x += xdir;
	}
	// 마지막 위치에서 q만큼 y방향으로의 이동
	for (int i = 0; i < q; i++)
	{
		ydir = (y == h) ? -1 : (y == 0) ? 1 : ydir;  // h또는0이면 방향전환함.
		y += ydir;
	}
	cout << x << " " << y << endl;
}

int main(void)
{
	clock_t start, end;

	int w, h, p, q;
	long t;

	cin >> w >> h;
	cin >> p >> q;
	cin >> t;

	cout << "솔루션1" << endl;
	start = clock();
	solution1(w, h, p, q, t);
	end = clock();
	cout << "소요시간(ms) = " << (end - start) << endl;

	cout << "솔루션2" << endl;
	start = clock();
	solution2(w, h, p, q, t);
	end = clock();
	cout << "소요시간(ms) = " << (end - start) << endl;
	return 0;
}