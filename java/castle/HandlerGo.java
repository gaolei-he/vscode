package castle;

public class HandlerGo extends Handler {

    
    public HandlerGo(Game game) {
        super(game);
    }

    @Override
    public void doCmd(String cmd) {
        game.goRoom(cmd);
    }
    
}
