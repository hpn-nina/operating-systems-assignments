#include <stdio.h>
#include<stdlib.h>
int main() 
{
 	int a[10],b[10],x[10], pn[10],i,j,smallest,count=0,time,n,response[10];
 	float avg=0,tt=0,end;
 	int wt[10], t_t[10];
 	FILE *file;
	file = fopen("input.txt","r");
	
	if(file == NULL)
		exit(1);
	
	fscanf(file,"%d", &n);
	
	for(int i = 1; i <= n; i++)
	{
		fscanf(file,"%d%d%d",&pn[i-1],&a[i-1],&b[i-1]);
		x[i-1] = b[i-1];
	}
  	
  	b[9]=9999;
  	
  	int flag[10];
  	
  	for(i = 0;i<10;i++) flag[i] = 0;
 	
 	for(time=0;count!=n;time++)
 	{
   		smallest=9;
  		
  		for(i=0;i<n;i++)
  		{	
   			if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
   				smallest=i;
  		}
  		b[smallest]--;
  		
  		if(flag[smallest] == 0)
   		{
   			 	response[smallest] = time;
   			 	flag[smallest] = 1;
   		}
  		
  		if(b[smallest]==0)
  		{
   			count++;
   			end=time+1;
   			wt[smallest] = end  - a[smallest]  - x[smallest];
   			t_t[smallest] = end - a[smallest]  ;
   			avg=avg+end-a[smallest]-x[smallest];
   			tt= tt+end-a[smallest];
   			
  		}
 	}

	file = fopen("output.txt","w");
	
	for(int i = 0; i < n; i++)
	{
		fprintf(file,"%d %d %d %d\n",pn[i],response[i],wt[i], t_t[i]);
	}
	
	float avg_wt = avg/n*100/100;
	
	float avg_tt = tt/n*100/100;
	
	fprintf(file,"%0.2f", avg_wt);
	fprintf(file,"\n%0.2f", avg_tt);
	fclose(file);
    	return 0;
}