#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
bool IsEnglish(char word)
{
	return(word >= 'a' && word <='z' || word <='Z' && word >='A')? 1 : 0;
}
char ToCap(char word)
{
	return (word>'Z')?word-('a'-'A'):word;
}
int main(int argc,char *argv[])
{
	int i,j;
	char word[100000]; 
	if(argc<2)
	{
		cout<<"no\n";
		return 0;
	}
	for(i = 1,j = 0;i < argc; i++)
		for(int k = 0; k < strlen(argv[i]); k++)
			if(IsEnglish(argv[i][k]))word[j++] = ToCap(argv[i][k]);
	word[j]='\0';
	size_t len = strlen(word);
	for(i = 0;i < len>>1; i++)if(word[i] != word[len-i-1])break;
	if(i < len>>1)cout<<"no\n";
	else cout<<"yes\n";
	return 0;
}
