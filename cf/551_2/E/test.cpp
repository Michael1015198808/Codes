#include <cstdio>
#include <cstdlib>
int snake[2000][2];
int direc[4][2]={
    { 0, 1},
    { 1, 0},
    { 0,-1},
    {-1, 0} 
};
int main(){
    int a,b,c,d,op;
    int i;
    snake[0][0]=rand()%1000;
    snake[0][1]=rand()%1000;
    for(i=1;i<2000;++i){
        do{
            op=rand()&3;
            snake[i][0]=snake[i-1][0]+direc[op][0];
            snake[i][1]=snake[i-1][1]+direc[op][1];
        }while(!(
                snake[i][0]>0&&snake[i][0]<1001&&
                snake[i][1]>0&&snake[i][1]<1001
        ));
    }
    printf("1000\n");
    fflush(stdout);
    while(1){
        do{
            op=getchar();
        }while(op!='?'&&op!='!');
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(op=='?'){
            int cnt=0;
            for(i=1;i<2000;++i){
                if((a<=snake[i][0]&&snake[i][0]<=c&&
                   b<=snake[i][1]&&snake[i][1]<=d)^
                   (a<=snake[i-1][0]&&snake[i-1][0]<=c&&
                   b<=snake[i-1][1]&&snake[i-1][1]<=d)){
                    ++cnt;
                }
            }
            printf("%d\n",cnt);
            fflush(stdout);
        }else{
            if(
                ( a==snake[0][0]
                &&b==snake[0][1]
                &&c==snake[1999][0]
                &&d==snake[1999][1]
                )||(
                  c==snake[0][0]
                &&d==snake[0][1]
                &&a==snake[1999][0]
                &&b==snake[1999][1]
                )
            )return fprintf(stderr,"true\n"),0;
            else return fprintf(stderr,"false\n"),1;
        }
    }
    return 0;
}
