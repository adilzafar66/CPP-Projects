package graphics;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Assets {
    private static int width = 32, height = 32;
    public static BufferedImage grass, sky, rock, gravel, sand, dirt;
    public static BufferedImage[] player_forward;
    public static BufferedImage[] player_backward;
    public static BufferedImage player_jump;
    public static BufferedImage player_stand;
    public static BufferedImage player_duck;
    public static BufferedImage[] enemy1;
    public static String path;

    public static void init(){
        SpriteSheet sheet = new SpriteSheet(graphics.ImageLoader.loadImage("/textures/bg2.png"));
        grass = sheet.crop(0, 0, width,height);
        sky = sheet.crop(width, 0, width, height);
        dirt = ImageLoader.loadImage("/grassCenter.png");
        gravel = sheet.crop(2*width, 0, width, height);
        sand = sheet.crop(3*width, 0 , width, height);
        player_forward = new BufferedImage[11];
        player_backward = new BufferedImage[11];
        player_jump = ImageLoader.loadImage("/Player/p1_jump.png");
        player_stand = ImageLoader.loadImage("/Player/p1_stand.png");
        player_duck = ImageLoader.loadImage("/Player/p1_duck.png");
        for (int x = 1; x < 12; x++){
            path = "/Player/p1_walk" + x + ".png";
            player_forward[x-1] = ImageLoader.loadImage(path);
            player_backward[11-x] = ImageLoader.loadImage(path);
        }

        enemy1 = new BufferedImage[2];
        for (int x = 1; x < 3; x++){
            path = "/Enemies/slimeWalk"+ x +".png";
            enemy1[x-1] = ImageLoader.loadImage(path);
        }


    }
}