#include<iostream>
#include <algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include<cstring>
#include<fstream>

using namespace std;
int main() {
	int level=0;
	int num=0;
	int number=0;
	int total_num=0;
	int switch_num=0;
	int if_else_num=0;
	int if_else_if_num=0;
	int case_num[switch_num];
	string data="";
	int len=0;
	int pos=0;
	int poss=0;
	string str;
	string::size_type idx;
	stack<int>s;
	string m[3]={"if","else","elif"};
	string key[32]={"auto","break","case","char","const","continue","default","double","do",
			"else","enum","extern","float","for","goto","if","int","long","register",
			"return","short","signed","sizeof","static","struct","switch","typedef",
			"union","unsigned","void","volatile","while"};
	cout << "Please enter the level = ";
	cin >> level;
	int c=0;
	int else_if_number=0;
	ifstream out("test.cpp");
	while (!out.eof()){
		getline(out,str);
		string strr="else if";
		string::size_type idx;
		idx=str.find(strr);
		if(idx!=str.npos){
			str.erase(str.find(strr)+2,3);
		}
		for(int i=0;i<=32;i++){
			string::size_type position;
			position=str.find(key[i]);
			if(position!=str.npos){
				total_num++;
				if(i==25){ // find the keyword "switch"
					switch_num++;
					case_num[switch_num]=0;
				}
				if(i==2){ // find the keyword "case"
					case_num[switch_num]++;
				}
				if(i==7){ // find the keyword "double"
					total_num--;//double & do will repeat
				}
			}
		}
		for(int i=0;i<3;i++){
			string::size_type id;
			id=str.find(m[i]);
			if(id!=str.npos){
				data.append(m[i]); // create a new array data for "if""else if""else"
				number++;
			}
		}
	}
	for(int i=0;i<number;i++){
		string::size_type pos;
		pos=data.find("elif");
		if(pos!=data.npos){
			if_else_if_num++;
			total_num++;
			data.erase(data.find("elif"),4);
			if(data[data.find("elif")]==data[data.find("elif")+4]){
				if_else_if_num--;
			}
		}
	}
	for(int i=0;i<number;i++){
		string::size_type poss;
		poss=data.find("else");
		if(poss!=data.npos){
			if_else_num++;
			data.erase(data.find("else"),4);
		}
	}
	if(level>=1) {
		printf("total num:%d\n", total_num);
		if(level>=2) {
			printf("switch num:%d\n", switch_num);
			printf("case num: ");
			for(int i=1; i<=switch_num;i++){
				printf("%d", case_num[i]);
				if(i==switch_num){
					printf("\n");
				}
				else{
					printf(" ");
				}
			}
			if(level>=3) {
				printf("if_else num:%d\n", if_else_num-if_else_if_num);
				if(level==4) {
					printf("if_else_if num:%d\n", if_else_if_num);
				}
			}
		}
	}
	return 0;
}
