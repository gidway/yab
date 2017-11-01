// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

namespace gidway {
namespace xml {
	class node;

template <typename _Node>
class dom {
public:
	using node_type = _Node;

	virtual ~dom (void) = default;

	dom (void)
	{
		_validate_node_type();
	}

	dom (const ::std::shared_ptr<_Node> & __root_node)
		: _root(__root_node)
	{
		_validate_node_type();
	}

	virtual void _insert_as_content_of(_Node & __node, const char __char) = 0;

protected:

	bool __validate_node_type (void) const {
		static ::std::shared_ptr<_Node> _test_node(::std::make_shared<_Node>());
		return (nullptr != dynamic_cast<::gidway::xml::node*>(_test_node.get()));
	}

	void _validate_node_type (void) const {
		assert(__validate_node_type() or "Node Element must have XMLNode as base");
	}

protected:

	::std::shared_ptr<_Node> _root;

}; // class dom

} // namespace xml
} // namespace gidway
