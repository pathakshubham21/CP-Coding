package com.FirstSpringBootProject.lern_spring_fremwork.game;

public class GameRunner {
	private GamingConsol game;
	public GameRunner (GamingConsol game)
	{
		this.game  = game;
	}
	public void run() {
		// TODO Auto-generated method stub
		System.out.println("Running game "+ game);
		game.up();
		game.down();
		game.left();
		game.right();

		// Adding comment 
	}

}
