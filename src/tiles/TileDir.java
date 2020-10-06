package tiles;

public class TileDir {

    public static Tiles[] tiles = new Tiles[256];
    public static Tiles grassTile = new GrassTile(2);
    public static Tiles gravelTile = new GravelTile(1);
    public static Tiles emptyTile = new EmptyTile(0);

}
