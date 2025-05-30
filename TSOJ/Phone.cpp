#include<iostream>
int main(){
	int h1,h2,m1,m2,s1,s2;
	scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
	int h = h2 - h1;
	int m = m2 - m1;
	int s = s2 - s1;
	int time = s + m*60 + h*60*60;
	if(time<0){
		time += 24*3600;
	}
	std::cout << time;
}
