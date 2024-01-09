#include "objPos.h"
#include "objPosList.h"
#include "objPosArrayList.h"
#include "objPosDLinkedList.h"

#include <cstdlib>
#include <ctime>

#define COUNT 10
#define TOTAL_ASSERT_COUNT 439

#include <iostream>
using namespace std;

objPosList *ListUnderTest;
int successCount;

void clearList();
objPos generateRandomPos();
void assert_equal(int, int);
void assert_equal(char, char);

// This is the polymorphic list changer
void createNewList()
{
	if(ListUnderTest != NULL) clearList();
	//ListUnderTest = new objPosArrayList();	
	ListUnderTest = new objPosDLinkedList();
}

// Turn this true once you are ready to test getNext() and resetReadPos()
bool testGetNextReady = false;



void testConstructorGetSize() {
	
	cout << "TEST: testConstructorGetSize" << endl;
	createNewList();
	int expected = 0;
	int actual = ListUnderTest->getSize();	

	assert_equal(expected, actual);
	clearList();
}

void testConstructorIsEmptyTrue() {
	
	cout << "TEST: testConstructorIsEmptyTrue" << endl;
	createNewList();	
	bool expected = true;
	bool actual = ListUnderTest->isEmpty();		

	assert_equal(expected, actual);
	clearList();
}




// INSERT HEAD
// INSERT HEAD
// INSERT HEAD

void testInsertHeadIsEmptyFalse() {

	cout << "TEST: testInsertHeadIsEmptyFalse" << endl;
	createNewList();
	objPos testPos{};
	ListUnderTest->insertHead(testPos);

	bool expected = false;
	bool actual = ListUnderTest->isEmpty();	

	assert_equal(expected, actual);
	clearList();
}

void testInsertHeadGetSize() {
	
	cout << "TEST: testInsertHeadGetSize" << endl;
	createNewList();
	objPos testPos{};
	ListUnderTest->insertHead(testPos);
	ListUnderTest->insertHead(testPos);
	ListUnderTest->insertHead(testPos);
	int expected = 3;
	int actual = ListUnderTest->getSize();	

	assert_equal(expected, actual);
	clearList();
}

