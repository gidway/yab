// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

namespace gidway {
namespace xml {

/**
 * Interface of XML nodes
 */
class node {
public:
	virtual ~node (void) = default;
	node (void) = default;
}; // class node

} // namespace xml

using XMLNode = xml::node;
} // namespace gidway
