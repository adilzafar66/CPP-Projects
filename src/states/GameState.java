package states;

import background.MainBackground;
import entities.Enemy1;
import entities.Player;
import main.Game;
import main.Handler;
import tiles.Tiles;
import worlds.World;

import java.awt.*;

public class GameState extends State {
    private Player player;
    private World world;
    private Enemy1 enemy1;


    public GameState(Handler handler){
        super(handler);
        world = new World(handler,"Resources/Worlds/world1.txt");
        handler.setWorld(world);
        player = new Player(handler,world.getSpawnX() * 66,world.getSpawnY() * 92);
        enemy1 = new Enemy1(handler, 600,-27, 50, 28);

    }
    @Override
    public void update() {
        world.update();
        player.update();
        enemy1.update();
    }

    @Override
    public void render(Graphics graphic) {
        MainBackground.render(graphic);
        world.render(graphic);
        player.render(graphic);
        enemy1.render(graphic);
    }
}