void testInsertHeadGetHead() {
	
	cout << "TEST: testInsertHeadGetHead" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->getHead();	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertHeadGetTail() {
	
	cout << "TEST: testInsertHeadGetTail" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->getTail();	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertHeadGetNegTen() {
	
	cout << "TEST: testInsertHeadGetNegTen" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(-10);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertHeadGetZero() {
	
	cout << "TEST: testInsertHeadGetZero" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(0);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertHeadGetOne() {
	
	cout << "TEST: testInsertHeadGetOne" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-2];
	objPos actual = ListUnderTest->get(1);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertHeadGetCountN3() {
	
	cout << "TEST: testInsertHeadGetCountN3" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[2];
	objPos actual = ListUnderTest->get(COUNT-3);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertHeadGetCountN1() {
	
	cout << "TEST: testInsertHeadGetCountN1" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(COUNT-1);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertHeadGetCountP5() {
	
	cout << "TEST: testInsertHeadGetCountP5" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(COUNT+5);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}




// INSERT TAIL
// INSERT TAIL
// INSERT TAIL

void testInsertTailIsEmptyFalse() {

	cout << "TEST: testInsertTailIsEmptyFalse" << endl;
	createNewList();
	objPos testPos{};
	ListUnderTest->insertTail(testPos);

	bool expected = false;
	bool actual = ListUnderTest->isEmpty();	

	assert_equal(expected, actual);
	clearList();
}

void testInsertTailGetSize() {
	
	cout << "TEST: testInsertTailGetSize" << endl;
	createNewList();
	objPos testPos{};
	ListUnderTest->insertTail(testPos);
	ListUnderTest->insertTail(testPos);
	ListUnderTest->insertTail(testPos);
	int expected = 3;
	int actual = ListUnderTest->getSize();	

	assert_equal(expected, actual);
	clearList();
}

void testInsertTailGetHead() {
	
	cout << "TEST: testInsertTailGetHead" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->getHead();	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertTailGetTail() {
	
	cout << "TEST: testInsertTailGetTail" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->getTail();	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertTailGetNegTen() {
	
	cout << "TEST: testInsertTailGetNegTen" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(-10);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertTailGetZero() {
	
	cout << "TEST: testInsertTailGetZero" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(0);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertTailGetOne() {
	
	cout << "TEST: testInsertTailGetOne" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[1];
	objPos actual = ListUnderTest->get(1);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertTailGetCountN3() {
	
	cout << "TEST: testInsertTailGetCountN3" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-3];
	objPos actual = ListUnderTest->get(COUNT-3);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertTailGetCountN1() {
	
	cout << "TEST: testInsertTailGetCountN1" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT-1);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertTailGetCountP5() {
	
	cout << "TEST: testInsertTailGetCountP5" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT+5);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}




// INSERT
// INSERT
// INSERT

void testInsertIsEmptyFalse() {

	cout << "TEST: testInsertIsEmptyFalse" << endl;
	createNewList();
	objPos testPos{};
	ListUnderTest->insert(testPos, 0);

	bool expected = false;
	bool actual = ListUnderTest->isEmpty();	

	assert_equal(expected, actual);
	clearList();
}

void testInsertGetSize() {
	
	cout << "TEST: testInsertGetSize" << endl;
	createNewList();
	objPos testPos{};
	ListUnderTest->insert(testPos, 0);
	ListUnderTest->insert(testPos, -1);
	ListUnderTest->insert(testPos, 10);
	int expected = 3;
	int actual = ListUnderTest->getSize();	

	assert_equal(expected, actual);
	clearList();
}

void testInsertGetHead() {
	
	cout << "TEST: testInsertGetHead" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->getHead();	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertGetTail() {
	
	cout << "TEST: testInsertGetTail" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->getTail();	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertGetNegTen() {
	
	cout << "TEST: testInsertGetNegTen" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(-10);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertGetZero() {
	
	cout << "TEST: testInsertGetZero" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(0);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertGetOne() {
	
	cout << "TEST: testInsertGetOne" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[1];
	objPos actual = ListUnderTest->get(1);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertGetCountN3() {
	
	cout << "TEST: testInsertGetCountN3" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-3];
	objPos actual = ListUnderTest->get(COUNT-3);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertGetCountN1() {
	
	cout << "TEST: testInsertGetCountN1" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT-1);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testInsertGetCountP5() {
	
	cout << "TEST: testInsertGetCountP5" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT+5);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}



// REMOVE HEAD
// REMOVE TAIL
// REMOVE 

void testRemoveHead() {
	
	cout << "TEST: testRemoveHead" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}	
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->removeHead();	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	assert_equal(expectedSize, actualSize);

	clearList();
}

void testRemoveTail() {
	
	cout << "TEST: testRemoveTail" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->removeTail();	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	assert_equal(expectedSize, actualSize);

	clearList();
}

void testRemoveNegTen() {
	
	cout << "TEST: testRemoveNegTen" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->remove(-10);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	assert_equal(expectedSize, actualSize);

	clearList();
}

void testRemoveZero() {
	
	cout << "TEST: testRemoveZero" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->remove(0);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	assert_equal(expectedSize, actualSize);

	clearList();
}

void testRemoveOne() {
	
	cout << "TEST: testRemoveOne" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}	
	
	objPos expected = itemArray[1];
	objPos actual = ListUnderTest->remove(1);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	assert_equal(expectedSize, actualSize);

	clearList();
}

void testRemoveCountN3() {
	
	cout << "TEST: testRemoveCountN3" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-3];
	objPos actual = ListUnderTest->remove(COUNT-3);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	assert_equal(expectedSize, actualSize);

	clearList();
}

void testRemoveCountN1() {
	
	cout << "TEST: testRemoveCountN1" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->remove(COUNT-1);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	assert_equal(expectedSize, actualSize);

	clearList();
}

void testRemoveCountP5() {
	
	cout << "TEST: testRemoveCountP5" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->remove(COUNT+5);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	assert_equal(expectedSize, actualSize);

	clearList();
}



// SET
// SET
// SET

void testSetNegTen() {
	
	cout << "TEST: testSetNegTen" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}

	objPos expected = generateRandomPos();	
	ListUnderTest->set(expected, -10);
	objPos actual = ListUnderTest->get(-10);	
	
	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testSetZero() {
	
	cout << "TEST: testSetZero" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, 0);
	objPos actual = ListUnderTest->get(0);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testSetOne() {
	
	cout << "TEST: testSetOne" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, 1);
	objPos actual = ListUnderTest->get(1);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testSetCountN3() {
	
	cout << "TEST: testSetCountN3" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, COUNT-3);
	objPos actual = ListUnderTest->get(COUNT-3);	

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testSetCountN1() {
	
	cout << "TEST: testSetCountN1" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, COUNT-1);
	objPos actual = ListUnderTest->get(COUNT-1);

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}

void testSetCountP5() {
	
	cout << "TEST: testSetCountP5" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, COUNT+5);
	objPos actual = ListUnderTest->get(COUNT+5);

	assert_equal(expected.getX(), actual.getX());
	assert_equal(expected.getY(), actual.getY());
	assert_equal(expected.getNum(), actual.getNum());
	assert_equal(expected.getPF(), actual.getPF());
	assert_equal(expected.getSym(), actual.getSym());
	clearList();
}


// GET NEXT and RESET
// GET NEXT and RESET
// GET NEXT and RESET

void testGetNextResetWholeList() {
	
	cout << "TEST: testGetNextResetWholeList" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		assert_equal(expected.getX(), actual.getX());
		assert_equal(expected.getY(), actual.getY());
		assert_equal(expected.getNum(), actual.getNum());
		assert_equal(expected.getPF(), actual.getPF());
		assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
}

void testGetNextResetPos2() {
	
	cout << "TEST: testGetNextResetPos2" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < 2; i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		assert_equal(expected.getX(), actual.getX());
		assert_equal(expected.getY(), actual.getY());
		assert_equal(expected.getNum(), actual.getNum());
		assert_equal(expected.getPF(), actual.getPF());
		assert_equal(expected.getSym(), actual.getSym());
	}

	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		assert_equal(expected.getX(), actual.getX());
		assert_equal(expected.getY(), actual.getY());
		assert_equal(expected.getNum(), actual.getNum());
		assert_equal(expected.getPF(), actual.getPF());
		assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
}

void testGetNextResetPos5() {
	
	cout << "TEST: testGetNextResetPos5" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < 5; i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		assert_equal(expected.getX(), actual.getX());
		assert_equal(expected.getY(), actual.getY());
		assert_equal(expected.getNum(), actual.getNum());
		assert_equal(expected.getPF(), actual.getPF());
		assert_equal(expected.getSym(), actual.getSym());
	}

	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		assert_equal(expected.getX(), actual.getX());
		assert_equal(expected.getY(), actual.getY());
		assert_equal(expected.getNum(), actual.getNum());
		assert_equal(expected.getPF(), actual.getPF());
		assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
}

void testGetNextResetPos8() {
	
	cout << "TEST: testGetNextResetPos8" << endl;
	createNewList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < 8; i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		assert_equal(expected.getX(), actual.getX());
		assert_equal(expected.getY(), actual.getY());
		assert_equal(expected.getNum(), actual.getNum());
		assert_equal(expected.getPF(), actual.getPF());
		assert_equal(expected.getSym(), actual.getSym());
	}

	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		assert_equal(expected.getX(), actual.getX());
		assert_equal(expected.getY(), actual.getY());
		assert_equal(expected.getNum(), actual.getNum());
		assert_equal(expected.getPF(), actual.getPF());
		assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
}


// add two more test cases for your unit test learning purpose


bool runAllTests(int argc, char const *argv[]) {
	
	
    testConstructorGetSize();
	testConstructorIsEmptyTrue();

	testInsertHeadIsEmptyFalse();
	testInsertHeadGetSize();
	testInsertHeadGetHead();
	testInsertHeadGetTail();
	testInsertHeadGetNegTen();
	testInsertHeadGetZero();
	testInsertHeadGetOne();
	testInsertHeadGetCountN3();
	testInsertHeadGetCountN1();
	testInsertHeadGetCountP5();

	testInsertTailIsEmptyFalse();
	testInsertTailGetSize();
	testInsertTailGetHead();
	testInsertTailGetTail();
	testInsertTailGetNegTen();
	testInsertTailGetZero();
	testInsertTailGetOne();
	testInsertTailGetCountN3();
	testInsertTailGetCountN1();
	testInsertTailGetCountP5();

	testRemoveHead();
	testRemoveTail();
	testRemoveNegTen();
	testRemoveZero();
	testRemoveOne();
	testRemoveCountN3();
	testRemoveCountN1();
	testRemoveCountP5();

	testSetNegTen();
	testSetZero();
	testSetOne();
	testSetCountN3();
	testSetCountN1();
	testSetCountP5();

	if(testGetNextReady)
	{
		testGetNextResetWholeList();
		testGetNextResetPos2();
		testGetNextResetPos5();
		testGetNextResetPos8();
	}
	
	if(successCount != TOTAL_ASSERT_COUNT) 
		return false;
	else 
		return true;
}

int main(int argc, char const *argv[]) {
  	
	srand(time(NULL));
	successCount = 0;
	bool successCode = runAllTests(argc, argv);
	if(successCode)	cout << endl << "Passed All Tests" << endl;
	else			cout << "Failed Tests, Check Failure" << endl;	
	cout << "Assertion Score: " << successCount << " / " << TOTAL_ASSERT_COUNT << endl;	

	return successCode? EXIT_SUCCESS : EXIT_FAILURE;
}

void clearList()
{
	delete ListUnderTest;
	ListUnderTest = NULL;	
}

objPos generateRandomPos()
{
	objPos temp;

	temp.setX(rand() % 100);
	temp.setY(rand() % 100);
	temp.setNum(rand() % 500);
	temp.setPF(rand() % 26 + 'a');
	temp.setSym(rand() % 26 + 'A');

	return temp;
}


void assert_equal(int a, int b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		cout << "\t\t[ASSERTION] Expected: " << a << ", but Actual: " << b << endl;		
	}
	//return result;
}

void assert_equal(char a, char b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		cout << "\t\tExpected: " << a << ", but Actual: " << b << endl;		
	}
	//return result;
}