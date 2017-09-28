// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

namespace gidway {
namespace xml {

/**
 * Interface of XML nodes
 */
class Node {
public:
	virtual ~Node (void) = default;
	Node (void) = default;
}; // class Node

} // namespace xml

using XMLNode = xml::Node;
} // namespace gidway
