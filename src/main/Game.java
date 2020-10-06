package main;

import background.MainBackground;
import graphics.Assets;
import graphics.Camera;
import graphics.Display;
import input.KeyManager;
import states.CurrentState;
import states.GameState;
import states.MainMenuState;
import states.State;
import tiles.TileDir;
import tiles.Tiles;

import java.awt.*;
import java.awt.image.BufferStrategy;

public class Game implements Runnable{
    private Display display;
    private int width, height;
    public String title;
    private Thread thread;
    private boolean running = false;

    private State gameState;
    private State menuState;

    private KeyManager keyManager;

    private Camera camera;

    private Handler handler;


    public Game(String title, int width, int height){
        this.width = width;
        this.height = height;
        this.title = title;
        keyManager = new KeyManager();

    }

    private void init(){
        display = new Display(width,height,title);
        display.getFrame().addKeyListener(keyManager);
        Assets.init();

        camera = new Camera(this,0,0);
        handler = new Handler(this);

        gameState = new GameState(handler);
        menuState = new MainMenuState(handler);
        CurrentState.SetState(gameState);
        MainBackground.init();
    }
    private void update(){
        if (CurrentState.GetState()!= null) {
            CurrentState.GetState().update();
        }
    }
    private void render(){
        BufferStrategy buffer = display.getCanvas().getBufferStrategy();
        if(buffer == null){
            display.getCanvas().createBufferStrategy(3);
            return;
        }
        Graphics graphic = buffer.getDrawGraphics();
        //Clear Screen
        graphic.clearRect(0,0,width,height);
        //Draw Here!
        if (CurrentState.GetState()!= null) {
            CurrentState.GetState().render(graphic);
        }

        //End Drawing!

        buffer.show();
        graphic.dispose();
    }

    public void run(){
        init();
        while(running){
            TimeControl.inLoop();
            if(TimeControl.check()){
                update();
                render();
            }

        }

        stop();
    }

    public KeyManager getKeyManager(){
        return keyManager;
    }

    public Camera getCamera(){
        return camera;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public synchronized void start(){
        if (running)
            return;
        thread = new Thread(this);
        thread.start();
        running = true;
    }

    public synchronized void stop(){
        if (!running)
            return;
        try {
            thread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

}
