#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
	if (argc == 3) {
		//���Զ�ȡ�ļ�������
		FILE *fp = fopen(argv[2], "r");

		if (!fp) {
			printf("wrong���ļ���ȡʧ��\n");
			return -1;
		}

		//�Բ��������ж�      
		if (!strcmp(argv[1], "-c")) {		//�ַ���
			char temp;
			int n = 0;
			temp = fgetc(fp);
			while (temp != EOF) {
				temp = fgetc(fp);
				n++;
			}
			printf("�ַ�����%d\n", n);
		}
		else if (!strcmp(argv[1], "-w")) {	//������
			int w = 1;
			char a = fgetc(fp);
			while (a != EOF) {
				if (a == ' ' || a == ','||a == '\n') {
					w++;
				}
				a = fgetc(fp);
			}
			printf("��������%d\n", w);
		}
		else {
			printf("wrong!\n");
			printf("use��-c��-w\n");
		}
		int n = fclose(fp);
	}
	else {
		printf("wrong!\n");
		printf("use��WordCount.exe [parameter] [input_file_name]\n");
	}
	system("pause");
	return 0;
}