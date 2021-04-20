int main()
{
	//字串copy
	char name[15], name2[30];  //15 bytes and 30 bytes
	strcpy_s(name, "陽明黃紹華"); 
	strcpy_s(name2, "陽明交通大學"); //英文字元1 byte; 中文字元2 bytes
	printf("Name is %s, Fschool is %s.\r\n", name, name2);
	//字串比較
	if (strcmp(name, name2))
		printf("string is different.\r\n");
	else
		printf("string is same.\r\n");

	if (strncmp(name, name2, 4))
		printf("前兩個字不同\r\n");
	else
		printf("前兩個字相同\r\n");

	//字串連接
	strncat_s(name2, name, 4);
	printf("name2 = %s\r\n", name2);

	strcat_s(name2, name);  //部分連接
	printf("name2 = %s\r\n", name2);

	//練習二: 以整數處理字串
    //http://www.asciitable.com/
	char a[100] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0}; // 16進位表示法; 最後的0代表的是字串結束!!!!
	//等價於 char a[100] = {48, 49, 50, 51, 52, 53, 54, 0} 十進位表示 
	printf("a = %s\r\n", a); //ascii codes 中: 0x32 代表 字元'0'; 0x31代表 字元'1'
	
	char b[4];
	b[0] = 48; b[1] = 49; b[2] = 50;
	b[3] = 0;  //0代表的是字串結束!!!!
	printf("b = %s\r\n", b);

	a[0] = '0';
	a[1] = 49;
	a[2] = 0x32;
	a[3] = '3';
	a[4] = 'a';
	a[5] = 0x62;
	a[6] = 'c';
	a[7] = 100;
	a[8] = 0;
	printf("a = %s\r\n", a);
	//10進位, 16進位, 字元 混用

	//練習三: 整數+字串處理
	char c[100] = { "This is a book." };
	printf("c = %s\r\n", c);

	c[10] = 0x63;
	printf("c' = %s\r\n", c);
	
	c[10] += 1;
	printf("c' = %s\r\n", c);
	
	c[6] = 0x00;
	printf("c'' = %s\r\n", c);
}
