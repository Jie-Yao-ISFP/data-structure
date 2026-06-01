#define _CRT_SECURE_NO_WARNINGS
#include"Seqlist.h"
int main()
{
	Seqliststart(&sl);
	Seqpush_back(&sl, 4);//Œ≤≤Â
	Seqpush_back(&sl, 3);//Œ≤≤Â
	Seqpush_back(&sl, 2);//Œ≤≤Â
	Seqpush_back(&sl, 1);//Œ≤≤Â
	SeqlistPrint(sl);
	//≤‚ ‘‘⁄÷∏∂®Œª÷√≤Â»Î/…æ≥˝
	int pos = SLFind(&sl, 3);
	SeqInsert(&sl, pos, 8);
	SeqlistPrint(sl);
	//Seqpop_back(&sl);//Œ≤…æ
	//SeqlistPrint(sl);//1 2 
	//Seqpop_back(&sl);
	//SeqlistPrint(sl);//1
	////Seqpop_back(&sl);
	//SeqlistPrint(sl);//
 	//Seqpush_front(&sl, 5);
	//Seqpush_front(&sl, 6);
	//Seqpush_front(&sl, 7);
	//Seqpush_front(&sl, 8);
	//Seqpush_front(&sl, 9);
	//SeqlistPrint(&sl);
	Seqdestroy(&sl);
	return 0;
}
