// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

namespace gidway {
namespace algorithms {
namespace streams {

template <typename TChar>
class chars_base
{
	const char * const _content {nullptr};
	mutable unsigned long long _pos {0ULL};

public:
	static constexpr auto stream_end = '\0';

	virtual ~chars_base (void) = default;

	chars_base (const TChar * const __content)
		: _content(__content)
	{
	}

	bool validate (void) const {
		return (nullptr != _content);
	}

	const chars_base<TChar> & begin (void) const {
		_pos = 0;
		return *this;
	}

	bool end (void) const {
		return (_content[_pos] == stream_end);
	}

	const chars_base<TChar> & operator ++ (void) const {
		++_pos;
		return *this;
	}

	const TChar get (void) const {
		return at(_pos);
	}

	const TChar at (unsigned long long __index) const {
		return _content[__index];
	}

	const TChar operator * (void) const {
		return get();
	}

}; // class chars

using chars = chars_base<char>;
using uchars = chars_base<unsigned char>;

} // namespace streams
} // namespace algorithms
} // namespace gidway
