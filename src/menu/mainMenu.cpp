#include "mainMenu.h"
#include "button.h"
#include "utils.h"
#include "programManager.h"

#include <iostream>

namespace MoonPatrol {
	namespace MainMenu {

		// Private 

		const int amountButtons = static_cast<int>(Options::COUNT);
		Buttons::Button buttons[amountButtons];
		int cursor;

		void resetHovering();
		void updateCursor();
		const char* getButtonName(Options option);
		void selectOption(Options option);
		void initButtons();
		void drawCredits();
		void drawText();
		void draw();

		// --

		void resetHovering() {
			for (int i = 0; i < static_cast<int>(Options::COUNT); i++) {
				Buttons::hover(buttons[i], false);
			}
		}

		void updateCursor() {
			if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) cursor--;
			if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) cursor++;
			if(cursor < static_cast<int>(Options::PLAY)) cursor = static_cast<int>(Options::EXIT);
			if(cursor > static_cast<int>(Options::EXIT)) cursor = static_cast<int>(Options::PLAY);
			resetHovering();
			Buttons::hover(buttons[cursor], true);
		}

		const char* getButtonName(Options option) {
			switch (option) {
			case MainMenu::Options::PLAY:
				return "Play";
				break;
			case MainMenu::Options::CREDITS:
				return "Credits";
				break;
			case MainMenu::Options::EXIT:
				return "Exit";
				break;
			default:
				std::cout << "Invalid Option! [MainMenu.cpp - getButtonName]\n";
				return "Error";
				break;
			}
		}

		void selectOption(Options option) {
			switch (option) {
			case MainMenu::Options::PLAY:
				setProgramStatus(ProgramStatus::INGAME);
				break;
			case MainMenu::Options::CREDITS:
				//setProgramStatus(ProgramStatus::CREDITS);
				std::cout << "Credits not yet implemented.\n";
				break;
			case MainMenu::Options::EXIT:
				setGameShouldClose(true);
				break;
			default:
				std::cout << "Invalid Option! [MainMenu.cpp - SelectOption()]\n";
				break;
			}
		}

		void initButtons() {
			float spacing = 0;
			for (int i = 0; i < amountButtons; i++) {
				if (i > 0)
					spacing += buttons[0].size.y + GetScreenHeight() * .025f;
				buttons[i] = Buttons::create(i,
					Vector2{ static_cast<float>(GetScreenWidth() * .5), static_cast<float>(GetScreenHeight() * .45) + spacing },
					Vector2{ static_cast<float>(GetScreenWidth() * .3), static_cast<float>(GetScreenHeight() * .1) },
					getButtonName((Options)i));
			}
		}

		void drawCredits() {
			const char* text = "Game built by Salazar using Raylib by Ray";
			int fontSize = static_cast<int>(GetScreenHeight() * .025f);
			int textWide = MeasureText(text, fontSize);
			DrawText(text, static_cast<int>((GetScreenWidth() * .99) - textWide), static_cast<int>((GetScreenHeight() * .99) - fontSize), fontSize, WHITE);
		}

		void drawText() {
			Utils::DrawCenteredText("Placeholder",
				{ static_cast<float>(GetScreenWidth() * .5), static_cast<float>(GetScreenHeight() * .17) },
				static_cast<int>(GetScreenHeight() * .2f), SKYBLUE);
			Utils::DrawCenteredText("A \"Moon Patrol\"-like Game",
				{ static_cast<float>(GetScreenWidth() * .5), static_cast<float>(GetScreenHeight() * .26) },
				static_cast<int>(GetScreenHeight() * .035f), ORANGE);
		}

		void draw() {
			BeginDrawing();
			ClearBackground(BLACK);

			for (int i = 0; i < amountButtons; i++) {
				Buttons::draw(buttons[i]);
			}

			drawText();
			drawCredits();

			EndDrawing();
		}

		// Public

		void update() {
			updateCursor();
			for (int i = 0; i < amountButtons; i++) {
				if (Buttons::update(buttons[i]))
					selectOption((Options)buttons[i].id);
			}

			draw();
		}

		void init() {
			initButtons();
			cursor = static_cast<int>(Options::PLAY);
		}
	}
}