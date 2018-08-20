#include"Declaration.h"
#include<iostream>

DoctorNode::DoctorNode()
{
	obj = NULL;
	next = NULL;
}
Doctor* DoctorNode::getObj()
{
	return obj;
}
void DoctorNode::setObj(Doctor *object)
{
	obj = object;
}
DoctorNode* DoctorNode::getNext()
{
	return next;
}
void DoctorNode::setNext(DoctorNode *nex)
{
	next = nex;
}