#pragma once

namespace MoonPatrol {
	namespace Credits {
		enum class Options {
			ITCH,
			RAYLIB,
			RETURN,
			COUNT
		};

		void update();
		void init();
	}
}