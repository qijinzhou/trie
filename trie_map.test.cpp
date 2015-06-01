#include <gtest/gtest.h>

#include "trie.hpp"

TEST(trie_map, clear)
{
	q::trie_map<char, int> t;
	std::string key("hello");
	t.emplace(key.begin(), key.end());

	t.clear();
	EXPECT_FALSE(t.find(key.begin(), key.end()));
	EXPECT_EQ(0u, t.size());
}

TEST(trie_map, emplace)
{
	q::trie_map<char, std::string> t;
	std::string key("hello");
	t.emplace(key.begin(), key.end());

	std::string key2("world");
	t.emplace(key2.begin(), key2.end(), "Hello World!");
}

TEST(trie_map, find)
{
	q::trie_map<char, int> t;
	std::string key("hello");
	t.emplace(key.begin(), key.end());

	std::string find1("hello");
	EXPECT_TRUE(t.find(find1.begin(), find1.end()));

	std::string find2("world");
	EXPECT_FALSE(t.find(find2.begin(), find2.end()));
}

TEST(trie_map, empty)
{
	q::trie_map<char, int> t;
	EXPECT_TRUE(t.empty());

	std::string key("hello");
	t.emplace(key.begin(), key.end());
	EXPECT_FALSE(t.empty());
}

TEST(trie_map, size)
{
	q::trie_map<char, int> t;
	EXPECT_EQ(0u, t.size());

	std::string key("hello");
	t.emplace(key.begin(), key.end());
	EXPECT_EQ(1u, t.size());
}