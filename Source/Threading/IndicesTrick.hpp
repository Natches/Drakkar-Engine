#pragma once

namespace drak {
namespace function {

// originaly inspired from : http://loungecpp.wikidot.com/tips-and-tricks%3aindices

template<int...idx>
struct index {
};

template<int s, int...i>
constexpr auto BuildIndex() {
	constexpr int s2 = s - 1;
	if constexpr(s == 0)
		return index<i...>();
	else
		return BuildIndex<s2, s2, i...>();
}

} // namespace function
} // namespace drak