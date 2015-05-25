#include <gtest/gtest.h>

#include "trie.hpp"

TEST(trie, emplace)
{
	q::trie<char, std::string> t;
	std::string key("hello");
	t.emplace(key.begin(), key.end());

	std::string key2("world");
	t.emplace(key2.begin(), key2.end(), "Hello World!");
}

TEST(trie, find)
{
	q::trie<char, int> t;
	std::string key("hello");
	t.emplace(key.begin(), key.end());

	std::string find1("hello");
	EXPECT_TRUE(t.find(find1.begin(), find1.end()));

	std::string find2("world");
	EXPECT_FALSE(t.find(find2.begin(), find2.end()));
}