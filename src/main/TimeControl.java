package main;

public class TimeControl {
    private static double fps = 50;
    private static double TPU = 1000000000/fps;
    private static double delta = 0;
    private static long now;
    private static long lastTime = System.nanoTime();

    public static void inLoop(){
        now = System.nanoTime();
        delta += (now - lastTime) / TPU;
        lastTime = now;
    }

    public static boolean check(){
        boolean checker = (delta >=1);
        if (checker)
            delta--;
        return checker;
    }

}
