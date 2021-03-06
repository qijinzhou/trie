#include <algorithm>
#include <memory>
#include <stack>
#include <vector>


namespace q
{


template<class TKey>
class trie_set
{
	template<class TNodeKey>
	struct trie_node
	{
		TNodeKey key;
		std::vector<std::unique_ptr<trie_node>> children;
	};

public:
	void clear()
	{
		_root.children.clear();
		_size = 0;
	}

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
				itrChild = children.emplace(itrChild, std::make_unique<trie_node<TKey>>());
				(*itrChild)->key = key;
			}
			pNode = itrChild->get();
		}
		++_size;
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

	bool empty() const
	{
		return _size == 0;
	}

	size_t size() const
	{
		return _size;
	}

private:
	trie_node<TKey> _root;
	size_t _size = 0;
};


template<class TKey, class TValue>
class trie_map
{
	template<class TNodeKey, class TNodeValue>
	struct trie_node
	{
		TNodeKey key;
		std::unique_ptr<TNodeValue> spValue;
		std::vector<std::unique_ptr<trie_node>> children;
	};

public:
	void clear()
	{
		_root.children.clear();
		_size = 0;
	}

	template<class TKeyIter, class... TValueConstructArg>
	void emplace(TKeyIter begin, TKeyIter end, TValueConstructArg&&... valueArg)
	{
		auto pNode = &_root;
		for (auto itr = begin; itr < end; ++itr)
		{
			auto&& key = *itr;
			auto& children = pNode->children;
			auto itrChild = std::lower_bound(children.begin(), children.end(), key, [](auto&& spNode, auto&& theKey){ return spNode->key < theKey; });
			if (itrChild == children.end() || (*itrChild)->key != key)
			{
				itrChild = children.emplace(itrChild, std::make_unique<trie_node<TKey, TValue>>());
				(*itrChild)->key = key;
			}
			pNode = itrChild->get();
		}
		pNode->spValue = std::make_unique<TValue>(std::forward<TValueConstructArg>(valueArg)...);
		++_size;
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

	bool empty() const
	{
		return _size == 0;
	}

	size_t size() const
	{
		return _size;
	}

private:
	trie_node<TKey, TValue> _root;
	size_t _size = 0;
};


}