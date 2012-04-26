/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#include <string>
#include <iostream>

#include "Expression.h"
#include "Keywords.h"
#include "PkParser.h"

using namespace std;

/*
//////////////////////////////TO CHECK MEMORY LEAK/////////////
#include	<stdio.h>
#include	<malloc.h>
#include	<string.h>
#include	"leak_detector_c.h"

#undef		malloc
#undef		calloc
#undef 		free


static MEM_LEAK * ptr_start = NULL;
static MEM_LEAK * ptr_next =  NULL;

void add(MEM_INFO alloc_info)
{

	MEM_LEAK * mem_leak_info = NULL;
	mem_leak_info = (MEM_LEAK *) malloc (sizeof(MEM_LEAK));
	mem_leak_info->mem_info.address = alloc_info.address;
	mem_leak_info->mem_info.size = alloc_info.size;
	strcpy(mem_leak_info->mem_info.file_name, alloc_info.file_name); 
	mem_leak_info->mem_info.line = alloc_info.line;
	mem_leak_info->next = NULL;

	if (ptr_start == NULL)	
	{
		ptr_start = mem_leak_info;
		ptr_next = ptr_start;
	}
	else {
		ptr_next->next = mem_leak_info;
		ptr_next = ptr_next->next;				
	}

}

void erase(unsigned pos)
{

	unsigned index = 0;
	MEM_LEAK * alloc_info, * temp;
	
	if(pos == 0)
	{
		MEM_LEAK * temp = ptr_start;
		ptr_start = ptr_start->next;
		free(temp);
	}
	else 
	{
		for(index = 0, alloc_info = ptr_start; index < pos; 
			alloc_info = alloc_info->next, ++index)
		{
			if(pos == index + 1)
			{
				temp = alloc_info->next;
				alloc_info->next =  temp->next;
				free(temp);
				break;
			}
		}
	}
}

void clear()
{
	MEM_LEAK * temp = ptr_start;
	MEM_LEAK * alloc_info = ptr_start;

	while(alloc_info != NULL) 
	{
		alloc_info = alloc_info->next;
		free(temp);
		temp = alloc_info;
	}
}

void * xmalloc (unsigned int size, const char * file, unsigned int line)
{
	void * ptr = malloc (size);
	if (ptr != NULL) 
	{
		add_mem_info(ptr, size, file, line);
	}
	return ptr;
}


void * xcalloc (unsigned int elements, unsigned int size, const char * file, unsigned int line)
{
	unsigned total_size;
	void * ptr = calloc(elements , size);
	if(ptr != NULL)
	{
		total_size = elements * size;
		add_mem_info (ptr, total_size, file, line);
	}
	return ptr;
}


void xfree(void * mem_ref)
{
	remove_mem_info(mem_ref);
	free(mem_ref);
}


void add_mem_info (void * mem_ref, unsigned int size,  const char * file, unsigned int line)
{
	MEM_INFO mem_alloc_info;


	memset( &mem_alloc_info, 0, sizeof ( mem_alloc_info ) );
	mem_alloc_info.address 	= mem_ref;
	mem_alloc_info.size = size;
	strncpy(mem_alloc_info.file_name, file, FILE_NAME_LENGTH);
	mem_alloc_info.line = line;
	

	add(mem_alloc_info);
}

void remove_mem_info (void * mem_ref)
{
	unsigned short index;
	MEM_LEAK  * leak_info = ptr_start;


	for(index = 0; leak_info != NULL; ++index, leak_info = leak_info->next)
	{
		if ( leak_info->mem_info.address == mem_ref )
		{
			erase ( index );
			break;
		}
	}
}

void report_mem_leak(void)
{

	MEM_LEAK * leak_info;

	FILE * fp_write = fopen (OUTPUT_FILE, "wt");
	char info[1024];

	if(fp_write != NULL)
	{
		sprintf(info, "%s\n", "Memory Leak Summary");
		fwrite(info, (strlen(info) + 1) , 1, fp_write);
		sprintf(info, "%s\n", "-----------------------------------");	
		fwrite(info, (strlen(info) + 1) , 1, fp_write);
		
		for(leak_info = ptr_start; leak_info != NULL; leak_info = leak_info->next)
		{
			sprintf(info, "address : %d\n", leak_info->mem_info.address);
			fwrite(info, (strlen(info) + 1) , 1, fp_write);
			sprintf(info, "size    : %d bytes\n", leak_info->mem_info.size);			
			fwrite(info, (strlen(info) + 1) , 1, fp_write);
			sprintf(info, "file    : %s\n", leak_info->mem_info.file_name);
			fwrite(info, (strlen(info) + 1) , 1, fp_write);
			sprintf(info, "line    : %d\n", leak_info->mem_info.line);
			fwrite(info, (strlen(info) + 1) , 1, fp_write);
			sprintf(info, "%s\n", "-----------------------------------");	
			fwrite(info, (strlen(info) + 1) , 1, fp_write);
		}
	}	
	clear();
}
*/

void PrintCopyright()
{
	cout << "*   Copyright 2008-2011 Pradeep Kodical" <<endl;
	cout << "*   NO WARRANTY" <<endl;
}

void PrintHelp()
{
	PrintCopyright();
	cout << PkParser::GetParserFunctions() << endl;
	cout << PkParser::GetParserOperators() << endl;
}
void PrintExpression(string &infix)
{
	try
	{
	Keywords keywords;
	double results = 0;
	keywords.ResolveKeywords(infix);

	Expression *exp = PkParser::Solve(infix);

	cout <<"Equation: " << exp->toString(0) <<endl;

	results = exp->Solve();

	cout << results <<endl;

	delete exp;
	}
	catch(PkException *exp)
	{
		cout << "Exception:" << exp->toString() <<endl;
	}
	catch(...)
	{
		cout << "Unknown Error"<<endl;
	}
}

int main()
{
	PrintCopyright();	
	string infix;
	char c[8000];

 	cout << "Type any math expression: (Ctrl-C to exit)" <<endl;
	while(1)
	{
		
		cout << ">";

		
		gets(c);
		infix = c;
		//infix = "78*78-78+IIF(78<89 AND 78>67,123,124)";
				
		if(infix == "help")
			PrintHelp();
		else
			PrintExpression(infix);
		infix = "";
	}

	//atexit(report_mem_leak);	

	return 1;
}