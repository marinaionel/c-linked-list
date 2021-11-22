extern "C" {
#include "../LinkedList/linked_list.h"
}

#include "gtest/gtest.h"

TEST(TestLinkedListCreate, DoesNotCrash) {
	list_t list = list_create();
	SUCCEED();
	list_destroy(list);
}

TEST(TestLinkedListCreate, ReturnedListPointerIsNotNull) {
	list_t list = list_create();
	ASSERT_TRUE(list != nullptr);
	list_destroy(list);
}

TEST(TestLinkedListCreate, TheCreatedListHasZeroItems) {
	list_t list = list_create();
	EXPECT_EQ(0, list_noOfItems(list));
	list_destroy(list);
}

class TestLinkedListDestroy :public::testing::Test
{
protected:
	list_t list0;
	void SetUp() override
	{
		list0 = list_create();
	}

	void TearDown() override
	{

	}
};

TEST_F(TestLinkedListDestroy, DoesNotCrash)
{
	list_destroy(list0);
	SUCCEED();
}

TEST_F(TestLinkedListDestroy, ReturnsAList_returncode_tType)
{
	list_ReturnCode_t result = list_destroy(list0);
	SUCCEED();
}

TEST(TestLinkedListDestroy_, returnsList_nullIfPassedNullArgument) {
	list_ReturnCode_t result = list_destroy(NULL);
	EXPECT_EQ(LIST_NULL, result);
}

TEST_F(TestLinkedListDestroy, ReturnsList_okIfPassedAValidPointerCreatedBefore)
{
	EXPECT_EQ(LIST_OK, list_destroy(list0));
}

TEST_F(TestLinkedListDestroy, AfterCallingDestroyThePointerPassedAsAnArgumentIsNull)
{
	list_destroy(list0);
	EXPECT_EQ(NULL, list0);
}

class TestLinkedListAddItem :public::testing::Test
{
protected:
	list_t list1;
	void SetUp() override
	{
		list1 = list_create();
	}

	void TearDown() override
	{
		list_destroy(list1);
	}
};

TEST_F(TestLinkedListAddItem, CanCallAdditemWithoutCrashing)
{
	list_addItem(list1, (void*)1);
	SUCCEED();
}

TEST_F(TestLinkedListAddItem, ReturnsAList_returncode_tType)
{
	list_ReturnCode_t result = list_addItem(list1, (void*)1);
	SUCCEED();
}