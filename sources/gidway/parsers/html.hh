#pragma once

#include <parsers/parser.hh>

namespace gidway {
namespace parsers {

class Html
	: public gidway::parsers::Parser
{
public:
	using gidway::parsers::Parser::Parser;

	virtual ~Html() = default;

	/**
	 * Load HTML content
	 */
	explicit Html (const char*) {}


	unsigned size (void) const {
		return 0; // TODO
	}

	unsigned layers (void) const {
		return 0; // TODO
	}

}; // clas Html

} // namespace parsers
} // namespace gidway
