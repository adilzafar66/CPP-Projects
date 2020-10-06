package input;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class KeyManager implements KeyListener {

    public boolean[] keys;
    private boolean[] keys2;
    private int last;


    public KeyManager(){
        keys = new boolean[256];
        keys2 = new boolean[256];
    }

    public boolean[] getKey(){
        return keys;
    }
    public boolean[] getKeys2(){
        return keys2;
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        keys[e.getKeyCode()] = true;
        keys2[last] = false;
        keys2[e.getKeyCode()] = true;
        last = e.getKeyCode();
    }

    @Override
    public void keyReleased(KeyEvent e) {
        if(e.getKeyCode()!=32){
            keys[e.getKeyCode()] = false;
        }


    }
}
