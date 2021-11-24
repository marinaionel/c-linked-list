extern "C" {
#include "../LinkedList/linked_list.h"
}

#include "gtest/gtest.h"

class TestLinkedList :public::testing::Test
{
protected:
	list_t list1;
	void SetUp() override
	{
		list1 = list_create();
	}

	void TearDown() override
	{
		list_destroy(&list1);
	}
};

TEST_F(TestLinkedList, DoesNotCrash) {
	SUCCEED();
}

TEST_F(TestLinkedList, ReturnedListPointerIsNotNull) {
	ASSERT_NE(nullptr, list1);
}

TEST_F(TestLinkedList, TheCreatedListHasZeroItems) {
	EXPECT_EQ(0, list_noOfItems(list1));
}

class TestLinkedListDestroy :public::testing::Test
{
protected:
	list_t list0;
	void SetUp() override
	{
		list0 = list_create();
	}

	void TearDown() override {}
};

TEST_F(TestLinkedListDestroy, DoesNotCrash)
{
	list_destroy(&list0);
	SUCCEED();
}

TEST_F(TestLinkedListDestroy, ReturnsAList_returncode_tType)
{
	list_ReturnCode_t result = list_destroy(&list0);
	SUCCEED();
}

TEST_F(TestLinkedListDestroy, returnsList_nullIfPassedNullArgument) {
	list_ReturnCode_t result = list_destroy(NULL);
	EXPECT_EQ(LIST_NULL, result);
}

TEST_F(TestLinkedListDestroy, ReturnsList_okIfPassedAValidPointerCreatedBefore)
{
	EXPECT_EQ(LIST_OK, list_destroy(&list0));
}

TEST_F(TestLinkedListDestroy, AfterCallingDestroyThePointerPassedAsAnArgumentIsNull)
{
	list_destroy(&list0);
	ASSERT_EQ(nullptr, list0);
}

TEST_F(TestLinkedList, AddItem_CanCallAdditemWithoutCrashing)
{
	list_addItem(list1, (void*)1);
	SUCCEED();
}

TEST_F(TestLinkedList, AddItem_ReturnsAList_returncode_tType)
{
	list_ReturnCode_t result = list_addItem(list1, (void*)1);
	SUCCEED();
}