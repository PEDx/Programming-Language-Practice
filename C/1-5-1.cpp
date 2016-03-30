#include<stdio.h>
int main()
{
	int cs=0,bcs=0;
	int i;
	scanf("%d %d",&bcs,&cs);
	if(bcs<cs){
	//	printf("0.");
		for(;bcs>0,i<=10;i++){
			int ret=0;
			ret=bcs%cs;	
			bcs/=cs;
			bcs*=10;
					//printf("d%d ",bcs);
		printf("%d",bcs);				//printf("a%d ",bcs);
	//	if(ret*10<cs){
	//	printf("0");
	//	ret*=10;
		//printf("%d ",bcs);
//		}						//printf("c%d ",bcs);
		
	}
		
		}else {
		int ret=bcs%cs;
		bcs/=cs;
		printf("%d.",bcs);
		while(ret>0)
			ret%=cs;
			printf("%d",ret);
			ret*=10;
			ret/=cs;
		}
	return 0;
}
