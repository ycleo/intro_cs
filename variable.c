
#include <stdio.h>

int main()
{
// Local Variable
char c1, c2;    // 1byte (-128 ~ 127)
short s1, s2;	// 2 bytes (-32768 ~ -32767)
int i1, i2;		// 4 bytes (-21億 ~ 21億)
long L1, L2;	// 4 bytes (-21億 ~ 21億)

float f1, f2;	//6位精確度
double d1, d2;	//15位精確度
long long LL1, LL2;  // 8 bytes

c1 = 100; c2 = 100; c1 += c2;
printf("Size = %d c1=%d c2=%d %c\r\n", sizeof(char), c1, c2, c2);

s1 = 100; s2 = 100; s1 += s2;
printf("Size = %d s1=%d s2=%d\r\n", sizeof(short), s1, s2);

i1 = 1100000000; i2 = 1100000000; i1 += i2;
printf("Size = %d i1=%d i2=%d\r\n", sizeof(int), i1, i2);

LL1 = 1100000000; LL2 = 1100000000; LL1 += LL2;
printf("Size = %d LL1=%lld LL2=%lld\r\n", sizeof(long long), LL1, LL2);

f1 = 12.3456789; float pi = 3.14159265358979323; f2 = pi * f1 * f1;
printf("size=%d pi=%f 半徑=%f 面積=%f\r\n", sizeof(float), pi, f1, f2);

d1 = 12.3456789; d2 = pi * d1 * d1;
printf("size=%d pi=%15.12f 半徑=%15.12f 面積=%15.12f\r\n", sizeof(double), pi, d1, d2); // 可印出15位 (含小數點及小數點後12位)

unsigned char uc1, uc2;  //1byte (0~255)
unsigned short us1, us2; //2byte (0~65535)
unsigned long uL1, uL2;	 //4byte (0~42億)

uc1 = 100; uc2 = 100; uc1 += uc2;
printf("uc1=%d uc2=%d\r\n", uc1, uc2);

//Array
int i, j, k, N = 10;
int S[100] = { 90, 30, 50, 44, 88, 66, 77, 92, 34, 98 };
float Ave;
	Ave = 0.0;  //一定要清成0
	for (i=0;i<N;i++)
	{
		Ave += (float)S[i];
		printf("i=%d S[%d]=%d Ave=%f\r\n", i, i, S[i], Ave);
	}
	printf("Average is %f\r\n", Ave / (float)N);

float std;

	Ave = std = 0.0;
	for (i = 0; i < N; i++)
	{
		Ave += (float)S[i];
		std += S[i] * S[i];
	}
	Ave /= (float)N;
	std = std/N - Ave*Ave;
	
	std = sqrt(std);
	printf("mean = %f, standard deviation=%f\r\n", Ave, std);

	//AL (Arithmetic & Logic)
float u = 0.0;
Ave = 0.0;
float Ave_fail = 0.0, Ave_above80 = 0.0;
	for (i = 0, j = 0, k = 0; i < N; i++)
	{
		if (S[i] >= 60) 
		{ 
			j++;
			Ave += (float)S[i];
			if (S[i] >= 80 && S[i] < 90) { k++; Ave_above80 += (float)S[i];}	
		}
		else
			Ave_fail += (float)S[i];
	}
	Ave /= (float)j;
	Ave_fail /= (float)(N-j);
	printf("the number of people who pass the test: %d, Average: %f\r\n", j, Ave);
	printf("the number of people who fail the test: %d, Average: %f\r\n", N-j, Ave_fail);
	printf("the number of people who score between 80~89: %d, Average: %f\r\n", k, Ave_above80);
	
	int x, result = 0;

	printf("input x = ");
	scanf_s("%d", &x);
	
	for (k = 0; k <= x; k++ )
	{
		result += (k * k + 2 * k + 3);
	}

	printf("f1(%d) = %d\r\n",x, result);


	result = 0;
	for (k = 0; k <= x; k++)
		for (j = 0; j <= (2 * x); j++)
			result += j * k + 2 * k + 5;
	printf("f2(%d) = %d\r\n", x, result);

	result = 0;
	int one = 0;
	int	two = 0;
	for (k = 0; k <= x; k++)
	{
		one += k * k;
		for (j = k; j <= 3 * k; j++)
			two += j * k + 2 * j + 5;
	}
	two *= 2;
	result = one + two;
	printf("f3(%d) = %d\r\n", x, result);
}
