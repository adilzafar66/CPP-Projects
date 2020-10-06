package background;

import graphics.ImageLoader;

import java.awt.*;
import java.awt.image.BufferedImage;

public class MainBackground {
    private static final int width = 320, height = 256;

    public static BufferedImage BG;
    public static void init(){
        BG = ImageLoader.loadImage("/bg.png");
    }

    public static void render(Graphics graphic){
        graphic.drawImage(BG,0,0,256,256,null);
        graphic.drawImage(BG, 0,256,256,256,null);
        graphic.drawImage(BG, 256,0,256,256,null);
        graphic.drawImage(BG, 256,256,256,256,null);
    }
}
