package tiles;

import java.awt.*;
import java.awt.image.BufferedImage;

public class Tiles {

    public static final int TILEWIDTH = 32, TILEHEIGHT = 32;
    protected BufferedImage texture;
    protected final int tileId;

    public Tiles(BufferedImage texture, int tileId){
        this.texture = texture;
        this.tileId = tileId;
        TileDir.tiles[tileId] = this;
    }

    public void update(){

    }

    public void render(Graphics graphic, int x, int y){
        graphic.drawImage(texture, x, y, TILEWIDTH, TILEHEIGHT, null);
    }

    public int getId(){
        return tileId;
    }

    public boolean isSolid(){
        return false;
    }
}