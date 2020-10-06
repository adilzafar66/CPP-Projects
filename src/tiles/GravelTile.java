package tiles;

import graphics.Assets;

import java.awt.image.BufferedImage;

public class GravelTile extends Tiles {
    public GravelTile(int tileId) {
        super(Assets.gravel, tileId);
    }

    @Override
    public boolean isSolid(){
        return true;
    }
}
