package com.FirstSpringBootProject.lern_spring_fremwork;

import com.FirstSpringBootProject.lern_spring_fremwork.game.GameRunner;
import com.FirstSpringBootProject.lern_spring_fremwork.game.MarioGame;
import com.FirstSpringBootProject.lern_spring_fremwork.game.SuperContraGame;
import com.FirstSpringBootProject.lern_spring_fremwork.game.GamingConsol;

public class AppGamingBasicJava {

	public static void main(String[] args) {
	
		var game = new MarioGame();
//		var game = new SuperContraGame();
		var gameRunner = new GameRunner(game);
		gameRunner.run();
		
		gameRunner.run();
		

	}

}
