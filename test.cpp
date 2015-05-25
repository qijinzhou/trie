#include <gtest/gtest.h>

#include "trie.hpp"


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