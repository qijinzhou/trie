#include <memory>
#include <stack>
#include <vector>


namespace q
{


template<class TKey, class TValue>
struct trie_node
{
	TKey key;
	TValue value;
	std::vector<std::unique_ptr<trie_node>> children;
};


template<class TKey, class TValue>
class trie
{
public:
	template<class TKeyIter>
	void emplace(TKeyIter begin, TKeyIter end)
	{
		auto pNode = &_root;
		for (auto itr = begin; itr < end; ++itr)
		{
			auto&& key = *itr;
			auto& children = pNode->children;
			auto itrChild = std::lower_bound(children.begin(), children.end(), key, [](auto&& spNode, auto&& theKey){ return spNode->key < theKey; });
			if (itrChild == children.end() || (*itrChild)->key != key)
			{
				itrChild = children.emplace(itrChild, new trie_node<TKey, TValue>());
				(*itrChild)->key = key;
			}
			pNode = itrChild->get();
		}
	}

	template<class TKeyIter>
	bool find(TKeyIter begin, TKeyIter end)
	{
		auto pNode = &_root;
		for (auto itr = begin; itr < end; ++itr)
		{
			auto&& key = *itr;
			auto& children = pNode->children;
			auto itrChild = std::lower_bound(children.begin(), children.end(), key, [](auto&& spNode, auto&& theKey){ return spNode->key < theKey; });
			if (itrChild == children.end() || (*itrChild)->key != key)
				return false;
			pNode = itrChild->get();
		}
		return true;
	}

private:
	trie_node<TKey, TValue> _root;
};


}