#include<stdio.h>
#include<string.h>
int main()
{
	char gps[100];
	char w[]="$GPRMC";
	char t[]="END";
	int c=0;
	char gs[6];
	while(c==0){
		scanf("%s",gps);
//		for(int i=0;i<100;i++){
//			printf("%p",p);
//		}
		char* s1=strstr(gps,w);
		char* s2=strstr(gps,t);
		if(s2){
			c++;
		}
		if(s1&&gps[18]=='A'){
			int l=strlen(gps);
			int r=gps[1];
			for(int i=1;i<l-4;i++){
				r^=gps[i+1];
//				printf("%d\n",r);
			}
//			printf("%d\n",r);printf("%d\n",m);
			int a=r%65536;
			char m=gps[l-2];
			switch(m){
				case '1':m=1;break;
				case '2':m=2;break;
				case '3':m=3;break;
				case '4':m=4;break;
				case '5':m=5;break;
				case '6':m=6;break;
				case '7':m=7;break;
				case '8':m=8;break;
				case '9':m=9;break;
				case '0':m=0;break;
				case 'A':m=10;break;
				case 'B':m=11;break;
				case 'C':m=12;break;
				case 'D':m=13;break;
				case 'E':m=14;break;
				case 'F':m=15;break;
			}
			char n=(char)gps[l-1];
			switch(n){
				case '1':n=1;break;
				case '2':n=2;break;
				case '3':n=3;break;
				case '4':n=4;break;
				case '5':n=5;break;
				case '6':n=6;break;
				case '7':n=7;break;
				case '8':n=8;break;
				case '9':n=9;break;
				case '0':n=0;break;
				case 'A':n=10;break;
				case 'B':n=11;break;
				case 'C':n=12;break;
				case 'D':n=13;break;
				case 'E':n=14;break;
				case 'F':n=15;break;
			}
			int cnt=m*16+n;
//			printf("%d",m);
			if(a==cnt){
				for(int i=7;i<13;i++){
					gs[i]=gps[i];
				}
			}
		}
	}
		printf("%c%c:%c%c:%c%c",gs[7],gs[8],gs[9],
					gs[10],gs[11],gs[12]);
	return 0;
}
