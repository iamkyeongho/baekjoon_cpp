#include <iostream>
#include <time.h>

using namespace std;

void solution1(int w, int h, int p, int q, long t)
{	
	long x = (p + t) % (2 * w);	// p��ġ���� t�ð���ŭ �̵��� �Ÿ��� 2w(�պ��Ÿ�)���� ���� �������� ������ x��ġ.
	long y = (q + t) % (2 * h); // q��ġ���� t�ð���ŭ �̵��� �Ÿ��� 2h(�պ��Ÿ�)���� ���� �������� ������ y��ġ.

	x = w - abs(w - x); // ������ ��ġ�� 0������������, w������������ ���.
	y = h - abs(h - y); // ������ ��ġ�� 0������������, h������������ ���.

	cout << x << " " << y << endl;
}

void solution2(int w, int h, int p, int q, long t)
{
	int xdir = (t / w) % 2 == 0 ? 1 : -1;  // ¦���� + (0��������), Ȧ���� - (w��������)
	int ydir = (t / h) % 2 == 0 ? 1 : -1;  // ¦���� + (0��������), Ȧ���� - (w��������)

	long x = (xdir > 0) ? t % w : w - t % w;  // 0��ġ�������� t�ð����� w������ �ݺ��� ���� x��ġ->���⼭ ������.
	long y = (ydir > 0) ? t % h : h - t % h;  // 0��ġ�������� t�ð����� h������ �ݺ��� ���� y��ġ->���⼭ ������.

	// ������ ��ġ���� p��ŭ x���������� �̵�
	for (int i = 0; i < p; i++)
	{
		xdir = (x == w) ? -1 : (x == 0) ? 1 : xdir;  // w�Ǵ�0�̸� ������ȯ��.
		x += xdir;
	}
	// ������ ��ġ���� q��ŭ y���������� �̵�
	for (int i = 0; i < q; i++)
	{
		ydir = (y == h) ? -1 : (y == 0) ? 1 : ydir;  // h�Ǵ�0�̸� ������ȯ��.
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

	cout << "�ַ��1" << endl;
	start = clock();
	solution1(w, h, p, q, t);
	end = clock();
	cout << "�ҿ�ð�(ms) = " << (end - start) << endl;

	cout << "�ַ��2" << endl;
	start = clock();
	solution2(w, h, p, q, t);
	end = clock();
	cout << "�ҿ�ð�(ms) = " << (end - start) << endl;
	return 0;
}