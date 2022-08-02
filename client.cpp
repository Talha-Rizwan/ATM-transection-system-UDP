#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<time.h>
using namespace std;


#define PORT	 8080
#define MAXLINE 1024


int main() {
srand(time(NULL));
	int sockfd;
	char buffer[MAXLINE];
	char buf[10000];
	//char *hello = "Hello from client";
	struct sockaddr_in	 servaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	//memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int n;
	socklen_t  len;
	
	
	int MAX_LIMIT=100;
char str[MAX_LIMIT];

string st="start";

//cout<<"the string is : "<<st<<endl;

char ch[st.length() + 1]; 
strcpy(ch, st.c_str()); 
	
	sendto(sockfd, (const char *)ch, strlen(ch),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
//	printf("Hello message sent.\n");
		
	n = recvfrom(sockfd, (char *)buf, sizeof(buf),
				0, (struct sockaddr *) &servaddr,
				&len);
		printf("Server : %s\n", buf);			
	
	if(buf[0]=='1'){
	
	while(true){

	n = recvfrom(sockfd, (char *)buf, sizeof(buf),
				0, (struct sockaddr *) &servaddr,
				&len);
		printf("Server : %s\n", buf);
		string s=string(buf);
		if(s=="process1")
		break;
		}			
//server will reply proceed

	cout<<"verifying your card"<<endl;
	cout<<"please be patient"<<endl;
	
//	system(wait(2));
	cout<<"your card has successfully been verified"<<endl;
	cout<<"terminating the card reading process"<<endl;
	
string st="completed";	
char ch[st.length() + 1]; 
strcpy(ch, st.c_str()); 
	
		sendto(sockfd, (const char *)ch, strlen(ch),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));

for(int i=0;i<2;i++){

	n = recvfrom(sockfd, (char *)buf, sizeof(buf),
				0, (struct sockaddr *) &servaddr,
				&len);
		printf("Server : %s\n", buf);
string s="already done";
char ch1[s.length() + 1]; 
strcpy(ch1, s.c_str()); 


		sendto(sockfd, (const char *)ch1, strlen(ch1),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));

	}


	
	}
	
	else if(buf[0]=='2'){
	
	while(true){
	n = recvfrom(sockfd, (char *)buf, sizeof(buf),
				0, (struct sockaddr *) &servaddr,
				&len);
		printf("Server : %s\n", buf);			
		
		string s=string(buf);
		if(s=="process2")
		break;
	string st="not completed";	
	char ch[st.length() + 1]; 
	strcpy(ch, st.c_str()); 
	
		sendto(sockfd, (const char *)ch, strlen(ch),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
	}


//server will reply start the second process	
	int pin;
	cout<<"pin varifying process"<<endl;
	cout<<"please enter your pin"<<endl;
	cin>>pin;
	
	cout<<"pin verified successfully"<<endl;
	cout<<"terminating the pin verifying process"<<endl;

string st="completed";	
char ch[st.length() + 1]; 
strcpy(ch, st.c_str()); 
	
		sendto(sockfd, (const char *)ch, strlen(ch),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));

for(int i=0;i<1;i++){

	n = recvfrom(sockfd, (char *)buf, sizeof(buf),
				0, (struct sockaddr *) &servaddr,
				&len);
		printf("Server : %s\n", buf);
string s="already done";
char ch1[s.length() + 1]; 
strcpy(ch1, s.c_str()); 


		sendto(sockfd, (const char *)ch1, strlen(ch1),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));

	}	
	}
	
	else if(buf[0]=='3'){
	
	while(true){
	n = recvfrom(sockfd, (char *)buf, sizeof(buf),
				0, (struct sockaddr *) &servaddr,
				&len);
		printf("Server : %s\n", buf);			
		
		string s=string(buf);
		if(s=="process3")
		break;
		
		
		string st="not completed";	
		char ch[st.length() + 1]; 
		strcpy(ch, st.c_str()); 
	
		sendto(sockfd, (const char *)ch, strlen(ch),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
		
		
		}
//srever will reply start the third process
	int total_amount=rand()%50000;
	int amount;
	cout<<"total amount in your bank account is "<<total_amount<<endl;
	cout<<"cash withdrawl"<<endl;
	cout<<"enter the amount you want to withdraw"<<endl;
	cin>>amount;
	if(amount>25000 || amount>total_amount){
	while(true){
	if(amount < 25000 && amount<total_amount){
	break;
	}

	cout<<"please enter again! the amount should be less than or equal to the total amount in the amount and must also not exceed 25000"<<endl;
	cin>>amount;
	}
	}
	
	total_amount=total_amount-amount;
	cout<<"amount withdrawled successfully, your remaining balance is : "<<total_amount<<endl;
	
	string st="completed";	
char ch[st.length() + 1]; 
strcpy(ch, st.c_str()); 
	
		sendto(sockfd, (const char *)ch, strlen(ch),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
	
	
	
	
	
	
	
	}
	
	
	
	
	
	

	
	
	close(sockfd);

	return 0;
}
	
