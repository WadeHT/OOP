#include<stdio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
bool VaildWord(char word)
{
	if(word<='9'&&word>='0' || word<='z'&&word>='a' || word<='Z'&&word>='A' || word=='\'')return 1;
	return 0;
}
void ToEnlish(char Eword[],char word[])
{
	size_t len=strlen(word);
	int j,i;
	for(i=0,j=0;i<len;i++)if(VaildWord(word[i]))Eword[j++]=word[i];
	Eword[j]='\0';
	return;
}
int findWord(FILE *fd,char key[],int n)
{
	unsigned int counter=0;
	char word[25],Eword[25];
	for(int now=1;fscanf(fd,"%s",word)!=EOF;now)
	{
		ToEnlish(Eword,word);
		if(strcasecmp(Eword,key) == 0)
			if(++counter == n)return now;
		if(word[0] != '\0')now++;
		word[0]='\0';
	}
	return -1;
}
int main(void)
{
	char keyIn[100],cmd[25],word[25],n[10],Eword[25];
	unsigned int counter;
	FILE *fd=NULL;	
	while(true)
	{
		gets(keyIn);
		sscanf(keyIn,"%s",cmd);
		if(strcmp(cmd,"load") == 0)
		{
			sscanf(keyIn,"%s%s",cmd,word);
			fd=fopen(word,"r");
			if(fd == NULL)cout<<"ERROR: Error reading from file\n";
		}
		else if(strcmp(cmd,"locate") == 0)
		{
			sscanf(keyIn,"%s%s%s",cmd,word,n);
			fseek(fd,0,SEEK_SET);
			ToEnlish(Eword,word);
			counter=findWord(fd,Eword,atoi(n));
			if(counter == -1) cout<<"No matching entry\n";
			else cout<<counter<<endl;
		}
		else if(strcmp(cmd,"new") == 0)fclose(fd);
		else if(strcmp(cmd,"end") == 0)
		{
			fclose(fd);
			break;
		}
		else cout<<"ERROR: Invalid command\n";
	}
	return 0;
}