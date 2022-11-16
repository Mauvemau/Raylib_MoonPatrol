#pragma once

namespace MoonPatrol {
	namespace MainMenu {
		enum class Options {
			PLAY,
			CREDITS,
			EXIT,
			COUNT
		};

		void update();
		void init();
	}
}