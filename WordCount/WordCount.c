#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
	if (argc == 3) {
		//尝试读取文件的内容
		FILE *fp = fopen(argv[2], "r");

		if (!fp) {
			printf("wrong：文件读取失败\n");
			return -1;
		}

		//对参数进行判断      
		if (!strcmp(argv[1], "-c")) {		//字符数
			char temp;
			int n = 0;
			temp = fgetc(fp);
			while (temp != EOF) {
				temp = fgetc(fp);
				n++;
			}
			printf("字符数：%d\n", n);
		}
		else if (!strcmp(argv[1], "-w")) {	//单词数
			int w = 1;
			char a = fgetc(fp);
			while (a != EOF) {
				if (a == ' ' || a == ','||a == '\n') {
					w++;
				}
				a = fgetc(fp);
			}
			printf("单词数：%d\n", w);
		}
		else {
			printf("wrong!\n");
			printf("use：-c，-w\n");
		}
		int n = fclose(fp);
	}
	else {
		printf("wrong!\n");
		printf("use：WordCount.exe [parameter] [input_file_name]\n");
	}
	system("pause");
	return 0;
}