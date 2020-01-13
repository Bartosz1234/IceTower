#pragma once

#define SCREEN_WIDTH 1420
#define SCREEN_HEIGHT 800

#define SPLASH_STATE_SHOW_TIME 3.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Splash State.jpg"

#define MAIN_MENU_BACKGROUND_FILEPATH "Ice Tower grafika.jpg"
#define PLAY_BUTTON_FILEPATH "PlayButton.png"
#define GAME_BACKGROUND_FILEPATH "game_background.png"
#define GROUND_1_FILEPATH "level_one_1.png"
#define GROUND_2_FILEPATH "level_one_2.png"
#define GROUND_3_FILEPATH "level_one_3.png"
#define ILOSC_POZYCJI_MENU 4
#define GROUND_MOVEMENT_SPEED 100.0f
#define GROUND_SPAWN_FREQUENCY 2.0f

#define OPTIONS_BACKGROUND_FILEPATH "Options background.png"
#define GAME_EDGE_FILEPATH "Edge.png"
#define END_FILEPATH "Koniec.png"

#define MATE_FRAME_FILEPATH "Stoi.png"
#define JUMP_FRAME_FILEPATH "Skok.png"
#define RIGHT_FRAME_FILEPATH "Prawo.png"
#define LEFT_FRAME_FILEPATH "Lewo.png"


#define MATE_STATE_STILL 1
#define MATE_STATE_FALLING 2
#define MATE_STATE_JUMPING 3

#define GRAVITY 350.0f
#define JUMPING_SPEED 700.0f

#define JUMPING_DURATION 0.4f

enum GameStates
{
	eReady,
	ePlaying,
	ePause,
	ePauseEsc,
	eReadyEsc,
	eGameOver
};

#define FLASH_SPEED 1300.0f
#define OPTIONS_F1_BACKGROUND_FILEPATH "OptionsF1.png"

#define SCORING_GROUND_FILEPATH "InvisibleScoringGround.png"
#define ICETWOER_FONT "arial.ttf"

#define PLAY_AGAIN_BUTTON "Play Again Button.png"
#define GAME_OVER_WINDOW "GameOver.png"

#define TIME_BEFORE_YOU_DIE 1.5f

#define WYNIKI_BACKGROUND_FIEPATH "Wynik.png"

#define ESC_WINDOW_FILEPATH "Quitting.png"
#define YES_BUTTON_FILEPATH "Yes.png"
#define NO_BUTTON_FILEPATH "No.png"