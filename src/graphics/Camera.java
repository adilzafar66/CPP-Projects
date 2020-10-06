package graphics;

import entities.Entity;
import main.Game;

public class Camera {
    private float xOffset, yOffset;
    private Game game;

    public Camera(Game game, float xOffset, float yOffset){
        this.game = game;
        this.xOffset = xOffset;
        this.yOffset = yOffset;

    }

    public void centerOnEntity(Entity e){
        xOffset = e.getX() - 10;
        //add e.getWidth/2 to center it on the player instead its corner
        yOffset = e.getY() - (game.getHeight()-200) + e.getHeight()/2;
    }

    //Optional
    public void move(float xAdd, float yAdd){
        xOffset += xAdd;
        yOffset += yAdd;
    }

    public float getxOffset() {
        return xOffset;
    }


    public float getyOffset() {
        return yOffset;
    }

}
