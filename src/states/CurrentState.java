package states;

import states.State;

public class CurrentState {
    private static State currentState = null;

    public static void SetState(State state){
        currentState = state;
    }

    public static State GetState(){
        return currentState;
    }

}
