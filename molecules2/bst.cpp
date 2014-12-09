/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include<iostream>
#include<cstring>
#include "molecules.h"
using namespace std;

bool find(mol root,buffer temp)
{
	if(root==NULL)
		return false;
	else
	{
		if(strcmp(root->finger,temp.finger)==0)
			return true;
		else if(temp.position<root->position)
			return find(root->left,temp);
		else
			return find(root->right,temp);
	}
}

int insert(mol &root,buffer temp)
{
	if(root==NULL)
	{
		mol node=new molecules;
		node->position=temp.position;
		node->speed=temp.speed;
		node->energy=temp.energy;
		strcpy(node->finger,temp.finger);
		node->left=NULL;
		node->right=NULL;
		root=node;
	}
	else if(temp.position>root->position)
			insert(root->right,temp);
	else
		insert(root->left,temp);
	return 1;
}

void inorder(mol root,molecules report[],int &i)
{		
	if(root!=NULL)
	{
		inorder(root->left,report,i);
		report[i].position=root->position;
		report[i].speed=root->speed;
		report[i].energy=root->energy;
		strcpy(report[i].finger,root->finger);
		i++;
		inorder(root->right,report,i);
	}
}