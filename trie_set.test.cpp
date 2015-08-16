#include "test.h"
#include "trie.hpp"

BEGIN_TEST_CLASS(trie_set)

TEST(trie_set, clear)
{
	q::trie_set<char> t;
	std::string key("hello");
	t.emplace(key.begin(), key.end());

	t.clear();
	EXPECT_FALSE(t.find(key.begin(), key.end()));
	EXPECT_EQ(0u, t.size());
}

TEST(trie_set, emplace)
{
	q::trie_set<char> t;
	std::string key("hello");
	t.emplace(key.begin(), key.end());

	std::string key2("world");
	t.emplace(key2.begin(), key2.end());
}

TEST(trie_set, find)
{
	q::trie_set<char> t;
	std::string key("hello");
	t.emplace(key.begin(), key.end());

	std::string find1("hello");
	EXPECT_TRUE(t.find(find1.begin(), find1.end()));

	std::string find2("world");
	EXPECT_FALSE(t.find(find2.begin(), find2.end()));
}

TEST(trie_set, empty)
{
	q::trie_set<char> t;
	EXPECT_TRUE(t.empty());

	std::string key("hello");
	t.emplace(key.begin(), key.end());
	EXPECT_FALSE(t.empty());
}

TEST(trie_set, size)
{
	q::trie_set<char> t;
	EXPECT_EQ(0u, t.size());

	std::string key("hello");
	t.emplace(key.begin(), key.end());
	EXPECT_EQ(1u, t.size());
}

END_TEST_CLASS
