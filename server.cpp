#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<fstream>
#include<time.h>
using namespace std;

#define PORT	 8080
#define MAXLINE 1024

// Driver code

int ran(void){

srand(time(NULL));

int r=rand()%3+1;

return r;

}




int main() {
	int sockfd;
	char buffer[MAXLINE];
//	char *hello = "Hello from server";
	char buf[200];
	struct sockaddr_in servaddr, cliaddr[3];
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	//memset(&servaddr, 0, sizeof(servaddr));
	//memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	socklen_t len;
	int n;

	len = sizeof(cliaddr); //len is value/resuslt
int MAX_LIMIT=100;
char str[MAX_LIMIT];


for(int i=0;i<3;i++){

n = recvfrom(sockfd, (char *)buf, MAXLINE,
				0, ( struct sockaddr *) &cliaddr[i],
				&len);
	printf("\n %s \n", buf);	

}











int option;
cout<<"MENU"<<endl;
cout<<"press 1 to withdraw cash from your account"<<endl;
cout<<"	this will include :"<<endl;
cout<<"	card reading"<<endl;
cout<<"	pin verification"<<endl;
cout<<"	cash withdrawl"<<endl<<endl;
cout<<"press 2 to exit"<<endl;
cin>>option;

if(option==1){

//implement the error of transaction on zero


srand(time(NULL));
int r;
r=rand()%4;
if(r==0){
cout<<"transaction failed"<<endl;
cout<<"please try again!!"<<endl;

string a="0";

char stt[a.length() + 1]; 
strcpy(stt, a.c_str()); 

for(int i=0;i<3;i++){
sendto(sockfd, (const char *)stt, strlen(stt),
		0, (const struct sockaddr *) &cliaddr[i],len);	

}

}

else {

int arr[3];


arr[0]=ran();

int num=ran();

if(num==arr[0]){

while(true){
num=ran();

if(num!=arr[0])
break;

}


}

arr[1]=num;

num=ran();

if(num==arr[0] || num==arr[1]){

while(true){
num=ran();

if(num!=arr[0] && num!=arr[1])
break;

}
}

arr[2]=num;

string numbers[3];

for(int i=0;i<3;i++){

numbers[i]=to_string(arr[i]);

}

//cout<<"the string numbers are"<<endl;
//cout<<numbers[0]<<endl;
//cout<<numbers[1]<<endl;
//cout<<numbers[2]<<endl;




char st1[numbers[0].length() + 1]; 
strcpy(st1, numbers[0].c_str()); 

char st2[numbers[1].length() + 1]; 
strcpy(st2, numbers[1].c_str()); 

char st3[numbers[2].length() + 1]; 
strcpy(st3, numbers[2].c_str()); 



sendto(sockfd, (const char *)st1, strlen(st1),
		0, (const struct sockaddr *) &cliaddr[0],len);	


sendto(sockfd, (const char *)st2, strlen(st2),
		0, (const struct sockaddr *) &cliaddr[1],len);	

sendto(sockfd, (const char *)st3, strlen(st3),
		0, (const struct sockaddr *) &cliaddr[2],len);	


string s1="process1";
char str1[s1.length() + 1]; 
strcpy(str1, s1.c_str()); 

for(int i=0;i<3;i++){
sendto(sockfd, (const char *)str1, strlen(str1),
		0, (const struct sockaddr *) &cliaddr[i],len);	

}

for(int i=0;i<3;i++){

n = recvfrom(sockfd, (char *)buf, MAXLINE,
				0, ( struct sockaddr *) &cliaddr[i],
				&len);
//	printf("\n %s \n", buf);	

}	


cout<<"card reading is successful"<<endl;


string s2="process2";
char str2[s2.length() + 1]; 
strcpy(str2, s2.c_str()); 

for(int i=0;i<3;i++){
sendto(sockfd, (const char *)str2, strlen(str2),
		0, (const struct sockaddr *) &cliaddr[i],len);	

}

for(int i=0;i<3;i++){

n = recvfrom(sockfd, (char *)buf, MAXLINE,
				0, ( struct sockaddr *) &cliaddr[i],
				&len);
//	printf("\n %s \n", buf);	

}	

cout<<"pin verification process is completed"<<endl;




string s3="process3";
char str3[s3.length() + 1]; 
strcpy(str3, s3.c_str()); 

for(int i=0;i<3;i++){
sendto(sockfd, (const char *)str3, strlen(str3),
		0, (const struct sockaddr *) &cliaddr[i],len);	

}

for(int i=0;i<3;i++){

n = recvfrom(sockfd, (char *)buf, MAXLINE,
				0, ( struct sockaddr *) &cliaddr[i],
				&len);
//	printf("\n %s \n", buf);	

}	




cout<<"your transection is successfully completed"<<endl;


}

}



else if(option==2){

cout<<"all processes terminated"<<endl;
cout<<"thanks for visiting"<<endl;

string a="0";

char stt[a.length() + 1]; 
strcpy(stt, a.c_str()); 

for(int i=0;i<3;i++){
sendto(sockfd, (const char *)stt, strlen(stt),
		0, (const struct sockaddr *) &cliaddr[i],len);	

}
}

char ip1[INET_ADDRSTRLEN]; 
inet_ntop(AF_INET, &(cliaddr[0].sin_addr), ip1, INET_ADDRSTRLEN);

char ip2[INET_ADDRSTRLEN]; 
inet_ntop(AF_INET, &(cliaddr[1].sin_addr), ip2, INET_ADDRSTRLEN);

char ip3[INET_ADDRSTRLEN]; 
inet_ntop(AF_INET, &(cliaddr[2].sin_addr), ip3, INET_ADDRSTRLEN);

cout<<"the ip addresses are :"<<endl;
cout<<ip1<<endl;
cout<<ip2<<endl;
cout<<ip3<<endl;




	// close the socket
	close(sockfd);
	
	return 0;
}
