#ifndef MYSTL_H
#define MYSTL_H
	#include <bits/stdc++.h>
	#include <errno.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	using namespace std;

    typedef struct Node{
        struct Node *next;
        char *path;
        string name;
        mode_t          st_mode;
        ino_t           st_ino;
        off_t           st_size;
        struct timespec st_atim;
        struct timespec st_mtim;
	}node;
	void printList(node *head);
	void storeAttributes(node **head,char *path);
	void mySort(node **head,string select);
#endif
