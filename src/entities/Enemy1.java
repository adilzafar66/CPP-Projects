package entities;

import graphics.Animations;
import graphics.Assets;
import main.Game;
import main.Handler;

import java.awt.*;
import java.awt.image.BufferedImage;

public class Enemy1 extends Creature{

    private Animations animMove;


    public Enemy1(Handler handler, float x, float y, int width, int height) {
        super(handler, x, y, width, height);
        animMove = new Animations(150, Assets.enemy1);
    }

    public void moveEnemy(){
        x--;
    }


    @Override
    public void update() {
        moveEnemy();
        animMove.update();
    }

    @Override
    public void render(Graphics graphic) {
        float xPos = x - handler.getCamera().getxOffset();
        float yPos = y - handler.getCamera().getyOffset();
        graphic.drawImage(animMove.getCurrentFrame(), (int)xPos, (int)yPos, width,height,null);
    }



}
