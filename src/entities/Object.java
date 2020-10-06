package entities;

import main.Game;
import main.Handler;

public abstract class Object extends Entity {

    public Object(Handler handler, float x, float y, int width, int height) {
        super(handler, x, y, width, height);
    }

}
