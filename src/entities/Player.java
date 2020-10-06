package entities;

import graphics.Animations;
import graphics.Assets;
import main.Game;
import main.Handler;
import main.TimeControl;

import java.awt.*;
import java.awt.image.BufferedImage;

public class Player extends Creature {

    private int temp;

    private Animations animForward;
    private Animations animBackward;
    private boolean flag = false;

    public Player(Handler handler, float x, float y) {
        super(handler, x, y, Creature.DEFAULT_WIDTH,Creature.DEFAULT_HEIGHT);
        animForward = new Animations(50,Assets.player_forward);
        animBackward = new Animations(50, Assets.player_backward);
    }

    public void movePlayer(){
        //Up (Up Arrow ASCII = 38)
        if(handler.getKeyManager().getKey()[32]){
            if (y > -175 && !flag){
                if(y >-150){
                    y-=4;
                }
                else{
                    y-=2;
                }

            }
            if(y <= -175){
                flag = true;
            }

            if(flag && y < -92){
                if(y < -160 && y > -175){
                    y+=2;
                }
                else if(y < -150 && y > -160){
                    y+=2;
                }
                else if (y < -110 && y > -150){
                    y+=3;
                }
                else{
                    y+=4;
                }
                if (y >= -92){
                    flag = false;
                    handler.getKeyManager().keys[32] = false;
                }

            }


        }
        //Down (Down Arrow ASCII = 40)
        /*if(game.getKeyManager().getKey()[40]){
            y+=3;
        }*/
        //Left (Left Arrow ASCII = 37)
        if(handler.getKeyManager().getKey()[37]){
            x-=3;
        }
        //Right (Right Arrow ASCII = 38)
        if(handler.getKeyManager().getKey()[39]){
            x+=3;
        }

    }

    public int getTemp(){
        return temp;
    }

    @Override
    public void update() {
        movePlayer();
        handler.getCamera().centerOnEntity(this);
        animForward.update();
        animBackward.update();
    }

    @Override
    public void render(Graphics graphic) {

        int xPos = (int) (x - handler.getCamera().getxOffset());
        int yPos = (int) (y - handler.getCamera().getyOffset());

        graphic.drawImage(getCurrentAnimFrame(),xPos,yPos,Creature.DEFAULT_WIDTH, Creature.DEFAULT_HEIGHT, null);
    }

    private BufferedImage getCurrentAnimFrame(){
        if(handler.getKeyManager().getKey()[32]){
            return Assets.player_jump;

        }
        else if(handler.getKeyManager().getKey()[37]){
            return animBackward.getCurrentFrame();
        }
        else if(handler.getKeyManager().getKey()[39]){
            return animForward.getCurrentFrame();
        }
        else if(handler.getKeyManager().getKey()[40]){
            return Assets.player_duck;
        }
        else{
            return Assets.player_stand;
        }
    }



}
