#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module mud.math;
#else
#include <stl/vector.hpp>
#include <stl/unordered_map.hpp>
#include <geom/Extern.h>
#endif

namespace stl
{
	using namespace mud;
	template class MUD_GEOM_EXPORT vector<Poisson*>;
	template class MUD_GEOM_EXPORT vector<Geometry*>;
	template class MUD_GEOM_EXPORT vector<Geometry>;
	template class MUD_GEOM_EXPORT vector<Circle>;
	template class MUD_GEOM_EXPORT vector<IcoSphere>;
	template class MUD_GEOM_EXPORT vector<ProcShape>;
	template class MUD_GEOM_EXPORT vector<Distribution::Point>;
	template class MUD_GEOM_EXPORT vector<vector<Distribution::Point>>;
	template class MUD_GEOM_EXPORT vector<vector<Distribution::Point>*>;
	template class MUD_GEOM_EXPORT unordered_map<int64_t, int>;
}