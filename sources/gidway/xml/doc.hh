// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <cassert>
#include <memory>

namespace gidway {
namespace xml {
	class Node;

template <typename _Node>
class doc
{
public:

	doc (void)
	{
		_validate_node_type();
	}

	doc (const ::std::shared_ptr<_Node> & __root_node)
		: _root(__root_node)
	{
		_validate_node_type();
	}

	virtual ~doc (void) = default;

protected:
	bool __validate_node_type (void) const {
		static ::std::shared_ptr<_Node> _test_node(::std::make_shared<_Node>());
		return (nullptr != dynamic_cast<::gidway::xml::Node*>(_test_node.get()));
	}
	void _validate_node_type (void) const {
		assert(__validate_node_type() or "Node Element must have XMLNode as base");
	}

protected:
	::std::shared_ptr<_Node> _root;
}; // class doc

} // namespace xml
} // namespace gidway
