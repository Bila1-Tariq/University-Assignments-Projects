#include"Declaration.h"
#include<iostream>

TeacherNode::TeacherNode()
{
	obj = NULL;
	next = NULL;
}
Teacher* TeacherNode::getObj()
{
	return obj;
}
void TeacherNode::setObj(Teacher *object)
{
	obj = object;
}
TeacherNode* TeacherNode::getNext()
{
	return next;
}
void TeacherNode::setNext(TeacherNode *nex)
{
	next = nex;
}