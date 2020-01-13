//#pragma once
//#include <stdio.h>
//#include "MainMenuState.h"
//
//
//namespace Bartux
//{
//
//	typedef struct Wyniczkowanie_gra {
//		float _time;
//		int _score;
//
//	};
//
//
//	class Wyniczkowanie
//	{
//	private:
//
//		FILE *wyniczkowanie;
//
//
//	public:
//		Wyniczkowanie()
//		{
//			wyniczkowanie = fopen("Wyniczkowanie.txt", "ab+");
//		}
//
//		void addGame(Wyniczkowanie_gra *GameState) 
//		{
//			fwrite(GameState, sizeof(Wyniczkowanie_gra), 1, wyniczkowanie);
//			fclose(wyniczkowanie);
//		}
//
//		void forEachGame()
//		{
//			while (!feof(wyniczkowanie))
//			{
//				
//			}
//		}
//   
//	};
//
//
//}