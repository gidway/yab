#pragma once

namespace gidway {
namespace parsers {

/**
 * Used as base for all parsers, to define objects as parsers.
 */
class Parser
{
protected:
	virtual ~Parser (void) = default;
	Parser (void) = default;
}; // class Parser

} // namespace parsers
} // namespace gidway
