package main;

import main.Game;

public class Launcher {
    public static void main(String[] args){
        Game game = new Game("Snaker", 500, 500);
        game.start();
    }
}
