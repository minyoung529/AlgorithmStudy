#include<stdio.h>

int main()
{
	int ch, cm, cs;			// current time
	int wh, wm, ws;			// wait time
	int h = 0, m = 0, s = 0;	// answer

	scanf_s("%d:%d:%d %d:%d:%d", &ch, &cm, &cs, &wh, &wm, &ws);

	s = (ws - cs);

	if (s < 0)
	{
		// �޾Ƴ��� 
		s += 60;
		cm++;
	}

	m = (wm - cm);

	if (m < 0)
	{
		// �޾Ƴ��� 
		m += 60;
		ch++;
	}

	h = wh - ch;
	if (h < 0)
		h += 24;

	// 1�� �̻� ��ٷ��� �ϹǷ� 24�ð� ��ٸ�  
	if (h == 0 && m == 0 && s == 0)
	{
		h = 24;
	}

	printf("%02d:%02d:%02d", h, m, s);
}
