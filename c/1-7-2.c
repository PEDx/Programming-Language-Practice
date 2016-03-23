;
	scanf("%d",&n);//开始输入数组； 
	int nmax=n-1;
	int a[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(cnt1<n*n){ 
					scanf("%d",&a[i][j]);
					cnt1++;
			}
		}
	}
	for (i=0;i<n;i++){
		int max=0;
		for (j=0;j<n;j++){
			if(a[i][j]>=max){
				max=a[i][j];//用于得到每行中最大的数字	
			}
			if(j==n-1){//直到一行传入完毕 
				for(j=0;j<n;j++){//因为下标会被覆盖丢失，再用值反向循环得出下标 
					if(a[i][j]==max){
						int k=j;//令k等于每行最大值的列 下标 
						int min=a[0][k];//假设每列第一个数字为最小值 
						for(int l=0;l<n;l++){//开始比较行最大值对应的列中的最小值 
							if(a[l][k]<=min){
								min=a[l][k];
							}
							if(l==n-1){
								if(min==max){//如果相等，那么输出下标且cnt加1
									cnt2++;
									printf("%d %d",i,j);
								}
							}	
						}
					}
				}	
			}	
	   }
	}	
	if(cnt2==0){//如果遍历完全都没有鞍点输出NO 
		printf("NO");
	}		
	return 0;
}
